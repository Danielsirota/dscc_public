#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "..\Core.h"

class Camera
{
public:
	Camera() = default;
	Camera(float x, float y, float z);

	glm::vec3 pos;
	glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 target;
	glm::vec3 direction;
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1200.0f / 800.0f, 0.1f, 100000.0f);
	float radius = 20.0f;
	glm::vec2 rot = glm::vec2(90.0f, 0.0f);

	void setAspectRatio(float aspectX, float aspectY);

	void rotate(float valuex, float valuey);
	void zoom(float value);
	void dolly(float valuex, float valuey);
	void frame(float valuex, float valuey, float valuez);
};
