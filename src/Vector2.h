#pragma once

#include "Core.h"
#include <string>
#include <cmath>

namespace math
{
	struct ENGINE_API Vector3;
	struct ENGINE_API UVCoords;

	struct ENGINE_API Vector2
	{
		float x;
		float y;

		Vector2()
		{
			x = 0.0f;
			y = 0.0f;
		}

		Vector2(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		static Vector2 Remap(const Vector2& value, const Vector2& inMin, const Vector2& inMax, const Vector2& outMin, const Vector2& outMax);

		void Normalize()
		{
			float length = std::sqrt(x * x + y * y);
			if (length > 0.0001)
			{
				float invLength = 1.0f / length;
				x *= invLength;
				y *= invLength;
			}
			else
			{
				x = y  = 0.0f;
			}
		}

		math::Vector2 Normalized()
		{
			math::Vector2 v = *this;
			v.Normalize();
			return v;
		}

		Vector2 operator-()
		{
			return Vector2(-x,-y);
		}

		operator Vector3() const;
		operator UVCoords() const;

		std::string ToString() const;
	};
}