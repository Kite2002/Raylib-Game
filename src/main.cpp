#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

int main()
{
	std::cout << "Hello\n";

	SetTargetFPS(60);

	InitWindow(800, 450, "game");
	rlImGuiSetup(true);

	int posX = 30;
	int posY = 30;
	int size = 100;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		rlImGuiBegin();
		ImGui::ShowDemoWindow();
		DrawText("Window", 190, 200, 20, {255, 0, 0, 127});
		DrawRectangle(75, 75, 100, 100, {255, 0, 0, 127});
		DrawRectangle(50, 50, 100, 100, {0, 255, 0, 127});

		rlImGuiEnd();
		EndDrawing();
	}

	rlImGuiShutdown();
	CloseWindow();

	return 0;
}