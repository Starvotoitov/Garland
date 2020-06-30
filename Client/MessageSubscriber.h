#pragma once

class MessageSubscriber {
public:
	virtual void onSendEvent(HANDLE newEvent) = 0;
	virtual void onLightUp(RGBColor* newColor) = 0;
	virtual void onLightOut() = 0;
	virtual void onError() = 0;
//	virtual void onConnectionClose() = 0;
};