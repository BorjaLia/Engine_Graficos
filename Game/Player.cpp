#include "Player.h"

#include "Input.h"
#include "Window.h"
#include "GameTime.h"
#include "Shader.h"

#include "Vector3.h"

#include "File.h"

#include <iostream>

Player::Player()
{
	dir = { 0.0f,0.0f,0.0f };
	animations.clear();
}

Player::~Player()
{
	for (int i = 0; i < animations.size(); i++)
	{
		if(animations[i]) delete animations[i];
	}
}

void Player::Start()
{
	engine::Sprite::Start();

	if (animations.size() == 0)
	{
		std::cout << "No animations have been set for the player!";
		return;
	}

	SetAnimation(animations[0]);
}

void Player::Update()
{
	engine::Sprite::Update();

	wasMoving = isMoving;
	isMoving = false;

	Teleport();

	Move();

	if (isMoving && !wasMoving)
	{
		SetAnimation(animations[1]);
	}
	else if (!isMoving && wasMoving)
	{
		SetAnimation(animations[0]);
	}
}

void Player::AddAnimation(engine::Animation* animation)
{
	animations.push_back(animation);
}

void Player::Teleport()
{
	queueTeleport = engine::Input::Get()->IsMouseButtonPressed(engine::MouseCode::Button0);

	if (queueTeleport && !isTeleporting)
	{
		math::Vector2 mousePos = engine::Input::Get()->GetMousePosition();

		math::Vector2 targetMin(-1.0f, 1.0f);
		math::Vector2 targetMax(1.0f, -1.0f);

		math::Vector2 normalizedPos = math::Vector2::Remap(mousePos, { 0.0f,0.0f }, renderer->GetSize(), targetMin, targetMax);

		this->setPosition(normalizedPos);

		std::cout << "\n" << "Mouse: " << mousePos.ToString() << std::endl;

		//ShowPosition();
	}

	isTeleporting = queueTeleport;
}

void Player::Move()
{
	dir = math::Vector3::zero();

	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::W)) dir.y += 1.0f;
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::A)) dir.x -= 1.0f;
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::S)) dir.y -= 1.0f;
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::D)) dir.x += 1.0f;

	this->setPosition(this->getPosition() + (dir * engine::Time::GetDeltaTime()));

	isMoving = (dir != math::Vector3::zero());
}

void Player::ShowPosition()
{
	std::cout << "Position: " << this->getPosition().ToString() << std::endl;
}