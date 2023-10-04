#include "AudioManager.h"

namespace SDLFramework
{
	AudioManager* AudioManager::p_Instance = nullptr;

	AudioManager* AudioManager::Load()
	{
		if (p_Instance == nullptr)
		{
			p_Instance = new AudioManager();
		}

		return p_Instance;
	}

	AudioManager::AudioManager()
	{
		m_pAssetManager = AssetManager::Load();

		if (SDL_Init(SDL_INIT_AUDIO) < 0)
		{
			std::cerr << "Unable to initialize SDL audio! SDL Error: " << SDL_GetError() << std::endl;
			return;
		}

		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
		{
			std::cerr << "Unable to initialize audio! SDL Error: " << Mix_GetError() << std::endl;
			return;
		}
	}

	AudioManager::~AudioManager()
	{
		m_pAssetManager = nullptr;
		Mix_CloseAudio();
		Mix_Quit();
	}

	void AudioManager::PlaySFX(std::string filename, int loops, int channel)
	{
		Mix_PlayChannel(channel, m_pAssetManager->GetSFX(filename), loops);
	}

	void AudioManager::PlayMusic(std::string filename, int loops)
	{
		Mix_PlayMusic(m_pAssetManager->GetMusic(filename), loops);
	}

	void AudioManager::PauseMusic()
	{
		if (Mix_PlayingMusic() != 0)
		{
			Mix_PauseMusic();
		}
	}

	void AudioManager::ResumeMusic()
	{
		if (Mix_PausedMusic() != 0)
		{
			Mix_ResumeMusic();
		}
	}

	void AudioManager::StopMusic()
	{
		Mix_HaltMusic();
	}

	void AudioManager::UnLoad()
	{
		delete p_Instance;
		p_Instance = nullptr;
	}
}


