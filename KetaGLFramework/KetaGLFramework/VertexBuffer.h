#include "VertexPositionColor.h"

namespace KetaFramework
{
	namespace KetaGraphics
	{
	#ifndef KetaFramework_KetaGraphics_VertexBuffer
	#define KetaFramework_KetaGraphics_VertexBuffer

		class VertexBuffer sealed
		{
		private:
			int count;
			int declaration;
			VertexPositionColor* vertices;

		public:
			VertexBuffer();
			VertexBuffer(const VertexBuffer &buffer);
			VertexBuffer(const VertexPositionColor* vertices, const int count, int declaration);
			~VertexBuffer();

			const int GetCount() const;
			const int GetDeclaration() const;
			void SetDeclaration(int declaration);
			const VertexPositionColor* GetVertices() const;
			void SetVertices(const VertexPositionColor* vertices, const int count);

			void operator=(const VertexBuffer &buffer);
		};

	#endif
	}
}