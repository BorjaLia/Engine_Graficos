#include "Button.h"

#include "CollisionManager.h"

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
	bool isMouseOver = engine::CollisionManager::Get()->IsPointInAABB(this->GetPosition(), this->AABB, input->GetMouseWorldPosition());
	bool isClicking = input->IsMouseButtonPressed(engine::MouseCode::ButtonLeft);

	switch (currentState)
	{
	case Button::State::Nothing:
	{
		if (isMouseOver) currentState = State::Hovered;

		break;
	}
	case Button::State::Hovered:
	{
		if (!isMouseOver)
		{
			currentState = State::Nothing;
			break;
		}

		if (isClicking)
		{
			currentState = State::Clicked;
		}

		break;
	}
	case Button::State::Clicked:
	{
		if (!isMouseOver)
		{
			currentState = State::Nothing;
			break;
		}

		if (!isClicking)
		{
			currentState = State::Nothing;
			onClick();
		}

		break;
	}
	default:
	{

		break;
	}
	}

	previousState = currentState;
}
