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
		static Color4 Black;
		static Color4 Blue;
		static Color4 Green;
		static Color4 Red;
		static Color4 White;

		//Represents a color that is null.
		static Color4 Empty;

		//Creates a new instance of class Color4
		Color4();
		Color4(Color4 &color);
		Color4(double value);
		Color4(double rgb, double a);
		Color4(double r, double g, double b, double a);

		bool operator==(Color4 &color);
		bool operator!=(Color4 &color);

		Color4 &operator=(Color4 &color);
	};

#endif
}