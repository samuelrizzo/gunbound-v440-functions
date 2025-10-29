/**
 * @file SendPacket.h
 * @brief Declaration of the packet sending routine for the Gunbound client.
 *
 * This header exposes the SendPacket function, which copies the provided payload into the
 * client's internal buffer and invokes the native sending routine. The implementation uses
 * function pointers and absolute addresses tied to a specific client version, so version
 * changes may invalidate the hardcoded offsets.
 *
 * Dependencies: requires Windows headers for BYTE type.
 *
 * @date 2025-08-25
 */

#pragma once

#include <windows.h>

/**
 * @brief Sends a raw packet to the client.
 *
 * Copies the buffer pointed to by packetData to the memory region expected by the client and
 * adjusts the packet size before invoking the internal send function. The function calls the
 * native send routine at address 0x00445CD0 using a function pointer with __stdcall calling
 * convention.
 *
 * Implementation details:
 * - Uses PACKET_BUFFER_BASE_ADDRESS (0x00870558) to get the packet buffer base address
 * - Copies payload data to [base + 0x9C]
 * - Writes packet length (WORD) at [base + 0x4098] using the provided packetLen parameter
 * - Invokes native send routine at SEND_PACKET_FUNCTION_ADDRESS (0x00445CD0) via function pointer
 * - Uses __stdcall calling convention (callee cleans up the stack)
 *
 * Contract:
 * - packetData must not be null
 * - packetLen must specify the exact length of the packet data in bytes
 * - Call site must run in the correct client context compatible with the offsets
 *
 * @param packetData Pointer to the packet data to send.
 * @param packetLen Length of the packet data in bytes.
 */
void SendPacket(BYTE *packetData, WORD packetLen);
