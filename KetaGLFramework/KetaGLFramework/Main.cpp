#include <iostream>
#include <glut.h>
#include "Keta.h"

using namespace std;
using namespace KetaFramework;
using namespace KetaGraphics;
using namespace KetaInput;

double theta = 0;

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

		glColor3d(1, 0, 0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);
		glRotated(theta, 0, 1, 0);
		glutWireCube(5);
		
		theta += 0.01;

		Game::Draw();
		spriteBatch.End();
	}
};

int main(int argc, char** argv)
{
	Game1 game1 = Game1();
	game1.Initialize(argc, argv);

	glLoadIdentity();
	glOrtho(-4, 4, -4, 4, -4, 4);

	game1.Run();

	return 0;
}