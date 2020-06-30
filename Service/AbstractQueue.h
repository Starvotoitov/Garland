#pragma once

#include <iterator>

using namespace std;

template<class T>
class AbstractQueue {
public:
	virtual void enqueue(T newElement) = 0;
	virtual void dequeue() = 0;
	virtual bool isEmpty() = 0;
	virtual void waitForElement() = 0;
	virtual T getNext() = 0;
//	virtual T getCurrent() = 0;
};
