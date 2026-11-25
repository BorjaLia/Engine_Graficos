#pragma once
#include "Core.h"
#include <Entity2D.h>

namespace engine
{
	class ENGINE_API CollisionManager
	{
	protected:

		CollisionManager() {}

		static Input* instance;

	public:

		CollisionManager(CollisionManager& other) = delete;
		void operator=(const CollisionManager&) = delete;

		static CollisionManager* Get();

		bool IsCollidingAABB(Entity2D& a, Entity2D& b);
		bool IsPointInAABB(Entity2D& entity, math::Vector2 point);
		bool IsPointInAABB(math::Vector2 pos, Bounds bounds, math::Vector2 point);
	};
}