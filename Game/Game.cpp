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

	player->SetPosition(math::Vector3(0.0f, 0.0f, 0.0f));
	player->SetScale(math::Vector3(0.2f, 0.2f, 1.0f));

	math::Vector2 frameSize = math::Vector2(200.0f, 246.6f);

	engine::Animation* idleAnim = new engine::Animation();

	idleAnim->AddFrame(math::Vector2(frameSize.x, frameSize.y), frameSize, math::Vector2(1200.0f, 1233.0f), 0.01);
	idleAnim->AddFrame(math::Vector2(2 *frameSize.x, frameSize.y), frameSize, math::Vector2(1200.0f, 1233.0f), 0.01);

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