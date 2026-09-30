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
	if (this->getPosition().y < -1.0f + size.y)
	{
		position.y = -1.0f + size.y;
		dir = { 1.0f,0.0f,0.0f };
	}
	else if (this->getPosition().x > 1.0f - size.x)
	{
		position.x = 1.0f - size.x;
		dir = { 0.0f,1.0f,0.0f };
	}
	else if (this->getPosition().y > 1.0f - size.y)
	{
		position.y = 1.0f - size.y;
		dir = { -1.0f,0.0f,0.0f };
	}
	else if (this->getPosition().x < -1.0f + size.x)
	{
		position.x = -1.0f + size.x;
		dir = { 0.0f,-1.0f,0.0f };
	}

	Move();
}

void BlueSquare::SetSize(math::Vector2 s)
{
	size = s;
}

void BlueSquare::Move()
{
	this->setPosition(this->getPosition() + (dir * renderer->deltaTime));

	//std::cout << position.x << "," << position.y << "," << position.z << std::endl;
}
