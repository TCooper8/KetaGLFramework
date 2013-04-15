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

		static int MouseLeft;
		static int MouseRight;
		static int Up;
		static int Down;

		MouseState();
		MouseState(MouseState &state);
		MouseState(int button, int state, int x, int y);

		bool operator==(const MouseState &state) const;
		bool operator!=(const MouseState &state) const;
		MouseState &operator=(const MouseState &state);
	};
	
	//Allows retrieval of position and button clicks from a mouse input device.
	class Mouse sealed
	{
	public:
		//Represents the current state of the mouse.
		static MouseState CurrentState;

		//Called when OpenGL invokes its MouseFunc.
		static void MouseCallback(int button, int state, int x, int y);
		//Called when OpenGL invokes its PassiveMotionFunc.
		static void MouseMotionCallback(int x, int y);
	};

#endif
}