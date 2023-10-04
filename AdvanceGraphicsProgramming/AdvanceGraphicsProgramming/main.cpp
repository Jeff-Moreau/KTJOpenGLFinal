#include "GameManager.h"

int main(int argc, char* args[])
{
	srand(time(0));

	GameManager* game = GameManager::Load();
	game->Run();
	GameManager::UnLoad();

	return 0;
}