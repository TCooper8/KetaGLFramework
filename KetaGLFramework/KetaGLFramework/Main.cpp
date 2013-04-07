#include <iostream>
#include <glut.h>
#include "Keta.h"

using namespace std;
using namespace KetaFramework;

int main(int argc, char** argv)
{
	Game game1 = Game();
	game1.Initialize(argc, argv);
	game1.Run();

	return 0;
}