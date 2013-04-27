namespace KetaFramework
{
	namespace KetaGraphics
	{
		#ifndef KetaFramework_KetaGraphics_PrimitiveType
		#define KetaFramework_KetaGraphics_PrimitiveType
		
		// Summary:
		//		Defines how vertex data is ordered.
		class PrimitiveType
		{
		private:
			int value;

		public:
			static const PrimitiveType Points;
			static const PrimitiveType Lines;
			static const PrimitiveType LineStrip;
			static const PrimitiveType LineLoop;
			static const PrimitiveType Triangles;
			static const PrimitiveType TriangleStrip;
			static const PrimitiveType TriangleFan;
			static const PrimitiveType Quads;
			static const PrimitiveType QuadStrip;
			static const PrimitiveType Polygon;

			PrimitiveType(const PrimitiveType &type);
			PrimitiveType(int declaration);

			operator int();
			PrimitiveType &operator=(const PrimitiveType &type);
		};

		#endif
	}
}