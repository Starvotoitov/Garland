#include "SendEventMessageHandler.h"

void SendEventMessageHandler::ProcessMessage(Message* processingMessage, MessageSubscriber* subscriber) {
	try {
		if (subscriber != nullptr) {
			HANDLE h = get<HANDLE>(processingMessage->messageData);
			subscriber->onSendEvent(h);
		//	subscriber->onSendEvent(processingMessage->getEvent());
		}
	}
	catch (const bad_variant_access & ex) {
		subscriber->onError();
	}
}