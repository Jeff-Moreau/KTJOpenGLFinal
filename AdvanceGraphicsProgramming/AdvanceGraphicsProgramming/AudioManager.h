#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

// PROJECT INCLUDES
#include "AssetManager.h"

namespace SDLFramework
{
	class AudioManager
	{
	private: // MEMBER POINTER VARIABLES
		AssetManager* m_pAssetManager;

	private: // SINGLETON
		static AudioManager* p_Instance;

	public: // SINGLETON
		static AudioManager* Load();

	private: // CONSTRUCTOR / OVERLOADS / DESTRUCTOR
		AudioManager();
		~AudioManager();

	public: // DOERS
		void PlaySFX(std::string filename, int loops = 0, int channel = -1);
		void PlayMusic(std::string filename, int loops = -1);
		void PauseMusic();
		void ResumeMusic();
		void StopMusic();

	public: // CLEANUP
		static void UnLoad();
	};
}
#endif // !AUDIO_MANAGER_H