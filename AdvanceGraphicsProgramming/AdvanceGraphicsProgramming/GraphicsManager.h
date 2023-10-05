#ifndef GRAPHICS_MANAGER_H
#define GRAPHICS_MANAGER_H

// EXTERNAL INCLUDES
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "SDL2/SDL.h"

// SYSTEM INCLUDES
#include <iostream>

// PROJECT INCLUDES
#include "Shader.h"

namespace SDLFramework
{
	class GraphicsManager
	{
	public: // ACCESSABLE VARIABLE DECLARATIONS
		const unsigned int SCREEN_WIDTH = 800;
		const unsigned int SCREEN_HEIGHT = 600;

		Shader TextureShader;
		Shader FontShader;
		Shader ModelShader;

	private: // MEMBER POINTER VARIABLE DECLARATIONS
		GLFWwindow* p_GameWindow;
	
	private: // SINGLETON
		static GraphicsManager* p_ThisInstance;
	
	public: // SINGLETON
		static GraphicsManager* Load();
		static GraphicsManager* Use();
	
	public: // CONSTRUCTOR / OVERLOADS / DESTRUCTOR
		GraphicsManager();
		~GraphicsManager();
	
	public: // GETTERS
		GLFWwindow* GetWindow();
	public: // DOERS
		static void FramebufferSizeCallback(GLFWwindow* gameWindow, int width, int height);

	private: // DOERS
		void Initialize();

	public: // CLEANUP
		static void UnLoad();
	};
}
#endif // !GRAPHICS_MANAGER_H