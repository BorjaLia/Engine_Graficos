#pragma once

#include "Sprite.h"

class Enemy : public engine::Sprite
{
public:
	Enemy();
	~Enemy();

	void Start() override;
	void Update() override;

	void OnCollision(engine::Entity2D* other) override;

private:


};
