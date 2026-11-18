#pragma once

#include "PhysicsObject.h"

class Rock : public PhysicsObject
{
public:
	Rock(const std::string& texturePath);
	~Rock();

	void Start() override;
	void Update() override;

	void AddAnimation(engine::Animation* animation);

private:
};
