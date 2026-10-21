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

		int Initialize();
		void Update();
		int Shutdown();

		bool IsKeyDown(KeyCode key);
		bool IsKeyPressed(KeyCode key);

	private:

		Window window;

	};
}