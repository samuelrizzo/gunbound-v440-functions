#include <windows.h>

DWORD __stdcall GetMasterSlot() {
    const DWORD GAME_STATE_BASE_ADDRESS = 0x00873040;
    const DWORD GET_MASTER_SLOT_FUNCTION_ADDRESS = 0x0042BFD0;
    DWORD result;

    __asm {
        pushad
        xor eax, eax
        mov ebx, 0x00000002
        mov edi, [GAME_STATE_BASE_ADDRESS]
        mov esi, 0x00000009
        xor edx, edx
        lea ecx, [edi + 0x0001A640]
        call [GET_MASTER_SLOT_FUNCTION_ADDRESS]
        mov result, eax
        popad
    }

    return result;
}
