#include "Camera.h"

Camera::Camera(float x, float y, float z)
{

	pos = glm::vec3(x, y, z);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	target = glm::vec3(0.0f, 0.0f, 0.0f);
	direction = glm::normalize(pos - target);
	right = glm::normalize(glm::cross(up, direction));
	up = glm::cross(direction, right);
	view = glm::lookAt(pos, pos + glm::vec3(0.0f, 0.0f, -1.0f), up);
	radius = 20;
	center = glm::vec3(0.0f, 0.0f, 0.0f);
	rotate(-30, 20);
}

void Camera::rotate(float valuex, float valuey)
{
	if (rot.y >= 360)
	{
		rot.y = 0;
	}
	if (rot.y <= -360)
	{
		rot.y = 0;
	}
	rot.x += valuex;
	rot.y += valuey;
	pos = {
		center.x + radius * glm::cos(glm::radians(rot.x)) * glm::cos(glm::radians(rot.y)),
		center.y + radius * glm::sin(glm::radians(rot.y)),
		center.z + radius * glm::sin(glm::radians(rot.x)) * glm::cos(glm::radians(rot.y))};
	if ((rot.y >= 90 && rot.y <= 270) || (rot.y <= -90 && rot.y >= -270))
	{
		view = glm::lookAt(pos, center, glm::vec3(0.0f, -1.0f, 0.0f));
	}
	else
	{
		view = glm::lookAt(pos, center, glm::vec3(0.0f, 1.0f, 0.0f));
	}
};

void Camera::zoom(float value)
{
	radius += value;

	pos = {
		center.x + radius * glm::cos(glm::radians(rot.x)) * glm::cos(glm::radians(rot.y)),
		center.y + radius * glm::sin(glm::radians(rot.y)),
		center.z + radius * glm::sin(glm::radians(rot.x)) * glm::cos(glm::radians(rot.y))};

	if (radius < 0)
	{
		radius = 0.2;
	}
	else
	{
		view = glm::lookAt(pos, center, glm::vec3(0.0f, 1.0f, 0.0f));
	}
};

void Camera::dolly(float valuex, float valuey)
{
	direction = glm::normalize(center - pos);
	right = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), direction));
	center = center + (right * -valuex);

	direction = glm::normalize(center - pos);
	right = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), direction));
	up = glm::normalize(glm::cross(right, direction));
	center = center + (up * valuey);
	pos = {
		center.x + radius * glm::cos(glm::radians(rot.x)) * glm::cos(glm::radians(rot.y)),
		center.y + radius * glm::sin(glm::radians(rot.y)),
		center.z + radius * glm::sin(glm::radians(rot.x)) * glm::cos(glm::radians(rot.y))};
	view = glm::lookAt(pos, center, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::frame(float valuex, float valuey, float valuez)
{

	center = glm::vec3(-valuex, -valuey, valuez);

	pos = {
		center.x + radius * glm::cos(glm::radians(rot.x)) * glm::cos(glm::radians(rot.y)),
		center.y + radius * glm::sin(glm::radians(rot.y)),
		center.z + radius * glm::sin(glm::radians(rot.x)) * glm::cos(glm::radians(rot.y))};
	view = glm::lookAt(pos, center, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::setAspectRatio(float aspectX, float aspectY)
{
	projection = glm::perspective(glm::radians(45.0f), aspectX / aspectY, 0.1f, 100000.0f);
};
