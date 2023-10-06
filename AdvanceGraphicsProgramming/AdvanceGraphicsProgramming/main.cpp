#include "GameManager.h"

int main(int argc, char* args[])
{
	srand(time(0));
	GameManager* game = GameManager::Instance();
	game->Run();

	GameManager::Release();

	return 0;
}