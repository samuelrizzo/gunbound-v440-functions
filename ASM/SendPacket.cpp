#include "SendPacket.h"
#include <cstring>

typedef void(__stdcall *SendPacketFunc)(DWORD baseAddress);

void SendPacket(BYTE *packetData, WORD packetLen) {
    const DWORD PACKET_BUFFER_BASE_ADDRESS = 0x00870558;
    const DWORD SEND_PACKET_FUNCTION_ADDRESS = 0x00445CD0;

    DWORD baseAddress = *reinterpret_cast<DWORD *>(PACKET_BUFFER_BASE_ADDRESS);

    memcpy(reinterpret_cast<void *>(baseAddress + 0x9C), packetData, packetLen);
    *reinterpret_cast<WORD *>(baseAddress + 0x4098) = packetLen;

    reinterpret_cast<SendPacketFunc>(SEND_PACKET_FUNCTION_ADDRESS)(baseAddress);
}