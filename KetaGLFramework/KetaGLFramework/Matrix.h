#include "Vector3.h"

namespace KetaFramework
{
#ifndef Matrix_h
#define Matrix_h

	class Matrix
	{
	public:
		static const int Width = 4;
		static const int Height = 4;
		double Element[Width * Height];

	public:
		static const Matrix Identity;

		Matrix();
		Matrix(const Matrix &matrix);
		Matrix(
			double m11, double m12, double m13, double m14,
			double m21, double m22, double m23, double m24,
			double m31, double m32, double m33, double m34,
			double m41, double m42, double m43, double m44);

		void glPush() const;

		static Matrix CreateLookAt(const Vector3 &cameraPosition, const Vector3 &cameraTarget, const Vector3 &cameraUpVector);

		Matrix operator*(const Matrix &matrix) const;
		void operator=(const Matrix &matrix);
		double &operator[](int i);
		const double &operator[](int i) const;
	};

#endif
}