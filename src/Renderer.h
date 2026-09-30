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

		Window* window = nullptr;

	public:

        Renderer(Renderer& other) = delete;
        void operator=(const Renderer&) = delete;

        static Renderer* Get();

		int Initialize(Window& window);
		void Update();
		void Draw(int vertexCount, int glDrawType = GL_POLYGON);
		int Shutdown();


	private:


	};
}