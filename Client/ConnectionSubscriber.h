#pragma once

#include "../Service/RGBColor.h"

class ConnectionSubscriber {
public:
	virtual void onLightUp(RGBColor* newColor) = 0;
	virtual void onLightOut() = 0;
	virtual void onError() = 0;
	virtual void onConnectionClose() = 0;
};