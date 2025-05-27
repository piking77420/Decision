#pragma once

#include "System.h"
#include "Ai/Planer.h"

class ControllerSystem : public System
{
public:

	ControllerSystem() = default;

	~ControllerSystem() = default;
	
	// Inherited via System
	void Init(LevelData& level) override;

	void Update(LevelData& level) override;
private:
	Planer m_Planer;
};

