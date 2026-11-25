#include "MainMenuScene.h"

#include "Button.h"
#include "Game.h"

void MainMenuScene::Setup()
{
	Button* playButton = CreateEntity<Button>();

	playButton->SetPosition(math::Vector3(0.0f, 0.0f, 0.0f));
	playButton->SetScale(math::Vector3(20.0f, 10.0f, 1.0f));

	playButton->SetupTextures(
		"res/assets/Button.png",
		"res/assets/ButtonHovered.png",
		"res/assets/ButtonClick.png");

	playButton->onClick = []()
		{
			std::cout << "Button pressed" << std::endl;
		};
}