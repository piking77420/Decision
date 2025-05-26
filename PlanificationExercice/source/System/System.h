#pragma once

#include "Core/Level.h"

class System
{
public:
	virtual void Init(LevelData& level) = 0;

	virtual void Update(LevelData& level) = 0;

	virtual void Render(const LevelData& level)
	{

	};

	System() = default;

	virtual ~System() = default;
};

