#pragma once
#include "Buffer.h"
#include "FrameBuffer.h"
#include "VertexArray.h"
class RenderAPI
{
public:
	RenderAPI(){};

	virtual void draw(int pointsNum) = 0;
	virtual VertexBuffer *MakeVertexBuffer(float vertices[], int size) = 0;
	virtual IndexBuffer *MakeIndexBuffer(int indices[], int size) = 0;
	virtual FrameBuffer *MakeFrameBuffer(const FrameBufferSpec fbs) = 0;
	virtual VertexArray *MakeVertexArray() = 0;
};