#pragma once

#include "AbstractMessageHandler.h"

class LightOutMessageHandler : public AbstractMessageHandler {
public:
	virtual void ProcessMessage(Message* ProcessingMessage, MessageSubscriber* subscriber);
};