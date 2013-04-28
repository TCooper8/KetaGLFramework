#include <iostream>
#include <glut.h>
#include <ctime>
#include "Keta.h"

using namespace std;
using namespace KetaFramework;
using namespace KetaGraphics;
using namespace KetaInput;
using namespace KetaContent;

double theta = 0;

int blipCount = 0;
const int blipLimit = 1000;
Vector3 blips[blipLimit];
Vector3 blipsV[blipLimit];

void AddBlip(const Vector3 &position)
{
	if (blipCount >= blipLimit)
		return;

	blips[blipCount] = position;
	blipsV[blipCount] = Vector3::Zero;
	blipCount++;
}

class Game1 : public Game
{
public:
	ContentManager Content;
	SpriteBatch spriteBatch;
	MouseState currentMouse, previousMouse;

	VertexBuffer buffer;
	Texture2D tileset;
	Texture2D ball;

	Rectangle bounds;
	Vector3 origin;
	double scale;
	double radius;

	Game1()
		: Game(), Content(&graphicsDevice, "Content/")
	{
	}

	virtual void Initialize(int argc, char** argv) override
	{
		Game::Initialize(argc, argv);

		//tileset = Content.LoadTexture("Textures/terrain.ki");
		ball = Content.LoadTexture("Textures/ShieldRaw.ki");
		bounds = Rectangle(0, 0, 32, 32);
		scale = 0.2;
		origin = Vector3(ball.GetWidth() / 2, ball.GetHeight() / 2);

		radius = origin.X * scale;
	}

	virtual void Update() override
	{
		previousMouse = currentMouse;
		currentMouse = Mouse::GetState();

		if(Keyboard::GetState().IsKeyDown(Keys::Escape))
			exit(0);
		
		if (currentMouse.Button == MouseState::MouseLeft && previousMouse.Button == MouseState::MouseLeft)
			if (currentMouse.State == MouseState::Up && previousMouse.State == MouseState::Down)
				AddBlip(Vector3(Mouse::GetX(), window.ClientBounds.Height - Mouse::GetY(), 0));


		for (int i = 0; i < blipCount; i++)
		{
			Vector3 force = Vector3(0, -0.0001, 0);

			if (blips[i].Y < 10)
			{
				blips[i].Y = 10;
				blipsV[i].Y *= -1;
			}
			else if (blips[i].Y > window.ClientBounds.Height)
			{
				blips[i].Y = window.ClientBounds.Height;
				blipsV[i].Y *= -1;
			}
			if (blips[i].X < 10)
			{
				blips[i].X = 10;
				blipsV[i].X *= -1;
			}
			else if (blips[i].X > window.ClientBounds.Width)
			{
				blips[i].X = window.ClientBounds.Width;
				blipsV[i].X *= -1;
			}

			for (int j = 0; j < blipCount; j++)
			{
				if (i == j)
					continue;

				Vector3 normal = blips[j] - blips[i];
				double distance = normal.LengthSquared();
				if (distance < 1000)
				{
					normal.Normalize();

					blipsV[i] -= normal / 1000;
					blipsV[j] += normal / 1000;
				}
			}

			blipsV[i] += force;
			blips[i] += blipsV[i];
		}

		Game::Update();
	}

	virtual void Draw() override
	{
		GetGraphicsDevice().Clear(Color4::White);
		spriteBatch.Begin(BlendState::AlphaBlend);

		for (int i = 0; i < blipCount; i++)
		{
			spriteBatch.Draw(ball, blips[i], scale, origin);
		}

		theta += 0.01f;

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
	srand(time(0));
	CompileTextures();

	Game1 game1 = Game1();
	game1.Initialize(argc, argv);

	//glLoadIdentity();
	//glOrtho(-4, 4, -4, 4, -4, 4);

	game1.Run();

	return 0;
}