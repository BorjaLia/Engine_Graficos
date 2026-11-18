#pragma once
#include "Core.h"
#include "Vector3.h"

namespace engine
{
	struct ENGINE_API Bounds
	{
		math::Vector3 min;
		math::Vector3 max;

		Bounds()
		{
			min = math::Vector3(0.0f, 0.0f, 0.0f);
			max = math::Vector3(0.0f, 0.0f, 0.0f);
		}
		Bounds(math::Vector3 min, math::Vector3 max)
		{
			this->min = min;
			this->max = max;
		}
		Bounds(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
		{
			min = math::Vector3(minX, minY, minZ);
			max = math::Vector3(maxX, maxY, maxZ);
		}
		Bounds(float minX, float minY, float maxX, float maxY)
		{
			min = math::Vector3(minX, minY, 0.0f);
			max = math::Vector3(maxX, maxY, 0.0f);
		}
	};
}