#include "SendPacket.h"
#include <cstring>

typedef void(__stdcall *SendPacketFunc)(DWORD baseAddress);

void SendPacket(BYTE *packetData, WORD packetLen) {
    const DWORD PACKET_BUFFER_BASE_ADDRESS = 0x00870558;
    const DWORD SEND_PACKET_FUNCTION_ADDRESS = 0x00445CD0;

    memcpy((void *)((*(DWORD *)PACKET_BUFFER_BASE_ADDRESS) + 0x9C), packetData, packetLen);
    *(WORD *)((*(DWORD *)PACKET_BUFFER_BASE_ADDRESS) + 0x4098) = packetLen;

    DWORD baseAddress = *(DWORD *)PACKET_BUFFER_BASE_ADDRESS;
    SendPacketFunc sendPacketFunc = (SendPacketFunc)SEND_PACKET_FUNCTION_ADDRESS;
    sendPacketFunc(baseAddress);
}