#include "Renderer.h"

int engine::Renderer::Initialize(Window& window)
{
	this->window = &window;
	return 0;
}

void engine::Renderer::Update()
{

	float positions[6] = {
		-0.5f,-0.5f,
		0.0f,0.5f,
		0.5f,-0.5f
	};

	unsigned int buffer;
	

	glGenBuffers(1,&buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER,6 * sizeof(float),positions,GL_STATIC_DRAW);



	glClear(GL_COLOR_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES,0,3);

	glfwSwapBuffers(&(window->GetGlfwWindow()));

	glfwPollEvents();

	/*glBegin(GL_TRIANGLES);

	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, -0.5f);

	glEnd();*/

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