#pragma once

#include "RGBColor.h"

class AbstractConnection {
public:
	virtual void sendLightUp(RGBColor* newColor) = 0;
	virtual void sendLightOut() = 0;
};