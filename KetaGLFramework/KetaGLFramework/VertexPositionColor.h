#include "Vector3.h"
#include "Color4.h"

namespace KetaGraphics
{
#ifndef VertexPositionColor_h
#define VertexPositionColor_h

	//Describes a Vertex structure format that contains position and color information.
	class VertexPositionColor
	{
	public:
		//The vertex color.
		KetaFramework::Color4 Color;
		//The vertex position.
		KetaFramework::Vector3 Position;

		//Overloaded. Initializes a new instance of VertexPositionColor.d
		VertexPositionColor();
		VertexPositionColor(const VertexPositionColor &vertex);
		VertexPositionColor(const KetaFramework::Vector3 position, const KetaFramework::Color4 color);

		void operator=(const VertexPositionColor &vertex);
	};

#endif
}