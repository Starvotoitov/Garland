#pragma once

#include "Painter.h"
#include "../Service/RGBColor.h"
#include <Windows.h>

class MainWindow {
public:
	MainWindow(HINSTANCE hInstance);
	MainWindow(HINSTANCE hInstance, TCHAR* windowName, int x, int y, int width, int height, int minWidth, int minHeight, int maxWidth, int maxHeight);
	void lightUp(RGBColor* newColor);
	void lightOut();
	void showError(const TCHAR* message);
	void showInfo(const TCHAR* message);
private:
	static bool isRegistered;
	static const int DEFAULT_MIN_WIDTH;
	static const int DEFAULT_MIN_HEIGHT;
	static const int DEFAULT_MAX_WIDTH;
	static const int DEFAULT_MAX_HEIGHT;
	static const TCHAR* DEFAULT_WINDOW_NAME;
	static const int DEFAULT_X;
	static const int DEFAULT_Y;
	static const int DEFAULT_WIDTH;
	static const int DEFAULT_HEIGHT;
	static const TCHAR* WINDOW_CLASS_NAME;

	HWND hWnd;
	int minWidth;
	int minHeight;
	int maxWidth;
	int maxHeight;
	RGBColor* currentColor;
	Painter painter;
	void setHWND(HWND hWnd);
	void registerWindowClass(HINSTANCE hInstance);
	void onPaint(HWND hWnd);
	static LRESULT CALLBACK windowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};