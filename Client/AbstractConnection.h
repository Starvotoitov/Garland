#pragma once

#include "../MessageDLL/Message.h"

class AbstractConnection {
public:
	virtual bool createConnection() = 0;
	virtual void closeConnection() = 0;
	virtual Message* getMessage() = 0;
};