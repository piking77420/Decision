#include "level.h"

Level::Level()
{
    levelData.actors.resize(MAX_ENTITIES);
    levelData.controllers.resize(MAX_ENTITIES);
}

