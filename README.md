# Gunbound World Champion v440 Plugin

DLL plugin for Gunbound World Champion v440 that demonstrates advanced packet manipulation, game state reading, and multimedia functionality.

> **Note:** This is an educational project created for learning purposes.

## Features

- **Master Slot Detection**: Retrieves and displays the current master slot number
- **Player Nickname Reading**: Reads and displays player nicknames from game memory
- **Localized Message Loading**: Loads and displays localized strings by ID (directly from language.txt)
- **Audio Playback**: Plays XES sound files in-game
- **Game Message Display**: Rich message display with customizable colors and icons
- **Packet Manipulation**: Advanced packet sending with automatic size calculation
- **Automatic Leave**: Sends leave packet and exits room on F10 keypress
- Inline assembly implementation for maximum performance

## Project Structure

```
gunbound-v440-functions/
├── ASM/
│   ├── SendPacket.cpp          # Packet sending function implementation
│   ├── SendPacket.h            # SendPacket function interface
│   ├── ShowGameMessage.cpp     # Game message display implementation
│   ├── ShowGameMessage.h       # ShowGameMessage function interface
│   ├── GetMasterSlot.cpp       # Master slot retrieval implementation
│   ├── GetMasterSlot.h         # GetMasterSlot function interface
│   ├── LoadStringFromLanguage.cpp # Localized string loading implementation
│   ├── LoadStringFromLanguage.h   # LoadStringFromLanguage function interface
│   ├── PlayXESSound.cpp        # XES sound playback implementation
│   └── PlayXESSound.h          # PlayXESSound function interface
├── Helpers/
│   ├── ReadSlotNickname.cpp    # Player nickname reading implementation
│   └── ReadSlotNickname.h      # ReadSlotNickname function interface
├── dllmain.cpp                 # DLL entry point and main thread
├── CMakeLists.txt              # CMake configuration
├── build.ps1                   # Automated build script
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

1. Inject the DLL into the Gunbound Thors Hammers process
2. Press F10 to trigger the demonstration sequence:
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

**Gabriel Castro** for contributing and encouraging reverse engineering research on Gunbound, and for initiating the publication of ASM functions for the v440 version
