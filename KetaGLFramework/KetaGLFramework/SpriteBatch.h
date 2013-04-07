#include "BlendState.h"

namespace KetaGraphics
{
#ifndef SpriteBatch_h
#define SpriteBatch_h

	class SpriteBatch sealed
	{
	public:
		SpriteBatch();

		void Begin();
		void Begin(BlendState blendState);
		//void Draw();
		void End();
	};

#endif
}