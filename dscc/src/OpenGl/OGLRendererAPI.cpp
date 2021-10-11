#include "OGLRendererAPI.h"
#include <iostream>

void OGLRendererAPI::draw(int pointsNum)
{
	glPointSize(6);
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDrawElements(GL_TRIANGLES, pointsNum, GL_UNSIGNED_INT, 0);
};

VertexBuffer *OGLRendererAPI::MakeVertexBuffer(float vertices[], int size)
{

	return new OGLVertexBuffer(vertices, size);
};

IndexBuffer *OGLRendererAPI::MakeIndexBuffer(int indices[], int size)
{

	return new OGLIndexBuffer(indices, size);
};

FrameBuffer *OGLRendererAPI::MakeFrameBuffer(const FrameBufferSpec fbs)
{

	return new OGLFrameBuffer(fbs);
};

VertexArray *OGLRendererAPI::MakeVertexArray()
{
	return new OGLVertexArray();
}
