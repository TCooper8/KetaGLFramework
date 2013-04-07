#include <glut.h>
#include "BlendState.h"

using namespace KetaGraphics;

BlendState BlendState::AA = BlendState(GL_SRC_ALPHA_SATURATE, GL_ONE);
BlendState BlendState::Additive = BlendState(GL_ONE, GL_ONE);
BlendState BlendState::AlphaBlend = BlendState(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

BlendState::BlendState(unsigned int sFactor, unsigned int dFactor)
	: SFactor(sFactor), DFactor(dFactor)
{ }