#include "Window.h"


engine::Window::Window()
{

}

engine::Window::~Window()
{
}

int engine::Window::Initialize()
{
    if (!glfwInit())
        return -1;

    glfwWindow = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!glfwWindow)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(glfwWindow);

    return 1;
}

int engine::Window::Update()
{
    //CAMBIAR!!!!
    glfwSwapBuffers(glfwWindow);
    return 0;
}

int engine::Window::Shutdown()
{
    glfwTerminate();
    return 1;
}

int engine::Window::ShouldClose()
{
    return glfwWindowShouldClose(glfwWindow);
}