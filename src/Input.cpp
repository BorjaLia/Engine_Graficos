#include "Input.h"

#include <GLFW/glfw3.h>

engine::Input* engine::Input::instance = nullptr;

engine::Input* engine::Input::Get()
{
    if (instance == nullptr)
    {
        instance = new engine::Input();
    }
    return instance;
}

int engine::Input::Initialize(Window& window)
{
    this->window = &window;
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

math::Vector2 engine::Input::GetMousePosition()
{
    double xpos, ypos;
    glfwGetCursorPos(&window->GetGlfwWindow(), &xpos, &ypos);

    return math::Vector2(static_cast<float>(xpos), static_cast<float>(ypos));
}

bool engine::Input::IsMouseButtonPressed(MouseCode button)
{
    int state = glfwGetMouseButton(&window->GetGlfwWindow(), static_cast<int>(button));
    return state == GLFW_PRESS;
}

bool engine::Input::IsKeyPressed(KeyCode key)
{
    int state = glfwGetKey(&window->GetGlfwWindow(), static_cast<int>(key));
    return state == GLFW_PRESS;
}
