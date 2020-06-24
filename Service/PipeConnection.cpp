#include "PipeConnection.h"
#include "Message.h"

PipeConnection::PipeConnection(HANDLE hPipe, OVERLAPPED overlap) :
	hPipe(hPipe), overlap(overlap)
{
}

void PipeConnection::sendLightUp(RGBColor* newColor) {
	Message* lightUpMessage = new Message(newColor);
	WriteFile(hPipe, lightUpMessage, sizeof(Message), NULL, &overlap);
	WaitForSingleObject(overlap.hEvent, INFINITE);
}

void PipeConnection::sendLightOut() {
	Message* lightOutMessage = new Message();
	WriteFile(hPipe, lightOutMessage, sizeof(Message), NULL, &overlap);
	WaitForSingleObject(overlap.hEvent, INFINITE);
}