#include <glut.h>
#include "Keyboard.h"
#include "Mouse.h"
#include "Game.h"


namespace KetaFramework
{
	using namespace KetaGraphics;

	Game::Game()
		:isActive(true), graphicsDevice(PresentationParameters())
	{
		GameInstance = this;
	}

	void Game::Initialize(int argc, char** argv)
	{
		this->window.Resize(Parameters.BackBufferWidth, Parameters.BackBufferHeight);

		glutInit(&argc, argv);

		glutInitDisplayMode(Parameters.DisplayMode);
		glutInitWindowSize(Parameters.BackBufferWidth, Parameters.BackBufferHeight);
		glutInitWindowPosition(Parameters.WindowPositionX, Parameters.WindowPositionY);

		if (Parameters.FullScreen)
		{
			glutGameModeString(Parameters.GameModeString);
			glutEnterGameMode();
		}
		else
			this->window.SetHandle(glutCreateWindow(this->window.Title));

		glutDisplayFunc(DisplayCallback);
		glutKeyboardFunc(KetaInput::Keyboard::KeyboardCallback);
		glutKeyboardUpFunc(KetaInput::Keyboard::KeyboardUpCallback);
		glutReshapeFunc(ReshapeCallback);
		glutMouseFunc(KetaInput::Mouse::MouseCallback);
		glutPassiveMotionFunc(KetaInput::Mouse::MouseMotionCallback);

		glClearColor(1, 1, 1, 0);
	}

	void Game::Run()
	{
		glutMainLoop();
	}

	void Game::Tick()
	{
		if (!this->isActive)
			return;

		this->Update();
		this->Draw();

		glutPostRedisplay();
	}

	const bool Game::GetIsActive() const
	{
		return this->isActive;
	}

	GraphicsDevice &Game::GetGraphicsDevice()
	{
		return this->graphicsDevice;
	}

	GameWindow &Game::GetWindow()
	{
		return this->window;
	}

	void Game::Draw(void)
	{
	}

	void Game::Reshape(int width, int height)
	{
		if (!window.AllowUserResizing)
			return;

		window.Resize(width, height);

		glViewport(0, 0, width, height);

		glMatrixMode(Parameters.MatrixMode);
		glLoadIdentity();
		//gluOrtho2D(0, width, 0, height);
		glOrtho(-10, 10, -10, 10, -10, 50);
	}

	void Game::Update()
	{
	}

	void Game::DisplayCallback(void)
	{
		GameInstance->Tick();
	}

	void Game::ReshapeCallback(int width, int height)
	{
		GameInstance->Reshape(width, height);
	}

	Game* Game::GameInstance = nullptr;
}