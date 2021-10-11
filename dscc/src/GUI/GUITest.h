#pragma once
#include "GUI.h"
#include "..\Scene\Scene.h"
#include <pxr\usd\usdGeom\xformCommonAPI.h>
#include "GUIFileExplorer.h"
#include <fstream>

class GUITest : public GUI
{
public:
	GUITest() : GUI(){};
	void onEvent(Event &e) override { int a = 2 + 2; }
	void Render() override
	{
		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("New", "CTRL+N"))
				{
					Scene::SetScene("");
				}
				if (ImGui::MenuItem("Open", "CTRL+O"))
				{
					Scene::SetScene(GUIFileExplorer::OpenFile("All Files (*.*)\0*.*\0"));
				}
				if (ImGui::MenuItem("Save", "CTRL+S"))
				{
					auto et = Scene::stage->stage->GetEditTargetForLocalLayer(0);
					Scene::stage->stage->SetEditTarget(et);
					et = Scene::stage->stage->GetEditTarget();
					Scene::stage->stage->Export(GUIFileExplorer::SaveFile("USD Files (*.usd, *.usda)\0*.usd\0*.usda\0"));
				}
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Edit"))
			{
				if (ImGui::MenuItem("Undo", "CTRL+Z"))
				{
				}
				if (ImGui::MenuItem("Redo", "CTRL+Y", false, false))
				{
				} // Disabled item
				ImGui::Separator();
				if (ImGui::MenuItem("Cut", "CTRL+X"))
				{
				}
				if (ImGui::MenuItem("Copy", "CTRL+C"))
				{
				}
				if (ImGui::MenuItem("Paste", "CTRL+V"))
				{
				}
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
		ImGui::ShowDemoWindow();
		ImGui::SetNextWindowSizeConstraints(ImVec2(1200, 1200), ImVec2(1200, 1200));
		ImGui::Begin("Timeline");
		static int i1 = 0;
		static int begin = 00, end = 300;
		ImGui::PushItemWidth(-200);
		ImGui::SliderInt("##timelineslider", &i1, begin, end);
		ImGui::SameLine();
		ImGui::PushItemWidth(-1);
		ImGui::DragIntRange2("##timelinerange", &begin, &end, 5, 0, 1000, "Min: %d units", "Max: %d units");
		ImGui::End();
	}
};