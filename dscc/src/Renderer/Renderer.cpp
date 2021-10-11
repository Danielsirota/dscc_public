#include "Renderer.h"

std::string Renderer::name;

Renderer::Renderer(std::string n)
{
	name = n;
	init();
};

void Renderer::init()
{
}
void Renderer::render(OGLShader s, VertexArray *vao, int pointsNum)
{

	s.Bind();
	vao->Bind();

	RenderCommand::Draw(pointsNum);
}
