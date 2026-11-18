#pragma once

#include "BaseGame.h"

class MyGame : public engine::BaseGame
{
public:

	void Start() override;
	void Update() override;
};

int main(void);