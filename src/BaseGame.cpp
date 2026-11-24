#include "BaseGame.h"

#include "Entity.h"
#include "Shape.h"

engine::BaseGame::BaseGame()
{
}

engine::BaseGame::~BaseGame()
{
}

void engine::BaseGame::Run()
{
	Initialize();

	//for (Entity* e : *entities)
	//{
	//	e->Start();
	//}

	while (isRunning)
	{
		window.Update();
		input->Update();
		renderer->Update();

		for (Entity* e : *entities)
		{
			e->Update();
		}

		for (Entity* e : *entities)
		{
			e->Draw();
		}

		UpdateLoadScene();

		isRunning = !window.ShouldClose();
	}

	Shutdown();
}

void engine::BaseGame::Initialize()
{
	window.Initialize();
	input->Initialize(window);
	renderer->Initialize(window);

	currentScene->Start();
	//Start();

	//for (Entity* e : *entities)
	//{
	//	e->Initialize();
	//}
}

void engine::BaseGame::Shutdown()
{
	currentScene->Shutdown();

	input->Shutdown();
	window.Shutdown();
}

void engine::BaseGame::LoadScene(Scene* scene)
{
	queuedScene = scene;
}

void engine::BaseGame::UpdateLoadScene()
{
	if (queuedScene == nullptr) return;

	currentScene->Shutdown();

	currentScene = queuedScene;
	queuedScene = nullptr;

	entities = &(currentScene->entities);

	currentScene->Start();
}

//void engine::BaseGame::AddEntity(Entity* entity)
//{
//	entities.push_back(entity);
//}