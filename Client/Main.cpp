#include "ClientApplication.h"
#include <Windows.h>

INT WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, INT nCmdShow) {
	ClientApplication app(hInstance);
	MSG message;
	while (GetMessage(&message, 0, 0, 0))
	{
		DispatchMessage(&message);
	}
	return 0;
}