#include "Vector3.h"
#include "Color4.h"

namespace KetaFramework
{
	namespace KetaGraphics
	{
	#ifndef KetaFramework_KetaGraphics_VertexPositionColor
	#define KetaFramework_KetaGraphics_VertexPositionColor

		//Describes a Vertex structure format that contains position and color information.
		class VertexPositionColor
		{
		public:
			//The vertex color.
			Color4 Color;
			//The vertex position.
			Vector3 Position;

			//Overloaded. Initializes a new instance of VertexPositionColor.d
			VertexPositionColor();
			VertexPositionColor(const VertexPositionColor &vertex);
			VertexPositionColor(const Vector3 position, const Color4 color);

			void operator=(const VertexPositionColor &vertex);
		};

	#endif
	}
}