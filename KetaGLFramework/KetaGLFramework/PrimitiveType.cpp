#include <glut.h>
#include "PrimitiveType.h"

namespace KetaFramework
{
	namespace KetaGraphics
	{
		const PrimitiveType PrimitiveType::Points = PrimitiveType(GL_POINTS);
		const PrimitiveType PrimitiveType::Lines = PrimitiveType(GL_LINES);
		const PrimitiveType PrimitiveType::LineStrip = PrimitiveType(GL_LINE_STRIP);
		const PrimitiveType PrimitiveType::LineLoop = PrimitiveType(GL_LINE_LOOP);
		const PrimitiveType PrimitiveType::Triangles = PrimitiveType(GL_TRIANGLES);
		const PrimitiveType PrimitiveType::TriangleStrip = PrimitiveType(GL_TRIANGLE_STRIP);
		const PrimitiveType PrimitiveType::TriangleFan = PrimitiveType(GL_TRIANGLE_FAN);
		const PrimitiveType PrimitiveType::Quads = PrimitiveType(GL_QUADS);
		const PrimitiveType PrimitiveType::QuadStrip = PrimitiveType(GL_QUAD_STRIP);
		const PrimitiveType PrimitiveType::Polygon = PrimitiveType(GL_POLYGON);

		PrimitiveType::PrimitiveType(const PrimitiveType &type)
			: value(type.value)
		{ }

		PrimitiveType::PrimitiveType(int declaration)
			: value(declaration)
		{ }

		PrimitiveType::operator int()
		{
			return value;
		}

		PrimitiveType &PrimitiveType::operator=(const PrimitiveType &type)
		{
			value = type.value;
			return *this;
		}
	}
}