#include "Bullet.h"

Bullet::Bullet()
{
	p_Graphics = GraphicsManager::Use();
    p_Bullet = new Model("Assets/Models/3dRedblueSaber.obj");
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	/*float velocity = 10 * glfwGetTime();
	glfwGetCursorPos(p_Graphics->GetWindow(), &_MouseX, &_MouseY);
	p_Bullet->SetPerspective(45);
	p_Bullet->SetPosition(glm::vec3(_MouseX, _MouseY, velocity));
	p_Bullet->SetRotation(45.0f, glm::vec3(1.0f, 0.0f, 1.0f));*/
}

void Bullet::Render()
{
	GraphicsManager::Use()->ModelShader.Use();
	float velocity = 10 * glfwGetTime();
	glfwGetCursorPos(p_Graphics->GetWindow(), &_MouseX, &_MouseY);
	p_Bullet->SetPerspective(45);
	p_Bullet->SetPosition(glm::vec3(_MouseX, _MouseY, velocity));
	p_Bullet->SetRotation(45.0f, glm::vec3(1.0f, 0.0f, 1.0f));
	p_Bullet->Draw(p_Graphics->ModelShader);
}
