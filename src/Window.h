#pragma once

#include <GL/glew.h>

#include <GLFW/glfw3.h>

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

		inline GLFWwindow& GetGlfwWindow() { return *glfwWindow; };

	private:

		GLFWwindow* glfwWindow = nullptr;
	};
}