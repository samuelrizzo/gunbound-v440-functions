#include "PlayXESSound.h"

typedef unsigned int(__cdecl *PlayXESSoundFunc)(const char *soundName, int loopFlag);

void PlayXESSound(const char *soundName) {
    const DWORD PLAY_XES_SOUND_FUNCTION_ADDRESS = 0x00529cb0;
    
    reinterpret_cast<PlayXESSoundFunc>(PLAY_XES_SOUND_FUNCTION_ADDRESS)(soundName, 0);
}