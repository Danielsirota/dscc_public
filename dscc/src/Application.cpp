#include "Application.h"
#include "GUI/GUITest.h"
#include "GUI/USDHierarchyGUI.h"
#include "GUI/GUIUSDAttributeEditor.h"
#include "GUI/GUIViewport.h"

void Application::run()
{

	Window w = Window(1300, 800, "DSCC", std::bind(&Application::onEvent, this, std::placeholders::_1));

	RenderCommand::Init(new OGLRendererAPI());

	Scene s = Scene(std::bind(&Application::onEvent, this, std::placeholders::_1));

	struct FrameBufferSpec fbs;
	fbs.Width = 1300;
	fbs.Height = 800;
	RenderCommand::MakeSceneRender(fbs);

	auto r = std::make_unique<Renderer>("r1");

	IMGUILayer imguil = IMGUILayer("IMGUI", w);
	SceneRenderLayer srl = SceneRenderLayer("Scene", &s);
	pushLayerStack(&srl);
	pushLayerStack(&imguil);

	GUITest gt = GUITest();
	USDHierarchyGUI uhg = USDHierarchyGUI(s.stage->HierarchyModel);
	GUIUSDAttributeEditor uad = GUIUSDAttributeEditor(s.stage->selected);
	GUIViewport vw = GUIViewport();
	imguil.guis.push_back(&vw);
	imguil.guis.push_back(&gt);
	imguil.guis.push_back(&uhg);
	imguil.guis.push_back(&uad);

	while (running)
	{

		imguil.Begin();
		vw.Ready();

		for (Layer *m_Layer : layerStack)
		{
			m_Layer->onUpdate();
		}

		for (Layer *m_Layer : layerStack)
		{
			m_Layer->onIMGUIRender();
		}
		imguil.End();

		w.repaint();
	}
};

void Application::func(windowResizeEvent &e)
{
	std::cout << "sssssssssssssss" << std::endl;
};

void Application::windowClose(windowCloseEvent &e)
{
	std::cout << "Closing Window" << std::endl;
	running = false;
};
void Application::mouseButtonPress(mouseButtonPressedEvent &e){};

void Application::keyButtonPress(keyButtonPressedEvent &e)
{
	if (e.key == DSCC_KEY_A)
	{
		std::cout << "A KEY PRESSED" << std::endl;
	}
};

void Application::mouseMoved(mouseMovedEvent &e){};

bool Application::onEvent(Event &e)
{
	Message_Bus m(e);
	m.notify<windowResizeEvent>(std::bind(&Application::func, this, std::placeholders::_1));
	m.notify<windowCloseEvent>(std::bind(&Application::windowClose, this, std::placeholders::_1));
	m.notify<mouseButtonPressedEvent>(std::bind(&Application::mouseButtonPress, this, std::placeholders::_1));
	m.notify<keyButtonPressedEvent>(std::bind(&Application::keyButtonPress, this, std::placeholders::_1));
	m.notify<mouseMovedEvent>(std::bind(&Application::mouseMoved, this, std::placeholders::_1));
	for (Layer *m_Layer : layerStack)
	{
		m_Layer->onEvent(e);
	}
	return true;
};

bool Application::pushLayerStack(Layer *L)
{
	layerStack.push_back(L);
	L->onAttach();
	return true;
}
