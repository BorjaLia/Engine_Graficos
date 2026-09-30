#include "Shape.h"

engine::Shape::Shape()
{
}

engine::Shape::~Shape()
{
}

void engine::Shape::Draw()
{
	glBindVertexArray(vao);

	Renderer::Get()->Draw(vertices.size());
	
	glBindVertexArray(0);
}
