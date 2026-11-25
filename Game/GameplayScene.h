#pragma once

#include "Scene.h"

	class GameplayScene : public engine::Scene
	{
	public:
		using Scene::Scene;

		void Setup() override;
	};
