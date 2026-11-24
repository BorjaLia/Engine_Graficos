#include "Scene.h"

int engine::Scene::sceneCount = 0;

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
