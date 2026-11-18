#pragma once

#include "Sprite.h"
#include "Bounds.h"

class PhysicsObject : public engine::Sprite
{

public:
	PhysicsObject();
	~PhysicsObject();

	void Start() override;
	void Update() override;

	void AddForce(math::Vector3 force);

	void CheckCollisions();

	void OnContact();

	virtual void OnContactOverride();

	PhysicsObject* other = nullptr;

protected:

	math::Vector3 dir;

	float drag = 0.85f;
	float gravity = 50.0f;
	float lowerLimit = -25.0f;
};
