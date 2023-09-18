#include "GraphicsManager.h"

GraphicsManager* GraphicsManager::sInstance = nullptr;

GraphicsManager* GraphicsManager::Instance() {
	if (sInstance == nullptr) {
		sInstance = new GraphicsManager();
	}

	return sInstance;
}

void GraphicsManager::Release() {
	delete sInstance;
	sInstance = nullptr;
	//glfwTerminate();
}

GraphicsManager::GraphicsManager() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	pWindow = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", nullptr, nullptr);

	if (pWindow == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(pWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}

	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

	//glEnable(GL_DEPTH_TEST); // Text showing issues were right here may be a problem
	//glEnable(GL_CULL_FACE); // same text issues here
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

GraphicsManager::~GraphicsManager() {
	glfwTerminate();
}

void GraphicsManager::FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

GLFWwindow* GraphicsManager::GetWindow() { return pWindow; }
