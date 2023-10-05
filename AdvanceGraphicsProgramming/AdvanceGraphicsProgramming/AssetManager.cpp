#include "AssetManager.h"

namespace SDLFramework
{
	AssetManager* AssetManager::p_Instance = nullptr;

	AssetManager* AssetManager::Load()
	{
		if (p_Instance == nullptr)
		{
			p_Instance = new AssetManager();
		}

		return p_Instance;
	}

	AssetManager* AssetManager::Use()
	{
		return Load();
	}

	AssetManager::AssetManager()
	{

	}

	AssetManager::~AssetManager()
	{

	}

	Mix_Music* AssetManager::GetMusic(std::string fileName, bool managed)
	{
		std::string fullPath = SDL_GetBasePath();
		fullPath.append("Assets/Sounds/" + fileName);

		if (p_Music[fullPath] == nullptr)
		{
			p_Music[fullPath] = Mix_LoadMUS(fullPath.c_str());
		}

		if (p_Music[fullPath] == nullptr)
		{
			std::cerr << "Unable to load music " << fileName << "! Mix error: " << Mix_GetError() << std::endl;
		}
		else if (managed)
		{
			p_MusicList[p_Music[fullPath]] += 1;
		}

		return p_Music[fullPath];
	}

	Mix_Chunk* AssetManager::GetSFX(std::string fileName, bool managed)
	{
		std::string fullPath = SDL_GetBasePath();
		fullPath.append("Assets/Sounds/" + fileName);

		if (p_SFXs[fullPath] == nullptr)
		{
			p_SFXs[fullPath] = Mix_LoadWAV(fullPath.c_str());
		}

		if (p_SFXs[fullPath] == nullptr)
		{
			std::cerr << "Unable to load SFX " << fileName << "! Mix error: " << Mix_GetError() << std::endl;
		}
		else if (managed)
		{
			p_SFXsList[p_SFXs[fullPath]] += 1;
		}

		return p_SFXs[fullPath];
	}

	void AssetManager::DestroyMusic(Mix_Music* music)
	{
		for (auto elem : p_Music)
		{
			if (elem.second == music)
			{
				p_MusicList[elem.second] -= 1;

				if (p_MusicList[elem.second] == 0)
				{
					Mix_FreeMusic(elem.second);
					p_Music.erase(elem.first);
				}
				return;
			}
		}
	}

	void AssetManager::DestroySFX(Mix_Chunk* sfx)
	{
		for (auto elem : p_SFXs)
		{
			if (elem.second == sfx)
			{
				p_SFXsList[elem.second] -= 1;

				if (p_SFXsList[elem.second] == 0)
				{
					Mix_FreeChunk(elem.second);
					p_SFXs.erase(elem.first);
				}
				return;
			}
		}
	}

	void AssetManager::UnLoad()
	{
		delete p_Instance;
		p_Instance = nullptr;
	}
}
