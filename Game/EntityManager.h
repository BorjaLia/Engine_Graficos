#pragma once
#include "Entity2D.h"

class EntityManager
{
private:

	static std::vector<engine::Entity2D*> entities;

public:

	static void Update();

	static void AddEntity2D(engine::Entity2D* entity);
};