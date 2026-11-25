#pragma once

#include "Core.h"

#include "Scene.h"

#include <concepts>
#include <vector>

/// The class that manages the scenes
/// @ingroup Scenes

namespace engine
{
	class ENGINE_API SceneManager
	{
		SceneManager() {}

		static SceneManager* instance;

	public:

		SceneManager(SceneManager& other) = delete;
		void operator=(const SceneManager&) = delete;

		static SceneManager* Get();

		void Initialize();

		void Update(std::vector<Entity*>& entities);

		void Shutdown();

		void RegisterScene(Scene* scene);

		void LoadScene(int index);

	private:

		Scene* queuedScene = nullptr;
		Scene* currentScene = nullptr;

		std::vector<Scene*> scenes;
	};
}