#pragma once
#include <glad/glad.h>
#include <GLFW\glfw3.h>
#include "../Core.h"
#include "../Renderer/VertexArray.h"
#include "OGLBuffer.h"

class OGLVertexArray : public VertexArray
{
public:
	OGLVertexArray();
	OGLVertexArray(unsigned int v);
	void Bind() override;
	void UnBind() override;
	void addVertexBuffer(VertexBuffer *vbo) override;
	void addIndexBuffer(IndexBuffer *ibo) override;
};
