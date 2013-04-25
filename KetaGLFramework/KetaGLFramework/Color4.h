namespace KetaFramework
{
#ifndef Color4_h
#define Color4_h

	//Represents a four component color using red, green, blue, and alpha.
	class Color4
	{
	public:
		//Represents the alpha component value of this Color.
		double A;
		//Represents the blue component value of this Color.
		double B;
		//Represents the green component value of this Color.
		double G;
		//Represents the red component value of this Color.
		double R;
		
		//System defined color.
		static const Color4 Black;
		static const Color4 Blue;
		static const Color4 Green;
		static const Color4 Red;
		static const Color4 White;

		//Represents a color that is null.
		static const Color4 Empty;

		//Creates a new instance of class Color4
		Color4();
		Color4(const Color4 &color);
		Color4(double value);
		Color4(double rgb, double a);
		Color4(double r, double g, double b, double a);

		bool operator==(const Color4 &color);
		bool operator!=(const Color4 &color);

		Color4 &operator=(const Color4 &color);
	};

#endif
}