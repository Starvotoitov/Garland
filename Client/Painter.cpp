#include "Painter.h"
#include <gdiplus.h>

using namespace Gdiplus;

bool Painter::isInitialized = false;
ULONG_PTR Painter::gdiToken = 0;

Painter::Painter(AbstractLightBulb* lightBulb) :
	lightBulbPainter(lightBulb)
{
}

void Painter::setLightBulb(AbstractLightBulb* lightBulb) {
	lightBulbPainter = lightBulb;
}

void Painter::draw(HWND hWnd, int x, int y, int width, int height, RGBColor* color) {
	lightBulbPainter->draw(hWnd, x, y, width, height, color);
}

void Painter::initializePainter() {
	if (!isInitialized) {
		GdiplusStartupInput gdiplusStartupInput;
		GdiplusStartup(&gdiToken, &gdiplusStartupInput, nullptr);
		isInitialized = true;
	}
}

void Painter::deinitializePainter() {
	if (isInitialized) {
		GdiplusShutdown(gdiToken);
		isInitialized = false;
	}
}