#include "Scene.h"

USDStage *Scene::stage;
Camera *Scene::currentCam;
bool Scene::grid;
std::function<void(Event &)> Scene::Func;

Scene::Scene(callbackFunc func)
{
	Func = func;
	currentCam = new Camera(0.0f, 200.0f, 1000.0f);
	stage = new USDStage();
	pxr::SdfPath primPath = stage->HierarchyModel->AddNewPrim(stage->stage, pxr::SdfPath("/Root"), pxr::TfToken("Xform"));
	Scene::stage->stage->SetDefaultPrim(stage->stage->GetPrimAtPath(primPath));
	auto primObj = new USDPrim(stage->stage, stage->stage->GetDefaultPrim().GetPath());
	stage->HierarchyModel->root = new USDHierarchyItem(primObj);
	Scene::stage->selected = Scene::stage->HierarchyModel->root;
	grid = true;
	stage = new USDStage("E:\\Disney_island\\moanaUsd\\isPalmDead_scene.usda");
}

bool Scene::SetScene(std::string path)
{
	delete stage;
	if (!path.empty())
	{
		stage = new USDStage(path);
		sceneChangedEvent event;
		Func(event);
		grid = true;
	}
	else
	{
		stage = new USDStage();
		pxr::SdfPath primPath = stage->HierarchyModel->AddNewPrim(stage->stage, pxr::SdfPath("/Root"), pxr::TfToken("Xform"));
		Scene::stage->stage->SetDefaultPrim(stage->stage->GetPrimAtPath(primPath));
		auto primObj = new USDPrim(stage->stage, stage->stage->GetDefaultPrim().GetPath());
		stage->HierarchyModel->root = new USDHierarchyItem(primObj);
		Scene::stage->selected = Scene::stage->HierarchyModel->root;
		sceneChangedEvent event;
		Func(event);
		grid = true;
	}
	return true;
}