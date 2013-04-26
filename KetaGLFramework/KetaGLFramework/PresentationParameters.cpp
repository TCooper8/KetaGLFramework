#include "PresentationParameters.h"

using namespace KetaFramework;

namespace KetaGraphics
{
	PresentationParameters::PresentationParameters()
		: backBufferHeight(0), backBufferWidth(0), bounds(0, 0, 0, 0), 
		windowHandle(nullptr), isFullScreen(false)
	{
	}

	PresentationParameters::PresentationParameters(const PresentationParameters &parameters)
		: backBufferHeight(parameters.backBufferHeight), backBufferWidth(parameters.backBufferWidth),
		bounds(parameters.bounds), windowHandle(parameters.windowHandle), isFullScreen(parameters.isFullScreen)
	{
	}

	const int PresentationParameters::GetBackBufferHeight() const
	{
		return backBufferHeight;
	}

	void PresentationParameters::SetBackBufferHeight(int height)
	{
		backBufferHeight = height;
	}

	const int PresentationParameters::GetBackBufferWidth() const
	{
		return backBufferWidth;
	}

	void PresentationParameters::SetBackBufferWidth(int width)
	{
		backBufferWidth = width;
	}

	const Rectangle &PresentationParameters::GetBounds() const
	{
		return bounds;
	}

	const int* PresentationParameters::GetDeviceWindowHandle() const
	{
		return windowHandle;
	}

	void PresentationParameters::SetDeviceWindowHandle(int* handle)
	{
		windowHandle = handle;
	}

	const bool PresentationParameters::GetIsFullScreen() const
	{
		return isFullScreen;
	}

	void PresentationParameters::SetIsFullScreen(bool isFullScreen)
	{
		this->isFullScreen = isFullScreen;
	}
}