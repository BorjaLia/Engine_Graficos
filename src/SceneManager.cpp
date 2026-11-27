#include "SceneManager.h"
#include "CollisionManager.h"

engine::SceneManager* engine::SceneManager::instance = nullptr;;

engine::SceneManager* engine::SceneManager::Get()
{
	if (instance == nullptr)
	{
		instance = new engine::SceneManager();
	}
	return instance;
}

void engine::SceneManager::Initialize()
{
	LoadScene(0);
}

void engine::SceneManager::Update(std::vector<Entity*>& entities)
{
	if (queuedScene == nullptr) return;
	std::cout << std::endl;
	std::cout << "Changing to scene " << queuedScene->GetName() << " (" << queuedScene->GetId() << ")" << "..." << std::endl;

	if (currentScene != nullptr) currentScene->Shutdown();

	currentScene = queuedScene;
	queuedScene = nullptr;

	std::cout << "Starting setup for " << currentScene->GetName() << " (" << currentScene->GetId() << ")" << std::endl;
	
	std::cout << std::endl << "{" << std::endl;
	currentScene->Setup();
	std::cout << "}" << std::endl << std::endl;

	entities = currentScene->entities;

	std::cout << "Calling start for " << currentScene->GetName() << " (" << currentScene->GetId() << ")" << std::endl;
	std::cout << std::endl << "{" << std::endl;
	currentScene->Start();
	std::cout << "}" << std::endl << std::endl;

	CollisionManager::Get()->SetEntities(&currentScene->entities);

	std::cout << "Scene " << currentScene->GetName() << " (" << currentScene->GetId() << ")" << " has been loaded" << std::endl;
	std::cout << std::endl;
}

void engine::SceneManager::Shutdown()
{
	for (int i = 0; i < scenes.size(); i++)
	{
		scenes[i]->Shutdown();
		delete scenes[i];
		scenes[i] = nullptr;
	}
}

void engine::SceneManager::RegisterScene(Scene* scene)
{
	std::cout << "Registered Scene " << scene->GetName() << std::endl;
	scene->SetId(scenes.size());
	scenes.push_back(scene);
}

void engine::SceneManager::LoadScene(int index)
{
	if (index < 0) return;
	if (index > scenes.size()) return;

	queuedScene = scenes[index];
}