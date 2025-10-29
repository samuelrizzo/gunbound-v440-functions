/**
 * @file ShowGameMessage.h
 * @brief Declaration of the game message display routine for the Gunbound client.
 *
 * This header exposes the ShowGameMessage function, which displays a message in the game
 * with specified color and icon. The implementation uses function pointers and absolute
 * addresses tied to a specific client version, so version changes may invalidate the
 * hardcoded offsets.
 *
 * Dependencies: requires Windows headers for basic types.
 *
 * @date 2025-10-15
 */

#pragma once

#include <windows.h>

/**
 * @brief Displays a message in the game interface.
 *
 * Invokes the game's internal message display functions with the provided parameters.
 * The message appears in the game's UI with the specified color and icon styling.
 * Uses function pointers to call the native routines at addresses 0x004CF180 and 0x004DCB50.
 *
 * Implementation details:
 * - Calls native functions at SHOW_GAME_MESSAGE_FUNCTION_ADDRESS_1 (0x004CF180) and
 *   SHOW_GAME_MESSAGE_FUNCTION_ADDRESS_2 (0x004DCB50)
 * - Parameters passed as (message, color, icon)
 * - Uses __stdcall calling convention (callee cleans up the stack)
 * - Calls both functions sequentially for complete message display
 *
 * Contract:
 * - message must be a valid null-terminated string
 * - color and icon values should be valid for the game's display system
 * - Call site must run in the correct client context compatible with the address
 *
 * @param icon Icon code to show alongside the message.
 * @param color Color code for the message display.
 * @param message Pointer to the null-terminated message string to display.
 */
void ShowGameMessage(int icon, int color, const char *message);