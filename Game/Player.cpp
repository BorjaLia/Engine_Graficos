#include "Player.h"

#include "Input.h"
#include "Window.h"
#include "GameTime.h"
#include "Shader.h"

#include "Vector3.h"

#include "File.h"

#include <iostream>

Player::Player(const std::string& texturePath)
{
	texture = engine::Texture(texturePath);

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
	engine::Sprite::Update();

	lastState = state;

	wasMoving = isMoving;
	isMoving = false;

	Move();

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

		this->SetPosition(normalizedPos);

		//std::cout << "\n" << "Mouse: " << mousePos.ToString() << std::endl;

		//ShowPosition();
	}

	isTeleporting = queueTeleport;
}

void Player::UpdateVisuals()
{

	if (state != lastState)
	{
		std::cout << "Changed anim! " << (int)state << std::endl;
		SetAnimation(animations[(int)state]);
	}

	if (dir.x != 0.0f)
	{
		SetFlipX(dir.x < 0.0f);
	}
}

void Player::Move()
{
	float deltaTime = engine::Time::GetDeltaTime();

	isDashing = (engine::Input::Get()->IsKeyPressed(engine::KeyCode::LeftShift));
	
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::A)) dir.x -= walkForce * deltaTime * (isDashing ? dashMultiplier : 1.0f);
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::D)) dir.x += walkForce * deltaTime * (isDashing ? dashMultiplier : 1.0f);

	dir.x *= 0.85f;

	if (dir.x > -0.05f && dir.x < 0.05f) dir.x = 0.0f;

	if (dir.x != 0.0f)
	{
		state = (isDashing ? KnucklesAnimationState::DASHING : KnucklesAnimationState::RUNNING );
	}
	else
	{
		state = KnucklesAnimationState::IDLE;
	}

	dir.y -= gravity * deltaTime;

	math::Vector3 currentPos = this->GetPosition();
	math::Vector3 nextPos = currentPos + (dir * deltaTime);

	if (nextPos.y <= lowerLimit)
	{
		nextPos.y = lowerLimit;
		dir.y = 0.0f;
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
		dir.y = jumpForce;
		isGrounded = false;
		jumpQueue = false;
	}

	this->SetPosition(this->GetPosition() + (dir * deltaTime));
}

void Player::ShowPosition()
{
	std::cout << "Position: " << this->GetPosition().ToString() << std::endl;
}