#pragma once
#include "..\..\Core.h"
#include "USDPrim.h"

class USDHierarchyItem
{
public:
	USDHierarchyItem(USDPrim *prim);
	~USDHierarchyItem();

	int id;
	USDPrim *primObject;
	std::string name;
	std::vector<USDHierarchyItem *> children;
	USDHierarchyItem *parent;
};
