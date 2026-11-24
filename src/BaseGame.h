#pragma once

#include <vector>

#include "Core.h"
#include "Window.h"
#include "Renderer.h"
#include "Input.h"
#include "Entity.h"
#include "Scene.h"
#include "CollisionManager.h"

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

		//virtual void Start() = 0;

		//void AddEntity(Entity* entity);

		void LoadScene(Scene* scene);

	private:

		bool isRunning = true;

		void Initialize();
		void Shutdown();

		void UpdateLoadScene();

		Window window;
		Renderer* renderer = Renderer::Get();
		Input* input = Input::Get();

		Scene* queuedScene = nullptr;
		Scene* currentScene = nullptr;

		std::vector<Entity*> entities;

	protected:

		CollisionManager collisions;
	};
}