#pragma once
#include <glad/glad.h>
#include <GLFW\glfw3.h>
#include "../Renderer/Buffer.h"

class OGLVertexBuffer : public VertexBuffer
{
public:
	OGLVertexBuffer(){};
	OGLVertexBuffer(float vertices[], int size);
	~OGLVertexBuffer(){};

	float *vertexArray;
	int size;
	uint32_t vbo;

	void Bind() override;
	void UnBind() override;
};

class OGLIndexBuffer : public IndexBuffer
{
public:
	OGLIndexBuffer(){};
	OGLIndexBuffer(int indices[], int size);
	~OGLIndexBuffer(){};

	unsigned int *indexArray;
	uint32_t ibo;

	void Bind() override;
	void UnBind() override;
};
