#pragma once

class Graphics_Context
{
public:
	Graphics_Context() = default;

	virtual void init() = 0;
	virtual void SwapBuffers() = 0;
};