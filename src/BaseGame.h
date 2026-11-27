#pragma once

#include <vector>

#include "Core.h"
#include "Window.h"
#include "Renderer.h"
#include "Input.h"
#include "Entity.h"
#include "SceneManager.h"
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

		virtual void SetupScenes() = 0;

	private:

		bool isRunning = true;

		void Initialize();
		void Shutdown();

		Window window;
		Renderer* renderer = Renderer::Get();
		Input* input = Input::Get();
		SceneManager* sceneManager = SceneManager::Get();
		CollisionManager* collisionManager = CollisionManager::Get();

		Scene* currentScene = nullptr;

		std::vector<Entity*> entities;

	protected:

		CollisionManager* collisions = CollisionManager::Get();
	};
}