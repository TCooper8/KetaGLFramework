#include <iostream>
#include <fstream>
#include <string>
#include "KetaSystem.h"
#include "Texture2D.h"

using namespace std;

namespace KetaFramework
{
	namespace KetaGraphics
	{
		Texture2D::Texture2D()
			: bindingID(-1), width(0), height(0)
		{ }

		Texture2D::Texture2D(const Texture2D &texture)
			: graphicsDevice(texture.graphicsDevice), bindingID(texture.bindingID), width(texture.width), height(texture.height)
		{ }

		Texture2D::Texture2D(GraphicsDevice *graphicsDevice, const int width, const int height)
		{
			this->graphicsDevice = graphicsDevice;
			this->bindingID = graphicsDevice->RequestTextureHandle();
		}

		Texture2D Texture2D::FromStream(GraphicsDevice *graphicsDevice, const char* filename)
		{
			cout << filename << endl;
			ifstream stream(filename);
			int lineNumber = 0;
			string keyword;

			while (stream.good())
			{
				stream >> keyword;
				lineNumber++;

				if (keyword == "<image>")
				{
					int count = 0, width = NULL, height = NULL;
					Color4* data = nullptr;
					string format = "";
					int i = 0;

					stream >> keyword;
					lineNumber++;

					while (stream.good() && keyword != "</image>")
					{
						if (!stream || stream.eof())
							KetaSystem::RaiseError("</image>", keyword.c_str(), lineNumber);

						if (keyword == "" || width == NULL || height == NULL)
						{
							if (keyword == "<format>")
							{
								stream >> format >> keyword;

								if (keyword != "</format>")
									KetaSystem::RaiseError("</format>", keyword.c_str(), lineNumber);
							}
							else if (keyword == "<width>")
							{
								stream >> width >> keyword;

								if (keyword != "</width>")
									KetaSystem::RaiseError("</width>", keyword.c_str(), lineNumber);
							}
							else if (keyword == "<height>")
							{
								stream >> height >> keyword;

								if (keyword != "</height>")
									KetaSystem::RaiseError("</height>", keyword.c_str(), lineNumber);
							}
							else
								KetaSystem::RaiseError("format, width, or height definition", keyword.c_str(), lineNumber);
						}
						else if (keyword == "<color>")
						{
							if (data == nullptr)
							{
								count = width * height;
								data = new Color4[count];
							}

							int R, G, B, A;
							stream >> R >> G >> B >> A >> keyword;

							data[i] = Color4(R, G, B, A);
							i++;

							if (keyword != "</color>")
								KetaSystem::RaiseError("</color>", keyword.c_str(), lineNumber);
						}
						else
							KetaSystem::RaiseError("<color>", keyword.c_str(), lineNumber);

						stream >> keyword;
						lineNumber++;
					}

					stream.close();
					Texture2D texture = Texture2D(graphicsDevice, width, height);
					texture.SetData(data, width, height);

					delete [] data;
					
					return texture;
				}
				else if (keyword == "</image>")
					break;
				else
					KetaSystem::RaiseError("</image>", keyword.c_str(), lineNumber);
			}
			stream.close();
			KetaSystem::RaiseError("image file", "nothing", lineNumber);

			return Texture2D();
		}

		const int Texture2D::GetBinding() const
		{
			return this->bindingID;
		}

		const int Texture2D::GetHeight() const
		{
			return height;
		}

		const int Texture2D::GetWidth() const
		{
			return width;
		}

		void Texture2D::SetData(const Color4* data, const int width, const int height)
		{
			this->width = width;
			this->height = height;

			graphicsDevice->SetTextureID(this->bindingID, data, width, height);
		}
	}
}