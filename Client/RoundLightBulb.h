#pragma once

#include "AbstractLightBulb.h"

class RoundLightBulb : public AbstractLightBulb {
public:
	virtual void draw(HWND hWnd, int x, int y, int width, int height, RGBColor* color);
private:
	void recalculateCoord(int& x, int& y, int& width, int& height);
	void drawLightBulb(HDC hDc, int x, int y, int width, int height, RGBColor* color);
};