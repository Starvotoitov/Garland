#pragma once

#include "../MessageDLL/RGBColor.h"

class AbstractColorGenerator {
public:
	virtual RGBColor* generateColor() = 0;
};