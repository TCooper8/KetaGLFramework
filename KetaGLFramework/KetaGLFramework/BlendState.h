namespace KetaFramework
{
	namespace KetaGraphics
	{
	#ifndef KetaFramework_KetaGraphics_BlendState
	#define KetaFramework_KetaGraphics_BlendState

		//Contains a blend state for the device.
		struct BlendState
		{
			//Gets or Sets the destination factor. Default is GL_ONE.
			unsigned int DFactor;
			//Gets or Sets the source factor. Default is GL_ONE.
			unsigned int SFactor;
		
			//Represents anti-aliasing blend state.
			static const BlendState AA;
			//Respresents an additive blend state.
			static const BlendState Additive;
			//Represents an alpha-blend blend state.
			static const BlendState AlphaBlend;

			//Creates an instance of the BlendState class. Default is using Additive blend.
			BlendState();
			BlendState(unsigned int sFactor, unsigned int dFactor);
		};

	#endif
	}
}