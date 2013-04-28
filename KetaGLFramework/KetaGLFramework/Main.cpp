#include <iostream>
#include <glut.h>
#include "Keta.h"

using namespace std;
using namespace KetaFramework;
using namespace KetaGraphics;
using namespace KetaInput;
using namespace KetaContent;

double theta = 0;

class Game1 : public Game
{
public:
	ContentManager Content;
	SpriteBatch spriteBatch;
	MouseState currentMouse, previousMouse;

	VertexBuffer buffer;

	Texture2D textureShield;

	Game1()
		: Game(), Content(&graphicsDevice, "Content/")
	{
	}

	virtual void Initialize(int argc, char** argv) override
	{
		Game::Initialize(argc, argv);

		textureShield = Content.LoadTexture("Textures/terrain.ki");
	}

	virtual void Update() override
	{
		previousMouse = currentMouse;
		currentMouse = Mouse::GetState();

		if(Keyboard::GetState().IsKeyDown(Keys::Escape))
			exit(0);

		if (previousMouse.Button == MouseState::MouseLeft && currentMouse.Button == MouseState::MouseLeft)
			if (previousMouse.State == MouseState::Down && currentMouse.State == MouseState::Up)
				cout << 5 << endl;

		Game::Update();
	}

	virtual void Draw() override
	{
		GetGraphicsDevice().Clear(Color4::White);
		spriteBatch.Begin(BlendState::AlphaBlend);

		spriteBatch.Draw(textureShield, Vector3::Zero, Color4::White);

		Game::Draw();
		spriteBatch.End();
	}
};

void CompileTextures()
{
	system("Parser.bat Content/Textures");
}

int main(int argc, char** argv)
{
	CompileTextures();

	Game1 game1 = Game1();
	game1.Initialize(argc, argv);

	//glLoadIdentity();
	//glOrtho(-4, 4, -4, 4, -4, 4);

	game1.Run();

	return 0;
}