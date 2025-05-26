#pragma once
#include <array>

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

    ControllerSystem controllerSystem;
   
    void DrawEntitySystem();

    void ControllerSystem();
};
