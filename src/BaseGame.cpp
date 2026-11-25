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
	SetupScenes();

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

		for (Entity* e : entities)
		{
			e->Update();
		}

		for (Entity* e : entities)
		{
			e->Draw();
		}

		sceneManager->Update(entities);

		isRunning = !window.ShouldClose();
	}

	Shutdown();
}

void engine::BaseGame::Initialize()
{


	window.Initialize();
	input->Initialize(window);
	renderer->Initialize(window);
	sceneManager->Initialize();

	//currentScene->Start();
	
	//Start();

	//for (Entity* e : *entities)
	//{
	//	e->Initialize();
	//}
}

void engine::BaseGame::Shutdown()
{

	sceneManager->Shutdown();
	input->Shutdown();
	window.Shutdown();
}

//void engine::BaseGame::AddEntity(Entity* entity)
//{
//	entities.push_back(entity);
//}