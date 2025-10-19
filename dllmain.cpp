#include "ASM/GetMasterSlot.h"
#include "ASM/LoadStringFromLanguage.h"
#include "ASM/PlayXESSound.h"
#include "ASM/SendPacket.h"
#include "ASM/ShowGameMessage.h"
#include "Helpers/ReadSlotNickname.h"
#include <cstdio>
#include <windows.h>
DWORD WINAPI FunctionDemonstration(LPVOID lpParam) {
    BYTE leave[4] = {0x00, 0x20, 0xFF, 0xFF};

    while (true) {
        if (GetAsyncKeyState(VK_F10) & 0x8000) {
            DWORD masterSlot = GetMasterSlot();
            char masterSlotBuffer[256];
            sprintf(masterSlotBuffer, "Master Slot: %lu", masterSlot);
            ShowGameMessage(5, 5, masterSlotBuffer);

            char *masterNickname = ReadSlotNickname(masterSlot);
            if (masterNickname) {
                char nicknameBuffer[256];
                sprintf(nicknameBuffer, "Master Nickname: %s", masterNickname);
                ShowGameMessage(5, 5, nicknameBuffer);
                delete[] masterNickname;
            } else {
                ShowGameMessage(5, 5, "Master Nickname: Failed to read");
            }

            const char *localizedMessage = LoadStringFromLanguageTxt(5000);
            if (localizedMessage) {
                char messageBuffer[512];
                sprintf(messageBuffer, "Localized Message (ID 5000): %s", localizedMessage);
                ShowGameMessage(5, 5, messageBuffer);
            } else {
                ShowGameMessage(5, 5, "Localized Message (ID 5000): NULL or not found");
            }

            PlayXESSound("gold.xes");
            Sleep(4000);
            ShowGameMessage(5, 5, "Leaving room...");
            Sleep(4000);
            SendPacket(&leave[0], 8); // always packet len +4
        }
        Sleep(50);
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, FunctionDemonstration, NULL, 0, NULL);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
