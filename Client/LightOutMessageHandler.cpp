#include "LightOutMessageHandler.h"

void LightOutMessageHandler::ProcessMessage(Message* processingMessage, MessageSubscriber* subscriber) {
	if (subscriber != nullptr) {
		subscriber->onLightOut();
	}
}