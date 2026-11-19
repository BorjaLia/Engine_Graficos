#pragma once

#include "Sprite.h"

class Player : public engine::Sprite
{
public:
	Player();
	~Player();

	void Start() override;
	void Update() override;
	
	void AddAnimation(engine::Animation* animation);

private:

	bool queueTeleport = false;
	bool isTeleporting = false;

	bool isRunning = false;
	bool wasRunning = false;

	bool isMoving = false;
	bool wasMoving = false;

	void Move();
	void Teleport();

	void UpdateVisuals();

	void ShowPosition();

	float runMultiplier = 1.75f;

	math::Vector3 dir;

	std::vector<engine::Animation*> animations;

	//test 

	bool changingMode = false;

	void PhysicsUpdate();

	bool physicsMode = false;

	float gravity = 1.0f;
	float lowerLimit = -0.8f;

	float walkForce = 25.0f;
	float jumpForce = 1.0f;

	bool isGrounded = false;
	bool jumpQueue = false;

	math::Vector3 accel;
};
