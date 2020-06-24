#pragma once

#include "AbstractServer.h"
#include "ColorGenerator.h"
#include <thread>

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
	bool isRunning;
	void garlandLogic();
};