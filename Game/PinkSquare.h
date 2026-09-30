#pragma once

#include "Shape.h"

#include "Vector3.h"

class PinkSquare : public engine::Shape
{
public:
	PinkSquare();
	~PinkSquare();

	void Update() override;

private:

	void ChangeSize();

	bool growing = true;

	const float minScale = 1;
	const float maxScale = 3;

	math::Vector2 size;
};
