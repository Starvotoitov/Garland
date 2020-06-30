#pragma once

#include "RGBColor.h"
#include <variant>
#include <Windows.h>

#ifdef DLL_EXPORT
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif // DLL_EXPORT

enum MessageType {lightUp, lightOut, sendEvent};

using namespace std;
struct DLL Message {
	Message();
	Message(RGBColor* newColor);

	MessageType type;
	variant<monostate, RGBColor> messageData;
};