#include "Entity.h"

engine::Entity::Entity()
{
	position = math::Vector3(0.0f, 0.0f, 0.0f);
	rotation = math::Vector3(0.0f, 0.0f, 0.0f);
	scale = math::Vector3(0.0f, 0.0f, 0.0f);

	buffer = 0;
}

engine::Entity::~Entity()
{
}

void engine::Entity::Initialize()
{
	float positions[6] = {
		-0.5f,-0.5f,
		0.0f,0.5f,
		0.5f,-0.5f
	};

	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2 /*change to size of vertex struct*/, 0);
}

