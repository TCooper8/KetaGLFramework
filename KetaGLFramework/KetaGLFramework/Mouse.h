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
	
	//Allows retrieval of position and button clicks from a mouse input device.
	class Mouse sealed
	{
	public:
		//Represents the current state of the mouse.
		static MouseState CurrentState;

		//Called when OpenGL invokes its MouseFunc.
		static void MouseCallback(int button, int state, int x, int y);
	};

#endif
}