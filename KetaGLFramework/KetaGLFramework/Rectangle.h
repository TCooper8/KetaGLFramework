namespace KetaFramework
{
#ifndef Rectangle_h
#define Rectangle_h

	class Rectangle
	{
	public:
		int Height;
		int Width;
		int X;
		int Y;

		Rectangle();
		Rectangle(Rectangle &rect);
		Rectangle(int x, int y, int width, int height);
	};

#endif
}