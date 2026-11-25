#include "SceneManager.h"
#include "Game.h"

#include "MainMenuScene.h"
#include "GameplayScene.h"

int main()
{
	MyGame game;

	game.Run();

	return 0;
}

void MyGame::SetupScenes()
{
 	engine::SceneManager::Get()->RegisterScene(new MainMenuScene("MainMenuScene"));
 	engine::SceneManager::Get()->RegisterScene(new GameplayScene("GameplayScene"));
}