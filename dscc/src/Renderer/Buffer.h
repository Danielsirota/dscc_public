#pragma once

class VertexBuffer
{
public:
	VertexBuffer(){};
	virtual void Bind() = 0;
	virtual void UnBind() = 0;
};

class IndexBuffer
{
public:
	IndexBuffer(){};
	virtual void Bind() = 0;
	virtual void UnBind() = 0;
};