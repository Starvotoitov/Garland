#include "Garland.h"
#include "PipeServer.h"

const DWORD Garland::TIMEOUT = 1000;

Garland::Garland():
	server(new PipeServer), generator(new ColorGenerator()), isRunning(true)
{
}

void Garland::start()
{
	thread listenThread(&AbstractServer::listen, server);
	thread garlandThread(&Garland::garlandLogic, this);
	listenThread.join();
	garlandThread.join();
}

void Garland::interrupt()
{
	server->interrupt();
}

void Garland::garlandLogic()
{
	while (isRunning) {
		server->waitForClient();
		while (!server->isEmpty()) {
			server->chooseNextUser();
			RGBColor* newColor = generator->generateColor();
			server->sendLightUp(newColor);
			delete newColor;
			Sleep(TIMEOUT);
			server->sendLightOut();
		}
	}
}