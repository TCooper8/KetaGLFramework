namespace KetaFramework
{
#ifndef LaunchParameters_h
#define LaunchParameters_h

	class LaunchParameters
	{
	public:
		unsigned int DisplayMode;
		unsigned int MatrixMode;
		int BackBufferWidth;
		int BackBufferHeight;
		int WindowPositionX;
		int WindowPositionY;
		bool FullScreen;
		char* GameModeString;

		LaunchParameters();
	};

#endif
}