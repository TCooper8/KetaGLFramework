#include "Rectangle.h"

namespace KetaFramework
{
#ifndef GameWindow_h
#define GameWindow_h

	class GameWindow
	{
	public:
		bool AllowUserResizing;
		Rectangle ClientBounds;
		char* Title;

		GameWindow();

		void Resize(int width, int height);
	};

#endif
}