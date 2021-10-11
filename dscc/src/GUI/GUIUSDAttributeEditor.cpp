#include "GUIUSDAttributeEditor.h"
#include "pxr/usd/usdGeom/mesh.h"
#include "pxr/usd/usdGeom/primvarsAPI.h"
#include "pxr/usd/usdGeom/xformCommonAPI.h"

void GUIUSDAttributeEditor::Render()
{
	selected = Scene::stage->selected;
	ImGui::Begin("Attribute Editor");
	if (selected)
	{
		auto prim = selected->primObject->GetPrim();
		auto XformCommonAPI = pxr::UsdGeomXformCommonAPI(prim);
		auto xfromops = XformCommonAPI.CreateXformOps();
		pxr::VtValue values;
		auto pm = prim.GetAttributes();
		ImVec2 wsize = ImGui::GetWindowSize();
		int amount = 0;
		for (pxr::UsdAttribute attrib : pm)
		{
			ImGuiIO &io = ImGui::GetIO();
			auto type = attrib.GetTypeName();
			ImGui::PushID(attrib.GetName().GetString().data());
			ImGui::PushItemWidth(50);
			ImGui::Columns(2);
			ImGui::Text(attrib.GetName().GetString().data());
			ImGui::SameLine();
			ImGui::PushItemWidth(50);
			ImGui::NextColumn();
			if (type == pxr::TfToken("float3"))
			{
				pxr::GfVec3f vec3fvalues;
				attrib.Get(&vec3fvalues);
				float dataf3[3] = {vec3fvalues[0], vec3fvalues[1], vec3fvalues[2]};
				ImGui::PushItemWidth(35);
				bool x = ImGui::DragFloat("##X", &dataf3[0], 1, -1, 2000);
				ImGui::SameLine();
				bool y = ImGui::DragFloat("##Y", &dataf3[1], 1, -1, 2000);
				ImGui::SameLine();
				bool z = ImGui::DragFloat("##Z", &dataf3[2], 1, -1, 2000);
				if (x || y || z)
				{
					attrib.Set(pxr::GfVec3f(dataf3[0], dataf3[1], dataf3[2]));
				}
			}
			else if (type == pxr::TfToken("float"))
			{
				float dataf = 0.0f;
				ImGui::PushItemWidth(-1);
				ImGui::DragFloat("##attrib.GetName().GetString().data()", &dataf, -1, 2000);
			}
			else if (type == pxr::TfToken("int3"))
			{
				pxr::GfVec3i int3fvalues;
				attrib.Get(&int3fvalues);
				int int3[3] = {int3fvalues[0], int3fvalues[1], int3fvalues[2]};
				ImGui::PushItemWidth(35);
				ImGui::DragInt("##X", &int3[0], 1, -2000, 2000);
				ImGui::SameLine();
				ImGui::DragInt("##Y", &int3[1], 1, -2000, 2000);
				ImGui::SameLine();
				ImGui::DragInt("##Z", &int3[2], 1, -2000, 2000);
			}
			else if (type == pxr::TfToken("double"))
			{
				float datad = 0.0f;
				ImGui::PushItemWidth(-1);
				ImGui::DragFloat("##attrib.GetName().GetString().data()", &datad, -1, 2000);
			}
			else if (type == pxr::TfToken("double3"))
			{
				pxr::GfVec3d double3fvalues;
				attrib.Get(&double3fvalues);
				float double3[3] = {double3fvalues[0], double3fvalues[1], double3fvalues[2]};
				ImGui::PushItemWidth(35);
				float x = ImGui::DragFloat("##X", &double3[0], 1, -2000, 2000);
				ImGui::SameLine();
				float y = ImGui::DragFloat("##Y", &double3[1], 1, -2000, 2000);
				ImGui::SameLine();
				float z = ImGui::DragFloat("##Z", &double3[2], 1, -2000, 2000);
				if (x || y || z)
				{
					attrib.Set(pxr::GfVec3d(double3[0], double3[1], double3[2]));
				}
			}
			else if (type == pxr::TfToken("int"))
			{
				int datai = 0.0f;
				ImGui::PushItemWidth(-1);
				ImGui::DragInt("##attrib.GetName().GetString().data()", &datai, -2000, 2000);
			}
			else
			{
				ImGui::PushItemWidth(-1);
				std::string warn = " ";
				warn.append(attrib.GetTypeName().GetAsToken().data());
				ImGui::Text(warn.data());
			}
			ImGui::Columns(1);
			ImGui::PopID();
			amount++;
		}

		static int i2 = 0;
		static int i3 = 0;
		static int i4 = 0;
		if (ImGui::BeginPopupContextItem("AttributePopup"))
		{
			if (ImGui::Selectable("Translate"))
				XformCommonAPI.SetTranslate(pxr::GfVec3d(0, 0, 0));
			if (ImGui::Selectable("Rotate"))
				XformCommonAPI.SetRotate(pxr::GfVec3f(0, 0, 0));
			if (ImGui::Selectable("Scale"))
				XformCommonAPI.SetScale(pxr::GfVec3f(0, 0, 0));
			ImGui::EndPopup();
		}
		if (ImGui::IsWindowHovered())
		{
			if (ImGui::IsMouseClicked(ImGuiMouseButton_Right))
			{
				ImGui::OpenPopup("AttributePopup");
			}
		}
	}
	ImGui::End();
}
void GUIUSDAttributeEditor::onEvent(Event &e){};