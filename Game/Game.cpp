#include "Game.h"

#include "Shape.h"
#include "Sprite.h"
#include "Player.h"

#include "BlueSquare.h"
#include "PinkSquare.h"
#include "PlayerSquare.h"

#include "Vector2.h"
#include "Vertex.h"
#include "Rock.h"

int main()
{
	MyGame game;

	game.Run();

	return 0;
}

void MyGame::Start()
{
	Player* player = new Player();
	
	math::Vector2 texSize = math::Vector2(646, 473);
	math::Vector2 frameSize = math::Vector2(40, 40);

	player->SetTexture(engine::Texture("res/assets/Knuckles_Sprite_Sheet.png"));
	player->SetTextureCoordinates(math::UVCoords(0, texSize.y - frameSize.y),
								  math::UVCoords(0, texSize.y),
								  math::UVCoords(frameSize.x, texSize.y - frameSize.y),
								  math::UVCoords(frameSize.x, texSize.y));

	player->SetPosition(math::Vector3(0, 0, 0));
	player->SetScale(math::Vector3(20, 20, 1));

	engine::Animation* idleAnim = new engine::Animation();

	idleAnim->AddFrame(math::Vector2(0, texSize.y - frameSize.y), frameSize, texSize, 0.001f);
	idleAnim->AddFrame(math::Vector2(0, texSize.y - frameSize.y), frameSize, texSize, 0.001f);

	player->AddAnimation(idleAnim);

	engine::Animation* runAnim = new engine::Animation();

	frameSize.x = 36;
	runAnim->AddFrame(math::Vector2(0, texSize.y - 83), frameSize, texSize, 0.0005f);
	frameSize.x = 40;
	runAnim->AddFrame(math::Vector2(36, texSize.y - 83), frameSize, texSize, 0.0005f);
	runAnim->AddFrame(math::Vector2(36, texSize.y - 83), frameSize, texSize, 0.0005f);
	runAnim->AddFrame(math::Vector2(76, texSize.y - 83), frameSize, texSize, 0.0005f);
	runAnim->AddFrame(math::Vector2(124, texSize.y - 83), frameSize, texSize, 0.0005f);
	runAnim->AddFrame(math::Vector2(167, texSize.y - 83), frameSize, texSize, 0.0005f);

	player->AddAnimation(runAnim);

	engine::Animation* spinAnim = new engine::Animation();

	frameSize = math::Vector2(28, 28);
	spinAnim->AddFrame(math::Vector2(230, texSize.y - 159), frameSize, texSize, 0.0005f);
	spinAnim->AddFrame(math::Vector2(264, texSize.y - 159), frameSize, texSize, 0.0005f);
	spinAnim->AddFrame(math::Vector2(297, texSize.y - 159), frameSize, texSize, 0.0005f);
	spinAnim->AddFrame(math::Vector2(329, texSize.y - 159), frameSize, texSize, 0.0005f);

	player->AddAnimation(spinAnim);

	AddEntity(player);
}