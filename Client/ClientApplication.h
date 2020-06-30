#pragma once

#include "ConnectionSubscriber.h"
#include "MainWindow.h"
#include "ClientConnection.h"
#include <Windows.h>

class ClientApplication : public ConnectionSubscriber {
public:
	ClientApplication(HINSTANCE hInstance);
	virtual void onLightUp(RGBColor* newColor);
	virtual void onLightOut();
	virtual void onError();
	virtual void onConnectionClose();
private:
	ClientConnection connection;
	MainWindow window;
};