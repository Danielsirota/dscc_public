#include "OGLGraphicsContext.h"

void OGLGraphicsContext::init() {

	glfwMakeContextCurrent(win);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glEnable(GL_DEPTH_TEST);
};
void OGLGraphicsContext::SwapBuffers() {
	glfwSwapBuffers(win);
};