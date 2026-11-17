#pragma once

#include "Core.h"
#include <string>

namespace math
{
	struct ENGINE_API Vector2;

	struct ENGINE_API UVCoords
	{
		float u;
		float v;

		UVCoords()
		{
			u = 0.0f;
			v = 0.0f;
		}

		UVCoords(float u, float v)
		{
			this->u = u;
			this->v = v;
		}

		operator Vector2() const;

		std::string ToString() const;
	};
}