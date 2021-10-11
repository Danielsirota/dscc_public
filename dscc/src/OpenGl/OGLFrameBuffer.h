#pragma once
#include <glad/glad.h>
#include <GLFW\glfw3.h>
#include "../Renderer/FrameBuffer.h"

class OGLFrameBuffer : public FrameBuffer
{
public:
	OGLFrameBuffer(const FrameBufferSpec fbs);
	uint32_t fbo;
	uint32_t rbo;
	void Bind() override;
	void UnBind() override;
};
