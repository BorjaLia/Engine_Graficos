#pragma once

#include "Window.h"

#include "Core.h"

#include "Keycodes.h"

#include "Vector2.h"

/// The class that handles the Input
/// @ingroup Input

namespace engine
{
	class ENGINE_API Input
	{
	protected:

		Input() {}

		static Input* instance;

		Window* window = nullptr;

	public:

		Input(Input& other) = delete;
		void operator=(const Input&) = delete;

		static Input* Get();

		int Initialize(Window& window);
		void Update();
		int Shutdown();


		math::Vector2 GetMousePosition();

		bool IsMouseButtonPressed(MouseCode button);
		bool IsKeyPressed(KeyCode key);

	private:

	};
}