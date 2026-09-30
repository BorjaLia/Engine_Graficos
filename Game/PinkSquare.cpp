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

	if (currentScale.x > maxScale && growing)
	{
		growing = false;
		//currentScale = { maxScale,maxScale ,maxScale };
	}


	if (currentScale.x < minScale && !growing)
	{
		//currentScale = { minScale,minScale ,minScale };
		growing = true;
	}

	ChangeSize();
}

void PinkSquare::ChangeSize()
{
	currentScale.x += (growing ? 1.0f : -1.0f) * renderer->deltaTime;
	currentScale.y = currentScale.x;

	this->setScale(currentScale);

	//std::cout << position.x << "," << position.y << "," << position.z << std::endl;
	std::cout << growing << " " << currentScale.x << std::endl;
}
