#pragma once

#define GLAD_GL_IMPLEMENTATION

#include <glad/glad.h>

//#define GLFW_INCLUDE_NONE

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

		GLFWwindow* glfwWindow;
	};
}