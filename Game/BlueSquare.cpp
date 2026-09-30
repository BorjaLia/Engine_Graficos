#include "BlueSquare.h"

#include <iostream>

BlueSquare::BlueSquare()
{
	dir = { 0.0f,-1.0f,0.0f };
}

BlueSquare::~BlueSquare()
{
}

void BlueSquare::Update()
{
	if (this->getPosition().y < -1.0f + borderOffset.y)
	{
		position.y = -1.0f + borderOffset.y;
		dir = { 1.0f,0.0f,0.0f };
	}
	else if (this->getPosition().x > 1.0f - borderOffset.x)
	{
		position.x = 1.0f - borderOffset.x;
		dir = { 0.0f,1.0f,0.0f };
	}
	else if (this->getPosition().y > 1.0f - borderOffset.y)
	{
		position.y = 1.0f - borderOffset.y;
		dir = { -1.0f,0.0f,0.0f };
	}
	else if (this->getPosition().x < -1.0f + borderOffset.x)
	{
		position.x = -1.0f + borderOffset.x;
		dir = { 0.0f,-1.0f,0.0f };
	}

	Move();
	Rotate();
}

void BlueSquare::SetborderOffset(math::Vector2 b)
{
	borderOffset = b;
}

void BlueSquare::Move()
{
	this->setPosition(this->getPosition() + (dir * renderer->deltaTime));

	//std::cout << position.x << "," << position.y << "," << position.z << std::endl;
}

void BlueSquare::Rotate()
{
	if (angle > 360.0f)
	{
		angle = 0.0f;
	}

	angle += renderer->deltaTime;

	this->setRotation({angle,0.0f,0.0f});
}
