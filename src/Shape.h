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

	public:

		Shape();
		~Shape();

		virtual void Start() override;
		virtual void Update() override;
	};
}