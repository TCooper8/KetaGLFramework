#include "GameWindow.h"

namespace KetaFramework
{
	GameWindow::GameWindow()
		: AllowUserResizing(true), clientBounds(0, 0, 700, 500), title("Keta Game")
	{ }

	GameWindow::GameWindow(GameWindow &window)
		: AllowUserResizing(window.AllowUserResizing), clientBounds(window.ClientBounds), title(window.Title)
	{ }

	void GameWindow::Resize(int width, int height)
	{
		this->clientBounds.Width = width;
		this->clientBounds.Height = height;
	}

	Rectangle &GameWindow::GetClientBounds()
	{
		return this->clientBounds;
	}

	int GameWindow::GetHandle() const
	{
		return this->handle;
	}

	void GameWindow::SetHandle(int handle)
	{
		this->handle = handle;
	}

	char* &GameWindow::GetTitle()
	{
		return this->title;
	}
}