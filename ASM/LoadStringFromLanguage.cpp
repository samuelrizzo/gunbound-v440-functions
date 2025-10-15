#include <windows.h>
const DWORD LOAD_STRING_FROM_LANGUAGE_FUNCTION_ADDRESS = 0x00444BA0;

const char *LoadStringFromLanguageTxt(int stringId) {
    const char *loadedString;
    __asm {
            push stringId
            push 0x00872f5c
            call dword ptr [LOAD_STRING_FROM_LANGUAGE_FUNCTION_ADDRESS]
            mov loadedString, eax
            add esp, 8
    }
    return loadedString;
}