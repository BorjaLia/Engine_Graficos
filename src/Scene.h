#pragma once

#include "Core.h"

#include "Entity.h"

#include <concepts>

/// The class that handles the entity list
/// @ingroup Scenes

namespace engine
{
	class ENGINE_API Scene
	{
	protected:

		static int sceneCount;

	public:

		Scene()
		{
			id = sceneCount;
			sceneCount++;
		}

		int GetId() { return id; };

		std::string GetName() { return name; };
		void SetName(std::string name) { this->name = name; };

		template <std::derived_from<Entity> T, typename... Args>
		T* CreateEntity(Args&&... args);

		virtual void Setup() = 0;

	private:
		friend class SceneManager;

		void Start();
		void Shutdown();

		int id;
		std::string name;

		std::vector<Entity*> entities;
	};

	template<std::derived_from<Entity> T, typename ...Args>
	T* Scene::CreateEntity(Args && ...args)
	{
		T* entity = new T(std::forward<Args>(args)...);

		entities.push_back(entity);

		return entity;
	}
}