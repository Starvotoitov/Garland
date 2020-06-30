#pragma once

#include "AbstractServer.h"
#include "ColorGenerator.h"
#include <thread>
#include <mutex>

using namespace std;

class Garland {
public:
	Garland();
	void start();
	void interrupt();
private:
	static const DWORD TIMEOUT;
	AbstractServer* server;
	ColorGenerator* generator;
	mutex serverMutex;
	bool isRunning;
	void garlandLogic();
};