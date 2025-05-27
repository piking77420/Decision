#include "RenderSystem.h"

#include "Core/App.h"

void RenderSystem::Init(LevelData& level)
{
}

void RenderSystem::Update(LevelData& level)
{
}

void RenderSystem::Render(const LevelData& level)
{
	
	for (int i = 0; i < level.entityCount; i++)
	{
		const Actor* npc = &level.actors[i];
		Vector2 pos = level.transforms[i].position;
		
		switch (npc->actorType)
		{
		case ActorType::Villager : 
			DrawCircle(static_cast<int>(pos.x) + offsetX,
				static_cast<int>(pos.y) + offsetY,
				10, GREEN);
			break;
		case ActorType::Soldier:
			break;
		default:
			break;
		}
	}
}


