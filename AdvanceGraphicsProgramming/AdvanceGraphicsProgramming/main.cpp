#include "GameManager.h"

int main(int argc, char* args[])
{
	GameManager* game = GameManager::Instance();
	game->Run();

	GameManager::Release();

	return 0;
}