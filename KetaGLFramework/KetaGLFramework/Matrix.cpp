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
		for (int i = 0; i < Width; i++)
		{
			for (int j = 0; j < Height; j++)
			{
				Element[i][j] = 0;
			}
		}
	}

	Matrix::Matrix(const Matrix &matrix)
	{
		for (int i = 0; i < Width; i++)
		{
			for (int j = 0; j < Height; j++)
			{
				Element[i][j] = matrix.Element[i][j];
			}
		}
	}

	Matrix::Matrix(
			double m11, double m12, double m13, double m14,
			double m21, double m22, double m23, double m24,
			double m31, double m32, double m33, double m34,
			double m41, double m42, double m43, double m44)
	{
		Element[0][0] = m11;
		Element[1][0] = m12;
		Element[2][0] = m13;
		Element[3][0] = m14;
		Element[0][1] = m21;
		Element[1][1] = m22;
		Element[2][1] = m23;
		Element[3][1] = m24;
		Element[0][2] = m31;
		Element[1][2] = m32;
		Element[2][2] = m33;
		Element[3][2] = m34;
		Element[0][3] = m41;
		Element[1][3] = m42;
		Element[2][3] = m43;
		Element[3][3] = m44;
	}

	Matrix Matrix::CreateLookAt(const Vector3 &cameraPosition, const Vector3 &cameraTarget, const Vector3 &cameraUpVector)
	{
		Matrix result = Matrix::Identity;
		
		result.Element[0][3] = -cameraPosition.X;
		result.Element[1][3] = -cameraPosition.Y;
		result.Element[2][3] = -cameraPosition.Z;

		Vector3 zAxis = cameraTarget - cameraPosition;
		Vector3 xAxis = Vector3::Cross(cameraUpVector, zAxis);
		zAxis.Normalize();
		xAxis.Normalize();
		Vector3 yAxis = Vector3::Cross(zAxis, xAxis);

		Matrix m2 = Matrix(
			xAxis.X, yAxis.X, zAxis.X, 0,
			xAxis.Y, yAxis.Y, zAxis.Y, 0,
			xAxis.Z, yAxis.Z, zAxis.Z, 0,
			0, 0, 0, 1);

		return result * m2;
	}

	Matrix Matrix::operator*(const Matrix &matrix) const
	{
		Matrix product;

		for (int x = 0; x < Width; x++)
		{
			for (int y = 0; y < Height; y++)
			{
				product.Element[x][y] = 0;
				for (int j = 0; j < Width; j++)
				{
					product.Element[x][y] += Element[x][y] * matrix.Element[x][j];
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
				Element[i][j] = matrix.Element[i][j];
			}
		}
	}
}