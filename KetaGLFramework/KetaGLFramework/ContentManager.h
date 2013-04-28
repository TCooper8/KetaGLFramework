#include "Texture2D.h"
#include "GraphicsDevice.h"

namespace KetaFramework
{
	namespace KetaContent
	{
		#ifndef KetaFramework_KetaContent_ContentManager
		#define KetaFramework_KetaContent_ContentManager

		class ContentManager
		{
		private:
			KetaGraphics::GraphicsDevice *graphicsDevice;
			char* rootDirectory;

		public:
			ContentManager(KetaGraphics::GraphicsDevice *graphicsDevice, const char* rootDirectory);

			KetaGraphics::Texture2D LoadTexture(const char* assetName) const;

		private:
			static void RaiseError(const char* expected, const char* got, int lineNumber);
		};

		#endif
	}
}