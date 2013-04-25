#include "Keys.h"

namespace KetaInput
{
#ifndef Keyboard_h
#define Keybaord_h
	
	//Represents a state of keystrokes recorded by a keyboard input device.
	class KeyboardState
	{
	private:
		bool keymap[256];

	public:
		KeyboardState();
		KeyboardState(bool keys[]);

		const bool *GetKeys() const;
		bool IsKeyDown(unsigned char key) const;
		bool IsKeyUp(unsigned char key) const;
		void SetKeyDown(unsigned char key);
		void SetKeyUp(unsigned char key);
	};

	//Allows retrieval of keystrokes from a keyboard input device.
	class Keyboard sealed
	{
	private:
		//Represents the current keyboard state.
		static KeyboardState currentState;

	public:
		//Returns the current keyboard state.
		static const KeyboardState &GetState();

		//Called when OpenGL invokes its KeyboardFunc.
		static void KeyboardCallback(unsigned char c, int x, int y);
		//Called when OpenGL invokes its KeyboardUpFunc.
		static void KeyboardUpCallback(unsigned char c, int x, int y);
	};

#endif
}