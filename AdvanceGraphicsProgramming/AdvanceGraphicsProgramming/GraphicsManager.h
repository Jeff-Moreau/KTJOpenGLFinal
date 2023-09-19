#ifndef GRAPHICS_MANAGER_H
#define GRAPHICS_MANAGER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class GraphicsManager
{
public: // GLOBALS
	const unsigned int SCREEN_WIDTH = 1920;
	const unsigned int SCREEN_HEIGHT = 1080;

private: // SINGLETON
	static GraphicsManager* p_ThisInstance;

private: // POINTER VARIABLES
	GLFWwindow* p_GameWindow;

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
#endif // !GRAPHICS_MANAGER_H