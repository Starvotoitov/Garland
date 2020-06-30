#pragma once

#include "../Service/Message.h"
#include "MessageSubscriber.h"

class AbstractMessageHandler {
public:
	virtual void ProcessMessage(Message* ProcessingMessage, MessageSubscriber* subscriber) = 0;
};