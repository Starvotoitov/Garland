#pragma once

#include "ConnectionSubscriber.h"
#include "MessageController.h"
#include "AbstractConnection.h"
#include <thread>

using namespace std;

class ClientConnection : public MessageSubscriber {
public:
	ClientConnection(ConnectionSubscriber* subscriber);
	void closeConnection();
	virtual void onLightUp(RGBColor* newColor);
	virtual void onLightOut();
	virtual void onError();
private:
	thread connectionThread;
	ConnectionSubscriber* subscriber;
	MessageController messageController;
	AbstractConnection* connection;
	void connectionThreadRoutine();
};