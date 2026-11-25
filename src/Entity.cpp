#include "Entity.h"

void* engine::Entity::operator new(std::size_t size)
{
	return ::operator new(size);
}

void engine::Entity::operator delete(void* ptr) noexcept
{
	::operator delete(ptr);
}

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