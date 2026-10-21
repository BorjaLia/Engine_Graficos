#pragma once

#include "Shape.h"

#include "Vector3.h"

class PlayerSquare : public engine::Shape
{
public:
	PlayerSquare();
	~PlayerSquare();

	void Update() override;

private:

	void Move();

	math::Vector3 dir;
};
