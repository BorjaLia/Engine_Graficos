#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Start()
{
	engine::Sprite::Start();
}

void Enemy::Update()
{
	engine::Sprite::Update();
	this->SetPosition(this->GetPosition() + (dir * pushForce * engine::Time::GetDeltaTime()));
	
	dir = math::Vector3::zero();
}

void Enemy::OnCollision(engine::Entity2D* other)
{
	std::cout << "Enemy collided with something" << std::endl;
	this->dir = (this->GetPosition() - other->GetPosition()) * 20.0f;
}