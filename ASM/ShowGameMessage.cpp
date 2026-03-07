#include "ShowGameMessage.h"

constexpr DWORD SHOW_GAME_MESSAGE_FUNCTION_ADDRESS = 0x004CF180;

using ShowGameMessageFunction = void(__stdcall *)(const char *message, int icon, int color);

void ShowGameMessage(int icon, int color, const char *message) {
    if (message == nullptr) return;
    reinterpret_cast<ShowGameMessageFunction>(SHOW_GAME_MESSAGE_FUNCTION_ADDRESS)(message, icon, color);
}
