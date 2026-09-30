#pragma once
#include "Entity2D.h"

#include "Core.h"

//#include <functional>
#include <vector>

namespace engine
{
	class ENGINE_API Shape : public Entity2D
	{
	private:

		//std::function<void()> updateFunction;

	public:

		Shape();
		~Shape();

		virtual void Update() override;

		virtual void Draw() override;

		//void SetUpdateFunction(std::function<void()> updateFunction);
	};
}