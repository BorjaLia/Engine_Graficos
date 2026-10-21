#include "PlayerSquare.h"

#include "Input.h"

#include <iostream>

PlayerSquare::PlayerSquare()
{
	dir = { 0.0f,0.0f,0.0f };
}

PlayerSquare::~PlayerSquare()
{
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
		ShowPosition();
		this->setPosition(engine::Input::Get()->GetMousePosition());
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
	std::cout << time << std::endl << this->getPosition().ToString() << std::endl;
}