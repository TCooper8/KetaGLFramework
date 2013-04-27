#include <cstring>
#include "GameWindow.h"

namespace KetaFramework
{
	GameWindow::GameWindow()
		: AllowUserResizing(true), clientBounds(0, 0, 700, 500), title("Keta Game")
	{ }

	GameWindow::GameWindow(const GameWindow &window)
		: AllowUserResizing(window.AllowUserResizing), clientBounds(window.GetClientBounds())
	{
		const int len = std::strlen(window.GetTitle());
		this->title = new char[len];

		strcpy(this->title, window.GetTitle());
	}

	void GameWindow::Resize(int width, int height)
	{
		this->clientBounds.Width = width;
		this->clientBounds.Height = height;
	}

	const Rectangle &GameWindow::GetClientBounds() const
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

	const char* GameWindow::GetTitle() const
	{
		return this->title;
	}
}