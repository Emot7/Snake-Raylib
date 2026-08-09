#include <raylib.h>
#include <deque>
#include <raymath.h>

int cellSize = 30;
int cellCount = 25;
Color lightBeige = { 198, 186, 172, 255 };
Color darkPurple = { 30, 28, 50, 255 };

double lastUpdateTime = 0;

bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

class Snake
{
    public :
        std::deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};

        Vector2 direction = {1,0};

        void Draw()
        {
            for(unsigned int i = 0; i < body.size(); i++)
            {
                float x = body[i].x;
                float y = body[i].y;
                Rectangle segment = Rectangle{(float)x * cellSize, (float)y * cellSize, (float)cellSize, (float)cellSize};
                DrawRectangleRounded(segment, 0.5, 6, darkPurple);
            }
        }
    
        void Update()
        {
            body.pop_back();
            body.push_front(Vector2Add(body[0], direction));
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

        if(eventTriggered(0.2))
        {
            snake.Update();
        }

        ClearBackground(lightBeige);  
        food.Draw();
        snake.Draw();

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}