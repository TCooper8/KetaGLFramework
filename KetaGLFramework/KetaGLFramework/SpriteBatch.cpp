#include <glut.h>
#include "SpriteBatch.h"

namespace KetaGraphics
{
	SpriteBatch::SpriteBatch()
	{ }

	void SpriteBatch::Begin()
	{
	}

	void SpriteBatch::Begin(BlendState blendState)
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