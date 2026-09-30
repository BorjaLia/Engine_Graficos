#pragma once

#include <vector>

#include "Core.h"
#include "Window.h"
#include "Renderer.h"
#include "Entity.h"

namespace engine
{
	/// The base class for the game
	///
	/// Has the main loop
	/// @ingroup Game

	class ENGINE_API BaseGame
	{
	public:
		BaseGame();
		~BaseGame();

		void Run();

		virtual void Start() = 0;

		void AddEntity(Entity* entity);

	private:

		bool isRunning = true;

		void Initialize();
		void Shutdown();

		Window window;
		Renderer* renderer = Renderer::Get();

		std::vector<Entity*> entities;
	};
}