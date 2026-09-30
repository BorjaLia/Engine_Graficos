#pragma once

#include "Window.h"

#include <glm/glm.hpp>

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
		void Draw(int indexCount, int glDrawType = GL_POLYGON);
		int Shutdown();

		glm::mat4 getMPVMat4x4() const { return mvp; };
		glm::mat4 getProjectionMat4x4() const { return proj; };
		glm::mat4 getViewMat4x4() const { return view; };


	private:


		glm::mat4 proj;
		glm::mat4 view;
		glm::mat4 model;
		glm::mat4 mvp;

	};
}