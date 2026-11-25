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
	Sprite::Start();

	currentState = State::Nothing;
	previousState = currentState;

	UpdateBounds();
}


void Button::Update()
{
	Sprite::Update();

	bool isMouseOver = engine::CollisionManager::Get()->IsPointInAABB(this->GetPosition(), this->AABB, input->GetMouseWorldPosition());
	bool isClicking = input->IsMouseButtonPressed(engine::MouseCode::ButtonLeft);

	switch (currentState)
	{
	case Button::State::Nothing:
	{
		if (isMouseOver) ChangeState(State::Hovered);

		break;
	}
	case Button::State::Hovered:
	{
		if (!isMouseOver)
		{
			ChangeState(State::Nothing);
			break;
		}

		if (isClicking)
		{
			ChangeState(State::Clicked);
		}

		break;
	}
	case Button::State::Clicked:
	{
		if (!isMouseOver)
		{
			ChangeState(State::Nothing);
			break;
		}

		if (!isClicking)
		{
			ChangeState(State::Hovered);
			if (onClick) onClick();
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

	SetTexture(*normalTexture);
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

	UpdateBounds();
}

void Button::UpdateBounds()
{
	math::Vector2 scale = this->GetScale();
	math::Vector2 halfSize(std::abs(scale.x) * 0.5f, std::abs(scale.y) * 0.5f);

	this->AABB.min = -halfSize;
	this->AABB.max = halfSize;
}