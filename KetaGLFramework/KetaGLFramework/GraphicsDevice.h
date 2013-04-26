#include "Color4.h"
#include "BlendState.h"
#include "VertexPositionColor.h"
#include "PresentationParameters.h"

namespace KetaGraphics
{
#ifndef KetaGraphics_GraphicsDevice_h
#define KetaGraphics_GraphicsDevice_h

	//Performs primitive-based rendering, and handles system-level variables.
	class GraphicsDevice sealed
	{
	private:
		KetaFramework::Color4 blendFactor;
		BlendState currentBlendState;
		PresentationParameters presentationParameters;

	public:
		//Creates an instance of GraphicsDevice.
		GraphicsDevice(const PresentationParameters presentationParameters);

		//Clears the resource buffers.
		void Clear(const KetaFramework::Color4 color);

		//Draws a pre-defined primitive circle.
		void DrawCircle(double x, double y, double radius);
		//Renders geometric primitives.
		void DrawPrimitives(int declaration, const VertexPositionColor* vertices, int vertexCount);
		//Presents the display with the contents of the next buffer.
		void Present();
	};

#endif
}