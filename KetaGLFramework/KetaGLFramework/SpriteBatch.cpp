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

		void SpriteBatch::Draw(const Texture2D &texture, const Vector3 &position, const double scale, const Vector3 &origin)
		{
			glPushMatrix();
			glTranslated(position.X, position.Y, 0);
			glScaled(scale, scale, 1);
			glTranslated(-origin.X, -origin.Y, 0);
			
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

		void SpriteBatch::Draw(const Texture2D &texture, const Rectangle &sourceRectangle, const Rectangle &destRectangle, const Color4 &color)
		{
			glPushMatrix();
			glTranslated(destRectangle.X, destRectangle.Y, 0);
			glColor4ub((GLubyte)color.R, (GLubyte)color.G, (GLubyte)color.B, (GLubyte)color.A);

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, texture.GetBinding());
			glBegin(GL_QUADS);

			double width = texture.GetWidth();
			double height = texture.GetHeight();

			glTexCoord2d(sourceRectangle.X / width, sourceRectangle.Y / height);
			glVertex2d(0, destRectangle.Height);
			glTexCoord2d(sourceRectangle.X / width, (sourceRectangle.Y + sourceRectangle.Height) / height);
			glVertex2d(destRectangle.Width, destRectangle.Height);
			glTexCoord2d((sourceRectangle.X + sourceRectangle.Width) / width, (sourceRectangle.Y + sourceRectangle.Height) / height);
			glVertex2d(destRectangle.Width, 0);
			glTexCoord2d((sourceRectangle.X + sourceRectangle.Width) / width, sourceRectangle.Y / height);
			glVertex2d(0, 0);

			glEnd();
			glPopMatrix();
		}

		void SpriteBatch::Draw(const Texture2D &texture, const Rectangle &sourceRectangle, const Vector3 &position, const Vector3 &scale, double rotation, const Vector3 &origin)
		{
			glPushMatrix();
			glTranslated(position.X, position.Y, 0);
			glRotated(rotation, 0, 0, 1);
			glScaled(scale.X, scale.Y, 1);
			glTranslated(-origin.X, -origin.Y, 0);
			
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, texture.GetBinding());
			glBegin(GL_QUADS);

			double width = texture.GetWidth();
			double height = texture.GetHeight();

			glTexCoord2d(sourceRectangle.X / width, sourceRectangle.Y / height);
			glVertex2d(0, sourceRectangle.Height);
			glTexCoord2d(sourceRectangle.X / width, (sourceRectangle.Y + sourceRectangle.Height) / height);
			glVertex2d(sourceRectangle.Width, sourceRectangle.Height);
			glTexCoord2d((sourceRectangle.X + sourceRectangle.Width) / width, (sourceRectangle.Y + sourceRectangle.Height) / height);
			glVertex2d(sourceRectangle.Width, 0);
			glTexCoord2d((sourceRectangle.X + sourceRectangle.Width) / width, sourceRectangle.Y / height);
			glVertex2d(0, 0);

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