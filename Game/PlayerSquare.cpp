#include "PlayerSquare.h"

#include "Input.h"
#include "Window.h"
#include "GameTime.h"
#include "Shader.h"

#include "File.h"

#include <iostream>

PlayerSquare::PlayerSquare()
{
	dir = { 0.0f,0.0f,0.0f };
}

PlayerSquare::~PlayerSquare()
{
}

void PlayerSquare::Start()
{
	material = new engine::Material("../res/shaders/VertexTexture.shader", "../res/shaders/FragmentTexture.shader");

	engine::Texture* myTexture = new engine::Texture("res/assets/images.png");
	material->SetTexture(myTexture);
}

void PlayerSquare::Update()
{	
	time += engine::Time::GetDeltaTime();

	if (objectiveTime < static_cast<int>(time))
	{
		objectiveTime = static_cast<int>(time) + 2;
		//ShowPosition();
	}

	Teleport();

	Move();
}

void PlayerSquare::Teleport()
{
	queueTeleport = engine::Input::Get()->IsMouseButtonPressed(engine::MouseCode::Button0);

	if (queueTeleport && !isTeleporting)
	{
		queueTeleport = engine::Input::Get()->IsMouseButtonPressed(engine::MouseCode::Button0);

		if (queueTeleport && !isTeleporting)
		{
			math::Vector2 mouseWorldPos = engine::Input::Get()->GetMouseWorldPosition();

			this->SetPosition(mouseWorldPos);

			std::cout << "\n" << "Mouse World: " << mouseWorldPos.ToString() << std::endl;
		}

		isTeleporting = queueTeleport;
	}

	isTeleporting = queueTeleport;
}

void PlayerSquare::Move()
{
	dir = { 0.0f,0.0f,0.0f };

	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::W)) dir.y += 1.0f;
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::A)) dir.x -= 1.0f;
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::S)) dir.y -= 1.0f;
	if (engine::Input::Get()->IsKeyPressed(engine::KeyCode::D)) dir.x += 1.0f;

	this->SetPosition(this->GetPosition() + (dir * engine::Time::GetDeltaTime()));
}

void PlayerSquare::ShowPosition()
{
	std::cout << "Position: " << this->GetPosition().ToString() << std::endl;
}