#include <iostream>
#include "Keta.h"
#include <glut.h>

using namespace std;
using namespace KetaFramework;
using namespace KetaGraphics;
using namespace KetaInput;

double theta = 0;

class Game1 : public Game
{
public:
	SpriteBatch spriteBatch;
	MouseState currentMouse, previousMouse;

	VertexBuffer buffer;

	Game1()
		: Game()
	{
	}

	virtual void Initialize(int argc, char** argv) override
	{
		Game::Initialize(argc, argv);

		VertexPositionColor* vertices = new VertexPositionColor[4];
		vertices[0] = VertexPositionColor(Vector3(-1, -1) * 5, Color4::Black);
		vertices[1] = VertexPositionColor(Vector3(-1, 1) * 5, Color4::Blue);
		vertices[2] = VertexPositionColor(Vector3(1, 1) * 5, Color4::Red);
		vertices[3] = VertexPositionColor(Vector3(1, -1) * 5, Color4::Green);

		buffer = VertexBuffer(vertices, 4, GL_QUADS);

		Matrix m = Matrix::CreateLookAt(Vector3(0, 0, -10), Vector3(0), Vector3::UnitY);

		cout << '[';
		for (int x = 0; x < Matrix::Width; x++)
		{
			for (int y = 0; y < Matrix::Height; y++)
			{
				cout << m.Element[x][y] << ',';
			}
			cout << endl;
		}
		cout << ']' << endl;
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

		glMatrixMode(GL_MODELVIEW);  
		glLoadIdentity();
		gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);
		glRotated(theta, 0, 1, 0);

		this->graphicsDevice.DrawPrimitives(buffer.GetDeclaration(), buffer.GetVertices(), buffer.GetCount());
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