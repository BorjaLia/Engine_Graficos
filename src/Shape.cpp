#include "Shape.h"

#include <math.h>

engine::Shape::Shape()
{
}

engine::Shape::~Shape()
{
}

void engine::Shape::Update()
{
	//updateFunction();
}

void engine::Shape::Draw()
{
	std::vector<math::Vertex> newV = vertices;

	float s = sin(rotation.x);
	float c = cos(rotation.x);

	for (math::Vertex& v : newV)
	{
		v.pos.x *= scale.x;
		v.pos.y *= scale.y;

		v.pos.x = v.pos.x * c - v.pos.y * s;
		v.pos.y = v.pos.x * s + v.pos.y * c;

		v.pos.x += position.x;
		v.pos.y += position.y;
	}

	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, newV.size() * sizeof(math::Vertex), newV.data(), GL_STATIC_DRAW);

	glBindVertexArray(vao);

	Renderer::Get()->Draw(indices.size());
	
	glBindVertexArray(0);
}

//void engine::Shape::SetUpdateFunction(std::function<void()> updateFunction)
//{
//	this->updateFunction = updateFunction;
//}
