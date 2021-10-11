#include "window.h"
#include "Events/Events.h"
#include <iostream>
Window::Window(int width, int height, const char *name, callbackFunc func)
{
	Width = width;
	Height = height;
	Name = name;
	Func = func;
	init();
}

bool Window::init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 25);
	win = glfwCreateWindow(Width, Height, Name, NULL, NULL);

	OGLGraphicsContext *oglc = new OGLGraphicsContext(win);
	gc = oglc;
	gc->init();

	glfwSetWindowUserPointer(win, static_cast<void *>(this));

	glfwSetWindowCloseCallback(win, [](GLFWwindow *window)
							   {
								   windowCloseEvent event;
								   Window &self = *(Window *)(glfwGetWindowUserPointer(window));
								   self.Func(event);
							   });

	glfwSetMouseButtonCallback(win, [](GLFWwindow *window, int button, int action, int mods)
							   {
								   mouseButtonPressedEvent event(button);
								   Window &self = *(Window *)(glfwGetWindowUserPointer(window));
								   self.Func(event);
							   });

	glfwSetKeyCallback(win, [](GLFWwindow *window, int key, int scancode, int action, int mods)
					   {
						   Window &self = *(Window *)(glfwGetWindowUserPointer(window));
						   if (action == GLFW_PRESS)
						   {
							   keyButtonPressedEvent event(key);
							   self.Func(event);
						   }
						   else if (action == GLFW_RELEASE)
						   {
							   //ADD TO HERE
							   int p = 0;
						   }
					   });

	glfwSetCursorPosCallback(win, [](GLFWwindow *window, double xpos, double ypos)
							 {
								 Window &self = *(Window *)(glfwGetWindowUserPointer(window));
								 mouseMovedEvent event(xpos, ypos);
								 self.Func(event);
							 });

	return true;
}

void Window::repaint()
{

	gc->SwapBuffers();
	glfwPollEvents();
}
