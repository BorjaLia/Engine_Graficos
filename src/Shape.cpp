#include "Shape.h"

#include <math.h>

engine::Shape::Shape()
{
}

engine::Shape::~Shape()
{
}

void engine::Shape::Start()
{
}

void engine::Shape::Update()
{

}

void engine::Shape::Draw()
{
	std::vector<math::Vertex> newV = vertices;

	float s = sin(rotation.x);
	float c = cos(rotation.x);

	float x,y;

	for (math::Vertex& v : newV)
	{
		v.pos.x *= scale.x;
		v.pos.y *= scale.y;

		x = v.pos.x;
		y = v.pos.y;

		v.pos.x = x * c - y * s;
		v.pos.y = x * s + y * c;

		v.pos.x += position.x;
		v.pos.y += position.y;
	}

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, newV.size() * sizeof(math::Vertex), newV.data(), GL_STATIC_DRAW);

	glBindVertexArray(vao);

	if (material)
	{
		material->Bind();
	}

	Renderer::Get()->Draw(indices.size());
	
	if (material)
	{
		material->Unbind();
	}

	glBindVertexArray(0);
}