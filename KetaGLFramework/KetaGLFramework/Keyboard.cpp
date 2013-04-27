#include <iostream>
#include <glut.h>
#include "Keyboard.h"

using namespace std;

namespace KetaFramework
{
	namespace KetaInput
	{
		KeyboardState::KeyboardState()
		{
			for (int i = 0; i < 256; i++)
			{
				keymap[i] = GLUT_UP;
			}
		}

		KeyboardState::KeyboardState(bool keys[])
		{
			for (int i = 0; i < 256; i++)
			{
				keymap[i] = keys[i];
			}
		}

		const bool *KeyboardState::GetKeys() const
		{
			return keymap;
		}

		bool KeyboardState::IsKeyDown(unsigned char key) const
		{
			return keymap[key] == GLUT_DOWN;
		}

		bool KeyboardState::IsKeyUp(unsigned char key) const
		{
			return keymap[key] == GLUT_UP;
		}

		void KeyboardState::SetKeyDown(unsigned char key)
		{
			keymap[key] = GLUT_DOWN;
		}

		void KeyboardState::SetKeyUp(unsigned char key)
		{
			keymap[key] = GLUT_UP;
		}

		KeyboardState Keyboard::currentState = KeyboardState();

		const KeyboardState &Keyboard::GetState()
		{
			return currentState;
		}

		void Keyboard::KeyboardCallback(unsigned char c, int x, int y)
		{
			currentState.SetKeyDown(c);
		}

		void Keyboard::KeyboardUpCallback(unsigned char c, int x, int y)
		{
			currentState.SetKeyUp(c);
		}
	}
}