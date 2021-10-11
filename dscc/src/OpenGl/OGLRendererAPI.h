#pragma once
#include "../Renderer/RendererAPI.h"
#include "OGLFrameBuffer.h"
#include "OGLBuffer.h"
#include "OGLVertexArray.h"
#include <glad/glad.h>
#include <GLFW\glfw3.h>

class OGLRendererAPI : public RenderAPI
{
public:
	OGLRendererAPI() {};

	void draw(int pointsNum) override;
	VertexBuffer* MakeVertexBuffer(float vertices[], int size) override;
	IndexBuffer* MakeIndexBuffer( int indices[], int size) override;
	FrameBuffer* MakeFrameBuffer(const FrameBufferSpec fbs) override;
	VertexArray* MakeVertexArray() override;

};

