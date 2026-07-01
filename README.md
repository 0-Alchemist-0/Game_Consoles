# Game Consoles

Custom WiFi handheld game consoles built with an Arduino Nano ESP32, a
Waveshare 3.5 inch ILI9488 SPI display, FT6336 capacitive touch, microSD RAW
assets, and a buzzer.

Current sketch: `Game_Consoles.ino`

Current firmware metadata:

- Version: `Version 9.3`
- Build ID: `GC-V93-2026070120`
- Build ID format: `GC-V<major><minor>-<YYYYMMDDHH>`

## Overview

The project boots into an arcade-style home screen, plays an optional RAW565
intro from the SD card, and provides a multi-page games menu. Games can be
played locally on one console or, where supported, over WiFi using Host/Join.

The UI is designed for portrait mode:

- Screen width: `320`
- Screen height: `480`
- Rotation: `0`
- Display colors are inverted in firmware with `INVERT_DISPLAY_COLORS = true`

The sketch draws directly to the display using targeted redraws and game-level
dirty rectangles. It does not use the old full-screen canvas framebuffer
approach described by earlier README versions.

## Hardware

Main board:

- Arduino Nano ESP32

Display:

- Waveshare 3.5 inch SPI TFT
- Controller: ILI9488
- Library class: `Arduino_ILI9488_18bit`

Touch:

- FT6336 capacitive touch controller
- I2C address: `0x38`

Storage:

- microSD card on the same SPI bus as the display
- SD assets are RAW565 files, usually `320x480`

Audio:

- Buzzer on GPIO4
- Used for menu clicks, SFX, and the background menu melody

## Pin Configuration

The sketch uses ESP32 GPIO numbering.

| Function | GPIO | Arduino Nano ESP32 label | Header note |
| --- | ---: | --- | --- |
| LCD CS | 21 | D10 | JP2-3 |
| LCD DC | 18 | D9 | JP2-4 |
| LCD RST | 17 | D8 | JP2-5 |
| LCD MOSI | 38 | D11 / MOSI | JP2-2 |
| LCD MISO | 47 | D12 / MISO | JP2-1 |
| LCD SCLK | 48 | D13 / SCK | JP1-1 |
| SD CS | 8 | D5 | JP2-8 |
| Touch INT | 6 | D3 | JP2-10 |
| Touch RST | 7 | D4 | JP2-9 |
| I2C SDA | 11 | A4 / SDA | JP1-8 |
| I2C SCL | 12 | A5 / SCL | JP1-9 |
| Buzzer | 4 | A3 | JP1-7 |

SD SPI frequency:

```cpp
static const int SD_SPI_FREQ = 49000000;
```

If the SD card is unstable with your wiring, lower this value in the sketch.

## Required Libraries

Install these in Arduino IDE / Arduino CLI:

- `Arduino_GFX_Library`
- ESP32 board package for Arduino Nano ESP32

The sketch also uses standard ESP32/Arduino libraries:

- `Wire`
- `WiFi`
- `Preferences`
- `SPI`
- `SD`
- `FS`
- `esp_now`
- `esp_wifi`
- `esp_system`

## Main Screens

Home screen:

- `GAMES`
- `SETTINGS`
- `EXIT`
- Version and Build ID are displayed in small text at the bottom

Games menu pages:

- Page 1: Tic Tac Toe, Rock-Paper-Scissors, Tanks Wars
- Page 2: Snake, Breakout, Pong, Ranch Rush
- Page 3: Hex Pipes, Frogger

Most game menus use:

- `LOCAL`
- `HOST`
- `JOIN`
- `RESET SCORE`
- `BACK`

## Settings

The Home screen `SETTINGS` button opens two settings categories.

### Music

- `MUSIC ON/OFF`
- `SFX ON/OFF`

Music controls the background arcade melody while not in a game.
SFX controls button and game sound effects.

Settings are saved persistently in ESP32 flash using `Preferences`.

### WiFi

WiFi settings allow:

- Default Host SSID selection from the built-in epic SSID list
- Host IP editing through four numeric fields
- Numeric keypad input
- Save button

Default Host IP:

```text
192.168.10.1
```

Network password for Host and Join:

```text
Alchemist2026
```

Network TCP port:

```text
3333
```

## Network Flow

Host:

1. Select `HOST` from a game menu.
2. Select an SSID from the built-in list.
3. Confirm or edit the Host IP.
4. The console starts a WiFi access point.
5. The host waits for the opponent.

Join:

1. Select `JOIN` from a game menu.
2. Scan/select an available WiFi network.
3. Confirm or edit the Host IP.
4. Join connects using the fixed password `Alchemist2026`.
5. The game starts when the socket connects.

The shared WiFi game protocol uses line-based TCP messages over port `3333`.

## Games

| Game | Local | Network Host/Join | Notes |
| --- | --- | --- | --- |
| Tic Tac Toe | Yes | Yes | Local X/O play, WiFi X/O play, persistent score |
| Rock-Paper-Scissors-Lizard-Spock | Yes | Yes | Uses SD RAW result images when available |
| Tanks Wars | Yes | Yes | Artillery-style tanks, destructible terrain, synced terrain seed |
| Breakout | Yes | Yes | First network player to lose all lives loses |
| Pong | Yes | Yes | Host-authoritative ball physics and synced paddles |
| Snake | Yes | Yes | Two-player network snakes with different colors |
| Ranch Rush | Yes | Yes | Lane-based lasso game with two visible network players |
| Frogger | Yes | Yes | Two visible network frogs, shared lanes/logs |
| Hex Pipes | Yes | Yes | Shared puzzle seed, P1/P2 move counters, solve race |

Each game has a score reset option in its game menu. High score or score data is
stored in ESP32 flash with separate `Preferences` namespaces per game.

<p align="center">
  <img src="Game_Consoles/Pics%26Videos/Games/0001_TicTacToe.jpeg" width="250">
  <img src="Game_Consoles/Pics%26Videos/Games/0002_RPSLS.jpeg" width="250">
  <img src="Game_Consoles/Pics%26Videos/Games/0003_Tanks.jpeg" width="250">
  <img src="Game_Consoles/Pics%26Videos/Games/0004_Snake.jpeg" width="250">
  <img src="Game_Consoles/Pics%26Videos/Games/0005_Breakout.jpeg" width="250">
  <img src="Game_Consoles/Pics%26Videos/Games/0006_Pong.jpeg" width="250">
  <img src="Game_Consoles/Pics%26Videos/Games/0007_RanchRush.jpeg" width="250">
  <img src="Game_Consoles/Pics%26Videos/Games/0008_HexPipes.jpeg" width="250">
  <img src="Game_Consoles/Pics%26Videos/Games/0009_Frogger.jpeg" width="250">
</p>


## SD Card Assets

The console can run with generated fallback screens when assets are missing, but
the intended UI uses RAW565 files from the microSD card.

Important SD paths:

```text
/intro/frame_000.raw ... /intro/frame_074.raw
/home_screen/background.raw
/home_screen/button_games.raw
/home_screen/button_settings.raw
/home_screen/button_exit.raw
/games_screen/games_background.raw
/tictactoe_game/tictactoe_background.raw
/RPSLS_game/main_screen/rock_paper_scissors_background.raw
/RPSLS_game/general/rpsls_wheel.raw
/RPSLS_game/local/player1_wins/*.raw
/RPSLS_game/local/player2_wins/*.raw
/RPSLS_game/local/draw/*.raw
/RPSLS_game/win/*.raw
/RPSLS_game/lose/*.raw
```

RAW image format:

- RGB565
- No header
- Full-screen assets are `320x480`
- Intro frames are also portrait `320x480`

The repository `SD_card` folder contains SD card content and preview PNGs.

## Persistent Data

Stored with `Preferences`:

- Tic Tac Toe score
- RPSLS score
- Tanks Wars score
- Breakout high score
- Pong score
- Snake high score
- Ranch Rush high score
- Frogger high score
- Hex Pipes best moves and best time
- Default WiFi/Host IP settings
- Music and SFX settings

## Notes

- Keep only one active Arduino sketch file in the project folder to avoid
  duplicate symbol errors.
- The active sketch should be `Game_Consoles.ino`.
- If you copy the project into Arduino IDE, the folder name should match the
  active `.ino` file or you should open the correct sketch directly.
- If SD assets do not load, the firmware falls back to generated screens for
  the main UI and several game menus.
- For network play, use the same firmware version on both consoles.
