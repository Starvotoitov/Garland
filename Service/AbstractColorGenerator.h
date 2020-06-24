#pragma once

#include "RGBColor.h"

class AbstractColorGenerator {
public:
	virtual RGBColor* generateColor() = 0;
};