#pragma once
#include "../Renderer/Graphics_Context.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class OGLGraphicsContext : public Graphics_Context
{
public:
	OGLGraphicsContext(GLFWwindow *window) : win(window){};

	void init() override;
	void SwapBuffers() override;

	GLFWwindow *win;
};
