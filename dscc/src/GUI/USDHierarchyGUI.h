#pragma once
#include "GUI.h"
#include "../Scene/Scene.h"
#include "../Scene/USD/USDHierarchyModel.h"
#include "../Scene/USD/USDHierarchyItem.h"

class USDHierarchyGUI : public GUI
{
public:
	USDHierarchyGUI(USDHierarchyModel *model) : GUI(), model(model){};
	USDHierarchyModel *model;
	void fill(USDHierarchyItem *ui);
	void Render() override;
	void onEvent(Event &e) override;
	void changeModel(sceneChangedEvent &e);
	int node_clicked = -1;
	ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
	ImGuiTreeNodeFlags node_flags;
	bool Wait;
};
