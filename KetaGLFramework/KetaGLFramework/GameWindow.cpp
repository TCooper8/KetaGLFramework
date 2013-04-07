#include "GameWindow.h"

using namespace KetaFramework;

GameWindow::GameWindow()
	: AllowUserResizing(true), ClientBounds(0, 0, 700, 500), Title("Keta Game")
{ }

void GameWindow::Resize(int width, int height)
{
	this->ClientBounds.Width = width;
	this->ClientBounds.Height = height;
}