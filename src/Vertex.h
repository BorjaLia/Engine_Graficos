#pragma once

#include "Vector2.h"
#include "Color.h"

namespace math
{
	struct Vertex
	{
		Vector2 pos;
		utils::Color color;

		Vertex(){}

		Vertex(Vector2 pos, utils::Color color)
		{
			this->pos = pos;
			this->color = color;
		}
	};
}