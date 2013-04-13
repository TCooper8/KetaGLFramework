#include "Color4.h"

namespace KetaFramework
{
	Color4 Color4::Black = Color4(0, 1);
	Color4 Color4::Blue = Color4(0, 0, 1, 1);
	Color4 Color4::Green = Color4(0, 1, 0, 1);
	Color4 Color4::Red = Color4(1, 0, 0, 1);
	Color4 Color4::White = Color4(1);

	Color4 Color4::Empty = Color4(0);

	Color4::Color4()
		: R(0), G(0), B(0), A(0)
	{ }

	Color4::Color4(Color4 &color)
		: R(color.R), G(color.G), B(color.B), A(color.A)
	{ }

	Color4::Color4(double value)
		: R(value), G(value), B(value), A(value)
	{ }

	Color4::Color4(double rgb, double a)
		: R(rgb), G(rgb), B(rgb), A(a)
	{ }

	Color4::Color4(double r, double g, double b, double a)
		: R(r), G(g), B(b), A(a)
	{ }

	bool Color4::operator==(Color4 &color)
	{
		return
			(A == color.A) &&
			(B == color.B) &&
			(G == color.G) &&
			(R == color.R);
	}

	bool Color4::operator!=(Color4 &color)
	{
		return !(*this == color);
	}

	Color4 &Color4::operator=(Color4 &color)
	{
		A = color.A;
		B = color.B;
		G = color.G;
		R = color.R;

		return *this;
	}
}