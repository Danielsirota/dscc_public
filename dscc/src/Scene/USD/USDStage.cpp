#include "USDStage.h"

#include <pxr/usd/usdGeom/mesh.h>
#include <pxr/usd/usdGeom/xformable.h>
#include <pxr\usd\usdGeom\xformCommonAPI.h>
#include "../Scene.h"
//ADD DISTRUCTOR

USDStage::USDStage()
{
	stage = pxr::UsdStage::CreateInMemory();
	HierarchyModel = new USDHierarchyModel();
}

USDStage::USDStage(const std::string file)
{
	stage = pxr::UsdStage::Open(file);
	HierarchyModel = new USDHierarchyModel(stage);
	selected = HierarchyModel->root;
};

void USDStage::updateModel()
{
	delete HierarchyModel;
	HierarchyModel = nullptr;
	HierarchyModel = new USDHierarchyModel(stage);
};

USDStage::~USDStage()
{
	delete HierarchyModel;
	HierarchyModel = nullptr;
};

void USDStage::Render()
{
	if (HierarchyModel->root != nullptr)
	{
		HierarchyModel->root->primObject->Render();
		renderPrims(HierarchyModel->root, false);
	}
};

void USDStage::renderPrims(USDHierarchyItem *ui, bool selectedBool)
{

	for (USDHierarchyItem *hi : ui->children)
	{
		hi->primObject->Render();
		renderPrims(hi, false);
	}
};
