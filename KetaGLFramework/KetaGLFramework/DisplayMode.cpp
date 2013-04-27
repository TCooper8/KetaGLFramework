#include <glut.h>
#include "DisplayMode.h"

namespace KetaFramework
{
	namespace KetaGraphics
	{
		const DisplayMode DisplayMode::RGBA = DisplayMode(GLUT_RGBA);
		const DisplayMode DisplayMode::RGB = DisplayMode(GLUT_RGB);
		const DisplayMode DisplayMode::Index = DisplayMode(GLUT_INDEX);
		const DisplayMode DisplayMode::Single = DisplayMode(GLUT_SINGLE);
		const DisplayMode DisplayMode::Double = DisplayMode(GLUT_DOUBLE);
		const DisplayMode DisplayMode::Accum = DisplayMode(GLUT_ACCUM);
		const DisplayMode DisplayMode::Alpha = DisplayMode(GLUT_ALPHA);
		const DisplayMode DisplayMode::Depth = DisplayMode(GLUT_DEPTH);
		const DisplayMode DisplayMode::Stencil = DisplayMode(GLUT_STENCIL);
		const DisplayMode DisplayMode::MultiSample = DisplayMode(GLUT_MULTISAMPLE);
		const DisplayMode DisplayMode::Stereo = DisplayMode(GLUT_STEREO);
		const DisplayMode DisplayMode::Luminance = DisplayMode(GLUT_LUMINANCE);

		DisplayMode::DisplayMode(int type)
			: value(type)
		{ }

		DisplayMode::operator int() const
		{
			return value;
		}

		DisplayMode &DisplayMode::operator=(const DisplayMode &mode)
		{
			this->value = mode.value;
			return *this;
		}
	}
}