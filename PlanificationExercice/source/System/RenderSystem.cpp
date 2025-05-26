#include "RenderSystem.h"

#include "Core/App.h"

void RenderSystem::Init(LevelData& level)
{
}

void RenderSystem::Update(LevelData& level)
{
}

void RenderSystem::Renderer(const LevelData& level)
{
	
	
		

	for (auto& entity : level.entities)
	{
		switch (entity.entityType)
		{
		case EntityType::Villager : 
			DrawCircle(static_cast<int>(entity.position.x) + offsetX,
				static_cast<int>(entity.position.y) + offsetY,
				10, GREEN);
			break;
		default:
			break;
		}
	}


}
