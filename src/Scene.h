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

	public:

		Scene(std::string name = "NO_NAME_SCENE");

		const int GetId() const { return this->id; };

		const std::string GetName() const { return name; };
		void SetName(std::string name) { this->name = name; };

		const std::vector<Entity*>& GetEntityVector() const { return entities; };

		template <std::derived_from<Entity> T, typename... Args>
		T* CreateEntity(Args&&... args);

		virtual void Setup() = 0;

	private:
		friend class SceneManager;

		void Start();
		void Shutdown();

		void SetId(int id) { this->id = id; }

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