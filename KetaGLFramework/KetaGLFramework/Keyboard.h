namespace KetaInput
{
#ifndef Keyboard_h
#define Keybaord_h
	
	//Represents a state of keystrokes recorded by a keyboard input device.
	class KeyboardState
	{
	public:
		unsigned char Char;
		int X;
		int Y;

		KeyboardState(unsigned char c, int x, int y);
	};

	//Allows retrieval of keystrokes from a keyboard input device.
	class Keyboard sealed
	{
	public:
		//Returns the current keyboard state.
		static KeyboardState CurrentState;

		//Called when OpenGL invokes its KeyboardFunc.
		static void KeyboardCallback(unsigned char c, int x, int y);
	};

#endif
}