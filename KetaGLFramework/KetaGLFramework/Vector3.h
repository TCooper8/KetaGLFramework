namespace KetaFramework
{
#ifndef Vector3_h
#define Vector3_h

	//Defines a vector with three components.
	class Vector3
	{
	public:
		//Represents the X component value of this structure.
		double X;
		//Represents the Y component value of this structure.
		double Y;
		//Represents the Z component value of this structure.
		double Z;

		//Represents a Vector3 with ones in all of its components.
		static const Vector3 One;
		//Represents the x unit Vector3 <1, 0, 0>.
		static const Vector3 UnitX;
		//Represents the y unit Vector3 <0, 1, 0>.
		static const Vector3 UnitY;
		//Represents the z unit Vector3 <0, 0, 1>.
		static const Vector3 UnitZ;
		//Represents a Vector3 with zeros in all of its components.
		static const Vector3 Zero;

		//Overloaded. Initializes a new instace of Vector3.
		Vector3();
		Vector3(const Vector3 &vector);
		Vector3(double value);
		Vector3(double x, double y);
		Vector3(double x, double y, double z);
		
		//Returns thw sum of all of the vectors components.
		double Sum() const;
		//Calculates the length of the vector.
		double Length() const;
		//Calculates the squared length of the vector.
		double LengthSquared() const;
		//Creates a unit vector pointing in the same direction as a original.
		void Normalize();

		//Performs a Catmull-Rom interpolation using the specified positions.
		static Vector3 CatmullRom(const Vector3 &value1, const Vector3 &value2, const Vector3 &value3, const Vector3 &value4, double amount);
		//Restricts a value to within a specified range.
		static Vector3 Clamp(const Vector3 &vector, const Vector3 &min, const Vector3 &max);
		//Calculates the cross product of two vectors.
		static Vector3 Cross(const Vector3 &vectorA, const Vector3 &vectorB);
		//Calculates the distance between two vectors.
		static double Distance(const Vector3 &vectorA, const Vector3 &vectorB);
		//Calculates the squared distance between two vectors.
		static double DistanceSquared(const Vector3 &vectorA, const Vector3 &vectorB);
		//Calculates the dot product of two vectors.
		static double Dot(const Vector3 &vectorA, const Vector3 &vectorB);
		//Performs a linear interpolation between two vectors.
		static Vector3 Lerp(const Vector3 &vectorA, const Vector3 &vectorB, double amount);
		//Returns a vector of the highest value from each matching pair of components.
		static Vector3 Max(const Vector3 &vector, const Vector3 &max);
		//Returns a vector of the lowest value from each matching pair of components.
		static Vector3 Min(const Vector3 &vector, const Vector3 &min);
		//Returns a vector pointing in the opposite direction.
		static Vector3 Negate(const Vector3 &vector);
		//Returns the reflection vector off a surface of the specified normal.
		static Vector3 Reflect(const Vector3 &vector, const Vector3 &normal);
		//Uses a cubic equation to interpolate between two vectors.
		static Vector3 SmoothStep(const Vector3 &vectorA, const Vector3 &vectorB, double amount);

		Vector3 operator*(const Vector3 &vector) const;
		Vector3 operator*(double scaleFactor) const;
		Vector3 operator+(const Vector3 &vector) const;
		Vector3 operator-() const;
		Vector3 operator-(const Vector3 &vector) const;
		Vector3 operator/(const Vector3 &vector) const;
		Vector3 operator/(double divisor) const;
		bool operator<(const Vector3 &vector) const;
		bool operator<=(const Vector3 &vector) const;
		bool operator==(const Vector3 &vector) const;
		bool operator!=(const Vector3 &vector) const;
		bool operator>(const Vector3 &vector) const;
		bool operator>=(const Vector3 &vector) const;
		
		Vector3 &operator=(const Vector3 &vector);
		Vector3 &operator*=(const Vector3 &vector);
		Vector3 &operator*=(double scaleFactor);
		Vector3 &operator+=(const Vector3 &vector);
		Vector3 &operator-=(const Vector3 &vector);
		Vector3 &operator/=(const Vector3 &vector);
		Vector3 &operator/=(double divisor);
	};

#endif
}