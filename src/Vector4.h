#pragma once

#include "core.h"
#include <string>

namespace math
{
	struct ENGINE_API Vector4
	{
		float x;
		float y;
		float z;
		float w;

		Vector4()
		{
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}
		Vector4(float x, float y, float z, float w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Vector4 operator + (Vector4 v)
		{
			return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
		}

		Vector4 operator * (float s)
		{
			return Vector4(x * s, y * s, z * s, w * s);
		}

		std::string ToString() const;
	};
}