#pragma once
#include "..\..\Core.h"
#include "USDPrim.h"
#include "USDHierarchyItem.h"
#include <pxr\usd\usd\stage.h>
#include <pxr\usd\usd\primRange.h>

class USDHierarchyModel
{
public:
	USDHierarchyModel(){};
	~USDHierarchyModel();
	USDHierarchyModel(pxr::UsdStageRefPtr stage);
	void Create(pxr::UsdStageRefPtr stage);
	pxr::SdfPath AddOverPrim(pxr::UsdStageRefPtr stage, pxr::SdfPath path, USDHierarchyItem *parent, std::string referencepath);
	pxr::SdfPath AddNewPrim(pxr::UsdStageRefPtr stage, pxr::SdfPath path, pxr::TfToken type, USDHierarchyItem *parent);
	pxr::SdfPath AddNewPrim(pxr::UsdStageRefPtr stage, pxr::SdfPath path, pxr::TfToken type);
	void DepthCreate(pxr::UsdPrimSiblingRange &k, int depth, USDHierarchyItem &parent, pxr::UsdStageRefPtr stage);
	void DepthDelete(USDHierarchyItem *parent);
	USDHierarchyItem *root;
};
