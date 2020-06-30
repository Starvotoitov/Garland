#pragma once

#include "../MessageDLL/Message.h"
#include "MessageSubscriber.h"

class AbstractMessageHandler {
public:
	virtual void ProcessMessage(Message* ProcessingMessage, MessageSubscriber* subscriber) = 0;
};