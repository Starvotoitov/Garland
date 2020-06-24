#pragma once

#include "../Service/RGBColor.h"
#include <Windows.h>

class AbstractLightBulb {
public:
	virtual void draw(HWND hWnd, int x, int y, int width, int height, RGBColor* color) = 0;
};