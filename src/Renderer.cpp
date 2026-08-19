#include "Renderer.h"

engine::Renderer::Renderer()
{
}

engine::Renderer::~Renderer()
{
}

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