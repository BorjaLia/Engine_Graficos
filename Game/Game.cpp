#include "Game.h"

int main()
{
	MyGame game;

	game.Run();

	return 0;
}

//void MyGame::Start()
//{
//	Player* player = new Player();
//
//	player->SetPosition(math::Vector3(0.0f, 0.0f, 0.0f));
//	player->SetScale(math::Vector3(10.0f, 10.0f, 1.0f));
//
//	engine::Animation* idleAnim = new engine::Animation(0.5f);
//
//	idleAnim->AddFrames(math::Rect(math::Vector2(0.0f,0.0f),math::Vector2(2* 200.0f,246.0f)), math::Vector2(1200.0f, 1233.0f),2);
//
//	player->AddAnimation(idleAnim);
//
//	engine::Animation* runAnim = new engine::Animation(1.5f);
//
//	runAnim->AddFrames(
//		math::Rect(math::Vector2(0.0f, 0.0f), math::Vector2(1200.0f, 1233.0f)),
//		math::Vector2(1200.0f, 1233.0f),
//		math::Vector2(6.0f, 5.0f)
//	);
//
//	player->AddAnimation(runAnim);
//
//	AddEntity(player);
//}

void MyGame::SetupScenes()
{
}