#include "PlayerSquare.h"

#include "Input.h"
#include "Window.h"

#include <iostream>

PlayerSquare::PlayerSquare()
{
	dir = { 0.0f,0.0f,0.0f };
}

PlayerSquare::~PlayerSquare()
{
}

void PlayerSquare::Start()
{
	//texture = new engine::Texture("res/assets/image.jpg");
	//texture->Bind();
	//bind shader uniform
}

void PlayerSquare::Update()
{	
	time += renderer->deltaTime;

	if (objectiveTime < static_cast<int>(time))
	{
		objectiveTime = static_cast<int>(time) + 2;
		ShowPosition();
	}

	Teleport();

	Move();
}

void PlayerSquare::Teleport()
{
	queueTeleport = engine::Input::Get()->IsMouseButtonPressed(engine::MouseCode::Button0);

	if (queueTeleport && !isTeleporting)
	{
		math::Vector2 mousePos = engine::Input::Get()->GetMousePosition();

		math::Vector2 targetMin(-1.0f, 1.0f);
		math::Vector2 targetMax(1.0f, -1.0f);

		math::Vector2 normalizedPos = math::Vector2::Remap(mousePos, { 0.0f,0.0f }, renderer->GetSize(),targetMin, targetMax);

		this->setPosition(normalizedPos);

		std::cout << "Mouse: " << mousePos.ToString() << std::endl;

		ShowPosition();
	}

	isTeleporting = queueTeleport;
}

void PlayerSquare::Move()
{
	dir = { 0.0f,0.0f,0.0f };

	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::W)) dir.y += 1.0f;
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::A)) dir.x -= 1.0f;
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::S)) dir.y -= 1.0f;
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::D)) dir.x += 1.0f;

	this->setPosition(this->getPosition() + (dir * renderer->deltaTime));
}

void PlayerSquare::ShowPosition()
{
	std::cout << "Position: " << this->getPosition().ToString() << std::endl;
}