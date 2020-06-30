#pragma once

class MessageSubscriber {
public:
	virtual void onLightUp(RGBColor* newColor) = 0;
	virtual void onLightOut() = 0;
	virtual void onError() = 0;
};