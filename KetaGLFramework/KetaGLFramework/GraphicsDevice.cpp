#include <iostream>
#include <cmath>
#include <glut.h>
#include "GraphicsDevice.h"

namespace KetaFramework
{
	namespace KetaGraphics
	{
		GraphicsDevice::GraphicsDevice(const PresentationParameters presentationParameters)
			: presentationParameters(presentationParameters)
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

		void GraphicsDevice::Present()
		{
			glutSwapBuffers();
		}
	}
}