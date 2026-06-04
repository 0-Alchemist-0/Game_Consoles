```text
 _______  _        _______           _______  _______ _________ _______ _________
(  ___  )( \      (  ____ \|\     /|(  ____ \(       )\__   __/(  ____ \\__   __/
| (   ) || (      | (    \/| )   ( || (    \/| () () |   ) (   | (    \/   ) (   
| (___) || |      | |      | (___) || (__    | || || |   | |   | (_____    | |   
|  ___  || |      | |      |  ___  ||  __)   | |(_)| |   | |   (_____  )   | |   
| (   ) || |      | |      | (   ) || (      | |   | |   | |         ) |   | |   
| )   ( || (____/\| (____/\| )   ( || (____/\| )   ( |___) (___/\____) |   | |   
|/     \|(_______/(_______/|/     \|(_______/|/     \|\_______/\_______)   )_(   
```


# Game_Consoles
WiFi Gaming Consoles using Arduino nano ESP32 &amp; Waveshare Display


PROJECT README
==============

This project is designed for a custom Arduino-based handheld game setup using an Arduino Nano ESP32, a Waveshare 3.5 inch ILI9488 SPI TFT display, and an FT6336U capacitive touch controller.

The goal of this setup is to run local touchscreen games with a retro arcade style interface, smooth graphics, and minimal screen flickering.

HARDWARE SETUP
==============

Main controller:
- Arduino Nano ESP32

Display:
- Waveshare 3.5 inch TFT display
- Display controller: ILI9488
- Resolution used in this project: 480 x 320 pixels
- Orientation: Landscape
- Communication: SPI

Touch controller:
- Capacitive touch controller: FT6336U
- Communication: I2C
- I2C address: 0x38

Optional audio:
- Passive or active buzzer
- Used for click sounds, game sounds, alerts, and simple effects

DISPLAY PIN CONFIGURATION
=========================

LCD_CS    = GPIO 21
LCD_DC    = GPIO 18
LCD_RST   = GPIO 17
LCD_MOSI  = GPIO 38
LCD_MISO  = GPIO 47
LCD_SCLK  = GPIO 48

TOUCH PIN CONFIGURATION
=======================

TOUCH_SDA = GPIO 11
TOUCH_SCL = GPIO 12
TOUCH_INT = GPIO 6
TOUCH_RST = GPIO 7

Touch I2C address:
FT6336_ADDR = 0x38

BUZZER CONFIGURATION
====================

BUZZER_PIN = GPIO 5
USE_BUZZER = true

SCREEN CONFIGURATION
====================

SCREEN_W = 480
SCREEN_H = 320

The project is intended to run in landscape mode.

GRAPHICS APPROACH
=================

To reduce flickering on the ILI9488 display, the game does not draw large screen updates directly to the TFT display.

Instead, the project uses a canvas buffer:

Arduino_Canvas *canvas = new Arduino_Canvas(480, 320, gfx);

All game elements are first drawn into the RAM canvas. After the full frame is complete, the complete image is pushed to the display using:

canvas->flush();

This approach works like a framebuffer and gives a much smoother visual result compared to directly calling fillScreen(), fillRect(), or drawing many elements directly on the LCD.

LIBRARIES USED
==============

The project is based on:

- Arduino_GFX_Library
- Wire library for I2C communication
- SPI communication for the TFT display

Typical include section:

#include <Arduino_GFX_Library.h>
#include <Wire.h>

GENERAL PURPOSE
===============

This setup can be used for:

- Touchscreen arcade games
- Local multiplayer games
- Retro-style UI screens
- Simple animations
- Game menus
- SD card based assets, if added
- Sound feedback using the buzzer

NOTES
=====

For best results:
- Keep the display in landscape mode.
- Draw all graphics to the canvas first.
- Call canvas->flush() only once per frame.
- Avoid clearing the physical display directly during gameplay.
- Use calibrated touch coordinates for reliable input.
- Keep UI buttons large enough for comfortable finger input.

This README describes the hardware and rendering setup used by the project.
