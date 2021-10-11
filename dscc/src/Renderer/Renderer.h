#pragma once

#include "RenderCommand.h"
#include "..\OpenGl\OGLShader.h"

class Renderer
{
public:
	Renderer(std::string name);
	void init();

	static void render(OGLShader s, VertexArray *vao, int pointsNum);

	static std::string name;
};
