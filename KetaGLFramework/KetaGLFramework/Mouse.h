namespace KetaInput
{
#ifndef Mouse_h
#define Mouse_h

	class MouseState
	{
	public:
		int X;
		int Y;
		int Button;
		int State;

		MouseState(int button, int state, int x, int y);
	};

	class Mouse sealed
	{
	public:
		static MouseState CurrentState;

		static void MouseCallback(int button, int state, int x, int y);
	};

#endif
}