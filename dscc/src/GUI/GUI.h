#pragma once
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include "../Events/Events.h"
#include "../Events/Event.h"
#include "../Core.h"
class GUI
{
public:
	GUI(){};
	virtual void Render() = 0;
	virtual void onEvent(Event &e) = 0;
};

