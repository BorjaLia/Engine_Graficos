#pragma once

#include "core.h"
#include <string>

namespace math
{
	struct ENGINE_API Vector2;

	struct ENGINE_API Vector3
	{
		float x;
		float y;
		float z;

		Vector3()
		{
			x = 0;
			y = 0;
			z = 0;
		}
		Vector3(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vector3 operator + (Vector3 v)
		{
			return Vector3(x + v.x,y + v.y,z + v.z);
		}

		Vector3 operator * (float s)
		{
			return Vector3(x * s, y * s, z * s);
		}

		bool operator == (const Vector3& v) const
		{
			return (x==v.x && y == v.y && z == v.z);
		}

		bool operator != (const Vector3& v) const
		{
			return !(*this == v);
		}

		operator Vector2() const;

		std::string ToString() const;
	
		static Vector3 zero() { return Vector3(0.0f, 0.0f, 0.0f); }
	};
}