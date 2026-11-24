#include "Game.h"

#include "GameplayScene.h"

int main()
{
	MyGame game;

	game.Run();

	return 0;
}

void MyGame::SetupScenes()
{
	LoadScene(new GameplayScene());
}