#include "OGLShader.h"

OGLShader::OGLShader()
{
	const char *vertexShaderSource2 = "#version 330 core\n"
									  "layout (location = 0) in vec3 aPos;\n"
									  "layout (location = 1) in vec3 aNormal;\n"
									  "uniform mat4 projection;\n"
									  "uniform mat4 model;\n"
									  "uniform mat4 view;\n"

									  "out vec3 normal;\n"
									  "void main()\n"
									  "{\n"
									  "   gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
									  "	normal = aNormal;\n"
									  "}\0";

	const char *vertexShaderSource = "#version 330 core\n"
									 "layout (location = 0) in vec3 aPos;\n"
									 "layout (location = 1) in vec3 aNormal;\n"
									 "uniform mat4 model;\n"
									 "uniform mat4 view;\n"

									 "out VS_OUT{\n"
									 "	vec3 normal;\n"
									 "} vs_out;\n"
									 "void main()\n"
									 "{\n"
									 "   gl_Position = view * model * vec4(aPos, 1.0);\n"
									 "	mat3 normalMatrix = mat3(transpose(inverse(view * model)));\n"
									 "	vs_out.normal = normalize(vec3(vec4(normalMatrix * aNormal, 0.0)));\n"
									 "}\0";

	const char *geometryShaderSource = "#version 330 core\n"
									   "layout (triangles) in;\n"
									   "layout (points, max_vertices = 6) out;\n"
									   "in VS_OUT{\n"
									   "	vec3 normal;\n"
									   "} gs_in[];\n"

									   "const float MAGNITUDE = 6; \n"
									   "uniform mat4 projection;\n"
									   "void GenerateLine(int index)\n"
									   "{\n"
									   "	gl_Position = projection * gl_in[index].gl_Position;\n"
									   "	EmitVertex();\n"
									   "	gl_Position = projection * (gl_in[index].gl_Position + vec4(gs_in[index].normal, 0.0) * MAGNITUDE);\n"
									   "	EmitVertex();\n"
									   "	EndPrimitive();\n"
									   "}\n"

									   "void main()\n"
									   "{\n"
									   "	GenerateLine(0);\n"
									   "	GenerateLine(1);\n"
									   "	GenerateLine(2);\n"
									   "}\n\0";

	const char *fragmentShaderSource = "#version 330 core\n"
									   "out vec4 FragColor;\n"
									   "uniform vec4 color;"
									   "void main()\n"
									   "{\n"
									   "   FragColor = color;\n"
									   "	//FragColor = vec4(1.0f, 1.5f, 0.2f, 1.0f); \n"
									   "	//FragColor = vec4(normal, 1.0f); \n"
									   "}\n\0";

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource2, NULL);
	glCompileShader(vertexShader);
	checkCompileErrors(vertexShader, "VERTEX");

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	checkCompileErrors(fragmentShader, "FRAGMENT");

	geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
	glShaderSource(geometryShader, 1, &geometryShaderSource, NULL);
	glCompileShader(geometryShader);
	checkCompileErrors(geometryShader, "GEOMETRY");

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteShader(geometryShader);
}

void OGLShader::Bind()
{
	glUseProgram(shaderProgram);
}

void OGLShader::UnBind()
{
	glUseProgram(0);
}

void OGLShader::updateUniformMat4(const std::string &name, const glm::mat4 &mat)
{
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void OGLShader::updateUniformVec4(const std::string &name, const glm::vec4 &vec)
{
	glUniform4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, &vec[0]);
}