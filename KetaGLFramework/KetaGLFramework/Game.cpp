#include <glut.h>
#include "Game.h"

using namespace KetaFramework;

Game::Game()
	:isActive(true)
{
	GameInstance = this;
}

void Game::Initialize(int argc, char** argv)
{
	this->window.Resize(parameters.BackBufferWidth, parameters.BackBufferHeight);

	glutInit(&argc, argv);

	glutInitDisplayMode(parameters.DisplayMode);
	glutInitWindowSize(parameters.BackBufferWidth, parameters.BackBufferHeight);
	glutInitWindowPosition(parameters.WindowPositionX, parameters.WindowPositionY);

	if (parameters.FullScreen)
	{
		glutGameModeString(parameters.GameModeString);
		glutEnterGameMode();
	}
	else
		glutCreateWindow(this->window.Title);

	glutDisplayFunc(DisplayCallback);
	glutReshapeFunc(ReshapeCallback);
	glutMouseFunc(MouseCallback);

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

void Game::Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();
}

void Game::Reshape(int width, int height)
{
	if (!window.AllowUserResizing)
		return;

	window.Resize(width, height);

	glViewport(0, 0, width, height);

	glMatrixMode(parameters.MatrixMode);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
}

void Game::Update()
{
}

void Game::DisplayCallback(void)
{
	GameInstance->Tick();
}

void Game::MouseCallback(int mouseButton, int mouseState, int x, int y)
{
	glutPostRedisplay();	
}

void Game::ReshapeCallback(int width, int height)
{
	GameInstance->Reshape(width, height);
}

Game* Game::GameInstance = nullptr;