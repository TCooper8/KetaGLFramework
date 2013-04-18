namespace KetaInput
{
#ifndef Mouse_h
#define Mouse_h

	class MouseState
	{
	public:
		int Button;
		int State;

		static int MouseLeft;
		static int MouseRight;
		static int Up;
		static int Down;

		MouseState();
		MouseState(MouseState &state);
		MouseState(int button, int state);

		bool operator==(const MouseState &state) const;
		bool operator!=(const MouseState &state) const;
		MouseState &operator=(const MouseState &state);
	};
	
	//Allows retrieval of position and button clicks from a mouse input device.
	class Mouse sealed
	{
	private:
		//Represents the current state of the mouse.
		static MouseState currentState;
		//Represents the current x-position of the mouse.
		static int mouseX;
		//Represents the current y-position of the mouse.
		static int mouseY;

	public:
		static MouseState GetState();
		static int GetX();
		static int GetY();

		//Called when OpenGL invokes its MouseFunc.
		static void MouseCallback(int button, int state, int x, int y);
		//Called when OpenGL invokes its PassiveMotionFunc.
		static void MouseMotionCallback(int x, int y);
	};

#endif
}