#include "SceneManager.h"

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

	if (currentScene != nullptr) currentScene->Shutdown();

	currentScene = queuedScene;
	queuedScene = nullptr;

	currentScene->Setup();

	entities = currentScene->entities;

	currentScene->Start();
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
	scenes.push_back(scene);
}

void engine::SceneManager::LoadScene(int index)
{
	if (index < 0) return;
	if (index > scenes.size()) return;

	queuedScene = scenes[index];
}