#pragma once
#include <array>

#include "Entity.h"

class App
{
public:
    App();
    
private:

    std::array<Entity, 4> entities;
};
