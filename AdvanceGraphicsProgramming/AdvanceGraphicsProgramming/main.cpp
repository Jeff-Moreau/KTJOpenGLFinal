#include "GameManager.h"

int main(int argc, char* args[])
{
	srand(time(0));
	GameManager* game = GameManager::Instance();
	game->Run();

	GameManager::Release();

    Gun renderer(800, 600, "Gun and Bullet");
    renderer.init();

    while (!renderer.shouldClose()) {
        renderer.processInput();
        renderer.update();
        renderer.render();
    }

	return 0;
}