#pragma once
#include "Entity2D.h"

#include <vector>

namespace engine
{
	class Shape : public Entity2D
	{
	private:

		std::vector<math::Vector2> points;

	public:

		Shape();
		~Shape();

		void AddPoint(math::Vector2 point);
		void SetPoints(std::vector<math::Vector2>& newPoints);

		virtual void Draw() override;
	};
}