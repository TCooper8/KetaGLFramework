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
		static Vector3 One;
		//Represents the x unit Vector3 <1, 0, 0>.
		static Vector3 UnitX;
		//Represents the y unit Vector3 <0, 1, 0>.
		static Vector3 UnitY;
		//Represents the z unit Vector3 <0, 0, 1>.
		static Vector3 UnitZ;
		//Represents a Vector3 with zeros in all of its components.
		static Vector3 Zero;

		//Overloaded. Initializes a new instace of Vector3.
		Vector3();
		Vector3(Vector3 &vector);
		Vector3(double value);
		Vector3(double xy, double z);
		Vector3(double x, double y, double z);
	};

#endif
}