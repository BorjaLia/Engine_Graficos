#include "Scene.h"

int engine::Scene::sceneCount = 0;

void engine::Scene::BuildScene()
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

void engine::Scene::UnloadScene()
{
	for (Entity* e : entities)
	{
		e->~Entity();
	}
}
