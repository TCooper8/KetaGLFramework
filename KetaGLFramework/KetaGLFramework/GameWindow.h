#include "Rectangle.h"

namespace KetaFramework
{
#ifndef GameWindow_h
#define GameWindow_h

	//The system window associated with a Game.
	class GameWindow
	{
	private:
		Rectangle clientBounds;
		int handle;
		char* title;

	public:
		//Specifies whether to allow the user to resize the game window.
		bool AllowUserResizing;

		//Creates a new instance of GameWindow.
		GameWindow();
		GameWindow(GameWindow &window);

		//Handles window resizing.
		void Resize(int width, int height);

		//The screen dimensions of the game window's client rectangle.
		Rectangle &GetClientBounds();
		//Gets the current window handle.
		int GetHandle() const;
		//Sets the current window handle.
		void SetHandle(int handle);
		//Gets the title of the system window.
		char* &GetTitle();
		//Sets the title of the system window.
		void SetTitle(char* title);

		__declspec(property( get = GetClientBounds ))
			Rectangle ClientBounds;
		__declspec(property( get = GetTitle, put = SetTitle))
			char* Title;
	};

#endif
}