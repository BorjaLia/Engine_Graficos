#include "Renderer.h"

#include "File.h"
#include "Shader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

int engine::Renderer::Initialize(Window& window)
{
	this->window = &window;

	File::SetRootPath("../res/shaders/");

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	proj = glm::ortho(-2.0f,2.0f,-1.5f,1.5f,-1.0f,1.0f);

	File::SetRootPath("");

	return 0;
}

void engine::Renderer::Update()
{
	glfwSwapBuffers(&(window->GetGlfwWindow()));
	glClear(GL_COLOR_BUFFER_BIT);
}

void engine::Renderer::Draw(int indexCount,int glDrawType)
{
	//GLCall(glDrawElements(glDrawType, indexCount,GL_UNSIGNED_INT,nullptr));
	glDrawElements(glDrawType, indexCount, GL_UNSIGNED_INT, nullptr);
}

int engine::Renderer::Shutdown()
{
	return 0;
}

void engine::Renderer::GenerateBuffers(std::vector<math::Vertex> vertices, std::vector<unsigned int> indices, unsigned int* vao, unsigned int* vbo, unsigned int* ibo)
{
	glGenVertexArrays(1, vao);
	glBindVertexArray(*vao);

	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(math::Vertex), vertices.data(), GL_STATIC_DRAW);

	glGenBuffers(1, ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(math::Vertex), (void*)offsetof(math::Vertex, pos));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(math::Vertex), (void*)offsetof(math::Vertex, textureCoords));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(math::Vertex), (void*)offsetof(math::Vertex, color));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
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