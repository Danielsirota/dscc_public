#pragma once
#include "RendererAPI.h"
#include "Buffer.h"
#include "FrameBuffer.h"
#include "VertexArray.h"

class RenderCommand
{
public:
	/// ADD SHADER BIND

	static void Init(RenderAPI *renApi)
	{
		rapi = renApi;
	}
	static void Draw(int pointsNum)
	{
		rapi->draw(pointsNum);
	}
	static VertexBuffer *MakeVertexBuffer(float vertices[], int size)
	{
		return rapi->MakeVertexBuffer(vertices, size);
	}

	static IndexBuffer *MakeIndexBuffer(int indices[], int size)
	{
		return rapi->MakeIndexBuffer(indices, size);
	}
	static FrameBuffer *MakeFrameBuffer(const FrameBufferSpec fbs)
	{
		return rapi->MakeFrameBuffer(fbs);
	}
	static VertexArray *MakeVertexArray()
	{
		return rapi->MakeVertexArray();
	}
	static void MakeSceneRender(const FrameBufferSpec fbs)
	{
		SceneRender = MakeFrameBuffer(fbs);
	}

	static FrameBuffer *GetSceneRender()
	{
		return SceneRender;
	}

private:
	static RenderAPI *rapi;
	static FrameBuffer *SceneRender;
};
