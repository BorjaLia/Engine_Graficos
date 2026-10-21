#include "Input.h"

#include <GLFW/glfw3.h>

engine::Input::Input()
{
}

engine::Input::~Input()
{
}

engine::Input* engine::Input::instance = nullptr;;

engine::Input* engine::Input::Get()
{
    if (instance == nullptr)
    {
        instance = new engine::Input();
    }
    return instance;
}

int engine::Input::Initialize(Window* newWindow)
{
    window = newWindow;
    return 0;
}

void engine::Input::Update()
{
    /* Poll for and process events */
    glfwPollEvents();
}

int engine::Input::Shutdown()
{
    return 0;
}

bool engine::Input::IsKeyPressed(KeyCode key)
{
    int state = glfwGetKey(&window->GetGlfwWindow(), static_cast<int>(key));
    return state == GLFW_PRESS;
}
