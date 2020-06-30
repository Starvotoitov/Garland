#include "Garland.h"
#include "PipeServer.h"
#include "RandomColorGenerator.h"

const DWORD Garland::TIMEOUT = 1000;

Garland::Garland():
	server(new PipeServer), generator(new ColorGenerator(new RandomColorGenerator())), isRunning(true)
{
}

void Garland::start()
{
	unique_lock<mutex> lock(serverMutex);
	thread listenThread(&AbstractServer::listen, server);
	thread garlandThread(&Garland::garlandLogic, this);
	listenThread.join();
	garlandThread.join();
}

void Garland::interrupt()
{
	isRunning = false;
	server->interrupt();
	unique_lock<mutex> lock(serverMutex);
	while (!server->isEmpty()) {
		server->chooseNextUser();
		server->closeCurrentConnection();
	}
}

void Garland::garlandLogic()
{
	server->waitForClient();
	while (isRunning) {
		RGBColor* newColor = generator->generateColor();

		Sleep(TIMEOUT);
		bool isClosed = false;
		do {
			server->chooseNextUser();
			isClosed = server->sendLightUp(newColor);
		} while (isClosed);

		delete newColor;

		Sleep(TIMEOUT);
		server->sendLightOut();
	}
}