#include <cmath>
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

	Vector3::Vector3(double x, double y)
		: X(x), Y(y), Z(0)
	{ }

	Vector3::Vector3(double x, double y, double z)
		: X(x), Y(y), Z(z)
	{ }

	double Vector3::Sum() const
	{
		return X + Y + Z;
	}

	Vector3 Vector3::CatmullRom(Vector3 &value1, Vector3 &value2, Vector3 &value3, Vector3 &value4, double amount)
	{
		return (
			(value2 * 2) +
			(-value1 + value3) * amount + 
			(value1 * 2.0 - value2 * 5 + value3 * 4 - value4) * std::pow(amount, 2) + 
			(-value1 + value2 * 3 - value4 * value3 * 3) * std::pow(amount, 3)) * 0.5;
	}

	Vector3 Vector3::Clamp(Vector3 &vector, Vector3 &min, Vector3 &max)
	{
		double x = (vector.X > max.X)? max.X : vector.X;
		x = (vector.X > min.X)? vector.X : min.X;

		double y = (vector.Y > max.Y)? max.Y : vector.Y;
		y = (vector.Y > min.Y)? vector.Y : min.Y;

		double z = (vector.Z > max.Y)? max.Z : vector.Z;
		z = (vector.Z > min.Z)? vector.Z : min.Z;

		return Vector3(x, y, z);
	}

	Vector3 Vector3::Cross(Vector3 &vectorA, Vector3 &vectorB)
	{
		return Vector3(
			vectorA.Y * vectorB.Z - vectorA.Z * vectorB.Y,
			vectorA.Z * vectorB.X - vectorA.X * vectorB.Z,
			vectorA.Z * vectorB.Y - vectorA.Y * vectorB.X);
	}

	double Vector3::Distance(Vector3 &vectorA, Vector3 &vectorB)
	{
		return std::sqrt(Vector3::DistanceSquared(vectorA, vectorB));
	}

	double Vector3::DistanceSquared(Vector3 &vectorA, Vector3 &vectorB)
	{
		return 
			std::pow(vectorB.X - vectorA.X, 2) + 
			std::pow(vectorB.Y - vectorA.Y, 2) + 
			std::pow(vectorB.Z - vectorA.Z, 2);
	}

	double Vector3::Dot(Vector3 &vectorA, Vector3 &vectorB)
	{
		return 
			vectorA.X * vectorB.X + 
			vectorA.Y * vectorB.Y +
			vectorA.Z * vectorB.Z;
	}

	Vector3 Vector3::operator*(Vector3 &vector) const
	{
		return Vector3(X * vector.X, Y * vector.Y, Z * vector.Z);
	}

	Vector3 Vector3::operator*(double scaleFactor) const
	{
		return *this * Vector3(scaleFactor);
	}

	Vector3 Vector3::operator+(Vector3 &vector) const
	{
		return Vector3(X + vector.X, Y + vector.Y, Z + vector.Z);
	}

	Vector3 Vector3::operator-() const
	{
		return Vector3(-X, -Y, -Z);
	}

	Vector3 Vector3::operator-(Vector3 &vector) const
	{
		return Vector3(X - vector.X, Y - vector.Y, Z - vector.Z);
	}

	Vector3 Vector3::operator/(Vector3 &vector) const
	{
		double x = (vector.X)? X / vector.X : 0;
		double y = (vector.Y)? Y / vector.Y : 0;
		double z = (vector.Z)? Z / vector.Z : 0;
		
		return Vector3(x, y, z);
	}

	Vector3 Vector3::operator/(double divisor) const
	{
		if (divisor)
			return Vector3(X / divisor, Y / divisor, Z / divisor);
		return Vector3(0);
	}

	bool Vector3::operator<(Vector3 &vector) const
	{
		return (this->Sum() < vector.Sum());
	}

	bool Vector3::operator<=(Vector3 &vector) const
	{
		return (this->Sum() <= vector.Sum());
	}

	bool Vector3::operator==(Vector3 &vector) const
	{
		return (this->Sum() == vector.Sum());
	}

	bool Vector3::operator!=(Vector3 &vector) const
	{
		return !(*this == vector);
	}

	bool Vector3::operator>(Vector3 &vector) const
	{
		return !(*this <= vector);
	}

	bool Vector3::operator>=(Vector3 &vector) const
	{
		return !(*this < vector);
	}

	Vector3 &Vector3::operator=(Vector3 &vector)
	{
		X = vector.X;
		Y = vector.Y;
		Z = vector.Z;

		return *this;
	}

	Vector3 &Vector3::operator*=(Vector3 &vector)
	{
		*this = *this * vector;
		return *this;
	}

	Vector3 &Vector3::operator*=(double scaleFactor)
	{
		*this = *this * scaleFactor;
		return *this;
	}

	Vector3 &Vector3::operator+=(Vector3 &vector)
	{
		*this = *this + vector;
		return *this;
	}

	Vector3 &Vector3::operator-=(Vector3 &vector)
	{
		*this = *this - vector;
		return *this;
	}

	Vector3 &Vector3::operator/=(Vector3 &vector)
	{
		*this = *this / vector;
		return *this;
	}

	Vector3 &Vector3::operator/=(double divisor)
	{
		*this = *this / divisor;
		return *this;
	}
}