#pragma once
#include "Buffer.h"
class VertexArray
{
public:
	VertexArray(){};
	virtual void Bind() = 0;
	virtual void UnBind() = 0;
	virtual void addVertexBuffer(VertexBuffer *vbo) = 0;
	virtual void addIndexBuffer(IndexBuffer *ibo) = 0;
	unsigned int vao;
	std::vector<VertexBuffer *> vb;
	int VertexBufferSize;
	IndexBuffer *ib;
	int IndexBufferSize;
};