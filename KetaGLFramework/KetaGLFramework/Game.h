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
		GameWindow window;	

	#pragma endregion
	#pragma region Functions, methods, properties

	public:
		LaunchParameters Parameters;

		static Game* GameInstance;

		Game();

		virtual void Initialize(int argc, char** argv);
		virtual void Run() final;
		virtual void Tick() final;

	protected:
		virtual void Draw(void);
		virtual void Reshape(int width, int height);
		virtual void Update();

	private:
		static void DisplayCallback(void);
		static void ReshapeCallback(int width, int height);

	#pragma endregion
	};

#endif
}