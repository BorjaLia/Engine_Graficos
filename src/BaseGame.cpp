#include "BaseGame.h"

#include "Shape.h"

engine::BaseGame::BaseGame()
{
}

engine::BaseGame::~BaseGame()
{
}

void engine::BaseGame::Run()
{
	Initialize();

	while (isRunning)
	{
		window.Update();
		renderer->Update();
		for (Entity* e : entities)
		{
			if (Shape* shape = dynamic_cast<Shape*>(e))
			{
				shape->Draw();
			}
		}

		isRunning = !window.ShouldClose();
	}

	Shutdown();
}

void engine::BaseGame::Initialize()
{
	window.Initialize();
	renderer->Initialize(window);

	Shape* e1 = new Shape();
	e1->setPosition(math::Vector3(0, 0, 0));
	e1->setTint(utils::Color::white());
	AddEntity(e1);

	Shape* e2 = new Shape();
	e2->setPosition(math::Vector3(0.5, 0.5, 0.5));
	e2->setTint(utils::Color::white());
	AddEntity(e2);

	for (Entity* e: entities)
	{
		e->Initialize();
	}
}

void engine::BaseGame::Shutdown()
{
	window.Shutdown();
}

void engine::BaseGame::AddEntity(Entity* entity)
{
	entities.push_back(entity);
}
