#include <raylib.h>
#include <deque>

int cellSize = 30;
int cellCount = 25;
Color lightBeige = { 198, 186, 172, 255 };
Color darkPurple = { 30, 28, 50, 255 };

class Snake
{
    public :
        std::deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};

        void Draw()
        {
            for(int i = 0; i < body.size(); i++)
            {
                int x = body[i].x;
                int y = body[i].y;
                DrawRectangle(x*cellSize, y*cellSize, cellSize, cellSize, darkPurple);
            }
        }
};

class Food {

public:
    Vector2 position;

    Texture2D texture;

    Food()
    {
        Image image = LoadImage ("food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        position = GenerateRandomPos();
    }

    ~Food()
    {
        UnloadTexture(texture);
    }

    void Draw()
    {
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }

    Vector2 GenerateRandomPos()
    {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return Vector2{x, y};
    }
};

int main()
{
    
    InitWindow(cellSize*cellCount, cellSize*cellCount, "Retro Snake");
    SetTargetFPS(60);

    Food food = Food();
    Snake snake = Snake();
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(lightBeige);  
        food.Draw();
        snake.Draw();

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}