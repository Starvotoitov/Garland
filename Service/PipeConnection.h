#pragma once

#include "AbstractConnection.h"
#include <Windows.h>

class PipeConnection : public AbstractConnection {
public:
	PipeConnection(HANDLE hPipe, OVERLAPPED overlap);
	virtual void sendLightUp(RGBColor* newColor);
	virtual void sendLightOut();
private:
	HANDLE hPipe;
	OVERLAPPED overlap;
};