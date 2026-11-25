#include "GameManager.h"

#include "SceneManager.h"
#include "MathUtils.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::Initialize()
{
	std::cout << "\nGame manager initialized" << std::endl;
}

void GameManager::Start()
{
	const engine::Scene& currentScene = engine::SceneManager::Get()->GetCurrentScene();
	
	for(Entity* e : currentScene.GetEntityVector())
	{
		if (Player* p = dynamic_cast<Player*>(e))
		{
			player = p;
			std::cout << "\nFound player!" << std::endl;
			break;
		}
		std::cout << "\nCouldnt find player!" << std::endl;
	}
}

static int GetNormalDir(float value)
{
	if (value > math::epsilon) return 1;
	if (value < -math::epsilon) return -1;
	return 0;
}

static math::Vector2 GetNormalDir(math::Vector2 dir)
{
	return math::Vector2(GetNormalDir(dir.x), GetNormalDir(dir.y));
}

void GameManager::Update()
{
	math::Vector2 dir = player->GetDir();

	math::Vector2 currentDir = GetNormalDir(dir);
	math::Vector2 previousDir = GetNormalDir(lastDir);

	bool wasMoving = (previousDir.x != 0 || previousDir.y != 0);
	bool isMoving = (currentDir.x != 0 || currentDir.y != 0);

	if (wasMoving && !isMoving)
	{
		std::cout << "\nGame manager detected stop!" << std::endl;
	}
	else
	{
		if (currentDir.x != previousDir.x)
		{
			if (currentDir.x > 0)
			{
				std::cout << "\nGame manager detected starting to move right!" << std::endl;
			}
			else if (currentDir.x < 0)
			{
				std::cout << "\nGame manager detected starting to move left!" << std::endl;
			}
		}

		if (currentDir.y != previousDir.y)
		{
			if (currentDir.y > 0)
			{
				std::cout << "\nGame manager detected starting to move up!" << std::endl;
			}
			else if (currentDir.y < 0)
			{
				std::cout << "\nGame manager detected starting to move down!" << std::endl;
			}
		}
	}

	lastDir = dir;
}

void GameManager::Draw()
{
}