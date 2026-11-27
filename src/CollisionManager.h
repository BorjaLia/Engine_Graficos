#pragma once
#include "Core.h"
#include "Entity2D.h"

#include <vector>

namespace engine
{
	class ENGINE_API CollisionManager
	{
	protected:

		CollisionManager() {}
		static CollisionManager* instance;

	public:

		CollisionManager(CollisionManager& other) = delete;
		void operator=(const CollisionManager&) = delete;

		static CollisionManager* Get();

		void Initialize(std::vector<Entity*>* entities);
		void Update();

		void SetEntities(std::vector<Entity*>* entities);

		bool IsCollidingEntity(Entity2D& a, Entity2D& b);
		bool IsCollidingAABB(Bounds& a, Bounds& b);
		bool IsPointInEntity(Entity2D& entity, math::Vector2 point);
		bool IsPointInAABB(Bounds bounds, math::Vector2 point);
	
		std::vector<Entity2D*>* entities = new std::vector<Entity2D*>();
	};
}