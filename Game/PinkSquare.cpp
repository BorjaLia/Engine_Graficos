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
		//currentScale = { maxScale,maxScale ,maxScale };
	}


	if (scale.x < minScale && !growing)
	{
		//currentScale = { minScale,minScale ,minScale };
		growing = true;
	}

	ChangeSize();
}

void PinkSquare::ChangeSize()
{
	scale.x += (growing ? 1.0f : -1.0f) * renderer->deltaTime;
	scale.y = scale.x;

	//this->setScale(scale);

	//std::cout << position.x << "," << position.y << "," << position.z << std::endl;
	std::cout << growing << " " << scale.x << std::endl;
}
