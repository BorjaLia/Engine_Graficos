#pragma once

#include "Window.h"
#include "Renderer.h"

namespace engine
{
	class BaseGame
	{
	public:
		BaseGame();
		~BaseGame();

		void Run();

	private:

		bool isRunning = true;

		void Initialize();
		void Shutdown();

		Window window;
		Renderer* renderer = Renderer::Get();
	};
}