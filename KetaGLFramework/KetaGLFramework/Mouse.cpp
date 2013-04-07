#include "Mouse.h"

using namespace KetaInput;

MouseState::MouseState(int button, int state, int x, int y)
	: X(x), Y(y), Button(button), State(state)
{ }

void Mouse::MouseCallback(int button, int state, int x, int y)
{
	CurrentState = MouseState(button, state, x, y);
}

MouseState Mouse::CurrentState(0, 0, 0, 0);