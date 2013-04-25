#include "Rectangle.h"

namespace KetaGraphics
{
#ifndef KetaGraphics_PresentationParameters
#define KetaGraphics_PresentationParameters

	//Contains information about the current device window.
	class PresentationParameters
	{
	public:
		//Initializes a new instance of this class.
		PresentationParameters();

		//Gets the value representing the height of the new swap chain's back buffer.
		const int GetBackBufferHeight() const;
		//Sets the value representing the height of the new swap chain's back buffer.
		void SetBackBufferHeight(const int height);
		//Gets the value representing the width of the new swap chain's back buffer.
		const int GetBackBufferWidth() const;
		//Sets the value representing the width of the new swap chain's back buffer.
		void SetBackBufferWidth(const int width);
		//Gets the current window bounds.
		const Rectangle &GetBounds() const;
		//Gets the handle to the device window.
		const int* GetDeviceWindowHandle() const;
		//Sets the handle to the device window.
		void SetDeviceWindowHandle(const int* handle);
		//Gets the value indicating whether the application is in full screen mode.
		const bool GetIsFullScreen() const;
		//Sets the value indicating whether the application is in full screen mode.
		void SetIsFullScreen(const bool isFullScreen);
	};

#endif
}