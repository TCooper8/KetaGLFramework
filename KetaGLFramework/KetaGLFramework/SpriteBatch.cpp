#include <iostream>
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
			glEnable(GL_BLEND);
			glBlendFunc(blendState.SFactor, blendState.DFactor);
		}

		void SpriteBatch::Draw(const Texture2D &texture, const Vector3 &position, const Color4 &color)
		{
			glPushMatrix();
			glTranslated(position.X, position.Y, 0);

			glColor4ub((GLubyte)color.R, (GLubyte)color.G, (GLubyte)color.B, (GLubyte)color.A);

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, texture.GetBinding());
			glBegin(GL_QUADS);

			glTexCoord2d(0, 0); glVertex2d(0, texture.GetHeight());
			glTexCoord2d(0, 1); glVertex2d(texture.GetWidth(), texture.GetHeight());
			glTexCoord2d(1, 1); glVertex2d(texture.GetWidth(), 0);
			glTexCoord2d(1, 0); glVertex2d(0, 0);

			glEnd();
			glPopMatrix();
		}

		void SpriteBatch::End()
		{
			glDisable(GL_BLEND);
			glutSwapBuffers();
		}
	}
}