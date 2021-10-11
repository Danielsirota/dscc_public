#include "GUIViewport.h"
#include "..\Scene\Scene.h"
#include "pxr/usd/usdGeom/xformCommonAPI.h"

void GUIViewport::Render()
{
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

	ImGui::Begin("Viewport");
	ImVec2 wsize = ImGui::GetWindowSize();
	ImVec2 vMin = ImGui::GetWindowContentRegionMin();
	ImVec2 vMax = ImGui::GetWindowContentRegionMax();

	wsize.x = vMax.x - vMin.x;
	wsize.y = vMax.y - vMin.y;

	Scene::currentCam->setAspectRatio(wsize.x, wsize.y);

	glBindTexture(GL_TEXTURE_2D, RenderCommand::GetSceneRender()->texColorBuffer);
	ImGui::Image((ImTextureID)RenderCommand::GetSceneRender()->texColorBuffer, wsize, ImVec2(0, 1), ImVec2(1, 0));
	static ImVec2 offset(30.0f, 30.0f);

	if (Scene::stage->selected)
	{
		ImGuizmo::SetOrthographic(false);
		ImGuizmo::SetDrawlist();
		ImGuizmo::SetRect(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y, wsize.x, wsize.y);
		auto prim = Scene::stage->selected->primObject->GetPrim();
		auto XformCommonAPI = pxr::UsdGeomXformCommonAPI(prim);
		glm::mat4 transfrom = Scene::stage->selected->primObject->GetTransform();

		ImGuizmo::Manipulate(glm::value_ptr(Scene::currentCam->view), glm::value_ptr(Scene::currentCam->projection), (ImGuizmo::OPERATION)gizmotype, ImGuizmo::LOCAL, glm::value_ptr(transfrom));

		if (ImGuizmo::IsUsing())
		{

			float matrixTranslation[3], matrixRotation[3], matrixScale[3];

			if ((Scene::stage->selected->parent) != NULL)
			{
				glm::mat4 parent = glm::inverse(Scene::stage->selected->parent->primObject->GetTransform());
				transfrom = parent * transfrom;
			}
			ImGuizmo::DecomposeMatrixToComponents(glm::value_ptr(transfrom), matrixTranslation, matrixRotation, matrixScale);
			transfrom = Scene::stage->selected->primObject->GetTransform();
			pxr::GfVec3d mat;
			pxr::GfVec3f rotate;
			pxr::GfVec3f scale;
			pxr::GfVec3f pivot;
			pxr::UsdGeomXformCommonAPI::RotationOrder ro;
			XformCommonAPI.GetXformVectors(&mat, &rotate, &scale, &pivot, &ro, pxr::UsdTimeCode::Default());
			float tmpMatrix[16];
			if (gizmotype == ImGuizmo::OPERATION::TRANSLATE)
			{
				XformCommonAPI.SetTranslate(pxr::GfVec3d(matrixTranslation[0], matrixTranslation[1], matrixTranslation[2]));
			}
			XformCommonAPI.SetScale(pxr::GfVec3f(matrixScale[0], matrixScale[1], matrixScale[2]));
			XformCommonAPI.SetRotate(pxr::GfVec3f(matrixRotation[0], matrixRotation[1], matrixRotation[2]));
		}
	}

	if (ImGui::IsWindowHovered() && !ImGuizmo::IsUsing())
	{
		const auto mousePos = ImGui::GetMousePos();
		const auto windowPos = ImGui::GetWindowPos();
		if (ImGui::IsMouseDragging(ImGuiMouseButton_Left))
		{
			offset.x = ImGui::GetIO().MouseDelta.x;
			offset.y = ImGui::GetIO().MouseDelta.y;
			Scene::currentCam->rotate(1 * (offset.x / 4), 1 * (offset.y / 2));
		}
		if (ImGui::IsMouseDragging(ImGuiMouseButton_Right))
		{
			Scene::currentCam->zoom(-1 * (ImGui::GetIO().MouseDelta.y) * 2);
		}
		if (ImGui::IsMouseDragging(ImGuiMouseButton_Middle))
		{
			offset.x = ImGui::GetIO().MouseDelta.x;
			offset.y = ImGui::GetIO().MouseDelta.y;
			Scene::currentCam->dolly(1 * (-offset.x), 1 * (-offset.y));
		}
		if (ImGui::IsKeyPressed(87))
		{
			gizmotype = ImGuizmo::OPERATION::TRANSLATE;
		}
		if (ImGui::IsKeyPressed(69))
		{
			gizmotype = ImGuizmo::OPERATION::ROTATE;
		}
		if (ImGui::IsKeyPressed(82))
		{
			gizmotype = ImGuizmo::OPERATION::SCALE;
		}
	}
	ImGui::End();
	ImGui::PopStyleVar();
}

void GUIViewport::Ready()
{
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
	ImGui::Begin("Viewport");
	ImVec2 wsize = ImGui::GetWindowSize();
	ImVec2 vMin = ImGui::GetWindowContentRegionMin();
	ImVec2 vMax = ImGui::GetWindowContentRegionMax();
	wsize.x = vMax.x - vMin.x;
	wsize.y = vMax.y - vMin.y;
	Scene::currentCam->setAspectRatio(wsize.x, wsize.y);
	ImGui::End();
	ImGui::PopStyleVar();
}

void GUIViewport::onEvent(Event &e){};