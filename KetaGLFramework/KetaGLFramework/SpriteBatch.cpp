#include <glut.h>
#include "SpriteBatch.h"

namespace KetaFramework
{
	namespace KetaGraphics
	{
		SpriteBatch::SpriteBatch()
		{ }

		void SpriteBatch::Begin()
		{
		}

		void SpriteBatch::Begin(const BlendState blendState)
		{
			glBlendFunc(blendState.SFactor, blendState.DFactor);
			glEnable(GL_BLEND);
		}

		void SpriteBatch::End()
		{
			glDisable(GL_BLEND);
			glutSwapBuffers();
		}
	}
}