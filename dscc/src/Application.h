#pragma once
#include "Core.h"
#include "KeyandMouseCodes.h"
#include "window.h"
#include "Renderer\Renderer.h"
#include "Renderer/Buffer.h"
#include "Renderer/FrameBuffer.h"
#include "Events/Message_Bus.h"
#include "Events/Event.h"
#include "Events/Events.h"
#include "Layer.h"
#include "IMGUILayer.h"
#include "SceneRenderLayer.h"
#include "OpenGl/OGLRendererAPI.h"

#include "Scene/Scene.h"

#include <glad\glad.h>
#include <glm/glm.hpp>
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

class Application
{
public:
	Application() = default;
	std::vector<Layer *> layerStack;
	bool running = true;

	void run();

	void func(windowResizeEvent &e);

	void windowClose(windowCloseEvent &e);
	void mouseButtonPress(mouseButtonPressedEvent &e);
	void keyButtonPress(keyButtonPressedEvent &e);
	void mouseMoved(mouseMovedEvent &e);

	bool onEvent(Event &e);

	bool pushLayerStack(Layer *L);
};
