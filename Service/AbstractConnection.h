#pragma once

#include "../MessageDLL/RGBColor.h"

class AbstractConnection {
public:
	virtual bool sendLightUp(RGBColor* newColor) = 0;
	virtual bool sendLightOut() = 0;
};