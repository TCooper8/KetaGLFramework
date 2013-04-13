#include "Vector3.h"

namespace KetaFramework
{
	Vector3 Vector3::One = Vector3(1);
	Vector3 Vector3::UnitX = Vector3(1, 0, 0);
	Vector3 Vector3::UnitY = Vector3(0, 1, 0);
	Vector3 Vector3::UnitZ = Vector3(0, 0, 1);
	Vector3 Vector3::Zero = Vector3(0);

	Vector3::Vector3()
		: X(0), Y(0), Z(0)
	{ }

	Vector3::Vector3(Vector3 &vector)
		: X(vector.X), Y(vector.Y), Z(vector.Z)
	{ }

	Vector3::Vector3(double value)
		: X(value), Y(value), Z(value)
	{ }

	Vector3::Vector3(double xy, double z)
		: X(xy), Y(xy), Z(z)
	{ }

	Vector3::Vector3(double x, double y, double z)
		: X(x), Y(y), Z(z)
	{ }
}