#pragma once
#include "Core.h"
#include <Entity2D.h>

namespace engine
{
	class ENGINE_API CollisionManager
	{
	private:

	public:

		bool IsCollidingAABB(Entity2D& a, Entity2D& b);
		bool IsPointInAABB(Entity2D& entity, math::Vector2 point);
		bool IsPointInAABB(math::Vector2 pos, Bounds bounds, math::Vector2 point);
	};
}