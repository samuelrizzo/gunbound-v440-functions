/**
 * @file LoadStringFromLanguage.h
 * @brief Declaration of the ASM-based string loading routine for the Gunbound client.
 *
 * This header exposes the LoadStringFromLanguageTxt function, which loads localized
 * strings from the client's language.txt file. The implementation uses x86 inline
 * assembly and absolute addresses tied to a specific client version, so version
 * changes may invalidate the hardcoded offsets.
 *
 * Dependencies: requires Windows headers for DWORD type.
 *
 * @date 2025-10-15
 */

#pragma once

#include <windows.h>

/**
 * @brief Loads a localized string from the language file by ID.
 *
 * Invokes the native string loading function to retrieve text strings from the client's
 * language system. The function returns a pointer to the loaded string. Implemented in
 * `LoadStringFromLanguage.cpp` using inline ASM.
 *
 * Implementation details:
 * - Uses LOAD_STRING_FROM_LANGUAGE_FUNCTION_ADDRESS (0x00444BA0) to call the native function
 * - Pushes stringId parameter and language file address (0x00872f5c) to the stack
 * - Calls the string loading function and retrieves the result in EAX
 * - Returns the const char pointer to the loaded string
 *
 * Contract:
 * - stringId should be a valid string identifier from the language file
 * - Return value is a pointer to internal string buffer - do not modify or free
 * - Call site must run in the correct client context compatible with the offsets
 *
 * @param stringId The numeric identifier of the string to load from the language file.
 * @return Pointer to null-terminated string containing the localized text.
 */
const char *LoadStringFromLanguageTxt(int stringId);
