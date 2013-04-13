#include "Keyboard.h"

namespace KetaInput
{
	KeyboardState::KeyboardState(unsigned char c, int x, int y)
		: Char(c), X(x), Y(y)
	{ }

	void Keyboard::KeyboardCallback(unsigned char c, int x, int y)
	{
		Keyboard::CurrentState = KeyboardState(c, x, y);
	}

	KeyboardState Keyboard::CurrentState(0, 0, 0);
}