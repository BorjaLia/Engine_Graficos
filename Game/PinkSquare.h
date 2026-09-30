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

	const float minScale = 1.0f;
	const float maxScale = 3.0f;

	math::Vector2 size;
};
