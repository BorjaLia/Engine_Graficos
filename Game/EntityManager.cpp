#include "EntityManager.h"
#include "CollisionManager.h"

void EntityManager::Update()
{
	for (int i = 0; i < entities.capacity(); i++)
	{
		if (entities[i])
		{
			for (int j = i + 1; j < entities.capacity(); j++)
			{
				if (entities[j])
				{
					if (engine::CollisionManager::IsCollidingAABB(*entities[i], *entities[j]))
						std::cout << "Collision!";
					else
						std::cout << "NO ";
				}
			}
		}
	}
}

void EntityManager::AddEntity2D(engine::Entity2D* entity)
{
	entities.push_back(entity);
}
