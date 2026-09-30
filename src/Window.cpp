#include "Window.h"


engine::Window::Window()
{
}

engine::Window::~Window()
{
}

int engine::Window::Initialize()
{
    if (!glfwInit()) return 1;

    glfwWindow = glfwCreateWindow(1200, 800, "Game Engine", NULL, NULL);

    if (!glfwWindow)
    {
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(glfwWindow);

    if (glewInit() != GLEW_OK)
    {
        return -1;
    }

    return 0;
}

void engine::Window::Update()
{
    /* Poll for and process events */
    glfwPollEvents();
}

int engine::Window::Shutdown()
{
    glfwTerminate();
    return 0;
}

int engine::Window::ShouldClose()
{
    return glfwWindowShouldClose(glfwWindow);
}