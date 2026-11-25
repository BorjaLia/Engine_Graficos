#pragma once

#include "Sprite.h"

#include "Texture.h"

#include <functional>

class Button : public engine::Sprite
{
public:

	enum class State
	{
		Nothing,
		Hovered,
		Clicked
	};

	Button();
	~Button();

	void Start() override;
	void Update() override;

	std::function<void()> onClick;

	void SetOnClick(std::function<void()> func) { onClick = func; };

private:

	State currentState;
	State previousState;

	engine::Texture* normalTexture;
	engine::Texture* hoverTexture;
	engine::Texture* clickTexture;
};
