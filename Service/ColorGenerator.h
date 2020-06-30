#pragma once

#include "AbstractColorGenerator.h"

class ColorGenerator {
public:
	ColorGenerator(AbstractColorGenerator *newGenerator);
	~ColorGenerator();
	void setGenerator(AbstractColorGenerator *newGenerator);
	RGBColor* generateColor();
private:
	AbstractColorGenerator* currentGenerator;
};