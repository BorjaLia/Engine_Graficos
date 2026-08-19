#include "Renderer.h"

int engine::Renderer::Initialize(Window& window)
{
	this->window = &window;
	return 0;
}

void engine::Renderer::Update()
{
	glClear(GL_COLOR_BUFFER_BIT);


	glBegin(GL_TRIANGLES);

	glVertex2f(-0.5f,-0.5f);
	glVertex2f(0.0f,0.5f);
	glVertex2f(0.5f,-0.5f);

	glEnd();

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