#include "CollisionManagerEntity.h"
#include "CollisionManager.h"


CollisionManagerEntyty::CollisionManagerEntyty()
{
	texture = engine::Texture("res/assets/images.png");
}

CollisionManagerEntyty::~CollisionManagerEntyty()
{
}

void CollisionManagerEntyty::Start()
{
	engine::Sprite::Start();
}

void CollisionManagerEntyty::Update()
{
	engine::Sprite::Update();
	for (int i = 0; i < entities.size()-1; i++)
	{
		if (manager.IsCollidingAABB(*entities[i], *entities[i + 1]))
		{
			math::Vector3 difference = entities[i]->GetPosition();

			difference.x -= entities[i+1]->GetPosition().x;
			difference.y -= entities[i+1]->GetPosition().y;
			difference.z -= entities[i+1]->GetPosition().z;
			
			entities[i]->AddForce(difference);
			entities[i+1]->AddForce(difference * -1);
		}
	}
}

void CollisionManagerEntyty::Draw()
{

}