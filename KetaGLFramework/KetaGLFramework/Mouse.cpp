#include <glut.h>
#include "Mouse.h"

namespace KetaInput
{
	int MouseState::MouseLeft = GLUT_LEFT_BUTTON;
	int MouseState::MouseRight = GLUT_RIGHT_BUTTON;
	int MouseState::Up = GLUT_UP;
	int MouseState::Down = GLUT_DOWN;

	MouseState::MouseState()
		: X(0), Y(0), Button(0), State(GLUT_UP)
	{ }

	MouseState::MouseState(MouseState &state)
		: X(state.X), Y(state.Y), Button(state.Button), State(state.State)
	{ }

	MouseState::MouseState(int button, int state, int x, int y)
		: X(x), Y(y), Button(button), State(state)
	{ }

	bool MouseState::operator==(const MouseState &state) const
	{
		return 
			(X == state.X) &&
			(Y == state.Y) &&
			(Button == state.Button) &&
			(State == state.State);
	}

	bool MouseState::operator!=(const MouseState &state) const
	{
		return !(*this == state);
	}

	MouseState &MouseState::operator=(const MouseState &state)
	{
		X = state.X;
		Y = state.Y;
		Button = state.Button;
		State = state.State;

		return *this;
	}

	void Mouse::MouseCallback(int button, int state, int x, int y)
	{
		CurrentState = MouseState(button, state, x, y);
	}

	void Mouse::MouseMotionCallback(int x, int y)
	{
		CurrentState.X = x;
		CurrentState.Y = y;
	}

	MouseState Mouse::CurrentState(0, GLUT_UP, 0, 0); 
}
