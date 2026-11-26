#include "CollisionManager.h"

engine::CollisionManager* engine::CollisionManager::instance = nullptr;

engine::CollisionManager* engine::CollisionManager::Get()
{
	if (instance == nullptr)
	{
		instance = new engine::CollisionManager();
	}
	return instance;
}


void engine::CollisionManager::Start()
{

}

void engine::CollisionManager::Update()
{

}

bool engine::CollisionManager::IsCollidingEntity(Entity2D& a, Entity2D& b)
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
bool engine::CollisionManager::IsCollidingAABB(Bounds& a, Bounds& b)
{

}

bool engine::CollisionManager::IsPointInEntity(Entity2D& entity, math::Vector2 point)
{
	return IsPointInEntity(entity.GetPosition(),entity.GetBounds(),point);
}


bool engine::CollisionManager::IsPointInAABB(Bounds bounds, math::Vector2 point)
{
	math::Vector2 localPoint = point;
	localPoint.x -= pos.x;
	localPoint.y -= pos.y;

	bool horizontal = (bounds.min.x <= localPoint.x && bounds.max.x >= localPoint.x);
	bool vertical = (bounds.min.y <= localPoint.y && bounds.max.y >= localPoint.y);
	
	return (horizontal && vertical);
}