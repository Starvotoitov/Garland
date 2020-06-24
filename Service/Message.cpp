#include "Message.h"

Message::Message():
	type(lightOut), color(RGBColor(0, 0, 0))
{
}

Message::Message(RGBColor* color):
	type(lightUp), color(*color)
{
}

RGBColor Message::getColor() {
	if (type == lightUp) {
		return color;
	} else {
		// TODO: throw Exception
		return color;
	}
}

MessageType Message::getType() {
	return type;
}