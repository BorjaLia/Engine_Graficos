#pragma once

#include "Entity.h"
#include "Player.h"

class GameManager : public engine::Entity
{
public:
	GameManager();
	~GameManager();

	void Initialize() override;
	void Start() override;
	void Update() override;
	void Draw() override;

private:

	Player* player;

	math::Vector2 lastDir;
};