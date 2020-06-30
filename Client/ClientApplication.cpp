#include "ClientApplication.h"

ClientApplication::ClientApplication(HINSTANCE hInstance):
	window(hInstance), connection(this)
{
}

void ClientApplication::onLightUp(RGBColor* newColor) {
	window.lightUp(newColor);
}

void ClientApplication::onLightOut() {
	window.lightOut();
}

void ClientApplication::onError() {
	window.handleErrorMessage();
}

void ClientApplication::onConnectionClose() {
	window.handleConnectionCloseMessage();
}