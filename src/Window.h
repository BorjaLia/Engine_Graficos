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
		void Update();
		int Shutdown();

		int ShouldClose();

		inline GLFWwindow& GetGlfwWindow() { return *glfwWindow; };

	private:

		GLFWwindow* glfwWindow;
	};
}