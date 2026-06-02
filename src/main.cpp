#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

int main() {
	std::cout << "Hello\n";

	SetTargetFPS(60);

	InitWindow(800, 450, "game");
	#pragma region imgui
	rlImGuiSetup(true);
	ImGuiIO& io = ImGui::GetIO();
	io.FontGlobalScale = 2; // Make GUI bigger
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	#pragma endregion

	int posX = 30;
	int posY = 30;
	int size = 100;

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);

		#pragma region imgui
		rlImGuiBegin();
		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);

		ImGui::Begin("TEST");
		ImGui::Text("Hello");
		if (ImGui::Button("Button")) {
			std::cout << "Button Pressed";
		}
		ImGui::SameLine();
		if (ImGui::Button("Button##2")) {
			std::cout << "Button 2 Pressed";
		}
		ImGui::End();

		ImGui::Begin("TEST2");
		ImGui::Text("Slider");
		ImGui::Separator();
		ImGui::NewLine();
		static float a = 0;
		ImGui::SliderFloat("Slider", &a, 0, 1);
		ImGui::End();

		ImGui::Begin("Sample");
		ImGui::Text("Speed");
		ImGui::SameLine();
		ImGui::TextDisabled("(?)");

		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			ImGui::Text("Controls how fast the player moves.");
			ImGui::EndTooltip();
		}
		static char buffer[128] = "";

		ImGuiInputTextFlags flags =
			ImGuiInputTextFlags_CharsNoBlank |        // no spaces
			ImGuiInputTextFlags_EnterReturnsTrue |    // return true on Enter
			ImGuiInputTextFlags_AutoSelectAll;        // select all text when focused

		if (ImGui::InputText("Player Name", buffer, sizeof(buffer), flags))
		{
			std::cout << "Confirmed name: " << buffer << "\n";
		}
		ImGui::End();

		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			ImGui::Text("Controls how fast the player moves.");
			ImGui::EndTooltip();
		}

		DrawText("Window", 190, 200, 20, { 255, 0, 0, 127 });
		DrawRectangle(75, 75, 100, 100, { 255, 0, 0, 127 });
		DrawRectangle(50, 50, 100, 100, { 0, 255, 0, 127 });

		rlImGuiEnd();
		#pragma endregion

		EndDrawing();
	}

	rlImGuiShutdown();
	CloseWindow();

	return 0;
}