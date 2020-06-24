#include "GarlandService.h"

SERVICE_STATUS GarlandService::serviceStatus;
SERVICE_STATUS_HANDLE GarlandService::hStatusHandle;
TCHAR* GarlandService::serviceName = nullptr;

void GarlandService::start(TCHAR* serviceName) {
	GarlandService::serviceName = serviceName;

	SERVICE_TABLE_ENTRY serviceTable[1];
	serviceTable[0].lpServiceName = serviceName;
	serviceTable[0].lpServiceProc = reinterpret_cast<LPSERVICE_MAIN_FUNCTION>(serviceMain);

	StartServiceCtrlDispatcher(serviceTable);
}

void GarlandService::serviceMain(int argc, TCHAR** argv) {
	serviceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	serviceStatus.dwCurrentState = SERVICE_START_PENDING;
	serviceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
	serviceStatus.dwWin32ExitCode = 0;
	serviceStatus.dwServiceSpecificExitCode = 0;
	serviceStatus.dwCheckPoint = 0;
	serviceStatus.dwWaitHint = 0;

	hStatusHandle = RegisterServiceCtrlHandler(serviceName, reinterpret_cast<LPHANDLER_FUNCTION>(serviceHandler));
	
	serviceStatus.dwCurrentState = SERVICE_RUNNING;
	SetServiceStatus(hStatusHandle, &serviceStatus);
}

void GarlandService::serviceHandler(DWORD request) {
	switch (request) {
	case SERVICE_CONTROL_STOP:
	case SERVICE_CONTROL_SHUTDOWN:
		serviceStatus.dwWin32ExitCode = 0;
		serviceStatus.dwCurrentState = SERVICE_STOPPED;
		SetServiceStatus(hStatusHandle, &serviceStatus);
		break;
	}
}