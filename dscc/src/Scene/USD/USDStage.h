#pragma once
#include "../../Core.h"
#include <pxr\usd\usd\stage.h>
#include "USDHierarchyModel.h"
class USDStage
{
public:
	~USDStage();
	USDStage();
	USDStage(const std::string file);
	pxr::UsdStageRefPtr stage;
	USDHierarchyModel *HierarchyModel;
	USDHierarchyItem *selected;
	void Render();
	void renderPrims(USDHierarchyItem *ui, bool selectedBool);
	void updateModel();
};
