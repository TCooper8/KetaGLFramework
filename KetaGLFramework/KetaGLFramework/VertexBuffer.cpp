#include "VertexBuffer.h"

namespace KetaGraphics
{
	VertexBuffer::VertexBuffer()
		: count(0), declaration(0), vertices(nullptr)
	{ }

	VertexBuffer::VertexBuffer(const VertexBuffer &buffer)
		: count(0), declaration(buffer.declaration), vertices(nullptr)
	{ 
		this->SetVertices(buffer.GetVertices(), buffer.GetCount());
	}

	VertexBuffer::VertexBuffer(const VertexPositionColor* vertices, const int count, int declaration)
		: count(count), declaration(declaration), vertices(nullptr)
	{
		this->SetVertices(vertices, count);
	}

	VertexBuffer::~VertexBuffer()
	{
		if (this->vertices)
			delete [] this->vertices;

		this->count = 0;
		this->declaration = 0;
		this->vertices = nullptr;
	}

	const int VertexBuffer::GetCount() const
	{
		return this->count;
	}

	const int VertexBuffer::GetDeclaration() const
	{
		return this->declaration;
	}

	void VertexBuffer::SetDeclaration(int declaration)
	{
		this->declaration = declaration;
	}

	const VertexPositionColor* VertexBuffer::GetVertices() const
	{
		return this->vertices;
	}

	void VertexBuffer::SetVertices(const VertexPositionColor* vertices, const int count)
	{
		if (this->vertices)
			delete [] this->vertices;

		this->count = count;
		this->vertices = new VertexPositionColor[count];

		for (int i = 0; i < count; i++)
		{
			this->vertices[i] = vertices[i];
		}
	}

	void VertexBuffer::operator=(const VertexBuffer &buffer)
	{
		this->declaration = buffer.GetDeclaration();
		this->SetVertices(buffer.GetVertices(), buffer.GetCount());
	}
}