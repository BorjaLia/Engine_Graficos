#include "Vector2.h"
#include "Vector3.h"

namespace math
{
	Vector3::operator Vector2() const
	{
		return Vector2(x, y);
	}

	Vector2 Vector2::Remap(const Vector2& value, const Vector2& inMin, const Vector2& inMax, const Vector2& outMin, const Vector2& outMax)
	{
		float newX = outMin.x + (value.x - inMin.x) * (outMax.x - outMin.x) / (inMax.x - inMin.x);
		float newY = outMin.y + (value.y - inMin.y) * (outMax.y - outMin.y) / (inMax.y - inMin.y);

		return Vector2(newX, newY);
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