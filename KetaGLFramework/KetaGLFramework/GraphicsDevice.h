#include "Color4.h"

namespace KetaGraphics
{
#ifndef GraphicsDevice_h
#define GraphicsDevice_h

	//Performs primitive-based rendering, and handles system-level variables.
	class GraphicsDevice sealed
	{
	public:
		//Creates an instance of GraphicsDevice.
		GraphicsDevice();

		//Clears the resource buffers.
		void Clear(KetaFramework::Color4 color);

		//Draws a pre-defined primitive circle.
		void DrawCircle(double x, double y, double radius);
	};

#endif
}