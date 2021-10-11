#pragma once
#include "../Core.h"
#include <Windows.h>
#include <GLFW\glfw3.h>
#include <commdlg.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW\glfw3native.h>

class GUIFileExplorer
{
public:
	static std::string OpenFile(const char *filter);
	static std::string SaveFile(const char *filter);
};
