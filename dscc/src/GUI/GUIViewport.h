#pragma once
#include "GUI.h"
#include <ImGuizmo/ImGuizmo.h>

class GUIViewport : public GUI
{
public:
	GUIViewport() : GUI(){};
	void Render() override;
	void onEvent(Event &e) override;
	void Ready();
	int gizmotype = ImGuizmo::OPERATION::TRANSLATE;
};
