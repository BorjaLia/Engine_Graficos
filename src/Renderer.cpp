#include "Renderer.h"

int engine::Renderer::Initialize(Window& window)
{
	this->window = &window;
	return 0;
}

void engine::Renderer::Update()
{
	glClear(GL_COLOR_BUFFER_BIT);


	glfwSwapBuffers(&(window->GetGlfwWindow()));
}

int engine::Renderer::Shutdown()
{
	return 0;
}


engine::Renderer* engine::Renderer::instance = nullptr;;


engine::Renderer* engine::Renderer::Get()
{
    if (instance == nullptr)
    {
        instance = new engine::Renderer();
    }
    return instance;
}