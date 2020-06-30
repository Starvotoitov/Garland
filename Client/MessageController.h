#pragma once

#include "AbstractMessageHandler.h"
#include "MessageSubscriber.h"
#include <map>

using namespace std;

class MessageController {
public:
	MessageController(MessageSubscriber* subscriber);
	~MessageController();
	void handleMessage(Message* message);
private:
	MessageSubscriber* subscriber;
	map<MessageType, AbstractMessageHandler*> handlersMap;
};