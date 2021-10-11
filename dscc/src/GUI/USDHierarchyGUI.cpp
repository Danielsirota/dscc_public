#include "USDHierarchyGUI.h"
#include "pxr/usd/usd/stage.h"
#include <pxr\usd\usdGeom\xformCommonAPI.h>
#include "GUIFileExplorer.h"

void USDHierarchyGUI::fill(USDHierarchyItem *ui)
{
	for (USDHierarchyItem *hi : ui->children)
	{
		int leaf = -1;
		if (hi->children.size() == 0)
		{
			node_flags = base_flags;
			node_flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen; // ImGuiTreeNodeFlags_Bullet
			leaf = 1;
		}
		else
		{
			node_flags = base_flags;
		}
		if (Scene::stage->selected == hi)
		{
			node_flags |= ImGuiTreeNodeFlags_Selected;
		}
		bool node_open = ImGui::TreeNodeEx((void *)(intptr_t)hi->id, node_flags, hi->name.data(), hi->id);
		if (ImGui::IsItemClicked())
		{
			Scene::stage->selected = hi;
		}
		if (node_open && leaf == -1)
		{
			fill(hi);
			ImGui::TreePop();
		}
	}
};

void USDHierarchyGUI::Render()
{
	static bool align_label_with_current_x_position = false;
	static bool test_drag_and_drop = false;
	ImGui::Begin("Outliner");
	if (model->root != nullptr)
	{
		int node_clicked = -1;

		int leaf = -1;
		if (model->root->children.size() == 0)
		{
			node_flags = base_flags;
			node_flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
			leaf = 1;
		}
		else
		{
			node_flags = base_flags;
		}
		if (Scene::stage->selected == model->root)
		{
			node_flags |= ImGuiTreeNodeFlags_Selected;
		}
		bool node_open = ImGui::TreeNodeEx((void *)(intptr_t)model->root->id, node_flags, model->root->name.data(), model->root->id);
		if (ImGui::IsItemClicked())
		{
			Scene::stage->selected = model->root;
		}
		if (node_open && leaf == -1)
		{
			fill(model->root);
			ImGui::TreePop();
		}
	}

	if (ImGui::BeginPopupContextItem("Right Click Menu"))
	{
		if (ImGui::Selectable("New Prim"))
		{
			Scene::stage->HierarchyModel->AddNewPrim(Scene::stage->stage, pxr::SdfPath("/newPrim"), pxr::TfToken("Xform"));
			Scene::stage->updateModel();
			model = Scene::stage->HierarchyModel;
		};
		ImGui::EndPopup();
	}

	if (ImGui::BeginPopupContextItem("Item Right Click"))
	{
		if (ImGui::Selectable("New Prim"))
		{
			if (Scene::stage->selected)
			{
				std::string currentPath = Scene::stage->selected->primObject->path.GetAsString();
				currentPath.append("/newPrim");
				Scene::stage->HierarchyModel->AddNewPrim(Scene::stage->stage, pxr::SdfPath(currentPath), pxr::TfToken("Xform"), Scene::stage->selected);
			}
			else
			{
				Scene::stage->HierarchyModel->AddNewPrim(Scene::stage->stage, pxr::SdfPath("/Root/newPrim"), pxr::TfToken("Xform"), Scene::stage->selected);
			}
			model = Scene::stage->HierarchyModel;
		};
		if (ImGui::Selectable("Reference Prim"))
		{
			if (Scene::stage->selected)
			{
				std::string currentPath = Scene::stage->selected->primObject->path.GetAsString();
				currentPath.append("/newPrim");
				auto prim = Scene::stage->HierarchyModel->AddOverPrim(Scene::stage->stage, pxr::SdfPath(currentPath), Scene::stage->selected, GUIFileExplorer::OpenFile("All Files (*.*)\0*.*\0"));
			}
			model = Scene::stage->HierarchyModel;
		};
		ImGui::EndPopup();
	}

	if (ImGui::IsWindowHovered())
	{
		if (Scene::stage->selected && ImGui::IsMouseClicked(ImGuiMouseButton_Right))
		{
			ImGui::OpenPopup("Item Right Click");
		}
	}

	ImGui::End();
}

void USDHierarchyGUI::changeModel(sceneChangedEvent &e)
{
	model = Scene::stage->HierarchyModel;
}

void USDHierarchyGUI::onEvent(Event &e)
{
	Message_Bus m(e);
	m.notify<sceneChangedEvent>(std::bind(&USDHierarchyGUI::changeModel, this, std::placeholders::_1));
};
