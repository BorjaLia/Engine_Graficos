#include "Vector2.h"
#include "Vector3.h"

namespace math
{
	Vector3::operator Vector2() const
	{
		return Vector2(x, y);
	}

	Vector2::operator Vector3() const
	{
		return Vector3(x, y, 0.0f);
	}

	std::string Vector2::ToString() const
	{
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	}

	std::string Vector3::ToString() const
	{
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
	}
}