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
	printf("Start Interrupt\n");
	isRunning = false;
	server->interrupt();
	unique_lock<mutex> lock(serverMutex);
	while (!server->isEmpty()) {
		server->chooseNextUser();
		server->closeCurrentConnection();
	}
	printf("End Interrupt\n");
}

void Garland::garlandLogic()
{
	printf("Start Logic\n");
	while (isRunning) {
		server->waitForClient();
		while (!server->isEmpty()) {
			RGBColor* newColor = generator->generateColor();
			printf("%d %d %d\n", newColor->red, newColor->green, newColor->blue);

			Sleep(TIMEOUT);
			bool isClosed = false;
			do {
				printf("Send lightUp\n");
				server->chooseNextUser();
			//	server->sendLightUp(newColor);
				isClosed = server->sendLightUp(newColor);
			} while (isClosed);

			delete newColor;

			Sleep(TIMEOUT);
			printf("Send lightOut\n");
			server->sendLightOut();
		}
	}
	printf("End Logic\n");
}