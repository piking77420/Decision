#pragma once

#include "System.h"

class RenderSystem : public System
{
public:

	// Inherited via System
	void Init(LevelData& level) override;

	void Update(LevelData& level) override;

	void Render(const LevelData& level) override;
};

