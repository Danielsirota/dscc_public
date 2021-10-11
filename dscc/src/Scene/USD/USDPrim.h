#pragma once
#include "..\..\Core.h"
#include <pxr/usd/usd/prim.h>
#include <pxr/usd/usdGeom/modelAPI.h>
#include "../../Renderer/Renderer.h"
#include <pxr/base/vt/types.h>
#include <pxr/base/gf/matrix4f.h>
class USDPrim
{
public:
	USDPrim(pxr::UsdStageRefPtr stage, pxr::SdfPath path);
	~USDPrim();
	void Render();
	pxr::UsdPrim GetPrim();
	glm::mat4 GetTransform();

	pxr::UsdStageRefPtr stage;
	pxr::SdfPath path;
	std::string name;

	pxr::VtVec3fArray points1;
	pxr::VtVec3fArray Color;
	pxr::VtIntArray indices1;
	pxr::VtIntArray fvc;
	std::vector<int> ind;
	std::vector<float> ak;
	std::vector<glm::vec3> normals;
	std::vector<float> normals2;

	VertexArray *vao;
	VertexBuffer *ovb;
	IndexBuffer *oib;
	OGLShader *s;
};
