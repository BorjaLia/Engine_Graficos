#pragma once

#include "PhysicsObject.h"

class Player : public PhysicsObject
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

	void OnContactOverride() override;

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

	std::vector<engine::Animation*> animations;


	float walkForce = 5000.0f;
	float jumpForce = 25.0f;

	bool isGrounded = false;
	bool jumpQueue = false;

	float dashMultiplier = 1.5f;

	bool isDashing = false;

	float pushLimit = 0.5f;
	float pushCounter = 0;
};
