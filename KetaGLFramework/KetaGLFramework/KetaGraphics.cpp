#include <glut.h>
#include "GraphicsDevice.h"

using namespace KetaFramework;
using namespace KetaGraphics;

GraphicsDevice::GraphicsDevice()
{ }

void GraphicsDevice::Clear(Color4 color)
{
	glClearColor(color.R, color.G, color.B, color.A);
	glClear(GL_COLOR_BUFFER_BIT);
}