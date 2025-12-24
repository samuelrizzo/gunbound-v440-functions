/**
 * @file SetKeyboardDirection.h
 * @brief Declaration of WASD to Arrow key mapping for the Gunbound client.
 *
 * This header exposes the MapWASDToArrows function, which enables WASD movement by
 * directly writing direction values to the game's keyboard and mouse input objects.
 *
 * Dependencies: requires Windows headers.
 *
 * @date 2024-12-24
 */

#pragma once

#include <windows.h>

/**
 * @brief Maps WASD key presses to movement direction values.
 *
 * Writes direction values directly to keyboard and mouse input objects.
 * Must be called continuously in a loop for responsive input.
 *
 * Implementation details:
 * - Keyboard object address: 0x8EABE0
 * - Mouse object address: 0x8EB840
 * - Direction offsets: +0x28 (LEFT/RIGHT), +0x2C (UP/DOWN)
 * - Direction values: -1000 (left/up), +1000 (right/down)
 */
void MapWASDToArrows();
