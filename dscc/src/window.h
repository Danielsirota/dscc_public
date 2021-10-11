#pragma once
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <functional>
#include "Events/Event.h"
#include "OpenGl/OGLGraphicsContext.h"

class Window
{
	using callbackFunc = std::function<void(Event &)>;

public:
	Window(int width, int height, const char *name, callbackFunc func);

	bool init();
	void repaint();

	GLFWwindow *win;
	Graphics_Context *gc;
	int Height;
	int Width;
	const char *Name;
	callbackFunc Func;
};
