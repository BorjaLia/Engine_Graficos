#include "PlayerSquare.h"

#include "Input.h"

PlayerSquare::PlayerSquare()
{
	dir = { 0.0f,0.0f,0.0f };
}

PlayerSquare::~PlayerSquare()
{
}

void PlayerSquare::Update()
{
	dir = { 0.0f,0.0f,0.0f };

	if (engine::Input::Get()->IsKeyPressed(KeyCode::W)) dir.y += 1.0f;
	if (engine::Input::Get()->IsKeyPressed(KeyCode::A)) dir.x -= 1.0f;
	if (engine::Input::Get()->IsKeyPressed(KeyCode::S)) dir.y -= 1.0f;
	if (engine::Input::Get()->IsKeyPressed(KeyCode::D)) dir.x += 1.0f;

	Move();
}

void PlayerSquare::Move()
{
	this->setPosition(this->getPosition() + (dir * renderer->deltaTime));
}