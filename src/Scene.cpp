#include "Scene.h"

engine::Scene::Scene(std::string name)
{
	this->name = name;
	id = -1;
}

void engine::Scene::Start()
{
	if (id == -1)
	{
		std::cout << "Scene has not been registered!" << std::endl;
		std::cout << "Aborting Start" << std::endl;
		return;
	}
	std::cout << "Starting scene "<< name << std::endl;

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
	std::cout << "Shutdown scene " << name << std::endl;

	for (Entity* e : entities)
	{
		delete e;
	}

	entities.clear();
}
