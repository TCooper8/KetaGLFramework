namespace KetaInput
{
#ifndef Keyboard_h
#define Keybaord_h
	
	class KeyboardState
	{
	public:
		unsigned char Char;
		int X;
		int Y;

		KeyboardState(unsigned char c, int x, int y);
	};

	class Keyboard sealed
	{
	public:
		static KeyboardState CurrentState;

		static void KeyboardCallback(unsigned char c, int x, int y);
	};

#endif
}