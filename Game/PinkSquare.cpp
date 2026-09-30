#include "PinkSquare.h"

#include <iostream>

PinkSquare::PinkSquare()
{
}

PinkSquare::~PinkSquare()
{
}

void PinkSquare::Update()
{

	if (scale.x > maxScale && growing)
	{
		growing = false;
	}


	if (scale.x < minScale && !growing)
	{
		growing = true;
	}

	ChangeSize();
}

void PinkSquare::ChangeSize()
{
	scale.x += (growing ? 1.0f : -1.0f) * renderer->deltaTime;
	scale.y = scale.x;

	//std::cout << position.x << "," << position.y << "," << position.z << std::endl;
	std::cout << growing << " " << scale.x << std::endl;
}
