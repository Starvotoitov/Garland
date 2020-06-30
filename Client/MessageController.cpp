#include "MessageController.h"
#include "LightUpMessageHandler.h"
#include "LightOutMessageHandler.h"
#include "SendEventMessageHandler.h"

MessageController::MessageController(MessageSubscriber* subscriber):
	subscriber(subscriber) {
	handlersMap[lightUp] = new LightUpMessageHandler();
	handlersMap[lightOut] = new LightOutMessageHandler();
	handlersMap[sendEvent] = new SendEventMessageHandler();
}

MessageController::~MessageController() {
	for (auto pair : handlersMap) {
		delete pair.second;
	}
}

void MessageController::handleMessage(Message* message) {
	if (message != nullptr) {
		handlersMap[message->type]->ProcessMessage(message, subscriber);
//		handlersMap[message->getType()]->ProcessMessage(message, subscriber);
	}
}