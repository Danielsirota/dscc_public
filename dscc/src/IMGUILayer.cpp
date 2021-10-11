#include "IMGUILayer.h"

void IMGUILayer::onAttach()
{
	const char *glsl_version = "#version 130";
	IMGUI_CHECKVERSION();
	auto a = ImGui::CreateContext();
	ImGui::SetCurrentContext(a);
	ImGuiIO &io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;	  // Enable Docking
	//io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	io.FontDefault = io.Fonts->AddFontFromFileTTF("C:\\Users\\danth\\Downloads\\Varela_Round\\VarelaRound-Regular.ttf", 14.0f);
	ImGui::StyleColorsDark();
	ImGuiStyle &style = ImGui::GetStyle();
	style.FrameRounding = 8.0f;
	style.GrabRounding = style.FrameRounding;

	ImVec4 *colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_FrameBg] = ImVec4(0.29f, 0.30f, 0.32f, 0.54f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.13f, 0.12f, 0.10f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.21f, 0.21f, 0.21f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.98f, 0.76f, 0.26f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.59f, 0.59f, 0.59f, 0.40f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.61f, 0.53f, 0.07f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.98f, 0.84f, 0.06f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.64f, 0.64f, 0.64f, 0.31f);
	colors[ImGuiCol_Tab] = ImVec4(0.40f, 0.42f, 0.45f, 0.86f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.69f, 0.69f, 0.69f, 0.80f);
	colors[ImGuiCol_TabActive] = ImVec4(0.62f, 0.62f, 0.62f, 1.00f);
	colors[ImGuiCol_DockingPreview] = ImVec4(0.91f, 0.98f, 0.26f, 0.70f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.52f, 0.52f, 0.52f, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.64f, 0.64f, 0.64f, 0.67f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.52f, 0.53f, 0.55f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.71f, 0.71f, 0.71f, 1.00f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.61f, 0.61f, 0.61f, 0.80f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.61f, 0.61f, 0.61f, 0.80f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.13f, 0.14f, 0.15f, 0.97f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.27f, 0.27f, 0.27f, 1.00f);

	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		style.WindowRounding = 0.0f;
		style.FrameRounding = 10.0f;
		style.GrabRounding = style.FrameRounding;
		style.Colors[ImGuiCol_WindowBg].w = 1.0f;
	}

	ImGui_ImplGlfw_InitForOpenGL(w.win, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
}

void IMGUILayer::Begin()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
}

void IMGUILayer::onIMGUIRender()
{
	for (GUI *g : guis)
	{
		g->Render();
	}
}

void IMGUILayer::End()
{
	// Render dear imgui into screen
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	GLFWwindow *backup_current_context = glfwGetCurrentContext();
	ImGui::UpdatePlatformWindows();
	ImGui::RenderPlatformWindowsDefault();
}

bool IMGUILayer::onEvent(Event &e)
{
	Message_Bus m(e);
	for (GUI *g : guis)
	{
		g->onEvent(e);
	}
	return true;
}

void IMGUILayer::onDetach()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void IMGUILayer::onUpdate()
{
}