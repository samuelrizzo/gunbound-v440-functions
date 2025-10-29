#include "ShowGameMessage.h"

const DWORD SHOW_GAME_MESSAGE_FUNCTION_ADDRESS_1 = 0x004CF180;
const DWORD SHOW_GAME_MESSAGE_FUNCTION_ADDRESS_2 = 0x004DCB50;

void ShowGameMessage(int icon, int color, const char *message) {
    __try {
        __asm {
            push icon
            push color
            push message
            call SHOW_GAME_MESSAGE_FUNCTION_ADDRESS_1

            push icon
            push color
            push message
            call SHOW_GAME_MESSAGE_FUNCTION_ADDRESS_2
        }
    } __except (EXCEPTION_EXECUTE_HANDLER) {
    }
}