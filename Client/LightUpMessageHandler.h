#pragma once

#include "AbstractMessageHandler.h"

class LightUpMessageHandler : public AbstractMessageHandler {
public: 
	virtual void ProcessMessage(Message* ProcessingMessage, MessageSubscriber* subscriber);
};