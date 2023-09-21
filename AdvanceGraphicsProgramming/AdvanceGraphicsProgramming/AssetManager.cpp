#include "AssetManager.h"

namespace SDLFramework
{
	// Singleton Setup to ensure only One Instance of AssetManager is in Memory
	AssetManager* AssetManager::p_Instance = nullptr;

	AssetManager* AssetManager::Instance()
	{
		if (p_Instance == nullptr)
		{
			p_Instance = new AssetManager();
		}

		return p_Instance;
	}
	// Singleton Setup stops here.

	AssetManager::AssetManager()
	{

	}

	AssetManager::~AssetManager()
	{
		for (auto tex : p_SDLTextures)
		{
			if (tex.second != nullptr)
			{
				SDL_DestroyTexture(tex.second);
			}
		}
		p_SDLTextures.clear();
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

	void AssetManager::DestroySurface(SDL_Surface* surface)
	{
		if (p_SDLSurfaceTexturesList.find(surface) != p_SDLSurfaceTexturesList.end())
		{
			p_SDLSurfaceTexturesList[surface] -= 1;
			if (p_SDLSurfaceTexturesList[surface] == 0)
			{
				for (auto elem : p_SDLSurfaceTextures)
				{
					if (elem.second == surface)
					{
						SDL_FreeSurface(elem.second);
						p_SDLSurfaceTextures.erase(elem.first);
						return; // leave function
					}
				}

				for (auto elem : p_SDLSurfaceTexts)
				{
					if (elem.second == surface)
					{
						SDL_FreeSurface(elem.second);
						p_SDLSurfaceTexts.erase(elem.first);
						return; // leave function
					}
				}
			}
		}
	}

	void AssetManager::DestroyTexture(SDL_Texture* texture)
	{
		if (p_SDLTexturesList.find(texture) != p_SDLTexturesList.end())
		{
			p_SDLTexturesList[texture] -= 1;
			if (p_SDLTexturesList[texture] == 0)
			{
				for (auto elem : p_SDLTextures)
				{
					if (elem.second == texture)
					{
						SDL_DestroyTexture(elem.second);
						p_SDLTextures.erase(elem.first);
						return;
					}
				}

				for (auto elem : p_SDLTexts)
				{
					if (elem.second == texture)
					{
						SDL_DestroyTexture(elem.second);
						p_SDLTexts.erase(elem.first);
						return;
					}
				}
			}
		}
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

	void AssetManager::Release()
	{
		delete p_Instance;
		p_Instance = nullptr;
	}
}
