namespace KetaGraphics
{
#ifndef BlendState_h
#define BlendState_h

	struct BlendState
	{
		unsigned int SFactor;
		unsigned int DFactor;
		
		static BlendState AA;
		static BlendState Additive;
		static BlendState AlphaBlend;

		BlendState();
		BlendState(unsigned int sFactor, unsigned int dFactor);
	};

#endif
}