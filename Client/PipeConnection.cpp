#include "PipeConnection.h"

const TCHAR* PipeConnection::PIPE_NAME = TEXT("\\\\.\\pipe\\GarlandPipe");

PipeConnection::PipeConnection() :
	hPipe(INVALID_HANDLE_VALUE)
{
}

bool PipeConnection::createConnection() {
	HANDLE hNewPipe = CreateFile(PIPE_NAME, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hNewPipe == INVALID_HANDLE_VALUE) {
		return false;
	}
	hPipe = hNewPipe;

	DWORD newMode = PIPE_READMODE_MESSAGE;
	if (SetNamedPipeHandleState(hNewPipe, &newMode, NULL, NULL)) {
		CloseHandle(hNewPipe);
		return false;
	}

	return true;
}

Message* PipeConnection::getMessage() {
	LPVOID buffer = calloc(1, sizeof(Message));
	if (ReadFile(hPipe, buffer, sizeof(Message), NULL, NULL)) {
		return reinterpret_cast<Message*>(buffer);
	} else {
		return nullptr;
	}
}

void PipeConnection::closeConnection() {
	if (hPipe != INVALID_HANDLE_VALUE) {
		CloseHandle(hPipe);
		hPipe = INVALID_HANDLE_VALUE;
	}
}