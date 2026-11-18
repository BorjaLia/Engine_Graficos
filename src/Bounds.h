#pragma once
#include "Core.h"
#include "Vector3.h"

namespace engine
{
	struct ENGINE_API Bounds
	{
		math::Vector3 min;
		math::Vector3 max;
	};
}