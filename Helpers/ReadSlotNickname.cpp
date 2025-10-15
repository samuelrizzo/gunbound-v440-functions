#include "ReadSlotNickname.h"

#include <windows.h>

char *ReadSlotNickname(int i) {
    DWORD address;
    switch (i) {
    case 0:
        address = 0x008971A5;
        break;
    case 1:
        address = 0x008971B9;
        break;
    case 2:
        address = 0x008971CD;
        break;
    case 3:
        address = 0x008971E1;
        break;
    case 4:
        address = 0x008971F5;
        break;
    case 5:
        address = 0x00897209;
        break;
    case 6:
        address = 0x0089721D;
        break;
    default:
        address = 0x00897231;
        break;
    }

    char *buffer = new char[17];
    int j = 0;
    while (j < 16) {
        char c = *reinterpret_cast<char *>(address + j);
        if (c == '\0') {
            break;
        }
        buffer[j] = c;
        j++;
    }
    buffer[j] = '\0';
    return buffer;
}