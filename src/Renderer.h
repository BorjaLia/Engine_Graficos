#pragma once

#include "Window.h"

namespace engine
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		int Initialize(Window& window);
		void Update();
		int Shutdown();

	private:

		Window* window;

	};
}