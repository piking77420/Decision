#pragma once
#include <array>
#include "Controller.h"
#include "Entity.h"

struct LevelData
{
	std::array<Entity, 4> entities;
	std::array<Controller, 4> controller;
};

class Level
{
public:
	bool hasInit;

	LevelData levelData;

	Level();

	~Level() = default;
};

