#ifndef _AUDIOMANAGER_H
#define _AUDIOMANAGER_H

#include "InputManager.h"
#include <SDL2/SDL_audio.h>

class AudioManager
{
private:
	AudioManager();
	~AudioManager();
	
	static AudioManager* sInstance;

public:
	static AudioManager* Instance();
	static void Release();

	void PlayMusic(std::string filename, int loops = -1);
	void PauseMusic();
	void ResumeMusic();
	void StopMusic();
	void ChangeVolume(int);
	void PlaySFX(std::string filename, int loops = 0, int channel = -1);
};

#endif