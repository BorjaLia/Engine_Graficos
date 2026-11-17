#pragma once

#include "Vector3.h"
#include "UVCoords.h"
#include "Color.h"

namespace math
{
	struct Vertex
	{
		Vector3 pos;
		UVCoords textureCoords;
		utils::Color color;

		Vertex(){}

		Vertex(Vector2 pos, utils::Color color)
		{
			this->pos = pos;
			this->color = color;
		}

		Vertex(Vector2 pos, UVCoords textureCoords, utils::Color color)
		{
			this->pos = pos;
			this->textureCoords = textureCoords;
			this->color = color;
		}
	};
}