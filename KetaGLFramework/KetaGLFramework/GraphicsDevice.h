#include "Color4.h"
#include "BlendState.h"
#include "VertexPositionColor.h"

namespace KetaGraphics
{
#ifndef GraphicsDevice_h
#define GraphicsDevice_h

	//Performs primitive-based rendering, and handles system-level variables.
	class GraphicsDevice sealed
	{
	private:
		KetaFramework::Color4 blendFactor;
		BlendState currentBlendState;

	public:
		//Creates an instance of GraphicsDevice.
		GraphicsDevice();

		//Clears the resource buffers.
		void Clear(const KetaFramework::Color4 color);

		//Draws a pre-defined primitive circle.
		void DrawCircle(double x, double y, double radius);
		//Renders geometric primitives.
		void DrawPrimitives(int declaration, const VertexPositionColor* vertices, int vertexCount);
	};

#endif
}