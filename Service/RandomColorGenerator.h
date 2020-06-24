#pragma once

#include "AbstractColorGenerator.h"
#include <vector>

using namespace std;

class RandomColorGenerator : public AbstractColorGenerator {
public:
	virtual RGBColor* generateColor();
private:
	static const BYTE MAX_BYTE_VALUE = 255;

	BYTE getRandomByte();
};