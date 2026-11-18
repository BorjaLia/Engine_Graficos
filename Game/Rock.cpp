#include "Rock.h"

Rock::Rock(const std::string& texturePath)
{
	texture = engine::Texture(texturePath);

	dir = { 0.0f,0.0f,0.0f };
}

Rock::~Rock()
{
}

void Rock::Start()
{
	engine::Sprite::Start();
}

void Rock::Update()
{
	engine::Sprite::Update();
	PhysicsObject::Update();
}

void Rock::AddAnimation(engine::Animation* animation)
{
	SetAnimation(animation);
}

void Rock::OnContactOverride()
{
}