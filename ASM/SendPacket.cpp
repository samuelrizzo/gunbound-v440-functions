#include "SendPacket.h"

void SendPacket(BYTE *packetData) {
    const DWORD PACKET_BUFFER_BASE_ADDRESS = 0x00870558;
    const DWORD SEND_PACKET_FUNCTION_ADDRESS = 0x00445CD0;

    memcpy((void *)((*(DWORD *)PACKET_BUFFER_BASE_ADDRESS) + 0x9C), packetData, sizeof(packetData) + 4);
    *(WORD *)((*(DWORD *)PACKET_BUFFER_BASE_ADDRESS) + 0x4098) = sizeof(packetData) + 4;
    __asm {
		pushad
		mov esi, [PACKET_BUFFER_BASE_ADDRESS]
		mov esi, [esi]
		lea ecx, [esi + 0x80BC]
		popad

		mov ecx, [PACKET_BUFFER_BASE_ADDRESS]
		mov ecx, [ecx]
		mov [ebp-4], ecx
		mov ecx, [SEND_PACKET_FUNCTION_ADDRESS]
		mov [ebp-8], ecx
		push [ebp-4]
		call dword ptr [ebp-8]
    }
}