#pragma once

#include "Window.h"

namespace engine
{
	/// The class that draws to the screen
	/// @ingroup Rnderer

	class Renderer
	{
	protected:

		Renderer(){}

		static Renderer* instance;

		Window* window;

	public:

        Renderer(Renderer& other) = delete;
        void operator=(const Renderer&) = delete;

        static Renderer* Get();

		int Initialize(Window& window);
		void Update();
		int Shutdown();

	private:


	};
}