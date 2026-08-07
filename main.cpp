#include <raylib.h>

int cellSize = 30;
int cellCount = 25;
Color lightBeige = { 198, 186, 172, 255 };
Color darkPurple = { 30, 28, 50, 255 };

class Food {

public:
    Vector2 position = {5, 6};

    Texture2D texture;

    Food()
    {
        Image image = LoadImage ("food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    }

    ~Food()
    {
        UnloadTexture(texture);
    }

    void Draw()
    {
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }

};

int main()
{
    
    InitWindow(cellSize*cellCount, cellSize*cellCount, "Retro Snake");
    SetTargetFPS(60);

    Food food = Food();
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(lightBeige);  
        food.Draw();

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}