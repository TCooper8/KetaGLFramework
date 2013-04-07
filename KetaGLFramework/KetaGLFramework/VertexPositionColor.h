#include "Vector3.h"
#include "Color4.h"

namespace KetaGraphics
{
#ifndef VertexPositionColor_h
#define VertexPositionColor_h

	class VertexPositionColor
	{
	public:
		KetaFramework::Color4 Color;
		KetaFramework::Vector3 Position;

		VertexPositionColor();
		VertexPositionColor(VertexPositionColor &vertex);
		VertexPositionColor(KetaFramework::Vector3 position, KetaFramework::Color4 color);
	};

#endif
}