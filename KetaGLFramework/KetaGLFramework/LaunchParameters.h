namespace KetaFramework
{
#ifndef KetaFramework_LaunchParameters
#define KetaFramework_LaunchParameters

	//The start up parameters for launching a Keta Game.
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