#include "Color4.h"

namespace KetaFramework
{
	Color4 const Color4::Black = Color4(0, 255);
	Color4 const Color4::Blue = Color4(0, 0, 255, 255);
	Color4 const Color4::Green = Color4(0, 255, 0, 255);
	Color4 const Color4::Red = Color4(255, 0, 0, 255);
	Color4 const Color4::White = Color4(255);

	Color4 const Color4::Empty = Color4(0);

	Color4::Color4()
		: R(0), G(0), B(0), A(0)
	{ }

	Color4::Color4(const Color4 &color)
		: R(color.R), G(color.G), B(color.B), A(color.A)
	{ }

	Color4::Color4(int value)
		: R(value), G(value), B(value), A(value)
	{ }

	Color4::Color4(int rgb, int a)
		: R(rgb), G(rgb), B(rgb), A(a)
	{ }

	Color4::Color4(int r, int g, int b)
		: R(r), G(g), B(b)
	{ }

	Color4::Color4(int r, int g, int b, int a)
		: R(r), G(g), B(b), A(a)
	{ }

	bool Color4::operator==(const Color4 &color)
	{
		return
			(A == color.A) &&
			(B == color.B) &&
			(G == color.G) &&
			(R == color.R);
	}

	bool Color4::operator!=(const Color4 &color)
	{
		return !(*this == color);
	}

	Color4 &Color4::operator=(const Color4 &color)
	{
		A = color.A;
		B = color.B;
		G = color.G;
		R = color.R;

		return *this;
	}
}