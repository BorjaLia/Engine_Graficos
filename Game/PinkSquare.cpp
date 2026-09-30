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
	if (growing)
	{
		if (getScale().x > maxScale)
		{
			growing = false;
		}
	}
	else
	{
		if (getScale().x < minScale)
		{
			growing = true;
		}
	}

	ChangeSize();
}

void PinkSquare::ChangeSize()
{
	this->setScale(this->getScale() * (growing ? 1.0f : -1.0f ) *renderer->deltaTime);
}
