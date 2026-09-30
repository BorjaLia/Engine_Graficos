#pragma once

namespace math
{
	struct Vector2
	{
		float x;
		float y;

		Vector2() {}

		Vector2(float x, float y)
		{
			this->x = x;
			this->y = y;
		}
	};
}