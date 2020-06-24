#pragma once

#include <Windows.h>

struct RGBColor {
	BYTE red;
	BYTE green;
	BYTE blue;

	RGBColor(BYTE red, BYTE green, BYTE blue);
};