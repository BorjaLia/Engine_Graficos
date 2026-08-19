#pragma once

#include <GLFW/glfw3.h>

namespace engine
{
	class Window
	{
	public:
		Window();
		~Window();

		int Initialize();
		int Update();
		int Shutdown();

		int ShouldClose();

		inline GLFWwindow& GetWindow() { return *glfwWindow; };

	private:

		GLFWwindow* glfwWindow;
	};
}