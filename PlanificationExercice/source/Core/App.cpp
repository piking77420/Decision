#include "App.h"
#include <raylib.h>

#include "System/RenderSystem.h"


App::App()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GOAP");

    m_System.push_back(std::make_unique<ControllerSystem>());
    m_System.push_back(std::make_unique<RenderSystem>());
    LevelData& data = level.levelData;

    InitVillager(data, data.entityCount);
    
    for (auto& system : m_System)
            system->Init(data);
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);

        for (auto& system : m_System)
            system->Update(level.levelData);
        
        for (auto& system : m_System)
            system->Render(level.levelData);
        
        EndDrawing();
    }

    CloseWindow();
}

void App::InitVillager(LevelData& levelData)
{
    levelData.entityCount += 3;
    
    for (int i = 0; i < levelData.entityCount; i++)
    {
        levelData.actors[i] = {
            .actorType = ActorType::Villager
        };
    }
    
   
    levelData.transforms[0] = {
        .position = { 100, 100 }
    };

    levelData.transforms[1] = {
        .position = { 200, 200 }
    };

    levelData.transforms[1] = {
        .position = { 300, 300 }
    };
    
}

