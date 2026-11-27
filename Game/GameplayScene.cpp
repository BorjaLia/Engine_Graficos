#include "GameplayScene.h"


#include "Player.h"
#include "Enemy.h"
#include "GameManager.h"


void GameplayScene::Setup()
{
	//GameManager* manager = CreateEntity<GameManager>();

	Player* player = CreateEntity<Player>();

	player->SetPosition(math::Vector3(-10.0f, 0.0f, 0.0f));
	player->SetScale(math::Vector3(10.0f, 10.0f, 1.0f));
	player->setBounds(engine::Bounds(player->GetScale()));

	engine::Animation* idleAnim = new engine::Animation(0.5f);

	idleAnim->AddFrames(math::Rect(math::Vector2(0.0f, 0.0f), math::Vector2(2 * 200.0f, 246.0f)), math::Vector2(1200.0f, 1233.0f), 2);

	player->AddAnimation(idleAnim);

	engine::Animation* runAnim = new engine::Animation(1.5f);

	runAnim->AddFrames(
		math::Rect(math::Vector2(0.0f, 0.0f), math::Vector2(1200.0f, 1233.0f)),
		math::Vector2(1200.0f, 1233.0f),
		math::Vector2(6.0f, 5.0f)
	);

	player->AddAnimation(runAnim);


	Enemy* enemy = CreateEntity<Enemy>();

	enemy->SetPosition(math::Vector3(10.0f, 0.0f, 0.0f));
	enemy->SetScale(math::Vector3(10.0f, 10.0f, 1.0f));
	enemy->setBounds(engine::Bounds(enemy->GetScale()));

	engine::Texture* enemyTex = new engine::Texture("res/assets/images.png");

	enemy->SetTexture(*enemyTex);
}