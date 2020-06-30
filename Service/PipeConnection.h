#pragma once

#include "AbstractConnection.h"
#include <Windows.h>

class PipeConnection : public AbstractConnection {
public:
	PipeConnection(HANDLE hPipe, OVERLAPPED overlap);
	~PipeConnection();
	virtual bool sendLightUp(RGBColor* newColor);
	virtual bool sendLightOut();
private:
	HANDLE hPipe;
	OVERLAPPED overlap;
};