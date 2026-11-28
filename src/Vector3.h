#pragma once

#include "core.h"

#include <string>
#include <cmath>

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

		void normalize()
		{
			float length = std::sqrt(x * x + y * y + z * z);
			if (length > 0.0001)
			{
				float invLength = 1.0f / length;
				x *= invLength;
				y *= invLength;
				z *= invLength;
			}
			else
			{
				x = y = z = 0.0f;
			}
		}

		float sqrMagnitude() const
		{
			return x * x + y * y + z * z;
		}

		float magnitude() const
		{
			return std::sqrt(sqrMagnitude());
		}

		Vector3 operator+(const Vector3& v) const
		{
			return Vector3(x + v.x, y + v.y, z + v.z);
		}

		Vector3 operator-(const Vector3& v) const
		{
			return Vector3(x - v.x, y - v.y, z - v.z);
		}

		Vector3 operator-() const
		{
			return Vector3(-x,-y,-z);
		}

		Vector3& operator+=(const Vector3& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		Vector3 operator * (float s)
		{
			return Vector3(x * s, y * s, z * s);
		}

		Vector3 operator / (float s)
		{
			return Vector3(x / s, y / s, z / s);
		}

		bool operator == (const Vector3& v) const
		{
			return (x == v.x && y == v.y && z == v.z);
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