#include "RandomColorGenerator.h"
#include <cstdlib>
#include <ctime>

RGBColor* RandomColorGenerator::generateColor() {
	srand(time(nullptr));
	return new RGBColor(getRandomByte(), getRandomByte(), getRandomByte());
}

BYTE RandomColorGenerator::getRandomByte() {
	return rand() % MAX_BYTE_VALUE;
}
