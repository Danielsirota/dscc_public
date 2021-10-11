#include "USDPrim.h"
#include "../Scene.h"
#include <pxr/usd/usdGeom/mesh.h>
#include <pxr/usd/usdGeom/xformable.h>
#include <pxr\usd\usdGeom\xformCommonAPI.h>
#include <pxr\usd\usdGeom\xformOp.h>
#include <pxr/usd/sdf/types.h>

//REATE DISTRUCTOR
USDPrim::~USDPrim()
{
	delete s;
	s = nullptr;
};

USDPrim::USDPrim(pxr::UsdStageRefPtr stage, pxr::SdfPath path) : stage(stage), path(path)
{
	name = GetPrim().GetName();

	std::cout << "Buildin: " << GetPrim().GetPath() << "    " << GetPrim().GetTypeName() << std::endl;
	s = new OGLShader();
	s->Bind();
	auto prim = GetPrim();

	auto cd = prim.GetAttribute((pxr::TfToken("primvars:displayColor")));
	cd.Get(&Color);
	if (Color.empty())
	{
		s->updateUniformVec4("color", glm::vec4(243, 243, 243, 1));
	}
	else
	{
		for (auto i = Color.begin(); i != Color.end(); i++)
		{
			s->updateUniformVec4("color", glm::vec4(Color[0][0], Color[0][1], Color[0][2], 1));
		}
	}

	s->UnBind();
	auto points = prim.GetAttribute(pxr::TfToken("points"));
	points.Get(&points1);

	auto indicies = prim.GetAttribute(pxr::TfToken("faceVertexIndices"));
	indicies.Get(&indices1);

	auto facevertices = prim.GetAttribute(pxr::TfToken("faceVertexCounts"));
	facevertices.Get(&fvc);

	auto p = indices1.data();
	auto c = points1.data();

	int j = 0;
	for (auto i = fvc.begin(); i != fvc.end(); i++)
	{
		if (*i == 4)
		{
			ind.push_back(indices1[j + 0]);
			ind.push_back(indices1[j + 1]);
			ind.push_back(indices1[j + 2]);

			ind.push_back(indices1[j + 0]);
			ind.push_back(indices1[j + 2]);
			ind.push_back(indices1[j + 3]);
		}
		else if (*i == 3)
		{
			ind.push_back(indices1[j + 0]);
			ind.push_back(indices1[j + 1]);
			ind.push_back(indices1[j + 2]);
		}
		j = j + *i;
	}

	int lk = 0;
	for (auto i = points1.begin(); i != points1.end(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ak.push_back((*i).data()[j]);
		}
		lk = lk + 3;
	}

	normals.resize(points1.size(), glm::vec3(0.0, 0.0, 0.0));
	for (int i = 0; i < ind.size(); i += 3)
	{
		GLushort ia = ind[i];
		GLushort ib = ind[i + 1];
		GLushort ic = ind[i + 2];
		glm::vec3 normal = glm::normalize(glm::cross(
			glm::vec3(points1[ib][0], points1[ib][1], points1[ib][2]) - glm::vec3(points1[ia][1], points1[ia][1], points1[ia][2]),
			glm::vec3(points1[ic][0], points1[ic][1], points1[ic][2]) - glm::vec3(points1[ia][0], points1[ia][1], points1[ia][2])));
		normals[ia] = normal;
		normals[ib] = normal;
		normals[ic] = normal;
	}

	lk = 0;
	for (auto i = normals.begin(); i != normals.end(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			normals2.push_back((*i)[j]);
		}
		lk = lk + 3;
	}
	vao = RenderCommand::MakeVertexArray();
	VertexBuffer *ovb = RenderCommand::MakeVertexBuffer(ak.data(), points1.size() * 3);
	IndexBuffer *oib = RenderCommand::MakeIndexBuffer(ind.data(), ind.size());

	vao->addVertexBuffer(ovb);
	vao->addIndexBuffer(oib);
	vao->UnBind();
}

void USDPrim::Render()
{
	int a;
	a = 4;
	if (GetPrim().GetPath().GetAsString() == "/Root/newPrim")
	{
		std::cout << "Rendering: " << GetPrim().GetPath() << "    " << GetPrim().GetTypeName() << std::endl;
	}
	glm::mat4 model = glm::mat4(1.0f);
	auto p = pxr::UsdGeomMesh(GetPrim());
	pxr::UsdGeomXformCache xc = pxr::UsdGeomXformCache();
	pxr::GfMatrix4f mat = pxr::GfMatrix4f(p.ComputeLocalToWorldTransform(pxr::UsdTimeCode::Default()));
	model = glm::mat4(mat[0][0], mat[0][1], mat[0][2], mat[0][3],
					  mat[1][0], mat[1][1], mat[1][2], mat[1][3],
					  mat[2][0], mat[2][1], mat[2][2], mat[2][3],
					  mat[3][0], mat[3][1], mat[3][2], mat[3][3]);

	glm::mat4 view = Scene::currentCam->view;
	glm::mat4 projection;
	projection = Scene::currentCam->projection;

	s->Bind();
	s->updateUniformMat4("model", model);
	s->updateUniformMat4("view", view);
	s->updateUniformMat4("projection", projection);
	s->UnBind();

	Renderer::render(*s, vao, ind.size());
}

pxr::UsdPrim USDPrim::GetPrim()
{
	return stage->GetPrimAtPath(path);
}

glm::mat4 USDPrim::GetTransform()
{
	auto p = pxr::UsdGeomMesh(GetPrim());
	auto XformCommonAPI = pxr::UsdGeomXformCommonAPI(p);
	pxr::GfMatrix4d mat = pxr::GfMatrix4d(p.ComputeLocalToWorldTransform(pxr::UsdTimeCode::Default()));
	auto xfromops = XformCommonAPI.CreateXformOps();
	pxr::VtValue v;
	glm::mat4 model = glm::mat4(mat[0][0], mat[0][1], mat[0][2], mat[0][3],
								mat[1][0], mat[1][1], mat[1][2], mat[1][3],
								mat[2][0], mat[2][1], mat[2][2], mat[2][3],
								mat[3][0], mat[3][1], mat[3][2], mat[3][3]);
	return model;
}
