#include "LaunchParameters.h"
#include "GameWindow.h"
#include "GraphicsDevice.h"

namespace KetaFramework
{
#ifndef KetaFramework_Game
#define KetaFramework_Game

	//Provides basic graphics device initialization, game logic, and rendering code.
	class Game
	{
	public:
	protected:
		bool isActive;
		KetaGraphics::GraphicsDevice graphicsDevice;
		GameWindow window;

	public:
		//Game pointer for redirecting OpenGL function callbacks.
		static Game* GameInstance;
		//Uses LaunchParameters object to pull initialization data for OpenGL and Keta.
		LaunchParameters Parameters;

		/*Initializes a new instance of this class, which provides basic graphics device initialization, game log, rendering code, and a game loop.*/
		Game();

		//Sets up Keta systems for OpenGL use.
		virtual void Initialize(int argc, char** argv);
		//Call this method to begin running the game loop and start processing events for the game.
		virtual void Run() final;
		//Updates the game clock and calls Update and Draw methods.
		virtual void Tick() final;

		//Indicates whether the game is currently the active application.
		const bool GetIsActive() const;
		//Gets the current GraphicsDevice
		KetaGraphics::GraphicsDevice &GetGraphicsDevice();
		//Gets the current operating window.
		GameWindow &GetWindow();

	protected:
		//Redirected callback for OpenGL's Display function.
		virtual void Draw(void);
		//Redirected callback for OpenGL's Reshape function.
		virtual void Reshape(int width, int height);
		//Called by the game before it's Draw function is called.
		virtual void Update();

	private:
		//Invoked when OpenGL calls it's Display function.
		static void DisplayCallback(void);
		//Invoked when OpenGL calls it's Reshape function.
		static void ReshapeCallback(int width, int height);

	#pragma endregion
	};

#endif
}