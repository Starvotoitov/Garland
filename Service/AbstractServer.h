#pragma once

#include "AbstractConnection.h"
#include "AbstractQueue.h"
#include "RGBColor.h"

class AbstractServer {
public:
	virtual bool sendLightUp(RGBColor* newColor) = 0;
	virtual bool sendLightOut() = 0;
	virtual void listen() = 0;
	virtual void chooseNextUser() = 0;
	virtual void waitForClient() = 0;
	virtual void interrupt() = 0;
	virtual bool isEmpty() = 0;
	virtual void closeCurrentConnection() = 0;
};