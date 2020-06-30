#include "MessageController.h"
#include "LightUpMessageHandler.h"
#include "LightOutMessageHandler.h"

MessageController::MessageController(MessageSubscriber* subscriber):
	subscriber(subscriber) {
	handlersMap[lightUp] = new LightUpMessageHandler();
	handlersMap[lightOut] = new LightOutMessageHandler();
}

MessageController::~MessageController() {
	for (auto pair : handlersMap) {
		delete pair.second;
	}
}

void MessageController::handleMessage(Message* message) {
	if (message != nullptr) {
		handlersMap[message->type]->ProcessMessage(message, subscriber);
	}
}