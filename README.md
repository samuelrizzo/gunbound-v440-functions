# Gunbound World Champion v440 Plugin

DLL plugin for Gunbound World Champion v440 that demonstrates advanced packet manipulation, game state reading, and multimedia functionality.

> **Note:** This is an educational project created for learning purposes.

## Features

- **WASD Movement**: Toggle WASD keys for character movement (works alongside arrow keys)
- **Master Slot Detection**: Retrieves and displays the current master slot number
- **Player Nickname Reading**: Reads and displays player nicknames from game memory
- **Localized Message Loading**: Loads and displays localized strings by ID (directly from language.txt)
- **Audio Playback**: Plays XES sound files in-game
- **Game Message Display**: Rich message display with customizable colors and icons
- **Packet Manipulation**: Advanced packet sending with automatic size calculation
- **Automatic Leave**: Sends leave packet and exits room

## Project Structure

```
gunbound-v440-functions/
├── ASM/
│   ├── SendPacket.cpp            # Packet sending function implementation
│   ├── SendPacket.h              # SendPacket function interface
│   ├── ShowGameMessage.cpp       # Game message display implementation
│   ├── ShowGameMessage.h         # ShowGameMessage function interface
│   ├── GetMasterSlot.cpp         # Master slot retrieval implementation
│   ├── GetMasterSlot.h           # GetMasterSlot function interface
│   ├── LoadStringFromLanguage.cpp # Localized string loading implementation
│   ├── LoadStringFromLanguage.h   # LoadStringFromLanguage function interface
│   ├── PlayXESSound.cpp          # XES sound playback implementation
│   ├── PlayXESSound.h            # PlayXESSound function interface
│   ├── SetKeyboardDirection.cpp  # WASD to arrow key mapping implementation
│   └── SetKeyboardDirection.h    # MapWASDToArrows function interface
├── Helpers/
│   ├── ReadSlotNickname.cpp      # Player nickname reading implementation
│   └── ReadSlotNickname.h        # ReadSlotNickname function interface
├── dllmain.cpp                   # DLL entry point and main thread
├── CMakeLists.txt                # CMake configuration
├── build.ps1                     # Automated build script
└── README.md
```

## Build

Run the PowerShell script:

```powershell
.\build.ps1
```

Or manually:

```bash
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A Win32
cmake --build . --config Release
```

Output: `build/Release/plugin.dll`

## Usage

1. Inject the DLL into the Gunbound World Champion process

2. **F10** - Toggle WASD movement:
   - Enables/disables WASD keys for character movement
   - Arrow keys continue working when WASD is enabled
   - Displays status message on toggle

3. **F6** - Demonstration sequence:
   - Display master slot number
   - Display master player nickname
   - Display localized message (ID 5000)
   - Play "gold.xes" sound effect
   - Display "Leaving room..." message
   - Send leave packet and exit room

## Requirements

- Visual Studio 2022
- CMake 3.20+
- Windows x86

## Author

**rizzo**

## Acknowledgments

**Luiz Felipe (Kyll3r)** for always publishing open source GunBound content and encouraging the community to do the same

**Finn** for research involving reverse engineering of GunBound
