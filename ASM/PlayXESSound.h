/**
 * @file PlayXESSound.h
 * @brief Declaration of the sound playing routine for the Gunbound client.
 *
 * This header exposes the PlayXESSound function, which plays XES sound files in the
 * client using the native sound system. The implementation uses function pointers
 * and absolute addresses tied to a specific client version, so version changes may
 * invalidate the hardcoded offsets.
 *
 * Dependencies: requires Windows headers for basic types.
 *
 * @date 2025-10-15
 */

#pragma once

#include <windows.h>

/**
 * @brief Plays a XES sound file in the client.
 *
 * Invokes the native sound playing function with the specified sound name. The sound
 * is played once (not in loop mode). Uses function pointer to call the native routine
 * at address 0x00529cb0.
 *
 * Implementation details:
 * - Uses PLAY_XES_SOUND_FUNCTION_ADDRESS (0x00529cb0) to call the native sound function
 * - Passes soundName as first parameter
 * - Passes 0x00 as loop flag (0x01 would enable looping)
 * - Uses __cdecl calling convention (caller cleans up the stack)
 *
 * Contract:
 * - soundName must not be null and should point to a valid sound file name
 * - Call site must run in the correct client context compatible with the offsets
 *
 * @param soundName Pointer to null-terminated string containing the sound file name.
 */
void PlayXESSound(const char *soundName);
