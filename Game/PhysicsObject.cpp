#include "PhysicsObject.h"

#include "CollisionManager.h"

PhysicsObject::PhysicsObject()
{
}

PhysicsObject::~PhysicsObject()
{
}

void PhysicsObject::Start()
{
}

void PhysicsObject::Update()
{
	float deltaTime = engine::Time::GetDeltaTime();

	dir.x *= drag;

	CheckCollisions();

	math::Vector3 currentPos = this->GetPosition();
	math::Vector3 nextPos = currentPos + (dir * deltaTime);

	if (nextPos.y <= lowerLimit)
	{
		math::Vector3 correctedPos = currentPos;
		correctedPos.y = lowerLimit;
		this->SetPosition(correctedPos);
		dir.y = 0.0f;
	}

	dir.y -= gravity * deltaTime;

	this->SetPosition(this->GetPosition() + (dir * deltaTime));
}

void PhysicsObject::AddForce(math::Vector3 force)
{
	dir += force;
}

void PhysicsObject::CheckCollisions()
{
	engine::CollisionManager manager;

	if (other == nullptr) return;

	if (manager.IsCollidingAABB(*this, *other)) OnContact();
}

void PhysicsObject::OnContact()
{
	std::cout << "Contact!" << std::endl;

	OnContactOverride();

	math::Vector3 forceDir = this->GetPosition();

	forceDir.x -= other->GetPosition().x;
	forceDir.y -= other->GetPosition().y;
	forceDir.z -= other->GetPosition().z;

	AddForce(forceDir + forceDir);
}

void PhysicsObject::OnContactOverride()
{
}