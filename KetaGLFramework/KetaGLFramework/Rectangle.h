namespace KetaFramework
{
#ifndef Rectangle_h
#define Rectangle_h

	//Defines a rectangle.
	class Rectangle
	{
	public:
		//Specifies the height of the rectangle.
		int Height;
		//Specifies the width of the rectangle.
		int Width;
		//Specifies the x-coordinate of the rectangle.
		int X;
		//Specifies the y-coordinate of the rectangle.
		int Y;

		//Overloaded. Initializes a new instance of Rectangle.
		Rectangle();
		Rectangle(const Rectangle &rect);
		Rectangle(int x, int y, int width, int height);
	};

#endif
}