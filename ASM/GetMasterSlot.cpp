#include "GetMasterSlot.h"

typedef unsigned int(__fastcall *GetMasterSlotFunc)(void *gameState);

DWORD __stdcall GetMasterSlot() {
    const DWORD GAME_STATE_BASE_ADDRESS = 0x008701cc;
    const DWORD GET_MASTER_SLOT_FUNCTION_ADDRESS = 0x0042BFD0;
    const DWORD GAME_STATE_OFFSET = 0x0001A640;

    DWORD baseAddress = *reinterpret_cast<DWORD *>(GAME_STATE_BASE_ADDRESS);
    void *gameStatePtr = reinterpret_cast<void *>(baseAddress + GAME_STATE_OFFSET);

    return reinterpret_cast<GetMasterSlotFunc>(GET_MASTER_SLOT_FUNCTION_ADDRESS)(gameStatePtr);
}
