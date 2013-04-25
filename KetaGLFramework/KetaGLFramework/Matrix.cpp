#include <glut.h>
#include "Matrix.h"

namespace KetaFramework
{
	const Matrix Matrix::Identity = Matrix(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);

	Matrix::Matrix()
	{
		for (int i = 0; i < Width * Height; i++)
		{
			Element[i] = 0;
		}
	}

	Matrix::Matrix(const Matrix &matrix)
	{
		for (int i = 0; i < Width * Height; i++)
		{
			Element[i] = matrix[i];
		}
	}

	Matrix::Matrix(
			double m11, double m12, double m13, double m14,
			double m21, double m22, double m23, double m24,
			double m31, double m32, double m33, double m34,
			double m41, double m42, double m43, double m44)
	{
		Element[0] = m11;
		Element[1] = m12;
		Element[2] = m13;
		Element[3] = m14;
		Element[4] = m21;
		Element[5] = m22;
		Element[6] = m23;
		Element[7] = m24;
		Element[8] = m31;
		Element[9] = m32;
		Element[10] = m33;
		Element[11] = m34;
		Element[12] = m41;
		Element[13] = m42;
		Element[14] = m43;
		Element[15] = m44;
	}

	void Matrix::glPush() const
	{
		glLoadMatrixd(Element);
	}

	Matrix Matrix::CreateLookAt(const Vector3 &cameraPosition, const Vector3 &cameraTarget, const Vector3 &cameraUpVector)
	{
		Vector3 zAxis = cameraTarget - cameraPosition;
		Vector3 xAxis = Vector3::Cross(cameraUpVector, zAxis);
		zAxis.Normalize();
		xAxis.Normalize();
		Vector3 yAxis = Vector3::Cross(zAxis, xAxis);

		Matrix result = Matrix(
			xAxis.X, yAxis.X, zAxis.X, 0,
			xAxis.Y, yAxis.Y, zAxis.Y, 0,
			xAxis.Z, yAxis.Z, zAxis.Z, 0,
			-Vector3::Dot(xAxis, cameraPosition), 
			-Vector3::Dot(yAxis, cameraPosition), 
			-Vector3::Dot(zAxis, cameraPosition)
			, 1);

		return result;
	}

	Matrix Matrix::operator*(const Matrix &matrix) const
	{
		Matrix product;

		for (int x = 0; x < Width; x++)
		{
			for (int y = 0; y < Height; y++)
			{
				int index = x + y*Height;
				product.Element[index] = 0;
				for (int j = 0; j < Width; j++)
				{
					product[index] += Element[index] * matrix[x + j*Height];
				}
			}
		}

		return product;
	}

	void Matrix::operator=(const Matrix &matrix)
	{
		for (int i = 0; i < Width; i++)
		{
			for (int j = 0; j < Height; j++)
			{
				Element[i+j*Width] = matrix.Element[i+j*Width];
			}
		}
	}

	double &Matrix::operator[](int i)
	{
		return Element[i];
	}

	const double &Matrix::operator[](int i) const
	{
		return Element[i];
	}
}