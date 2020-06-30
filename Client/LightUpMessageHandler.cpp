#include "LightUpMessageHandler.h" 

void LightUpMessageHandler::ProcessMessage(Message* processingMessage, MessageSubscriber* subscriber) {
	try {
		if (subscriber != nullptr) {
			RGBColor color = get<RGBColor>(processingMessage->messageData);
			subscriber->onLightUp(&color);
		}
	}
	catch (const bad_variant_access& ex) {
		subscriber->onError();
	}
}