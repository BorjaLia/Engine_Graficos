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
}

void Enemy::OnCollision(engine::Entity2D* other)
{
	std::cout << "Enemy collided with something" << std::endl;
}