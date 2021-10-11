#pragma once
#include <functional>
#include "../Core.h"
#include "Camera.h"
#include "USD/USDStage.h"
#include "../Events/Event.h"
#include "../Events/Events.h"

class Scene
{
public:
	using callbackFunc = std::function<void(Event &)>;

	Scene(callbackFunc func);
	static Camera *currentCam;
	static USDStage *stage;
	static bool SetScene(std::string path);
	static callbackFunc Func;
	static bool grid;
};
