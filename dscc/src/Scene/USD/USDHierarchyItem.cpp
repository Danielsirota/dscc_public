#include "USDHierarchyItem.h"

//ADD DISTRUCTOR

USDHierarchyItem::USDHierarchyItem(USDPrim *prim) : primObject(prim)
{
	name = primObject->GetPrim().GetName();
}

USDHierarchyItem::~USDHierarchyItem()
{
	delete primObject;
	primObject = nullptr;
};
