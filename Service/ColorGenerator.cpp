#include "ColorGenerator.h"

ColorGenerator::ColorGenerator(AbstractColorGenerator *newGenerator) :
	currentGenerator(newGenerator)
{
}

ColorGenerator::~ColorGenerator() {
	delete currentGenerator;
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