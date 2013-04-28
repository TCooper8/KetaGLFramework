#include "Color4.h"
#include "BlendState.h"
#include "VertexPositionColor.h"
#include "PresentationParameters.h"

typedef unsigned int GLuint;

namespace KetaFramework
{
	namespace KetaGraphics
	{
	#ifndef KetaFramework_KetaGraphics_GraphicsDevice
	#define KetaFramework_KetaGraphics_GraphicsDevice

		//Performs primitive-based rendering, and handles system-level variables.
		class GraphicsDevice sealed
		{
		private:
			KetaFramework::Color4 blendFactor;
			BlendState currentBlendState;
			PresentationParameters presentationParameters;

			GLuint* textureIDs;
			int textureCount;

		public:
			//Creates an instance of GraphicsDevice.
			GraphicsDevice(const PresentationParameters presentationParameters);

			//Clears the resource buffers.
			void Clear(const KetaFramework::Color4 color);

			//Draws a pre-defined primitive circle.
			void DrawCircle(double x, double y, double radius);
			//Renders geometric primitives.
			void DrawPrimitives(int declaration, const VertexPositionColor* vertices, int vertexCount);
			//Returns the texture data of a given texture id.
			void GetTextureData(const int handleID, Color4* data, const int startIndex, const int elementCount) const;
			//Copies image data from one texture to another.
			void CopyTexture(const int handleIDTarget, int mipmapLevel, int xOffset, int yOffset, int x, int y, int width, int height);
			//Returns a refernce to the OpenGL textures.
			const GLuint* GetTextures() const;
			//Presents the display with the contents of the next buffer.
			void Present();
			//Requests a new OpenGL texture handle and returns it.
			int RequestTextureHandle();
			//Sets the texture data of the given texture handle index.
			void SetTextureID(const int handleID, const Color4* data, const int width, const int height);
		};

	#endif
	}
}