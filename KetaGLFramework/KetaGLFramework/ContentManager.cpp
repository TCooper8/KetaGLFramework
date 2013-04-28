#include <iostream>
#include <fstream>
#include <string>
#include "ContentManager.h"

using namespace std;

namespace KetaFramework
{
	using namespace KetaGraphics;

	namespace KetaContent
	{
		ContentManager::ContentManager(GraphicsDevice *graphicsDevice, const char* rootDirectory)
			: graphicsDevice(graphicsDevice), rootDirectory("")
		{
			int len = strlen(rootDirectory);
			this->rootDirectory = new char[len];
			strcpy(this->rootDirectory, rootDirectory);
		}

		KetaGraphics::Texture2D ContentManager::LoadTexture(const char* assetName) const
		{
			string filepath = rootDirectory;
			filepath.append(assetName);

			Texture2D texture = KetaGraphics::Texture2D::FromStream(graphicsDevice, filepath.c_str());

			return texture;
		}

		void ContentManager::RaiseError(const char* expected, const char* got, int lineNumber)
		{
			cerr << "Expected " << expected << ", got " << got << " on line " << lineNumber << '.' << endl;
			exit(0);
		}
	}
}