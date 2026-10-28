#pragma once

#include "Shape.h"
#include "Texture.h"

#include "Vector3.h"

class PlayerSquare : public engine::Shape
{
public:
	PlayerSquare();
	~PlayerSquare();

	void Start() override;
	void Update() override;

private:

	float time = 0.0f;
	int objectiveTime = 0;

	bool queueTeleport = false;
	bool isTeleporting = false;

	//engine::Texture* texture;

	void Move();
	void Teleport();
	
	void ShowPosition();

	math::Vector3 dir;
};
