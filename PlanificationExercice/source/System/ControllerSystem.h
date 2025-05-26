#pragma once

#include "System.h"

class ControllerSystem : public System
{
public:
	// Inherited via System
	void Init(LevelData& level) override;

	void Update(LevelData& level) override;

};

