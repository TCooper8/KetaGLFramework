#include <iostream>
#include <cmath>
#include <glut.h>
#include "GraphicsDevice.h"

namespace KetaFramework
{
	namespace KetaGraphics
	{
		GraphicsDevice::GraphicsDevice(const PresentationParameters presentationParameters)
			: presentationParameters(presentationParameters), textureCount(0), textureIDs(0)
		{ 

		}

		void GraphicsDevice::Clear(Color4 color)
		{
			glClearColor(color.R, color.G, color.B, color.A);
			glClear(GL_COLOR_BUFFER_BIT);
		}

		void GraphicsDevice::DrawCircle(double x, double y, double radius)
		{
			glColor3d(.5, .5, .5);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 32; i++)
			{
				double theta = (double)i / 32.0 * 2.0 * 3.1415926;
				double xf = x + cos(theta) * radius;
				double yf = y + sin(theta) * radius;
				glVertex2d(xf, yf);
			}
			glEnd();
		}

		void GraphicsDevice::DrawPrimitives(int declaration, const VertexPositionColor* vertices, int vertexCount)
		{
			glBegin(declaration);

			for (int i = 0; i < vertexCount; i++)
			{
				glColor4d(vertices[i].Color.R, vertices[i].Color.G, vertices[i].Color.B, 1);
				glVertex3d(vertices[i].Position.X, vertices[i].Position.Y, vertices[i].Position.Z);
			}

			glEnd();
		}

		void GraphicsDevice::GetTextureData(const int handleID, Color4* data, const int startIndex, const int elementCount) const
		{
			GLubyte* byteData = new GLubyte[elementCount * 4];

			glBindTexture(GL_TEXTURE_2D, handleID);
			glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, byteData);

			std::cout << startIndex << ' ' << elementCount << std::endl;

			int j = startIndex;
			for (int i = startIndex; i < startIndex + elementCount; i++)
			{
				Color4 color = Color4(
					(int)byteData[j], (int)byteData[j+1],
					(int)byteData[j+2], (int)byteData[j+3]);
				j += 4;

				data[i] = color;
			}

			std::cout << j << std::endl;

			delete [] byteData;
		}

		const GLuint* GraphicsDevice::GetTextures() const
		{
			return this->textureIDs;
		}

		void GraphicsDevice::Present()
		{
			glutSwapBuffers();
		}

		int GraphicsDevice::RequestTextureHandle()
		{
			textureCount += 1;
			GLuint* newIDs = new GLuint[textureCount];

			for (int i = 0; i < textureCount - 1; i++)
			{
				newIDs[i] = textureIDs[i];
			}

			delete [] textureIDs;
			textureIDs = newIDs;

			return textureCount-1;
		}

		void GraphicsDevice::SetTextureID(const int handleID, const Color4* data, const int width, const int height)
		{
			glGenTextures(1, &textureIDs[handleID]);
			glBindTexture(GL_TEXTURE_2D, handleID);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

			//Set Texture2D parameters in OpenGL.
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

			//Convert Color4s to propert byte data.
			int elementCount = width * height * 4;
			GLubyte* byteData = new GLubyte[elementCount];

			int j = 0;
			for (int i = 0; i < elementCount; i += 4)
			{
				const Color4 color = data[j];
				byteData[i] = (GLubyte)color.R;
				byteData[i+1] = (GLubyte)color.G;
				byteData[i+2] = (GLubyte)color.B;
				byteData[i+3] = (GLubyte)color.A;

				j++;
			}

			//Build2D mipmaps in OpenGL.
			gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, byteData);
			delete [] byteData;
		}
	}
}