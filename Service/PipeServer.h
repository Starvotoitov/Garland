#pragma once

#include "AbstractServer.h"
#include <Windows.h>

class PipeServer : public AbstractServer {
public:
	PipeServer();
	~PipeServer();
	virtual bool sendLightUp(RGBColor* newColor);
	virtual bool sendLightOut();
	virtual void listen();
	virtual void chooseNextUser();
	virtual void waitForClient();
	virtual void interrupt();
	virtual bool isEmpty();
	virtual void closeCurrentConnection();
private:
	static const TCHAR* PIPE_NAME;
	static const int TIMEOUT;
	bool isRunning;
	HANDLE hPipeEvent;
	AbstractQueue<AbstractConnection*>* queue;
	AbstractConnection* currentUser;
};