#pragma once

#include "Shape.h"

#include "Vector3.h"

#include "Input.h"

class PlayerSquare : public engine::Shape
{
public:
	PlayerSquare();
	~PlayerSquare();

	void Update() override;

private:

	engine::Input* input = engine::Input::Get();

	void Move();

	math::Vector3 dir;
};
