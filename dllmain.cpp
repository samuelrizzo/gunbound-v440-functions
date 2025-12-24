#include "ASM/GetMasterSlot.h"
#include "ASM/GunbaMessageBox.h"
#include "ASM/LoadStringFromLanguage.h"
#include "ASM/PlayXESSound.h"
#include "ASM/SendPacket.h"
#include "ASM/SetKeyboardDirection.h"
#include "ASM/ShowGameMessage.h"
#include "Helpers/ReadSlotNickname.h"
#include <cstdio>
#include <windows.h>

static bool g_wasdEnabled = false;

DWORD WINAPI WASDMappingThread(LPVOID lpParam) {
    while (true) {
        if (g_wasdEnabled) {
            MapWASDToArrows();
        }
        Sleep(0);
    }
    return 0;
}

DWORD WINAPI FunctionDemonstration(LPVOID lpParam) {
    BYTE leave[4] = {0x00, 0x20, 0xFF, 0xFF};

    while (true) {
        if (GetAsyncKeyState(VK_F10) & 0x8000) {
            g_wasdEnabled = !g_wasdEnabled;

            if (g_wasdEnabled) {
                ShowGameMessage(5, 5, "WASD ativado (setas continuam funcionando)");
            } else {
                ShowGameMessage(5, 5, "WASD desativado (apenas setas)");
            }

            while (GetAsyncKeyState(VK_F10) & 0x8000) {
                Sleep(10);
            }
        }

        if (GetAsyncKeyState(VK_F6) & 0x8000) {
            DWORD masterSlot = GetMasterSlot();
            char buffer[256];
            sprintf(buffer, "Master Slot: %lu", masterSlot);
            ShowGameMessage(5, 5, buffer);

            char *masterNickname = ReadSlotNickname(masterSlot);
            if (masterNickname) {
                sprintf(buffer, "Master Nickname: %s", masterNickname);
                ShowGameMessage(5, 5, buffer);
                delete[] masterNickname;
            } else {
                ShowGameMessage(5, 5, "Master Nickname: Failed to read");
            }

            const char *localizedMessage = LoadStringFromLanguageTxt(5000);
            if (localizedMessage) {
                sprintf(buffer, "Localized Message (ID 5000): %s", localizedMessage);
                ShowGameMessage(5, 5, buffer);
            } else {
                ShowGameMessage(5, 5, "Localized Message (ID 5000): NULL or not found");
            }

            PlayXESSound("gold.xes");
            Sleep(4000);
            // GunbaMessageBox("Leaving room...", 1); // crashing game for some reason
            ShowGameMessage(5, 5, "Leaving room...");
            Sleep(4000);
            SendPacket(&leave[0], 8); // always packet len +4

            while (GetAsyncKeyState(VK_F6) & 0x8000) {
                Sleep(10);
            }
        }

        Sleep(50);
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, WASDMappingThread, NULL, 0, NULL);
        CreateThread(NULL, 0, FunctionDemonstration, NULL, 0, NULL);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
