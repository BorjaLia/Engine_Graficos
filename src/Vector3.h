#pragma once

namespace math
{
	struct Vector3
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
	};
}