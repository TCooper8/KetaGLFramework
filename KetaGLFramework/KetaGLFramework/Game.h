#include "LaunchParameters.h"
#include "GameWindow.h"

namespace KetaFramework
{
#ifndef Game_h
#define Game_h

	class Game
	{
	#pragma region Fields

	public:
	protected:
	private:
		bool isActive;
		LaunchParameters parameters;
		GameWindow window;	

	#pragma endregion
	#pragma region Functions, methods, properties

	public:
		static Game* GameInstance;

		Game();

		void Initialize(int argc, char** argv);
		void Run();
		void Tick();

	protected:
		void Draw(void);
		void Reshape(int width, int height);
		void Update();

	private:
		static void DisplayCallback(void);
		static void MouseCallback(int mouseButton, int mouseState, int x, int y);
		static void ReshapeCallback(int width, int height);

	#pragma endregion
	};

#endif
}