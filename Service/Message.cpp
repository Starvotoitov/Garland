#include "Message.h"

Message::Message() :
	type(lightOut) 
{
}

Message::Message(HANDLE newEvent) :
	type(sendEvent), messageData(newEvent)
{
}

Message::Message(RGBColor* newColor) :
	type(lightUp), messageData(*newColor)
{
}
/*
MessageType Message::getType() {
	return type;
}

HANDLE Message::getEvent() {
	return get<HANDLE>(messageData);
}

RGBColor Message::getColor() {
	return get<RGBColor>(messageData);
}
*/