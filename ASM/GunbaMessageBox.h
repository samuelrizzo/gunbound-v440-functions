/**
 * @file GunbaMessageBox.h
 * @brief Declaration of the message box routine for the Gunbound client.
 *
 * This header exposes the GunbaMessageBox function, which displays a message box dialog
 * in the Gunbound client interface. The implementation uses inline assembly and absolute
 * addresses tied to a specific client version, so version changes may invalidate the
 * hardcoded offsets.
 *
 * Dependencies: requires Windows headers for DWORD type.
 *
 * @date 2025-08-25
 */

#pragma once

#include <windows.h>

/**
 * @brief Displays a message box dialog in the Gunbound client.
 *
 * Invokes the native message box function at address 0x00413AE0 using inline assembly.
 * The function displays a message dialog to the user and optionally closes the game
 * based on the closeGame parameter.
 *
 * Implementation details:
 * - Uses GUNBA_MESSAGE_BOX_FUNCTION_ADDRESS (0x00413AE0) to call the native message box routine
 * - Pushes the closeGame parameter onto the stack
 * - Moves the string pointer to ESI register
 * - Calls the native function using a function pointer
 * - Returns the result from EAX register
 *
 * Contract:
 * - str must not be null and should point to a valid null-terminated string
 * - closeGame parameter: 0 = do not close game, non-zero = close game after message
 * - Call site must run in the correct client context compatible with the offsets
 *
 * @param str Pointer to the null-terminated message string to display.
 * @param closeGame Flag indicating whether to close the game (0 = no, non-zero = yes).
 * @return Pointer to DWORD containing the function's return value.
 */
DWORD *GunbaMessageBox(const char *str, char closeGame);
