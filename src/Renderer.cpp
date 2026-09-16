#include "Renderer.h"

#include "File.h"
#include "Shader.h"

#include <iostream>

int engine::Renderer::Initialize(Window& window)
{
	this->window = &window;

	float positions[6] = {
		-0.5f,-0.5f,
		0.0f,0.5f,
		0.5f,-0.5f
	};

	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(float) * 2 /*change to size of vertex struct*/, 0);

	File::SetRootPath("../res/shaders/");

	if (!CreateShaderFromFile("VertexShaderOne.shader", "FragmentShaderOne.shader"))
	{
		std::cout << "Couldnt create shaders!";
	}

	return 0;
}

void engine::Renderer::Update()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES,0,3);

	glfwSwapBuffers(&(window->GetGlfwWindow()));

	//Change to somewhere else
	glfwPollEvents();
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