#pragma once

#include "Sprite.h"

#include "Texture.h"
#include "Input.h"

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

	void SetupTextures(std::string normalPath, std::string hoverPath, std::string clickPath);
	void ChangeState(State newState);

private:

	engine::Input* input = engine::Input::Get();

	State currentState = State::Nothing;
	State previousState = State::Nothing;

	engine::Texture* normalTexture = nullptr;
	engine::Texture* hoverTexture = nullptr;
	engine::Texture* clickTexture = nullptr;
};
