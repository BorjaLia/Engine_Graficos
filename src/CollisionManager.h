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
	};
}