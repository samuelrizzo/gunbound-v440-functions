#include <windows.h>

DWORD PLAY_XES_SOUND_FUNCTION_ADDRESS = 0x00529cb0;

void PlayXESSound(const char *soundName) {
    _asm {
        pushad
        push 0x00 // if 0x01 it will play in loop
        push soundName
        call dword ptr [PLAY_XES_SOUND_FUNCTION_ADDRESS]
        add esp, 8
        popad
    }
}