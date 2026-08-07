#include <raylib.h>

int main()
{
    InitWindow(750, 750, "Retro Snake");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLUE);
        DrawRectangle(100, 100, 200, 200, RED);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
