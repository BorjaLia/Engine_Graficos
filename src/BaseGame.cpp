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
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);


		//ESTO NO VA ACA
		window.Update();
		/* Swap front and back buffers */
		//glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		isRunning = !window.ShouldClose();
	}

	Shutdown();
}

void engine::BaseGame::Initialize()
{
	window.Initialize();


}

void engine::BaseGame::Shutdown()
{
	window.Shutdown();
}
