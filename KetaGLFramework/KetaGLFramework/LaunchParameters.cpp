#include <glut.h>
#include "LaunchParameters.h"

using namespace KetaFramework;

LaunchParameters::LaunchParameters()
	: DisplayMode(GLUT_DOUBLE | GLUT_RGB), MatrixMode(GL_PROJECTION),
	BackBufferWidth(700), BackBufferHeight(500), 
	WindowPositionX(50), WindowPositionY(50),
	FullScreen(false), GameModeString("800x600:32")
{ }