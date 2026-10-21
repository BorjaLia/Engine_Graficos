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

    size = math::Vector2(1200, 1200);

    glfwWindow = glfwCreateWindow(size.x,size.y, "Game Engine", NULL, NULL);

    if (!glfwWindow)
    {
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(glfwWindow);

    glfwSetWindowUserPointer(glfwWindow, this);

    glfwSetFramebufferSizeCallback(glfwWindow, FramebufferResizeCallback);

    if (glewInit() != GLEW_OK)
    {
        return -1;
    }

    glfwSwapInterval(1); // VSYNC

    return 0;
}

void engine::Window::Update()
{

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

void engine::Window::FramebufferResizeCallback(GLFWwindow* glfwWindow, int width, int height)
{
    Window* windowInstance = static_cast<Window*>(glfwGetWindowUserPointer(glfwWindow));

    if (windowInstance)
    {
        windowInstance->size.x = static_cast<float>(width);
        windowInstance->size.y = static_cast<float>(height);
    }

    glViewport(0, 0, width, height);
}