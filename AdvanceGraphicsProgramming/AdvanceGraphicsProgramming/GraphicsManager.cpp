#include "GraphicsManager.h"

GraphicsManager* GraphicsManager::p_ThisInstance = nullptr;

// SINGLETON START
GraphicsManager* GraphicsManager::Instance()
{
	if (p_ThisInstance == nullptr)
	{
		p_ThisInstance = new GraphicsManager();
	}

	return p_ThisInstance;
}
// SINGLETON END

GraphicsManager::GraphicsManager()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	p_GameWindow = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Jarjar Drinks - Ken, Tammy, Jeff", nullptr, nullptr);

	if (p_GameWindow == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return;
	}

	glfwMakeContextCurrent(p_GameWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;

		return;
	}

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	//glEnable(GL_DEPTH_TEST); // Text showing issues were right here may be a problem
	//glEnable(GL_CULL_FACE); // same text issues here
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

GraphicsManager::~GraphicsManager()
{
	glfwTerminate();
}

GLFWwindow* GraphicsManager::GetWindow()
{ 
	return p_GameWindow;
}

void GraphicsManager::FramebufferSizeCallback(GLFWwindow* gameWindow, int width, int height)
{
	glViewport(0, 0, width, height);
}

void GraphicsManager::Release()
{
	delete p_ThisInstance;
	p_ThisInstance = nullptr;
}