#include "OGLVertexArray.h"
OGLVertexArray::OGLVertexArray()
{
	glGenVertexArrays(1, &vao);
}

OGLVertexArray::OGLVertexArray(unsigned int v)
{
	vao = v;
}

void OGLVertexArray::Bind()
{
	glBindVertexArray(vao);
}

void OGLVertexArray::UnBind()
{
	glBindVertexArray(0);
}

void OGLVertexArray::addVertexBuffer(VertexBuffer *vbo)
{
	Bind();
	vbo->Bind();
	vb.push_back(vbo);
	//glEnableVertexAttribArray(vao);
	glVertexAttribPointer(vb.size() - 1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
}

void OGLVertexArray::addIndexBuffer(IndexBuffer *ibo)
{
	Bind();
	ibo->Bind();
	ib = ibo;
}
