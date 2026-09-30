#include "Game.h"

#include "Shape.h"

#include "BlueSquare.h"
#include "PinkSquare.h"

#include "Vector2.h"
#include "Vertex.h"


int main()
{
	MyGame game;

	game.Run();

	return 0;
}

void MyGame::Start()
{

	BlueSquare* blueSquare = new BlueSquare();
	blueSquare->setPosition(math::Vector3(0.0f, 0.0f, 0.0f));
	blueSquare->setTint(utils::Color::white());

	blueSquare->AddVertex(math::Vertex(math::Vector2(-0.1f, -0.1f), utils::Color::blue()));
	blueSquare->AddVertex(math::Vertex(math::Vector2(-0.1f, 0.1f), utils::Color::blue()));
	blueSquare->AddVertex(math::Vertex(math::Vector2(0.1f, 0.1f), utils::Color::blue()));
	blueSquare->AddVertex(math::Vertex(math::Vector2(0.1f, -0.1f), utils::Color::blue()));

	blueSquare->Setindex({ 0,1,2,2,3,0 });

	blueSquare->SetborderOffset({0.15f,0.15f});

	AddEntity(blueSquare);

	PinkSquare* pinkSquare = new PinkSquare();
	pinkSquare->setPosition(math::Vector3(0.0f, 0.0f, 0.0f));
	pinkSquare->setTint(utils::Color::white());

	pinkSquare->AddVertex(math::Vertex(math::Vector2(-0.1f, -0.1f), utils::Color::pink()));
	pinkSquare->AddVertex(math::Vertex(math::Vector2(-0.1f, 0.1f), utils::Color::pink()));
	pinkSquare->AddVertex(math::Vertex(math::Vector2(0.1f, 0.1f), utils::Color::pink()));
	pinkSquare->AddVertex(math::Vertex(math::Vector2(0.1f, -0.1f), utils::Color::pink()));

	pinkSquare->Setindex({ 0,1,2,2,3,0 });

	AddEntity(pinkSquare);
}
