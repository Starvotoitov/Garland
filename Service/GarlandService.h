#pragma once

#include <tchar.h>
#include <Windows.h>

class GarlandService {
public:
	static void start(TCHAR* serviceName);
private:
	static SERVICE_STATUS serviceStatus;
	static SERVICE_STATUS_HANDLE hStatusHandle;
	static TCHAR* serviceName;

	static void serviceMain(int argc, TCHAR** argv);
	static void serviceHandler(DWORD request);
};