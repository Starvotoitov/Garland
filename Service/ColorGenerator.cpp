#include "ColorGenerator.h"

ColorGenerator::ColorGenerator():
	currentGenerator(nullptr) 
{
}

ColorGenerator::ColorGenerator(AbstractColorGenerator *newGenerator) :
	currentGenerator(newGenerator)
{
}

void ColorGenerator::setGenerator(AbstractColorGenerator* newGenerator) {
	if (newGenerator != nullptr) {
		currentGenerator = newGenerator;
	}
}

RGBColor* ColorGenerator::generateColor() {
	if (currentGenerator != nullptr) {
		return currentGenerator->generateColor();
	} else {
		return nullptr;
	}
}