/**
 * @file ReadSlotNickname.h
 * @brief Declaration of the helper function for reading slot nicknames from the Gunbound client.
 *
 * This header exposes the ReadSlotNickname function, which reads player nicknames
 * from specific memory addresses in the client's game state. The function allocates
 * memory for the returned string, which should be freed by the caller.
 *
 * Dependencies: requires Windows headers for DWORD type and C++ standard library.
 *
 * @date 2025-10-15
 */

#pragma once

#include <windows.h>

/**
 * @brief Reads a player's nickname from the specified slot index.
 *
 * Allocates and returns a null-terminated string containing the nickname of the player
 * in the specified slot. The function reads from hardcoded memory addresses specific
 * to each slot index and copies up to 16 characters.
 *
 * Memory management details:
 * - Allocates memory using 'new' operator - caller must 'delete[]' the returned pointer
 * - Returns up to 16 characters + null terminator (17 bytes total)
 * - Stops at null terminator if found earlier in the memory
 *
 * Slot mapping:
 * - 0: Address 0x008971A5
 * - 1: Address 0x008971B9
 * - 2: Address 0x008971CD
 * - 3: Address 0x008971E1
 * - 4: Address 0x008971F5
 * - 5: Address 0x00897209
 * - 6: Address 0x0089721D
 * - 7+: Address 0x00897231 (default)
 *
 * Contract:
 * - Valid slot indices: 0-7 (higher values default to slot 7)
 * - Return value must be freed with 'delete[]' to prevent memory leaks
 * - Returns empty string if memory allocation fails
 * - Call site must run in the correct client context compatible with the addresses
 *
 * @param i The slot index (0-7) to read the nickname from.
 * @return Pointer to dynamically allocated null-terminated string containing the nickname.
 */
char *ReadSlotNickname(int i);
