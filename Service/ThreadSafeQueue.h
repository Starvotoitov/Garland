#pragma once

#include "AbstractQueue.h"
#include <list>
#include <condition_variable>
#include <mutex>

using namespace std;

template<typename T>
class ThreadSafeQueue : public AbstractQueue<T> {
public:
	ThreadSafeQueue();
	virtual void enqueue(T newElement);
	virtual void dequeue();
	virtual bool isEmpty();
	virtual void waitForElement();
	virtual T getNext();
private:
	typename list<T>::iterator currentElement;
	list<T> queue;
	mutex queueMutex;
	condition_variable queueConditionVariable;
};

template<class T>
ThreadSafeQueue<T>::ThreadSafeQueue() {
	currentElement = queue.begin();
}

template<class T>
void ThreadSafeQueue<T>::enqueue(T newElement) {
	unique_lock<mutex> queueLock(queueMutex);
	queue.push_back(newElement);
	currentElement = queue.begin();
	queueLock.unlock();
	queueConditionVariable.notify_all();
}

template<class T>
void ThreadSafeQueue<T>::dequeue() {
	unique_lock<mutex> queueLock(queueMutex);
	if (queue.empty()) {
		queueConditionVariable.wait(queueLock);
	}
	queue.erase(currentElement);
	currentElement = queue.begin();
}

template<class T>
bool ThreadSafeQueue<T>::isEmpty() {
	unique_lock<mutex> queueLock(queueMutex);
	return queue.empty();
}

template<class T>
void ThreadSafeQueue<T>::waitForElement() {
	unique_lock<mutex> queueLock(queueMutex);
	if (queue.empty()) {
		queueConditionVariable.wait(queueLock);
	}
}

template<class T>
T ThreadSafeQueue<T>::getNext() {
	unique_lock<mutex> queueLock(queueMutex);
	if (queue.empty()) {
		queueConditionVariable.wait(queueLock);
	}

	currentElement++;
	if (currentElement == queue.end()) {
		currentElement = queue.begin();
	}

	return *currentElement; 
}