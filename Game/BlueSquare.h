#pragma once

#include "Shape.h"

#include "Vector3.h"

class BlueSquare : public engine::Shape
{
public:
	BlueSquare();
	~BlueSquare();

	void Update() override;

	void SetSize(math::Vector2 s);

private:

	void Move();

	math::Vector3 dir;

	math::Vector2 size;
};
