#include "GameManager.h"
//#include "stb_image.h"

static void GetCursorPosition(GLFWwindow* window, double xPos, double yPos);


int main(int argc, char* args[])
{
	glfwSetCursorPosCallback(GraphicsManager::Instance()->GetWindow(), GetCursorPosition);
	GameManager* game = GameManager::Instance();
	game->Run();

	GameManager::Release();

	return 0;
}

void GetCursorPosition(GLFWwindow* window, double xPos, double yPos)
{
	std::cout << xPos << " : " << yPos << std::endl;
}