#include "SetKeyboardDirection.h"

const DWORD KEYBOARD_OBJECT_ADDRESS = 0x8EABE0;
const DWORD MOUSE_OBJECT_ADDRESS = 0x8EB840;

const DWORD DIRECTION_LEFTRIGHT_OFFSET = 0x28;
const DWORD DIRECTION_UPDOWN_OFFSET = 0x2C;

const int DIRECTION_VALUE = 1000;

void MapWASDToArrows() {
    int *kbLeftRight = reinterpret_cast<int *>(KEYBOARD_OBJECT_ADDRESS + DIRECTION_LEFTRIGHT_OFFSET);
    int *kbUpDown = reinterpret_cast<int *>(KEYBOARD_OBJECT_ADDRESS + DIRECTION_UPDOWN_OFFSET);

    int *mouseLeftRight = reinterpret_cast<int *>(MOUSE_OBJECT_ADDRESS + DIRECTION_LEFTRIGHT_OFFSET);
    int *mouseUpDown = reinterpret_cast<int *>(MOUSE_OBJECT_ADDRESS + DIRECTION_UPDOWN_OFFSET);

    if (GetAsyncKeyState('S') & 0x8000) {
        *kbUpDown = DIRECTION_VALUE;
        *mouseUpDown = DIRECTION_VALUE;
    }
    if (GetAsyncKeyState('W') & 0x8000) {
        *kbUpDown = -DIRECTION_VALUE;
        *mouseUpDown = -DIRECTION_VALUE;
    }
    if (GetAsyncKeyState('A') & 0x8000) {
        *kbLeftRight = -DIRECTION_VALUE;
        *mouseLeftRight = -DIRECTION_VALUE;
    }
    if (GetAsyncKeyState('D') & 0x8000) {
        *kbLeftRight = DIRECTION_VALUE;
        *mouseLeftRight = DIRECTION_VALUE;
    }
}
