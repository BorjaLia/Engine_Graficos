#pragma once

#include "Vector2.h"

namespace math
{
	struct Rect
	{
		Vector2 pos;
		Vector2 size;
	
		Rect(math::Vector2 pos, math::Vector2 size)
		{
			this->pos = pos;
			this->size = size;
		}
	};
}