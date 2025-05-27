#pragma once

#include <array>
#include <memory>
#include <vector>

#include "Level.h"
#include "System/ControllerSystem.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 1024;
const int offsetX = SCREEN_WIDTH / 2;
const int offsetY = SCREEN_HEIGHT / 2;

class App
{
public:
    App();

private:

    Level level;
    
    std::vector<std::unique_ptr<System>> m_System;

    static void InitVillager(LevelData& levelData);
    
};
