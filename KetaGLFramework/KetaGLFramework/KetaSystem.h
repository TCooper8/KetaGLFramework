#include <iostream>
#ifndef KetaSystem_h
#define KetaSystem_h

class KetaSystem sealed
{
public:
	static void RaiseError(const char* expected, const char* got, int lineNumber)
	{
		std::cerr << "Expected " << expected << ", got " << got << " on line " << lineNumber << '.' << std::endl;
		exit(0);
	}
};

#endif