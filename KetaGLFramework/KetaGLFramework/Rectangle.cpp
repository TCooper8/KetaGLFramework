#include "Rectangle.h"

namespace KetaFramework
{
	Rectangle::Rectangle()
		: X(0), Y(0), Width(0), Height(0)
	{ }

	Rectangle::Rectangle(Rectangle &rect)
		: X(rect.X), Y(rect.Y), Width(rect.Width), Height(rect.Height)
	{ }

	Rectangle::Rectangle(int x, int y, int width, int height)
		: X(x), Y(y), Width(width), Height(height)
	{ }
}