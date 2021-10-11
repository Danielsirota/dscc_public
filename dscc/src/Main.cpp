
#define NOMINMAX

#include "Core.h"

#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdGeom/modelAPI.h>
#include <pxr/usd/usdGeom/sphere.h>
#include "pxr/base/tf/debug.h"

#include "Application.h"

#define TF_DEBUG
#define TF_INFO

int main()
{
	Application app;
	app.run();
	return 0;
};
