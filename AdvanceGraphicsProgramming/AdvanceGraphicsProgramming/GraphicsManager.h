#ifndef GRAPHICS_MANAGER_H
#define GRAPHICS_MANAGER_H

#include "SDL2/SDL.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace SDLFramework
{
	class GraphicsManager
	{
	public: // ACCESSABLE VARIABLE DECLARATIONS
		const unsigned int SCREEN_WIDTH = 800;
		const unsigned int SCREEN_HEIGHT = 600;
	
	private: // MEMBER POINTER VARIABLE DECLARATIONS
		GLFWwindow* p_GameWindow;
	
	private: // SINGLETON
		static GraphicsManager* p_ThisInstance;
	
	public: // SINGLETON
		static GraphicsManager* Instance();
	
	public:// CONSTRUCTORS / DESTRUCTORS / OVERLOADS
		GraphicsManager();
		~GraphicsManager();
	
	public: // GETTERS
		GLFWwindow* GetWindow();
	
	public: // DOERS
		static void FramebufferSizeCallback(GLFWwindow* gameWindow, int width, int height);
		static void Release();
	};
}
#endif // !GRAPHICS_MANAGER_H