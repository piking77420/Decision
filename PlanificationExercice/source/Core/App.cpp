#include "App.h"
#include <raylib.h>



App::App()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GOAP");

    controllerSystem.Init(level.levelData);
    LevelData& data = level.levelData;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);

        controllerSystem.Update(data);

        DrawEntitySystem();

        EndDrawing();
    }

    CloseWindow();
}

void App::DrawEntitySystem()
{
    
}

void App::ControllerSystem()
{
    
}
