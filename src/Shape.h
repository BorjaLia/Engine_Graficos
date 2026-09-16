#pragma once
#include "Entity2D.h"

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