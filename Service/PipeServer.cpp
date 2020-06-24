#include "PipeServer.h"
#include "Message.h"
#include "PipeConnection.h"

const TCHAR* PipeServer::PIPE_NAME = TEXT("\\\\.\\pipe\\GarlandPipe");
const int PipeServer::TIMEOUT = 0;

PipeServer::PipeServer():
	isRunning(true)
{
}

void PipeServer::sendLightUp(RGBColor* newColor) {
	if (currentUser != nullptr) {
		currentUser->sendLightUp(newColor);
	}
}

void PipeServer::sendLightOut() {
	if (currentUser != nullptr) {
		currentUser->sendLightOut();
	}
}

void PipeServer::listen() {
	while (isRunning) {
		hPipeEvent = CreateEvent(NULL, true, false, NULL);
		if (hPipeEvent == NULL) {
			return;
		}

		OVERLAPPED overlap;
		overlap.Internal = 0;
		overlap.InternalHigh = 0;
		overlap.Offset = 0;
		overlap.OffsetHigh = 0;
		overlap.hEvent = hPipeEvent;

		HANDLE hPipe = CreateNamedPipe(PIPE_NAME, PIPE_ACCESS_OUTBOUND | FILE_FLAG_OVERLAPPED,
			PIPE_TYPE_MESSAGE | PIPE_WAIT, PIPE_UNLIMITED_INSTANCES, sizeof(Message), sizeof(Message), TIMEOUT, NULL);

		if (hPipe == INVALID_HANDLE_VALUE) {
			return;
		}

		ConnectNamedPipe(hPipe, &overlap);
		int connectionStatus = GetLastError();

		if (connectionStatus == ERROR_IO_PENDING || connectionStatus == ERROR_PIPE_CONNECTED) {
			WaitForSingleObject(overlap.hEvent, INFINITE);
			if (isRunning) {
				queue->enqueue(new PipeConnection(hPipe, overlap));
			}
		}
	}
}

void PipeServer::chooseNextUser() {
	currentUser = queue->getNext();
}

void PipeServer::waitForClient() {
	queue->waitForElement();
}

bool PipeServer::isEmpty() {
	return queue->isEmpty();
}

void PipeServer::interrupt() {
	isRunning = false;
	SetEvent(hPipeEvent);
}