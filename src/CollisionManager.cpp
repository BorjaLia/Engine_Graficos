#include "CollisionManager.h"

bool engine::CollisionManager::IsCollidingAABB(Entity2D* a, Entity2D* b)
{
	Bounds ab = a->GetBounds();
	ab.max += a->GetPosition();
	ab.min += a->GetPosition();
	Bounds bb = b->GetBounds();
	bb.max += b->GetPosition();
	bb.min += b->GetPosition();

	return 
		ab.max.x >= bb.min.x && ab.min.x <= bb.max.x &&
		ab.max.y >= bb.min.y && ab.min.y <= bb.max.y &&
		ab.max.z >= bb.min.z && ab.min.z <= bb.max.z;
}
