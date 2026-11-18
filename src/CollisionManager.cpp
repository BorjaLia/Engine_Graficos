#include "CollisionManager.h"

bool engine::CollisionManager::IsCollidingAABB(Entity2D& a, Entity2D& b)
{
	Bounds ab = a.GetBounds();
	Bounds bb = b.GetBounds();

	math::Vector3 posA = a.GetPosition();
	math::Vector3 posB = b.GetPosition();

	return 
		ab.max.x + posA.x >= bb.min.x + posB.x && ab.min.x + posA.x <= bb.max.x + posB.x &&
		ab.max.y + posA.y >= bb.min.y + posB.y && ab.min.y + posA.y <= bb.max.y + posB.y &&
		ab.max.z + posA.z >= bb.min.z + posB.z && ab.min.z + posA.z <= bb.max.z + posB.z;
}
