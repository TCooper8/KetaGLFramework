namespace KetaFramework
{
#ifndef Color4_h
#define Color4_h

	class Color4
	{
	public:
		double A;
		double B;
		double G;
		double R;
		
		static Color4 Black;
		static Color4 Blue;
		static Color4 Green;
		static Color4 Red;
		static Color4 White;

		Color4();
		Color4(Color4 &color);
		Color4(double value);
		Color4(double rgb, double a);
		Color4(double r, double g, double b, double a);
	};

#endif
}