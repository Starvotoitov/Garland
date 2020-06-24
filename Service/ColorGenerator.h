#pragma once

#include "AbstractColorGenerator.h"

class ColorGenerator {
public:
	ColorGenerator();
	ColorGenerator(AbstractColorGenerator *newGenerator);
	void setGenerator(AbstractColorGenerator *newGenerator);
	RGBColor* generateColor();
private:
	AbstractColorGenerator* currentGenerator;
};