#pragma once

#include "AbstractConnection.h"
#include <Windows.h>

class PipeConnection : public AbstractConnection {
public:
	PipeConnection();
	virtual bool createConnection();
	virtual void closeConnection();
	virtual Message* getMessage();
private:
	static const TCHAR* PIPE_NAME;
	HANDLE hPipe;
};