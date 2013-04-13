#include "BlendState.h"

namespace KetaGraphics
{
#ifndef SpriteBatch_h
#define SpriteBatch_h

	//Used for interfacing with OpenGL and a GraphicsDevice at a high level.
	class SpriteBatch sealed
	{
	public:
		//Initializes a new instance of SpriteBatch.
		SpriteBatch();

		//Overloaded. Begins a SpriteBatch operation using default AlphaBlend.
		void Begin();
		//Overloaded. Beings a SpriteBatch operation using user-defined BlendState.
		void Begin(BlendState blendState);
		//void Draw();
		//Flushes the GraphicsDevice and restores the device state to how it was before Begin was called.
		void End();
	};

#endif
}