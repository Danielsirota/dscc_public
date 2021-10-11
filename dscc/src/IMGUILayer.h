#pragma once
#include "Layer.h"
#include "GUI/GUI.h"

class IMGUILayer : public Layer
{
public:
	IMGUILayer(const std::string &n, Window &win) : Layer(n), w(win){};

	bool onEvent(Event &e) override;
	void onIMGUIRender() override;
	void onAttach() override;
	void onDetach() override;
	void onUpdate() override;
	void Begin();
	void End();
	Window &w;
	std::vector<GUI *> guis;
};
