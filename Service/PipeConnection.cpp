#include "PipeConnection.h"
#include "../MessageDLL/Message.h"

PipeConnection::PipeConnection(HANDLE hPipe, OVERLAPPED overlap) :
	hPipe(hPipe), overlap(overlap)
{
}

PipeConnection::~PipeConnection() {
	DisconnectNamedPipe(hPipe);
	CloseHandle(hPipe);
	CloseHandle(overlap.hEvent);
}

bool PipeConnection::sendLightUp(RGBColor* newColor) {
	Message* lightUpMessage = new Message(newColor);
	SetLastError(0);
	WriteFile(hPipe, lightUpMessage, sizeof(Message), NULL, &overlap);
	if (GetLastError() == 0) {
		WaitForSingleObject(overlap.hEvent, INFINITE);
    	return false;
	} else {
		return GetLastError() == ERROR_NO_DATA;
	}
}

bool PipeConnection::sendLightOut() {
	Message* lightOutMessage = new Message();
	SetLastError(0);
	WriteFile(hPipe, lightOutMessage, sizeof(Message), NULL, &overlap);
	if (GetLastError() == 0) {
		WaitForSingleObject(overlap.hEvent, INFINITE);
		return false;
	} else {
		return GetLastError() == ERROR_NO_DATA;
	}
}