#pragma once

#include "Window.h"

#include "Keycodes.h"

/// The class that handles the Input
/// @ingroup Input


namespace engine
{
	class Input
	{
	public:
		Input();
		~Input();

		static Input* Get();

		int Initialize(Window* newWindow);
		void Update();
		int Shutdown();

		bool IsKeyPressed(KeyCode key);

	private:

		static Input* instance;

		Window* window;
	};
}