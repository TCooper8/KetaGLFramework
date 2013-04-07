#include "Color4.h"

namespace KetaGraphics
{
#ifndef GraphicsDevice_h
#define GraphicsDevice_h

	class GraphicsDevice sealed
	{
	public:
		GraphicsDevice();

		void Clear(KetaFramework::Color4 color);

		void DrawCircle(double x, double y, double radius);
	};

#endif
}