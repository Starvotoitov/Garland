#include "MainWindow.h"
#include "AbstractLightBulb.h"
#include "RoundLightBulb.h"

bool MainWindow::isRegistered = false;
const int MainWindow::DEFAULT_MIN_WIDTH = 300;
const int MainWindow::DEFAULT_MIN_HEIGHT = 300;
const int MainWindow::DEFAULT_MAX_WIDTH = 500;
const int MainWindow::DEFAULT_MAX_HEIGHT = 500;
const TCHAR* MainWindow::DEFAULT_WINDOW_NAME = TEXT("New Window");
const int MainWindow::DEFAULT_X = 0;
const int MainWindow::DEFAULT_Y = 0;
const int MainWindow::DEFAULT_WIDTH = MainWindow::DEFAULT_MIN_WIDTH;
const int MainWindow::DEFAULT_HEIGHT = MainWindow::DEFAULT_MIN_HEIGHT;
const TCHAR* MainWindow::WINDOW_CLASS_NAME = TEXT("GarlandWindowClass");

MainWindow::MainWindow(HINSTANCE hInstance):
	minWidth(DEFAULT_MIN_WIDTH), minHeight(DEFAULT_MIN_HEIGHT), maxWidth(DEFAULT_MAX_WIDTH), 
	maxHeight(DEFAULT_MAX_HEIGHT), painter(Painter(new RoundLightBulb())), currentColor(nullptr), hWnd(reinterpret_cast<HWND>(INVALID_HANDLE_VALUE)) {
	if (!MainWindow::isRegistered) {
		registerWindowClass(hInstance);
	}

	CreateWindow(WINDOW_CLASS_NAME, DEFAULT_WINDOW_NAME, WS_VISIBLE | WS_OVERLAPPEDWINDOW, DEFAULT_X, DEFAULT_Y,
		DEFAULT_WIDTH, DEFAULT_HEIGHT, NULL, NULL, hInstance, this);
}

MainWindow::MainWindow(HINSTANCE hInstance, TCHAR* windowName, int x, int y, int width, int height,
	int minWidth, int minHeight, int maxWidth, int maxHeight): painter(Painter(new RoundLightBulb())), 
	currentColor(nullptr), hWnd(reinterpret_cast<HWND>(INVALID_HANDLE_VALUE)) {

	this->minWidth = (minWidth <= 0 || minWidth > maxWidth) ? DEFAULT_MIN_WIDTH : minWidth;
	this->minHeight = (minHeight <= 0 || minHeight > maxHeight) ? DEFAULT_MIN_HEIGHT : minHeight;
	this->maxWidth = (maxWidth <= 0 || maxWidth < minWidth) ? DEFAULT_MAX_WIDTH : maxWidth;
	this->maxHeight = (maxHeight <= 0 || maxHeight < minHeight) ? DEFAULT_MAX_HEIGHT : maxHeight;
	const int windowX = (x < 0) ? DEFAULT_X : x;
	const int windowY = (y < 0) ? DEFAULT_Y : y;
	const int windowWidth = (width < this->minWidth || width > this->maxWidth) ? this->minWidth : width;
	const int windowHeight = (height < this->minHeight || height > this->maxHeight) ? this->minHeight : height;
	const TCHAR* newName = (windowName == nullptr) ? DEFAULT_WINDOW_NAME : windowName;

	if (!MainWindow::isRegistered) {
		registerWindowClass(hInstance);
	}

	CreateWindow(WINDOW_CLASS_NAME, newName, WS_VISIBLE | WS_OVERLAPPEDWINDOW, windowX, windowY,
		windowWidth, windowHeight, NULL, NULL, hInstance, this);
}

void MainWindow::lightUp(RGBColor* newColor) {
	currentColor = newColor;
	RECT windowRect;
	GetClientRect(hWnd, &windowRect);
	InvalidateRect(hWnd, &windowRect, true);
}

void MainWindow::lightOut() {
	currentColor = nullptr;
	RECT windowRect;
	GetClientRect(hWnd, &windowRect);
	InvalidateRect(hWnd, &windowRect, true);
}

void MainWindow::showError(const TCHAR* message) {
	MessageBox(hWnd, message, TEXT("Error"), MB_OK | MB_ICONERROR);
}

void MainWindow::showInfo(const TCHAR* message) {
	MessageBox(hWnd, message, TEXT("Information"), MB_OK | MB_ICONINFORMATION);
}

void MainWindow::registerWindowClass(HINSTANCE hInstance) {
	WNDCLASS windowClass;
	windowClass.style = CS_GLOBALCLASS;
	windowClass.lpfnWndProc = windowProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = sizeof(MainWindow*);
	windowClass.hInstance = hInstance;
	windowClass.hIcon = NULL;
	windowClass.hCursor = NULL;
	windowClass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = WINDOW_CLASS_NAME;
	RegisterClass(&windowClass);
	isRegistered = true;
}

void MainWindow::setHWND(HWND hWnd) {
	this->hWnd = hWnd;
}

void MainWindow::onPaint(HWND hWnd) {
	RECT windowRect;
	GetClientRect(hWnd, &windowRect);
	if (currentColor != nullptr) {
		painter.draw(hWnd, windowRect.left, windowRect.top, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, currentColor);
	}
}

LRESULT CALLBACK MainWindow::windowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	MainWindow* windowInfo = nullptr;
	switch (uMsg) {
	case WM_CREATE: {
		CREATESTRUCT* createInfo = reinterpret_cast<CREATESTRUCT*>(lParam);
		MainWindow* window = reinterpret_cast<MainWindow*>(createInfo->lpCreateParams);
		window->setHWND(hWnd);
		SetWindowLongPtr(hWnd, 0, reinterpret_cast<LONG>(window));
		Painter::initializePainter();
		break;
	}
	case WM_GETMINMAXINFO: {
		windowInfo = reinterpret_cast<MainWindow*>(GetWindowLongPtr(hWnd, 0));
		if (windowInfo != nullptr)
		{
			MINMAXINFO* minMaxInfo = reinterpret_cast<MINMAXINFO*>(lParam);
			minMaxInfo->ptMinTrackSize.x = windowInfo->minWidth;
			minMaxInfo->ptMinTrackSize.y = windowInfo->minHeight;
			minMaxInfo->ptMaxTrackSize.x = windowInfo->maxWidth;
			minMaxInfo->ptMaxTrackSize.y = windowInfo->maxHeight;
		}
		break;
	}
	case WM_PAINT: {
		windowInfo = reinterpret_cast<MainWindow*>(GetWindowLongPtr(hWnd, 0));
		windowInfo->onPaint(hWnd);
		break;
	}
	case WM_SIZE: {
		RECT windowRect;
		GetClientRect(hWnd, &windowRect);
 		InvalidateRect(hWnd, &windowRect, true);
		break;
	}
	case WM_DESTROY: {
		Painter::deinitializePainter();
		PostQuitMessage(0);
		break;
	}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}