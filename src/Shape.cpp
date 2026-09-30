#include "Shape.h"

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

	for (math::Vertex& v : newV)
	{
		v.pos.x *= scale.x;
		v.pos.y *= scale.y;

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
