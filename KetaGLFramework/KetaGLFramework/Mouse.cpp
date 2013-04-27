#include <glut.h>
#include "Mouse.h"

namespace KetaFramework
{
	namespace KetaInput
	{
		int MouseState::MouseLeft = GLUT_LEFT_BUTTON;
		int MouseState::MouseRight = GLUT_RIGHT_BUTTON;
		int MouseState::Up = GLUT_UP;
		int MouseState::Down = GLUT_DOWN;

		MouseState::MouseState()
			: Button(0), State(GLUT_UP)
		{ }

		MouseState::MouseState(MouseState &state)
			: Button(state.Button), State(state.State)
		{ }

		MouseState::MouseState(int button, int state)
			: Button(button), State(state)
		{ }

		bool MouseState::operator==(const MouseState &state) const
		{
			return 
				(Button == state.Button) &&
				(State == state.State);
		}

		bool MouseState::operator!=(const MouseState &state) const
		{
			return !(*this == state);
		}

		MouseState &MouseState::operator=(const MouseState &state)
		{
			Button = state.Button;
			State = state.State;

			return *this;
		}

		void Mouse::MouseCallback(int button, int state, int x, int y)
		{
			currentState = MouseState(button, state);
		}

		void Mouse::MouseMotionCallback(int x, int y)
		{
			mouseX = x;
			mouseY = y;
		}

		MouseState Mouse::currentState(0, GLUT_UP); 
		int Mouse::mouseX = 0;
		int Mouse::mouseY = 0;

		MouseState Mouse::GetState()
		{
			return currentState;
		}

		int Mouse::GetX()
		{
			return mouseX;
		}

		int Mouse::GetY()
		{
			return mouseY;
		}
	}
}