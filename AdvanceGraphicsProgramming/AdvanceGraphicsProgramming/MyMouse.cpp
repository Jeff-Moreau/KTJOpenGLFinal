#include "MyMouse.h"


MyMouse::MyMouse()
{
	glfwSetCursorPosCallback(GraphicsManager::Instance()->GetWindow(), GetCursorPosition);
}

MyMouse::~MyMouse()
{

}

void MyMouse::GetCursorPosition(GLFWwindow* window, double xPos, double yPos)
{
	std::cout << xPos << " : " << yPos << std::endl;
}
