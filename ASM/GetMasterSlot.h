/**
 * @file GetMasterSlot.h
 * @brief Declaration of the master slot retrieval routine for the Gunbound client.
 *
 * This header exposes the GetMasterSlot function, which retrieves the master slot
 * information from the client's game state. The implementation uses function pointers
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
 * current master slot in the game session. Uses function pointer to call the native
 * routine at address 0x0042BFD0.
 *
 * Implementation details:
 * - Uses GAME_STATE_BASE_ADDRESS (0x008701cc) as the base pointer for game state
 * - Calculates game state pointer as [base + 0x0001A640]
 * - Calls native function at GET_MASTER_SLOT_FUNCTION_ADDRESS (0x0042BFD0) via function pointer
 * - Uses __fastcall calling convention (first parameter passed in ECX register)
 * - Returns the master slot value as DWORD
 *
 * Contract:
 * - Call site must run in the correct client context compatible with the offsets
 * - Return value represents the master slot information
 *
 * @return DWORD containing the master slot information.
 */
DWORD __stdcall GetMasterSlot();
