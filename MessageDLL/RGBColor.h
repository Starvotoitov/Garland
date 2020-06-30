#pragma once

#include <Windows.h>

#ifdef DLL_EXPORT
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif // DLL_EXPORT

struct DLL RGBColor {
	BYTE red;
	BYTE green;
	BYTE blue;

	RGBColor(BYTE red, BYTE green, BYTE blue);
};