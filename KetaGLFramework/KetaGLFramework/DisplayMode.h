namespace KetaFramework
{
	namespace KetaGraphics
	{
		#ifndef KetaFramework_KetaGraphics_DisplayMode
		#define KetaFramework_KetaGraphics_DisplayMode

		class DisplayMode sealed
		{
		private:
			int value;

		public:
			static const DisplayMode RGBA;
			static const DisplayMode RGB;
			static const DisplayMode Index;
			static const DisplayMode Single;
			static const DisplayMode Double;
			static const DisplayMode Accum;
			static const DisplayMode Alpha;
			static const DisplayMode Depth;
			static const DisplayMode Stencil;
			static const DisplayMode MultiSample;
			static const DisplayMode Stereo;
			static const DisplayMode Luminance;

			DisplayMode(const DisplayMode &mode);
			DisplayMode(int type);

			operator int() const;
			DisplayMode &operator=(const DisplayMode &mode);
		};

		#endif
	}
}