#include "Input.h"

#include <GLFW/glfw3.h>

engine::Input::Input()
{
}

engine::Input::~Input()
{
}

int engine::Input::Initialize()
{
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
    int state = glfwGetKey(&window.GetGlfwWindow(), static_cast<int>(key));
    return state == GLFW_PRESS;
}