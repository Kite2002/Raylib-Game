#include <iostream>
#include <raylib.h>

int main()
{
	std::cout << "Hello\n";

	SetTargetFPS(60);

	InitWindow(800, 450, "game");

	int posX = 30;
	int posY = 30;
	int size = 100;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Window", 190, 200, 20, RED);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}