#pragma once
#include "GUI.h"
#include "../Scene/Scene.h"
#include "../Scene/USD/USDHierarchyItem.h"

class GUIUSDAttributeEditor : public GUI
{
public:
	GUIUSDAttributeEditor(USDHierarchyItem *selected) : GUI(), selected(selected){};
	void Render() override;
	void onEvent(Event &e) override;
	USDHierarchyItem *selected;
};
