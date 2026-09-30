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

	Renderer::Get()->Draw(indices.size());
	
	glBindVertexArray(0);
}
