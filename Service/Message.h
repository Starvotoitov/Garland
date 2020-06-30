#pragma once

#include "RGBColor.h"
#include <variant>
#include <Windows.h>

enum MessageType {lightUp, lightOut, sendEvent};

using namespace std;
struct Message {
	Message();
	Message(HANDLE newEvent);
	Message(RGBColor* newColor);

	MessageType type;
	variant<monostate, RGBColor, HANDLE> messageData;
};

/*
class Message {
public:
	Message();
	Message(HANDLE newEvent);
	Message(RGBColor* newColor);
	MessageType getType();
	HANDLE getEvent();
	RGBColor getColor();
private:
	MessageType type;
	variant<monostate, RGBColor, HANDLE> messageData;
};
*/