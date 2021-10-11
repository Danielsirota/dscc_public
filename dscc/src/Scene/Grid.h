#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Core.h"
#include "..\OpenGl\OGLShader.h"

class Grid
{
public:
	Grid(){};
	void render()
	{
		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		OGLShader s = OGLShader();

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = Scene::currentCam->view;
		glm::mat4 projection = Scene::currentCam->projection;
		s.Bind();
		s.updateUniformMat4("model", model);
		s.updateUniformMat4("view", view);
		s.updateUniformMat4("projection", projection);
		s.updateUniformVec4("color", glm::vec4(1.0f, 1.5f, 0.2f, 1.0f));

		std::vector<float> verticesz;

		verticesz.clear();
		for (float i = -5; i <= 5; i++)
		{
			verticesz.push_back(i);
			verticesz.push_back(0.0f);
			verticesz.push_back(5.0f);
			verticesz.push_back(i);
			verticesz.push_back(0.0f);
			verticesz.push_back(-5.0f);
			unsigned int VAO2;
			unsigned int VBO2;
			glGenVertexArrays(1, &VAO2);
			glGenBuffers(1, &VBO2);

			glBindVertexArray(VAO2);

			glBindBuffer(GL_ARRAY_BUFFER, VBO2);
			glBufferData(GL_ARRAY_BUFFER, verticesz.size() * sizeof(float), &verticesz.front(), GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
			glEnableVertexAttribArray(0);
			glDrawArrays(GL_LINES, 0, verticesz.size());
			glBindVertexArray(0);
		}
		verticesz.clear();
		for (float i = -5; i <= 5; i++)
		{
			verticesz.push_back(-5.0f);
			verticesz.push_back(0.0f);
			verticesz.push_back(i);
			verticesz.push_back(5.0f);
			verticesz.push_back(0.0f);
			verticesz.push_back(i);
			unsigned int VAO2;
			unsigned int VBO2;
			unsigned int EBO2;
			glGenVertexArrays(1, &VAO2);
			glGenBuffers(1, &VBO2);

			glBindVertexArray(VAO2);

			glBindBuffer(GL_ARRAY_BUFFER, VBO2);
			glBufferData(GL_ARRAY_BUFFER, verticesz.size() * sizeof(float), &verticesz.front(), GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
			glEnableVertexAttribArray(0);
			glDrawArrays(GL_LINES, 0, verticesz.size());
			glBindVertexArray(0);
		}
		verticesz.clear();
		s.UnBind();
	}
};
