/**
 * @file GetMasterSlot.h
 * @brief Declaration of the ASM-based master slot retrieval routine for the Gunbound client.
 *
 * This header exposes the GetMasterSlot function, which retrieves the master slot
 * information from the client's game state. The implementation uses x86 inline assembly
 * and absolute addresses tied to a specific client version, so version changes may
 * invalidate the hardcoded offsets.
 *
 * Dependencies: requires Windows headers for DWORD type.
 *
 * @date 2025-10-15
 */

#pragma once

#include <windows.h>

/**
 * @brief Retrieves the master slot information from the game state.
 *
 * Invokes the native master slot retrieval function to get information about the
 * current master slot in the game session. Implemented in `GetMasterSlot.cpp`
 * using inline ASM with stdcall calling convention.
 *
 * Implementation details:
 * - Uses GAME_STATE_BASE_ADDRESS (0x00873040) as the base pointer for game state
 * - Calls native function at GET_MASTER_SLOT_FUNCTION_ADDRESS (0x0042BFD0)
 * - Sets up registers: EBX=2, ESI=9, ECX=[EDI+0x0001A640]
 * - Calls the function and retrieves the result in EAX
 * - Returns the master slot value as DWORD
 *
 * Contract:
 * - Call site must run in the correct client context compatible with the offsets
 * - Return value represents the master slot information
 *
 * @return DWORD containing the master slot information.
 */
DWORD __stdcall GetMasterSlot();
