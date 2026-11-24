#pragma once

#include "Core.h"

#include "SceneBuilder.h"

#include "Entity.h"

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

		virtual void Build(SceneBuilder builder) = 0;

		void Start();

		int GetId() { return id; };

		std::string GetName() { return name; };
		void SetName(std::string name) { this->name = name; };

	private:
		friend class BaseGame;

		int id;
		std::string name;

		void Shutdown();
		std::vector<Entity*> entities;
	};
}