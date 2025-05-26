#pragma once

#include <cstdint>

#include <raylib.h>

using entityId = uint32_t;

enum struct EntityType
{
    Villager,
    Soldier,

    Farm,
    Furnace,
};

struct Entity
{
    EntityType entityType;
    Vector2 position;
};
