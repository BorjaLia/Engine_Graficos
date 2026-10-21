#pragma once

#include "Core.h"
#include <string>

namespace math
{
	struct ENGINE_API Vector3;

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

		operator Vector3() const;

		std::string ToString() const;
	};
}