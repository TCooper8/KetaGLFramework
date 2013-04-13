#include <cmath>
#include <glut.h>
#include "GraphicsDevice.h"

using namespace KetaFramework;

namespace KetaGraphics
{
	GraphicsDevice::GraphicsDevice()
	{ }

	void GraphicsDevice::Clear(Color4 color)
	{
		glClearColor(color.R, color.G, color.B, color.A);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void GraphicsDevice::DrawCircle(double x, double y, double radius)
	{
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
}