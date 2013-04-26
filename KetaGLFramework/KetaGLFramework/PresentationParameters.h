#include "Rectangle.h"

namespace KetaGraphics
{
#ifndef KetaGraphics_PresentationParameters
#define KetaGraphics_PresentationParameters

	//Contains information about the current device window.
	class PresentationParameters
	{
	private:
		int backBufferHeight;
		int backBufferWidth;
		KetaFramework::Rectangle bounds;
		int* windowHandle;
		bool isFullScreen;

	public:
		//Initializes a new instance of this class.
		PresentationParameters();
		//Copies an instance of this class.
		PresentationParameters(const PresentationParameters &parameters);

		//Gets the value representing the height of the new swap chain's back buffer.
		const int GetBackBufferHeight() const;
		//Sets the value representing the height of the new swap chain's back buffer.
		void SetBackBufferHeight(int height);
		//Gets the value representing the width of the new swap chain's back buffer.
		const int GetBackBufferWidth() const;
		//Sets the value representing the width of the new swap chain's back buffer.
		void SetBackBufferWidth(int width);
		//Gets the current window bounds.
		const KetaFramework::Rectangle &GetBounds() const;
		//Gets the handle to the device window.
		const int* GetDeviceWindowHandle() const;
		//Sets the handle to the device window.
		void SetDeviceWindowHandle(int* handle);
		//Gets the value indicating whether the application is in full screen mode.
		const bool GetIsFullScreen() const;
		//Sets the value indicating whether the application is in full screen mode.
		void SetIsFullScreen(bool isFullScreen);
	};

#endif
}