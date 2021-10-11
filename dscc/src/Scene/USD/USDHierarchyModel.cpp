#include "USDHierarchyModel.h"
#include "pxr/usd/usdGeom/mesh.h"
#include "pxr/usd/usdGeom/primvarsAPI.h"
#include <pxr/usd/usd/primFlags.h>

//ADD DISTRUCTOR
USDHierarchyModel::~USDHierarchyModel()
{
	if (root)
	{
		DepthDelete(root);
	}
};

USDHierarchyModel::USDHierarchyModel(pxr::UsdStageRefPtr stage)
{
	auto temp = stage->GetDefaultPrim().GetPath();
	auto primObj = new USDPrim(stage, temp);
	root = new USDHierarchyItem(primObj);
	pxr::UsdPrimSiblingRange k = root->primObject->GetPrim().GetFilteredChildren(pxr::UsdTraverseInstanceProxies());
	DepthCreate(k, 0, *root, stage);
};

void USDHierarchyModel::Create(pxr::UsdStageRefPtr stage)
{
	auto primObj = new USDPrim(stage, stage->GetDefaultPrim().GetPath());
	root = new USDHierarchyItem(primObj);
}

pxr::SdfPath USDHierarchyModel::AddOverPrim(pxr::UsdStageRefPtr stage, pxr::SdfPath path, USDHierarchyItem *parent, std::string referencepath)
{
	auto prim = stage->OverridePrim(path);
	prim.GetReferences().AddReference(referencepath);
	auto primObj = new USDPrim(stage, path);
	USDHierarchyItem *uhi = new USDHierarchyItem(primObj);
	parent->children.push_back(uhi);
	pxr::UsdPrimSiblingRange k = prim.GetFilteredChildren(pxr::UsdTraverseInstanceProxies());
	DepthCreate(k, 0, *uhi, stage);
	return prim.GetPath();
}

pxr::SdfPath USDHierarchyModel::AddNewPrim(pxr::UsdStageRefPtr stage, pxr::SdfPath path, pxr::TfToken type, USDHierarchyItem *parent)
{
	auto prim = stage->DefinePrim(path, type);
	auto primObj = new USDPrim(stage, path);
	USDHierarchyItem *uhi = new USDHierarchyItem(primObj);
	parent->children.push_back(uhi);
	return prim.GetPath();
}

pxr::SdfPath USDHierarchyModel::AddNewPrim(pxr::UsdStageRefPtr stage, pxr::SdfPath path, pxr::TfToken type)
{
	auto prim = stage->DefinePrim(path, type);
	return prim.GetPath();
}

void USDHierarchyModel::DepthCreate(pxr::UsdPrimSiblingRange &k, int depth, USDHierarchyItem &parent, pxr::UsdStageRefPtr stage)
{
	int i = 1;
	for (auto const &prim : k)
	{
		auto primObj2 = new USDPrim(stage, prim.GetPath());
		auto child = new USDHierarchyItem(primObj2);
		child->parent = &parent;
		child->id = i;
		parent.children.push_back(child);
		pxr::UsdPrimSiblingRange m = prim.GetFilteredChildren(pxr::UsdTraverseInstanceProxies());
		DepthCreate(m, depth + 1, *child, stage);
		i++;
	}
}

void USDHierarchyModel::DepthDelete(USDHierarchyItem *parent)
{
	for (auto child : parent->children)
	{
		DepthDelete(child);
	}
	delete parent;
	parent = nullptr;
}
