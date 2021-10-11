#include "OGLBuffer.h"
#include <iostream>
OGLVertexBuffer::OGLVertexBuffer(float vertices[], int size) : vertexArray(vertices), size(size)
{
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, vertices, GL_STATIC_DRAW);
}

void OGLVertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

void OGLVertexBuffer::UnBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

OGLIndexBuffer::OGLIndexBuffer(int indices[], int size)
{
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * size, indices, GL_STATIC_DRAW);
}

void OGLIndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
}

void OGLIndexBuffer::UnBind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
