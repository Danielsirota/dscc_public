#pragma once
class Shader
{
public:
	Shader(){};

	virtual void Bind() = 0;
	virtual void UnBind() = 0;
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;
	unsigned int geometryShader;
};
