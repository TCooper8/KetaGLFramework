#include <glut.h>
#include "BlendState.h"

namespace KetaFramework
{
	namespace KetaGraphics
	{
		BlendState const BlendState::AA = BlendState(GL_SRC_ALPHA_SATURATE, GL_ONE);
		BlendState const BlendState::Additive = BlendState(GL_ONE, GL_ONE);
		BlendState const BlendState::AlphaBlend = BlendState(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		BlendState::BlendState(unsigned int sFactor, unsigned int dFactor)
			: SFactor(sFactor), DFactor(dFactor)
		{ }

		BlendState::BlendState()
			: SFactor(GL_ONE), DFactor(GL_ONE)
		{
		}
	}
}