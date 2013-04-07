#include <iostream>
#include <glut.h>
#include "Keta.h"

using namespace std;
using namespace KetaFramework;
using namespace KetaInput;

class Game1 : public Game
{
public:
	Game1()
		: Game()
	{
	}

	virtual void Initialize(int argc, char** argv) override
	{
		Game::Initialize(argc, argv);
	}

	virtual void Update() override
	{
		if(Keyboard::CurrentState.Char == 27)
		{
			exit(0);
		}

		Game::Update();
	}
};

int main(int argc, char** argv)
{
	Game1 game1 = Game1();
	game1.Initialize(argc, argv);
	game1.Run();

	return 0;
}