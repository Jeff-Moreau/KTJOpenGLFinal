#ifndef _AUDIOMANAGER_H
#define _AUDIOMANAGER_H

#include <SDL2/SDL.h>
#include <vector>
#include <string>

class AudioManager {
public:
	AudioManager();
	~AudioManager();

	bool Initialize();
	void Shutdown();

	bool LoadSound(const std::string& soundPath);
	void PlaySound(int soundIndex, int volume = 128);
	void StopAllSounds();

private:
	SDL_AudioDeviceID audioDevice;
	std::vector<SDL_AudioSpec> soundSpecs;
	std::vector<Uint8*> soundBuffers;
};


#endif