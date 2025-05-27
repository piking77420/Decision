#pragma once
#include <array>
#include <vector>

#include "Component/ComponentHeader.h"

constexpr size_t MAX_ENTITIES = 1000;

struct LevelData
{
	std::vector<Transfrom> transforms;
	std::vector<Controller> controllers;
	std::vector<Actor> actors;
	size_t entityCount;
};

class Level
{
public:
	bool hasInit;

	LevelData levelData;

	Level();

	~Level() = default;

private:
};

