#pragma once
//#include "KeyandMouseCodes.h"
#include <utility>

class Input
{
public:
	static bool isKeyPressed();
	static bool isMouseButtonPressed();
	static std::pair<float, float> getMousePos();
};
