#include "Renderer.h"

#include "File.h"
#include "Shader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

int engine::Renderer::Initialize(Window& window)
{
	this->window = &window;

	File::SetRootPath("../res/shaders/");

	if (!CreateShaderFromFile("VertexShaderOne.shader", "FragmentShaderOne.shader"))
	{
		std::cout << "Couldnt create shaders!";
	}
	else
	{
		std::cout << "Shader Created";
	}

	proj = glm::ortho(-2.0f,2.0f,-1.5f,1.5f,-1.0f,1.0f);


	return 0;
}

void engine::Renderer::Update()
{
	glfwSwapBuffers(&(window->GetGlfwWindow()));
	glClear(GL_COLOR_BUFFER_BIT);
}

void engine::Renderer::Draw(int indexCount,int glDrawType)
{
	glDrawElements(glDrawType, indexCount,GL_UNSIGNED_INT,nullptr);
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