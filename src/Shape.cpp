#include "Shape.h"

engine::Shape::Shape()
{
}

engine::Shape::~Shape()
{
}

void engine::Shape::AddPoint(math::Vector2 point)
{
	points.push_back(point);
}

void engine::Shape::SetPoints(std::vector<math::Vector2>& newPoints)
{
	points = newPoints;
}

void engine::Shape::Draw()
{
	Renderer::Get()->Draw(3);
}
