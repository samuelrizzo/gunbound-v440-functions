/**
 * @file ShowGameMessage.h
 * @brief Declares the wrapper around the client's in-game message routine.
 *
 * The implementation forwards to a fixed Gunbound v440 client address.
 * It is expected to be portable to future client versions by updating the
 * mapped address and, if necessary, the native function signature.
 */

#pragma once

#include <windows.h>

/**
 * @brief Displays a message in the game chat UI.
 *
 * @param icon Icon code used by the client.
 * @param color Color code used by the client.
 * @param message Null-terminated message text.
 */
void ShowGameMessage(int icon, int color, const char *message);
