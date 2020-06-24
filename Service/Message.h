#pragma once

#include "RGBColor.h"

enum MessageType {lightUp, lightOut};

class Message {
public:
	Message();
	Message(RGBColor* color);
	RGBColor getColor();
	MessageType getType();
private:
	MessageType type;
	RGBColor color;
};