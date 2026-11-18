#include "CollisionManager.h"

bool engine::CollisionManager::isCollidingAABB(Entity2D a, Entity2D b)
{
	Bounds ab = a.getBounds();
	Bounds bb = b.getBounds();

	return 
		ab.max.x >= bb.min.x && ab.min.x <= bb.max.x &&
		ab.max.y >= bb.min.y && ab.min.y <= bb.max.y &&
		ab.max.z >= bb.min.z && ab.min.z <= bb.max.z;
}
