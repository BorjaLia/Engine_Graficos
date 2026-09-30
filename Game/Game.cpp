#include "BaseGame.h"
#include "Shape.h"

class MyGame : public engine::BaseGame
{
public:
	void Start() override
	{


		engine::Shape* e1 = new engine::Shape();
		e1->setPosition(math::Vector3(0.0f, 0.0f, 0.0f));
		e1->setTint(utils::Color::white());
		AddEntity(e1);

		engine::Shape* e2 = new engine::Shape();
		e2->setPosition(math::Vector3(0.5f, 0.5f, 0.5f));
		e2->setTint(utils::Color::white());
		AddEntity(e2);
	}
};

int main()
{
	MyGame game;

	game.Run();

	return 0;
}