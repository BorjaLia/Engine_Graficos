#include "BaseGame.h"

engine::BaseGame::BaseGame()
{
}

engine::BaseGame::~BaseGame()
{
}

void engine::BaseGame::Run()
{
	Initialize();

	while (isRunning)
	{
		renderer->Update();

		/* Poll for and process events */
		glfwPollEvents();

		isRunning = !window.ShouldClose();
	}

	Shutdown();
}

void engine::BaseGame::Initialize()
{
	window.Initialize();
	//renderer = Renderer::Get();
	renderer->Initialize(window);
}

void engine::BaseGame::Shutdown()
{
	window.Shutdown();
}
