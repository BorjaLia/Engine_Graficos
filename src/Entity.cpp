#include "Entity.h"

engine::Entity::Entity()
{
	position = math::Vector3(0.0f, 0.0f, 0.0f);
	rotation = math::Vector3(0.0f, 1.0f, 0.0f);
	scale = math::Vector3(1.0f, 1.0f, 1.0f);
}

engine::Entity::~Entity()
{
}

void engine::Entity::Initialize()
{
}

