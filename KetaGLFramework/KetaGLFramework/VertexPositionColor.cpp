#include "VertexPositionColor.h"

using namespace KetaFramework;

namespace KetaGraphics
{
	VertexPositionColor::VertexPositionColor()
		: Color(), Position()
	{ }

	VertexPositionColor::VertexPositionColor(const VertexPositionColor &vertex)
		: Color(vertex.Color), Position(vertex.Position)
	{ }

	VertexPositionColor::VertexPositionColor(const Vector3 position, const Color4 color)
		: Color(color), Position(position)
	{ }

	void VertexPositionColor::operator=(const VertexPositionColor &vertex)
	{
		this->Position = vertex.Position;
		this->Color = vertex.Color;
	}
}