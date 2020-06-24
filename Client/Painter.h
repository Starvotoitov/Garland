#pragma once

#include "AbstractLightBulb.h"

class Painter {
public:
	Painter(AbstractLightBulb* lightBulb);
	void setLightBulb(AbstractLightBulb* lightBulb);
	void draw(HWND hWnd, int x, int y, int width, int height, RGBColor* color);
	static void initializePainter();
	static void deinitializePainter();
private:
	static bool isInitialized;
	static ULONG_PTR gdiToken;
	AbstractLightBulb* lightBulbPainter;
};