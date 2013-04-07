#include "VertexPositionColor.h"

using namespace KetaFramework;
using namespace KetaGraphics;

VertexPositionColor::VertexPositionColor()
	: Color(), Position()
{ }

VertexPositionColor::VertexPositionColor(VertexPositionColor &vertex)
	: Color(vertex.Color), Position(vertex.Position)
{ }

VertexPositionColor::VertexPositionColor(Vector3 position, Color4 color)
	: Color(color), Position(position)
{ }