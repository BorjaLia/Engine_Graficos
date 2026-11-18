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
	//BlueSquare* blueSquare = new BlueSquare();
	//blueSquare->setPosition(math::Vector3(0.0f, 0.0f, 0.0f));
	//blueSquare->setTint(utils::Color::white());

	//blueSquare->AddVertex(math::Vertex(math::Vector2(-0.1f, -0.1f), utils::Color::blue()));
	//blueSquare->AddVertex(math::Vertex(math::Vector2(-0.1f, 0.1f), utils::Color::blue()));
	//blueSquare->AddVertex(math::Vertex(math::Vector2(0.1f, 0.1f), utils::Color::blue()));
	//blueSquare->AddVertex(math::Vertex(math::Vector2(0.1f, -0.1f), utils::Color::blue()));

	//blueSquare->Setindex({ 0,1,2,2,3,0 });

	//blueSquare->SetborderOffset({ 0.15f,0.15f });

	//AddEntity(blueSquare);

	//PinkSquare* pinkSquare = new PinkSquare();
	//pinkSquare->setPosition(math::Vector3(0.0f, 0.0f, 0.0f));
	//pinkSquare->setTint(utils::Color::white());

	//pinkSquare->AddVertex(math::Vertex(math::Vector2(-0.1f, -0.1f), utils::Color::pink()));
	//pinkSquare->AddVertex(math::Vertex(math::Vector2(-0.1f, 0.1f), utils::Color::pink()));
	//pinkSquare->AddVertex(math::Vertex(math::Vector2(0.1f, 0.1f), utils::Color::pink()));
	//pinkSquare->AddVertex(math::Vertex(math::Vector2(0.1f, -0.1f), utils::Color::pink()));

	//pinkSquare->Setindex({ 0,1,2,2,3,0 });

	//AddEntity(pinkSquare);

	//PlayerSquare* playerSquare = new PlayerSquare();
	//playerSquare->setPosition(math::Vector3(0.0f, 0.0f, 0.0f));
	//playerSquare->setTint(utils::Color(255, 255, 255, 200));

	//playerSquare->AddVertex(math::Vertex(math::Vector2(-0.1f, -0.1f), math::Vector2(0.0f, 0.0f), utils::Color::white()));
	//playerSquare->AddVertex(math::Vertex(math::Vector2(-0.1f, 0.1f), math::Vector2(0.0f, 1.0f), utils::Color::white()));
	//playerSquare->AddVertex(math::Vertex(math::Vector2(0.1f, 0.1f), math::Vector2(1.0f, 1.0f), utils::Color::white()));
	//playerSquare->AddVertex(math::Vertex(math::Vector2(0.1f, -0.1f), math::Vector2(1.0f, 0.0f), utils::Color::white()));

	//playerSquare->Setindex({ 0,1,2,2,3,0 });

	//AddEntity(playerSquare);


	//engine::Sprite* testSprite = new engine::Sprite;

	//testSprite->setPosition(math::Vector3(0.0f, 0.0f, 0.0f));
	//testSprite->setScale(math::Vector3(0.2f, 0.2f, 1.0f));

	//engine::Animation* runAnim = new engine::Animation();

	//math::Vector2 frameSize = math::Vector2(200.0f, 246.6f);

	//for (int j = 4; j >= 0; j--)
	//{
	//	for (int i = 0; i < 6; i++)
	//	{
	//		runAnim->AddFrame(math::Vector2(i * frameSize.x, j * frameSize.y), frameSize, math::Vector2(1200.0f, 1233.0f), 0.001);
	//	}
	//}

	//testSprite->SetAnimation(runAnim);

	//AddEntity(testSprite);

	Player* player = new Player();

	player->setPosition(math::Vector3(0.0f, 0.0f, 0.0f));
	player->setScale(math::Vector3(0.2f, 0.2f, 1.0f));

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
