#pragma once
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include "Events/Event.h"
#include "Events/Events.h"
#include "Events/Message_Bus.h"
#include "window.h"
#include "Renderer/Renderer.h"

class Layer
{
public:
	Layer(const std::string &n) : name(n){};

	virtual bool onEvent(Event &e) { return false; };
	virtual void onIMGUIRender(){};
	virtual void onUpdate(){};
	virtual void onAttach(){};
	virtual void onDetach(){};

	const std::string &name;
};
