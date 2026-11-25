#include "Scene.h"

int engine::Scene::sceneCount = 0;

void engine::Scene::Start()
{
	std::cout << "Starting scene" << std::endl;

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
	std::cout << "Shutdown scene" << std::endl;

	for (Entity* e : entities)
	{
		delete e;
	}

	entities.clear();
}
