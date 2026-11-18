#pragma once

#include "Sprite.h"


class Player : public engine::Sprite
{
	enum class KnucklesAnimationState
	{
		IDLE,
		RUNNING,
		DASHING,
		PUSHING
	};

public:
	Player(const std::string& texturePath);
	~Player();

	void Start() override;
	void Update() override;
	
	void AddAnimation(engine::Animation* animation);

private:

	KnucklesAnimationState state = KnucklesAnimationState::IDLE;
	KnucklesAnimationState lastState = KnucklesAnimationState::IDLE;

	bool queueTeleport = false;
	bool isTeleporting = false;

	bool isMoving = false;
	bool wasMoving = false;

	void Move();
	void Teleport();

	void UpdateVisuals();

	void ShowPosition();

	math::Vector3 dir;

	std::vector<engine::Animation*> animations;


	bool physicsMode = false;

	float gravity = 50.0f;
	float lowerLimit = -25.0f;

	float walkForce = 5000.0f;
	float jumpForce = 50.0f;

	bool isGrounded = false;
	bool jumpQueue = false;

	float dashMultiplier = 1.5f;

	bool isDashing = false;
};
