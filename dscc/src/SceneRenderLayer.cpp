#include "SceneRenderLayer.h"
#include "Scene/Grid.h"

void SceneRenderLayer::search(pxr::UsdPrimSiblingRange k, int depth)
{
	for (pxr::UsdPrim prim : k)
	{
		pxr::UsdPrimSiblingRange m = prim.GetChildren();
		search(m, depth + 1);
	}
}

void SceneRenderLayer::onAttach()
{
}

void SceneRenderLayer::onUpdate()
{
	RenderCommand::GetSceneRender()->Bind();
	scene->stage->Render();
	if (Scene::grid)
	{
		Grid grid = Grid();
		grid.render();
	}
	RenderCommand::GetSceneRender()->UnBind();
}

void SceneRenderLayer::onIMGUIRender()
{
}

bool SceneRenderLayer::onEvent(Event &e)
{
	return true;
}

void SceneRenderLayer::onDetach()
{
}