namespace KetaFramework
{
#ifndef KetaFramework_Color4
#define KetaFramework_Color4

	//Represents a four component color using red, green, blue, and alpha.
	class Color4
	{
	public:
		//Represents the alpha component value of this Color.
		int A;
		//Represents the blue component value of this Color.
		int B;
		//Represents the green component value of this Color.
		int G;
		//Represents the red component value of this Color.
		int R;
		
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
		Color4(int value);
		Color4(int rgb, int a);
		Color4(int r, int g, int b);
		Color4(int r, int g, int b, int a);

		bool operator==(const Color4 &color);
		bool operator!=(const Color4 &color);

		Color4 &operator=(const Color4 &color);
	};

#endif
}