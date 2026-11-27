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

void engine::CollisionManager::Initialize(std::vector<engine::Entity*>* entities)
{
}

void engine::CollisionManager::Update()
{
	if (entities == nullptr) return;
	if (entities->size() == 0) return;

	for (int i = 0; i < entities->size() - 1; i++)
	{
		Entity2D& a = *(*entities)[i];

		for (int j = i + 1; i < entities->size(); i++)
		{
			Entity2D& b = *(*entities)[j];

			if (IsCollidingEntity(a,b))
			{
				a.OnCollision(&b);
				b.OnCollision(&a);
			}
		}
	}
}

void engine::CollisionManager::SetEntities(std::vector<Entity*>* entities)
{		
	this->entities->clear();

	for (Entity* e : *entities)
	{
		Entity2D* e2D = dynamic_cast<Entity2D*>(e);
		if (e2D != nullptr)
		{
			this->entities->push_back(e2D);
		}
	}
}

bool engine::CollisionManager::IsCollidingEntity(Entity2D& a, Entity2D& b)
{
	Bounds ab = a.GetBounds();
	Bounds bb = b.GetBounds();

	math::Vector3 posA = a.GetPosition();
	math::Vector3 posB = b.GetPosition();

	ab.min += posA;
	ab.max += posA;
	bb.min += posB;
	bb.max += posB;

	return IsCollidingAABB(ab, bb);
}

bool engine::CollisionManager::IsCollidingAABB(Bounds& a, Bounds& b)
{
	return
		a.max.x >= b.min.x && a.min.x <= b.max.x &&
		a.max.y >= b.min.y && a.min.y <= b.max.y &&
		a.max.z >= b.min.z && a.min.z <= b.max.z;
}

bool engine::CollisionManager::IsPointInEntity(Entity2D& entity, math::Vector2 point)
{
	math::Vector2& localPoint = point;

	localPoint.x -= entity.GetPosition().x;
	localPoint.y -= entity.GetPosition().y;

	return IsPointInAABB(entity.GetBounds(), point);
}


bool engine::CollisionManager::IsPointInAABB(Bounds bounds, math::Vector2 point)
{
	bool horizontal = (bounds.min.x <= point.x && bounds.max.x >= point.x);
	bool vertical = (bounds.min.y <= point.y && bounds.max.y >= point.y);

	return (horizontal && vertical);
}