#pragma once
#include "../Core.h"

struct FrameBufferSpec
{
	uint32_t Width, Height;
	uint32_t Samples = 1;
};

class FrameBuffer
{
public:
	FrameBuffer(const FrameBufferSpec fbs);
	const FrameBufferSpec fbspec;
	uint32_t texColorBuffer;
	virtual void Bind() = 0;
	virtual void UnBind() = 0;
};
