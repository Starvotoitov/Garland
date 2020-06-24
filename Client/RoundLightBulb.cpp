#include "RoundLightBulb.h"
#include <gdiplus.h>

#pragma comment(lib,"gdiplus.lib")

using namespace Gdiplus;

void RoundLightBulb::draw(HWND hWnd, int x, int y, int width, int height, RGBColor* color) {
	PAINTSTRUCT ps;
	recalculateCoord(x, y, width, height);
	HDC hDc = BeginPaint(hWnd, &ps);
	drawLightBulb(hDc, x, y, width, height, color);
	EndPaint(hWnd, &ps);
}

void RoundLightBulb::recalculateCoord(int& x, int& y, int& width, int& height) {
	if (width < height) {
		y += (height / 2) - (width / 2);
		height = width;
	} else {
		x += (width / 2) - (height / 2);
		width = height;
	}
}

void RoundLightBulb::drawLightBulb(HDC hDc, int x, int y, int width, int height, RGBColor* ellipseColor) {
	Graphics graphics(hDc);
	Brush* ellipseBrush = new SolidBrush(Color(ellipseColor->red, ellipseColor->green, ellipseColor->blue));
	graphics.Clear(Color(255, 255, 255));
	graphics.FillEllipse(ellipseBrush, x, y, width, height);
}