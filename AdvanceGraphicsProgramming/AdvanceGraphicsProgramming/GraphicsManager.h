#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class GraphicsManager
{
public:
	const unsigned int SCR_WIDTH = 1920;
	const unsigned int SCR_HEIGHT = 1080;

private:
	static GraphicsManager* sInstance;
	GLFWwindow* pWindow;

public:
	GraphicsManager();
	~GraphicsManager();

	static GraphicsManager* Instance();
	static void Release();
	static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

	GLFWwindow* GetWindow();
};
#endif // !GRAPHICSMANAGER_H