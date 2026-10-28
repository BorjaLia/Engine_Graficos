#pragma once

#include "GLFunctions.h"

#include "Vector2.h"

namespace engine
{
	/// The class that handles the glfw Window
	/// @ingroup Window
	
	class Window
	{
	public:
		Window();
		~Window();

		int Initialize();
		void Update();
		int Shutdown();

		int ShouldClose();

		math::Vector2 GetSize() { return size; };

		inline GLFWwindow& GetGlfwWindow() { return *glfwWindow; };

	private:

		static void FramebufferResizeCallback(GLFWwindow* glfwWindow, int width, int height);

		GLFWwindow* glfwWindow = nullptr;

		math::Vector2 size;
	};
}