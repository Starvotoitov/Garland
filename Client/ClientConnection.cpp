#include "ClientConnection.h"
#include "PipeConnection.h"

ClientConnection::ClientConnection(ConnectionSubscriber* subscriber) :
	subscriber(subscriber), messageController(this), connection(new PipeConnection()), 
	connectionThread(&ClientConnection::connectionThreadRoutine, this)
{
	connectionThread.detach();
}

void ClientConnection::closeConnection() {
	connection->closeConnection();
}

void ClientConnection::connectionThreadRoutine() {
	if (!connection->createConnection()) {
		if (subscriber != nullptr) {
			subscriber->onError();
		}
		return;
	}

	Message* currentMessage = nullptr;
	do {
		currentMessage = connection->getMessage();
		if (currentMessage != nullptr) {
			messageController.handleMessage(currentMessage);
		} else {
			subscriber->onConnectionClose();
		}
	} while(currentMessage != nullptr);
}

void ClientConnection::onLightUp(RGBColor* newColor) {
	if (subscriber != nullptr) {
		subscriber->onLightUp(newColor);
	}
}

void ClientConnection::onLightOut() {
	if (subscriber != nullptr) {
		subscriber->onLightOut();
	}
}

void ClientConnection::onError() {
	if (subscriber != nullptr) {
		subscriber->onError();
	}
}

