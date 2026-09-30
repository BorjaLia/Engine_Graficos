#pragma once
#include "Entity2D.h"

#include <vector>

namespace engine
{
	class Shape : public Entity2D
	{
	private:

	public:

		Shape();
		~Shape();

		virtual void Draw() override;
	};
}