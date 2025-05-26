#pragma once
#include "Entity.h"

struct Controller
{
public:
    enum struct ControllerType
    {
        Ai,
        Player,
        Count,
    };
    ControllerType controllerType;

    entityId controlledEntityId;
};
