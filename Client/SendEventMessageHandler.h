#pragma once

#include "AbstractMessageHandler.h"

class SendEventMessageHandler : public AbstractMessageHandler {
public:
	virtual void ProcessMessage(Message* ProcessingMessage, MessageSubscriber* subscriber);
};