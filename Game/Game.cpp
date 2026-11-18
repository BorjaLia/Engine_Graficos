#include "Game.h"

#include "Shape.h"
#include "Sprite.h"
#include "Player.h"

#include "BlueSquare.h"
#include "PinkSquare.h"
#include "PlayerSquare.h"

#include "Vector2.h"
#include "Vertex.h"

int main()
{
	MyGame game;

	game.Run();

	return 0;
}

void MyGame::Start()
{
	Player* knuckles = new Player("res/assets/Knuckles_Sprite_Sheet.png");

	knuckles->SetPosition(math::Vector3(0.0f, 0.0f, 0.0f));
	knuckles->SetScale(math::Vector3(10.0f, 10.0f, 1.0f));

	//math::Vector2 textureSize = math::Vector2(560.0f, 387.0f);
	math::Vector2 textureSize = math::Vector2(646.0f, 473.0f);
	math::Vector2 frameSize = math::Vector2(40.0f, 43.0f);

	engine::Animation* idleAnim = new engine::Animation();

	idleAnim->AddFrame(math::Vector2(0.0f,0.0f), frameSize, textureSize, 0.001);
	idleAnim->AddFrame(math::Vector2(0.0f,0.0f), frameSize, textureSize, 0.001);

	knuckles->AddAnimation(idleAnim);

	engine::Animation* runAnim = new engine::Animation();

	frameSize.x = 41.0f;

	for (int i = 0; i < 8; i++)
	{
		runAnim->AddFrame(math::Vector2(i * frameSize.x, frameSize.y), frameSize, textureSize, 0.001);
	}

	knuckles->AddAnimation(runAnim);

	engine::Animation* dashAnim = new engine::Animation();

	frameSize.x = 32.5f;
	frameSize.y = 42.0f;

	for (int i = 0; i < 7; i++)
	{
		dashAnim->AddFrame(math::Vector2(i * frameSize.x, 3 * frameSize.y), frameSize, textureSize, 0.001);
	}

	knuckles->AddAnimation(dashAnim);


	engine::Animation* pushAnim = new engine::Animation();

	for (int i = 11; i < 14; i++)
	{
		pushAnim->AddFrame(math::Vector2(i * frameSize.x, 3 * frameSize.y), frameSize, textureSize, 0.001);
	}

	knuckles->AddAnimation(pushAnim);

	AddEntity(knuckles);
}