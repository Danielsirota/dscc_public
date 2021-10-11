#pragma once
#include "Layer.h"

#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usd/primRange.h>
#include <pxr/usd/usdGeom/modelAPI.h>
#include <pxr/usd/usdGeom/sphere.h>
#include "pxr/base/tf/debug.h"
#include "Scene/Scene.h"
class SceneRenderLayer : public Layer
{
public:
	SceneRenderLayer(const std::string &n, Scene *scene) : Layer(n), scene(scene){};

	bool onEvent(Event &e) override;
	void onIMGUIRender() override;
	void onUpdate() override;
	void onAttach() override;
	void onDetach() override;
	void search(pxr::UsdPrimSiblingRange, int depth);
	OGLShader s;
	Scene *scene;
	VertexArray *vao;
	VertexBuffer *ovb;
	IndexBuffer *oib;
	unsigned int VAO;
	float vertices[24] = {
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,

		0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, -1.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, -1.0f};
	unsigned int indices[12] = {
		0, 1, 3,
		1, 2, 3,
		4, 5, 6,
		5, 6, 7};
	float vertices2[24] = {
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,

		0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, -1.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, -1.0f};
	int indices2[6] = {

		0, 1, 21,
		0, 21, 20};

	void gnear();
	pxr::VtVec3fArray points;
	pxr::VtIntArray indices1;
	pxr::VtIntArray fvc;
	std::vector<int> ind;
	std::vector<float> ak;
	std::vector<glm::vec3> normals;
	std::vector<float> normals2;
};
