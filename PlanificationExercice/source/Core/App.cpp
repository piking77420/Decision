#include "App.h"

#include <raylib.h>

App::App()
{
    InitWindow(1280, 1024, "GOAP");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(GRAY);
        
        EndDrawing();
    }
}
