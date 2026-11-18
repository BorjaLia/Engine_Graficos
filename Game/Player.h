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

	bool isMoving = false;
	bool wasMoving = false;

	void Move();
	void Teleport();

	void ShowPosition();

	math::Vector3 dir;

	std::vector<engine::Animation*> animations;
};
