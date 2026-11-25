#include "Button.h"

Button::Button()
{
}

Button::~Button()
{
}

void Button::Start()
{
	currentState = State::Nothing;
	previousState = currentState;
}

void Button::Update()
{
}
