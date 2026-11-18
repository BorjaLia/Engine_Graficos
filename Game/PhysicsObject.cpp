#include "PhysicsObject.h"

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
