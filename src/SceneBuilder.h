#include "Core.h"

#include "Entity.h"
#include <queue>

/// The class that handles loading the scenes with entities
/// @ingroup Scenes

//namespace engine
//{
//	class ENGINE_API SceneBuilder
//	{
//	protected:
//
//	public:
//
//		SceneBuilder(Scene* loadScene) {this->loadScene = loadScene};
//
//		~SceneBuilder()
//		{
//			while (!entityQueue.empty())
//			{
//				delete entityQueue.front();
//				entityQueue.pop();
//			}
//		};
//
//
//
//	private:
//
//		Scene* loadScene;
//
//		std::queue<Entity*> entityQueue;
//	};
//}