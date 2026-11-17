#include "BlueSquare.h"

#include <iostream>

#include "GameTime.h"

BlueSquare::BlueSquare()
{
	dir = { 0.0f,-1.0f,0.0f };
}

BlueSquare::~BlueSquare()
{
}

void BlueSquare::Start()
{
	material = new engine::Material("../res/shaders/VertexShaderOne.shader", "../res/shaders/FragmentShaderOne.shader");
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
	this->setPosition(this->getPosition() + (dir * engine::Time::GetDeltaTime()));

	//std::cout << position.x << "," << position.y << "," << position.z << std::endl;
}

void BlueSquare::Rotate()
{
	if (angle > 360.0f)
	{
		angle = 0.0f;
	}

	angle += engine::Time::GetDeltaTime() * 30.0f;

	this->setRotation({0.0f,0.0f,angle});
}
