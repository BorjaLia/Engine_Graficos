#pragma once

#include "Sprite.h"
#include "CollisionManager.h"
#include "PhysicsObject.h"
#include <vector>

class CollisionManagerEntyty : public engine::Sprite
{
public:
	CollisionManagerEntyty();
	~CollisionManagerEntyty();

	void Start() override;
	void Update() override;
	void Draw() override;

	std::vector<PhysicsObject*> entities;

private:
	engine::CollisionManager manager;
};