#include "Button.h"

#include "CollisionManager.h"

Button::Button()
{
}

Button::~Button()
{
	delete normalTexture;
	delete hoverTexture;
	delete clickTexture;
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
			SetTexture(*normalTexture);
			break;
		}

		if (isClicking)
		{
			currentState = State::Clicked;
			SetTexture(*clickTexture);
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

void Button::SetupTextures(std::string normalPath, std::string hoverPath, std::string clickPath)
{
	normalTexture = new engine::Texture(normalPath);
	hoverTexture = new engine::Texture(hoverPath);
	clickTexture = new engine::Texture(clickPath);

	ChangeState(State::Nothing);
}

void Button::ChangeState(State newState)
{
	if (currentState == newState) return;

	currentState = newState;

	switch (newState)
	{
	case Button::State::Nothing:
		SetTexture(*normalTexture);
		break;
	case Button::State::Hovered:
		SetTexture(*hoverTexture);
		break;
	case Button::State::Clicked:
		SetTexture(*clickTexture);
		break;
	default:
		break;
	}
}