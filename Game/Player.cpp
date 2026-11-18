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
		if (animations[i]) delete animations[i];
	}
}

void Player::Start()
{
	engine::Sprite::Start();

	if (animations.size() == 0)
	{
		std::cout << "No animations have been set for the player!" << std::endl;
		return;
	}

	SetAnimation(animations[0]);
}

void Player::Update()
{
	bool pressingChangeKey = engine::Input::Get()->IsKeyPressed(engine::KeyCode::G);

	if (pressingChangeKey && !changingMode)
	{
		std::cout << "Changed mode!" << std::endl;
		physicsMode = !physicsMode;
	}
	changingMode = pressingChangeKey;

	engine::Sprite::Update();

	wasMoving = isMoving;
	isMoving = false;

	Teleport();

	if (physicsMode)
	{
		PhysicsUpdate();
	}
	else
	{
		Move();
	}


	UpdateVisuals();
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

void Player::UpdateVisuals()
{
	isMoving = (dir != math::Vector3::zero());

	if (isMoving && !wasMoving)
	{
		std::cout << "Changed anim!" << std::endl;
		SetAnimation(animations[1]);
	}
	else if (!isMoving && wasMoving)
	{
		std::cout << "Changed anim!" << std::endl;
		SetAnimation(animations[0]);
	}

	if (dir.x != 0.0f)
	{
		SetFlipX(dir.x < 0.0f);
	}
}

void Player::Move()
{
	dir = math::Vector3::zero();

	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::W)) dir.y += 1.0f;
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::A)) dir.x -= 1.0f;
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::S)) dir.y -= 1.0f;
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::D)) dir.x += 1.0f;

	this->setPosition(this->getPosition() + (dir * engine::Time::GetDeltaTime()));
}

void Player::ShowPosition()
{
	std::cout << "Position: " << this->getPosition().ToString() << std::endl;
}

void Player::PhysicsUpdate()
{
	float deltaTime = engine::Time::GetDeltaTime();

	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::A)) accel.x -= walkForce * deltaTime;
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::D)) accel.x += walkForce * deltaTime;

	accel.x *= 0.85f;

	if (accel.x > -0.05f && accel.x < 0.05f) accel.x = 0.0f;

	accel.y -= gravity * deltaTime;

	math::Vector3 currentPos = this->getPosition();
	math::Vector3 nextPos = currentPos + (accel * deltaTime);

	if (nextPos.y <= lowerLimit)
	{
		nextPos.y = lowerLimit;
		accel.y = 0.0f;
		isGrounded = true;
		jumpQueue = false;
	}
	else
	{
		isGrounded = false;
	}

	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::Space)) jumpQueue = true;

	if (isGrounded && jumpQueue)
	{
		accel.y = jumpForce;
		isGrounded = false;
		jumpQueue = false;
	}

	this->setPosition(this->getPosition() + (accel * deltaTime));

	dir = accel;
}