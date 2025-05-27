#pragma once

#include <raylib.h>

using EntityId = uint32_t;

enum struct ComponentType
{
    Transform,
    Controller,
    NPC,

    Count
};

constexpr const char* ComponentTypeNames[] = { "Transform", "Controller", "NPC" };

struct Transfrom
{
    Vector2 position;
    Vector2 scale;
    float rotation;
};

struct Controller
{
    enum struct ControllerType
    {
        Ai,
        Player,
        Count,
    };
    
    ControllerType controllerType;
    EntityId entityControlledId;
};


enum struct ActorType
{
    Villager,
    Soldier,
};

struct Actor
{
    ActorType actorType; 
};