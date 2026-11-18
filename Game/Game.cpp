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
	Player* player = new Player();
	
	player->SetTexture(engine::Texture("res/assets/Knuckles_Sprite_Sheet.png"));

	math::Vector2 texSize = math::Vector2(646.0f, 473.0f);

	player->SetPosition(math::Vector3(0.0f, 0.0f, 0.0f));
	player->SetScale(math::Vector3(34.0f, 39.0f, 1.0f));

	math::Vector2 frameSize = math::Vector2(34.0f, 39.0f);

	engine::Animation* idleAnim = new engine::Animation();

	idleAnim->AddFrame(math::Vector2(0, texSize.y - frameSize.y), frameSize, texSize, 0.001);
	idleAnim->AddFrame(math::Vector2(0, texSize.y - frameSize.y), frameSize, texSize, 0.001);
	//idleAnim->AddFrame(math::Vector2(frameSize.x, texSize.y - frameSize.y), frameSize, texSize, 0.001);

	player->AddAnimation(idleAnim);

	engine::Animation* runAnim = new engine::Animation();

	for (int j = 4; j >= 0; j--)
	{
		for (int i = 0; i < 6; i++)
		{
			runAnim->AddFrame(math::Vector2(i * frameSize.x, j * frameSize.y), frameSize, math::Vector2(1200.0f, 1233.0f), 0.001);
		}
	}

	player->AddAnimation(runAnim);

	AddEntity(player);
}