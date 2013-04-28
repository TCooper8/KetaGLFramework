#include "Rectangle.h"
#include "GraphicsDevice.h"
#include "Color4.h"

namespace KetaFramework
{
	namespace KetaGraphics
	{
		#ifndef KetaFramework_KetaGraphics_Texture2D
		#define KetaFramework_KetaGraphics_Texture2D

		class Texture2D
		{
		private:
			GraphicsDevice* graphicsDevice;
			int bindingID;
			int width;
			int height;

		public:
			Texture2D();
			Texture2D(const Texture2D &texture);
			Texture2D(GraphicsDevice *graphicsDevice, const int width, const int height);

			static Texture2D FromStream(GraphicsDevice *graphicsDevice, const char* filename);
			const int GetBinding() const;
			const int GetHeight() const;
			const int GetWidth() const;
			void SetData(const Color4* data, const int width, const int height);
		};

		#endif
	}
}