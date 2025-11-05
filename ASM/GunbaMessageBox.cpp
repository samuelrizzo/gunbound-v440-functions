#include "GunbaMessageBox.h"

DWORD *GunbaMessageBox(const char *str, char closeGame) {
    const DWORD GUNBA_MESSAGE_BOX_FUNCTION_ADDRESS = 0x00413AE0;
    DWORD *ret;

    __asm {
		push  closeGame
		mov   esi, str
		call  [GUNBA_MESSAGE_BOX_FUNCTION_ADDRESS]
		mov   ret, eax
    }
    return ret;
}
