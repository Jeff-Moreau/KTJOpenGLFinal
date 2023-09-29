#include "GraphicsManager.h"
namespace SDLFramework
{
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
	if (SDL_Init(SDL_INIT_EVENTS) < 0)
	{
		std::cerr << std::endl << "Something went wrong, cannot initialize SDL!" << std::endl;
		std::cerr << "SDL Error : " << SDL_GetError() << std::endl;
	}

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// MEMBER VARIABLE INSTANTIATION
	p_GameWindow = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Jarjar Drinks - Ken, Tammy, Jeff", nullptr, nullptr);

	if (p_GameWindow == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return;
	}

	glfwMakeContextCurrent(p_GameWindow);
	glfwSetFramebufferSizeCallback(p_GameWindow, FramebufferSizeCallback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;

		return;
	}
	glEnable(GL_DEPTH_TEST); // CHECK THIS IN A BIT
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
}