#include "Message.h"

Message::Message() :
	type(lightOut) 
{
}

Message::Message(RGBColor* newColor) :
	type(lightUp), messageData(*newColor)
{
}