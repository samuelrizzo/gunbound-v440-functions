#include "ShowGameMessage.h"

typedef void(__stdcall *ShowGameMessageFunc1)(const char *message, int color, int icon);
typedef void(__stdcall *ShowGameMessageFunc2)(void *obj, const char *message, char color, WORD icon);

void ShowGameMessage(int icon, int color, const char *message) {
    const DWORD SHOW_GAME_MESSAGE_FUNCTION_ADDRESS_1 = 0x004CF180;
    const DWORD SHOW_GAME_MESSAGE_FUNCTION_ADDRESS_2 = 0x004DCB50;
    const DWORD GAME_STATE_BASE_ADDRESS = 0x008701cc;

    __try {
        reinterpret_cast<ShowGameMessageFunc1>(SHOW_GAME_MESSAGE_FUNCTION_ADDRESS_1)(message, color, icon);

        void *gameStateObj = reinterpret_cast<void *>(*reinterpret_cast<DWORD *>(GAME_STATE_BASE_ADDRESS));
        reinterpret_cast<ShowGameMessageFunc2>(SHOW_GAME_MESSAGE_FUNCTION_ADDRESS_2)(
            gameStateObj, message, static_cast<char>(color), static_cast<WORD>(icon));
    } __except (EXCEPTION_EXECUTE_HANDLER) {
    }
}