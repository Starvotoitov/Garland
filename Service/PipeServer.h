#pragma once

#include "AbstractServer.h"
#include <Windows.h>

class PipeServer : public AbstractServer {
public:
	PipeServer();
	virtual void sendLightUp(RGBColor* newColor);
	virtual void sendLightOut();
	virtual void listen();
	virtual void chooseNextUser();
	virtual void waitForClient();
	virtual void interrupt();
	virtual bool isEmpty();
private:
	static const TCHAR* PIPE_NAME;
	static const int TIMEOUT;
	bool isRunning;
	HANDLE hPipeEvent;
};