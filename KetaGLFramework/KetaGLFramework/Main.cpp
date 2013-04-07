#include <iostream>
#include <glut.h>
#include "Keta.h"

using namespace std;
using namespace KetaFramework;
using namespace KetaGraphics;
using namespace KetaInput;

class Game1 : public Game
{
public:
	SpriteBatch spriteBatch;

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

	virtual void Draw() override
	{
		graphicsDevice.Clear(Color4::White);
		spriteBatch.Begin(BlendState::AlphaBlend);

		glColor4d(1, 0, 0, .5);
		graphicsDevice.DrawCircle(100, 100, 50);
		glColor4d(0, 1, 0, .5);
		graphicsDevice.DrawCircle(150, 100, 50);
		glColor4d(0, 0, 1, .5);
		graphicsDevice.DrawCircle(125, 150, 50);

		Game::Draw();
		spriteBatch.End();
	}
};

int main(int argc, char** argv)
{
	Game1 game1 = Game1();
	game1.Initialize(argc, argv);
	game1.Run();

	return 0;
}