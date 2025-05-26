#include "level.h"

Level::Level()
{

    levelData.entities[0] = { { 0, 0 } };
    levelData.entities[1] = { { 100, 100 } };
    levelData.entities[2] = { { 200, 200 } };
    levelData.entities[3] = { { -200, 200 } };

    int cindex = 0;
    for (auto& c : levelData.controller)
    {
        c.controllerType = Controller::ControllerType::Ai;
        c.controlledEntityId = cindex++;
    }
}