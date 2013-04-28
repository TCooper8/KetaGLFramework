#include "Texture2D.h"
#include "BlendState.h"

namespace KetaFramework
{
	namespace KetaGraphics
	{
	#ifndef KetaFramework_KetaGraphics_SpriteBatch
	#define KetaFramework_KetaGraphics_SpriteBatch

		//Used for interfacing with OpenGL and a GraphicsDevice at a high level.
		class SpriteBatch sealed
		{
		public:
			//Initializes a new instance of SpriteBatch.
			SpriteBatch();

			//Overloaded. Begins a SpriteBatch operation using default AlphaBlend.
			void Begin();
			//Overloaded. Beings a SpriteBatch operation using user-defined BlendState.
			void Begin(const BlendState blendState);
			//Overloaded. Draws a specified texture to the buffer.
			void Draw(const Texture2D &texture, const Vector3 &position, const Color4 &color);
			void Draw(const Texture2D &texture, const Vector3 &position, const double scale, const Vector3 &origin);
			//Overloaded. Draws a rectangle part of a texture to the buffer.
			void Draw(const Texture2D &texture, const Rectangle &sourceRectangle, const Rectangle &destRectangle, const Color4 &color);
			void Draw(const Texture2D &texture, const Rectangle &sourceRectangle, const Vector3 &position, const Vector3 &scale, double rotation, const Vector3 &origin);
			//Flushes the GraphicsDevice and restores the device state to how it was before Begin was called.
			void End();
		};

	#endif
	}
}