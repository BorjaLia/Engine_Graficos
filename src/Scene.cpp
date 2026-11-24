#include "Scene.h"

int engine::Scene::sceneCount = 0;

template<std::derived_from<engine::Entity> T, typename ...Args>
T* engine::Scene::CreateEntity(Args && ...args)
{
	T* entity = new T(std::forward<Args>(args)...);

	entities.push(entity);

	return entity;
}

void engine::Scene::Start()
{
	for (Entity* e : entities)
	{
		e->Initialize();
	}

	for (Entity* e : entities)
	{
		e->Start();
	}
}

void engine::Scene::Shutdown()
{
	for (Entity* e : entities)
	{
		e->~Entity();
	}
}
