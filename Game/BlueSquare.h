#pragma once

#include "Shape.h"

#include "Vector3.h"

class BlueSquare : public engine::Shape
{
public:
	BlueSquare();
	~BlueSquare();

	void Update() override;

	void SetborderOffset(math::Vector2 b);

private:

	void Move();
	
	void Rotate();

	float angle = 0.0f;

	math::Vector3 dir;

	math::Vector2 borderOffset;
};
