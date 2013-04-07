namespace KetaFramework
{
#ifndef Vector3_h
#define Vector3_h

	class Vector3
	{
	public:
		double X;
		double Y;
		double Z;

		static Vector3 One;
		static Vector3 UnitX;
		static Vector3 UnitY;
		static Vector3 UnitZ;
		static Vector3 Zero;

		Vector3();
		Vector3(Vector3 &vector);
		Vector3(double value);
		Vector3(double xy, double z);
		Vector3(double x, double y, double z);
	};

#endif
}