#include "ControllerSystem.h"
#include "Core/Level.h"



void ControllerSystem::Init(LevelData& level)
{
    int cindex = 0;
    for (auto& c : level.controllers)
    {
        c.controllerType = Controller::ControllerType::Ai;
        c.entityControlledId = cindex++;
    }
}

void ControllerSystem::Update(LevelData& level)
{
    
}
