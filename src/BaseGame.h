#pragma once

#include <vector>

#include "Window.h"
#include "Renderer.h"
#include "Entity.h"

namespace engine
{
	/// The base class for the game
	///
	/// Has the main loop
	/// @ingroup Game

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

		void AddEntity(Entity* entity);

		Window window;
		Renderer* renderer = Renderer::Get();

		std::vector<Entity*> entities;
	};
}