#include <raylib.h>
#include <gameMain.h>
#include <iostream>

bool initGame() {
    return true;
}

bool updateGame() {
    DrawText("Window", 190, 200, 20, { 255, 0, 0, 127 });
    DrawRectangle(75, 75, 100, 100, { 255, 0, 0, 127 });
    DrawRectangle(50, 50, 100, 100, { 0, 255, 0, 127 });
    return true;
}

void closeGame() {
    std::cout << "\n\nCLOSED!!!!!!!!!\n\n";
}