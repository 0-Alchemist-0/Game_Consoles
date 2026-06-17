// ============================================================================
// CHANGELOG
// ============================================================================
// Version 5.5 - 2026-06-17 19:24 - Added a generated arcade HOME fallback
// screen when SD home assets are missing.
// Version 5.4 - 2026-06-16 22:19 - Renamed user-facing artillery game text to
// Tanks Wars across menus, placeholders, and screen titles.
// Version 5.3 - 2026-06-03 22:20 - Added SD-loaded Rock-Paper-Scissors menu
// background support from /RPSLS_game/main_screen/rock_paper_scissors_background.raw.
// Version 5.2 - 2026-06-03 22:11 - Ported the Rock-Paper-Scissors arcade menu
// background and switched its menu to the transparent arcade text buttons.
// Version 5.1 - 2026-06-03 21:35 - Changed Games and Tic Tac Toe menu buttons
// to transparent arcade text buttons with consistent two-color lettering.
// Version 5.0 - 2026-06-03 21:30 - Added SD-loaded Tic Tac Toe menu background
// support from /tictactoe_game/tictactoe_background.raw with generated fallback.
// Version 4.9 - 2026-06-03 21:25 - Added SD-loaded Games screen background
// support from /games_screen/games_background.raw with generated fallback.
// Version 4.8 - 2026-06-03 18:28 - Added an arcade background and marquee title
// to the Games selection screen, reusing the neon button text style.
// Version 4.7 - 2026-06-03 18:14 - Ported the arcade Tic Tac Toe menu artwork
// and changed shared UI buttons to the same neon arcade style.
// Version 4.6 - 2026-06-03 17:42 - Added Arduino Nano ESP32 board-label and
// physical-header comments for each configured GPIO.
// Version 4.5 - 2026-05-28 11:43 - Added explanatory comments across the main
// source blocks to make hardware, UI, networking, and game logic easier to read.
// Version 4.4 - 2026-05-27 17:28 - Added randomized Tanks Wars terrain
// generation for each new local round.
// Version 4.3 - 2026-05-27 17:24 - Removed Tanks Wars full-screen redraws
// from angle and power controls to reduce UI flicker.
// Version 4.2 - 2026-05-27 17:16 - Smoothed Tanks Wars projectile animation
// by redrawing only the projectile area with a fixed frame time.
// Version 4.1 - 2026-05-27 16:59 - Replaced Battleship with a Tanks Wars
// menu and added first local artillery gameplay with destructible terrain.
// Version 4.0 - 2026-05-27 15:32 - Added viewpoint-specific RPSLS network
// result images from /RPSLS_game/win and /RPSLS_game/lose.
// Version 3.9 - 2026-05-27 15:03 - Added network Host/Join gameplay for RPSLS
// using the same WiFi setup flow and hidden-choice result logic as local play.
// Version 3.8 - 2026-05-27 14:48 - Changed game mode menu Home buttons to Back
// buttons that return to the Games selection screen.
// Version 3.7 - 2026-05-20 22:52 - Added SD-loaded RPSLS draw screens based on
// the shared choice selected by both players.
// Version 3.6 - 2026-05-20 22:27 - Added SD-loaded RPSLS winning screens based
// on the exact winning choice combination for Player 1 and Player 2.
// Version 3.5 - 2026-05-20 21:36 - Added Home screen version/build metadata
// and defined the Build ID format based on version plus date/hour.
// Version 3.4 - 2026-05-20 21:29 - Removed timezone offsets from changelog
// timestamps and standardized future changelog entries to omit them.
// Version 3.3 - 2026-05-20 21:27 - Added version numbers to all
// changelog entries, starting at Version 1.0 and incrementing by 0.1 per change.
// Version 3.2 - 2026-05-20 21:16 - Switched the RPSLS choice screen to use the
// SD-loaded /RPSLS_game/general/rpsls_wheel.raw image while keeping invisible
// touch segments for selection.
// Version 3.1 - 2026-05-15 23:01 - Added the missing RGB888 to RGB565 helper used by
// the Rock-Paper-Scissors wheel colors.
// Version 3.0 - 2026-05-15 22:56 - Replaced the Rock-Paper-Scissors placeholder with
// a local Rock-Paper-Scissors-Lizard-Spock flow, menu, scores, and result page.
// Version 2.9 - 2026-05-15 21:52 - Added a Games hub page with Tic Tac Toe,
// Rock-Paper-Scissors, Battleship, and Home navigation.
// Version 2.8 - 2026-05-14 23:38 - Expanded Join WiFi selection to show eight SSIDs
// per page and added MORE pagination for additional scanned networks.
// Version 2.7 - 2026-05-14 23:31 - Added "Connect and Die" and "The LAN of the Free"
// to the selectable Host SSID list.
// Version 2.6 - 2026-05-14 23:27 - Expanded the Host Select SSID page to show eight
// SSID options per page.
// Version 2.5 - 2026-05-14 23:24 - Changed the frame_000.raw intro hold from 4 seconds
// to 1 second.
// Version 2.4 - 2026-05-14 23:13 - Finalized Host Select SSID layout with four visible
// SSIDs per page, compact list text, and larger Host waiting SSID/IP display.
// Version 2.3 - 2026-05-14 23:00 - Added two-step Host setup: select an epic SSID,
// confirm Host IP with keypad, then start AP mode with password Alchemist2026.
// Version 2.2 - 2026-05-14 22:47 - Added two-step Join setup: select scanned WiFi
// network, confirm Host IP with keypad, then connect with password Alchemist2026.
// Version 2.1 - 2026-05-14 22:18 - Added an IP settings page with four editable fields,
// numeric keypad input, persistent storage, and default IP 192.168.10.1.
// Version 2.0 - 2026-05-11 22:06 - Moved the Tic Tac Toe Home button to the game mode
// menu page with Local, Host, Join, and Reset Score.
// Version 1.9 - 2026-05-11 19:41 - Changed the home screen Exit button to reboot the
// ESP32 instead of blanking the display.
// Version 1.8 - 2026-05-11 19:33 - Scaled the home screen RAW buttons to fit the
// button slots defined in background.raw.
// Version 1.7 - 2026-05-11 18:52 - Added an SD-loaded home screen after the intro with
// background and Games, Settings, and Exit RAW buttons.
// Version 1.6 - 2026-05-11 18:40 - Added a 4 second hold on frame_000.raw before the
// rest of the RAW intro animation plays.
// Version 1.5 - 2026-05-11 18:05 - Finalized RAW565 portrait intro playback at normal
// rotation, starting from frame_000.raw.
// Version 1.4 - 2026-05-11 15:35 - Enabled inverted display colors through a dedicated
// display setting.
// Version 1.3 - 2026-05-11 15:27 - Added microSD support for boot intro and SD-loaded
// UI assets while keeping local and WiFi gameplay modes.
// Version 1.2 - 2026-05-11 14:58 - Removed the duplicate sketch compile conflict by
// keeping Game_Consoles.ino as the active Arduino sketch file.
// Version 1.1 - 2026-05-11 14:49 - Rebuilt the sketch with a clean structure while
// keeping local play, WiFi host/join play, persistent score, touch input, and UI.
// Version 1.0 - 2026-05-11 14:18 - Added local play mode with a main menu option,
// allowing X and O to play on the same device without WiFi.

#include <Arduino_GFX_Library.h>
#include <Wire.h>
#include <WiFi.h>
#include <Preferences.h>
#include <SPI.h>
#include <SD.h>
#include <FS.h>
#include <math.h>
#include <esp_system.h>

// ============================================================================
// HARDWARE CONFIG
// ============================================================================
// Board wiring for Arduino Nano ESP32 + ILI9488 display, FT6336 touch,
// microSD card, and buzzer. Keep these values aligned with the physical wiring.
// The sketch uses ESP32 GPIO numbering. Comments also show the Arduino Nano
// ESP32 board label and physical header position.
static const int PIN_LCD_CS   = 21;  // GPIO21, Arduino D10, physical header JP2-3.
static const int PIN_LCD_DC   = 18;  // GPIO18, Arduino D9, physical header JP2-4.
static const int PIN_LCD_RST  = 17;  // GPIO17, Arduino D8, physical header JP2-5.

static const int PIN_LCD_MOSI = 38;  // GPIO38, Arduino D11/MOSI, physical header JP2-2.
static const int PIN_LCD_MISO = 47;  // GPIO47, Arduino D12/MISO, physical header JP2-1.
static const int PIN_LCD_SCLK = 48;  // GPIO48, Arduino D13/SCK, physical header JP1-1.

static const int PIN_SD_CS    = 8;   // GPIO8, Arduino D5, physical header JP2-8.
static const int SD_SPI_FREQ  = 49000000;

static const int PIN_TP_INT   = 6;   // GPIO6, Arduino D3, physical header JP2-10.
static const int PIN_TP_RST   = 7;   // GPIO7, Arduino D4, physical header JP2-9.

static const int PIN_SDA      = 11;  // GPIO11, Arduino A4/SDA, physical header JP1-8.
static const int PIN_SCL      = 12;  // GPIO12, Arduino A5/SCL, physical header JP1-9.

static const int PIN_BUZZER   = 4;   // GPIO4, Arduino A3, physical header JP1-7.

static const uint8_t FT6336_ADDR = 0x38;

// Keep these in sync with the newest CHANGELOG entry.
// Build ID format: GC-V<major><minor>-<YYYYMMDDHH>.
const char *APP_VERSION_TEXT = "Version 5.5";
const char *APP_BUILD_ID_TEXT = "Build ID GC-V55-2026061719";



// ============================================================================
// NETWORK CONFIG
// ============================================================================
// Shared network settings used by all WiFi game modes. The host creates an
// access point, and the join device connects to it using the fixed password.
const char *AP_SSID = "TicTacToe_ESP32";
const char *AP_PASS = "Alchemist2026";
const char *JOIN_WIFI_PASS = "Alchemist2026";

// Human-friendly SSID options shown on the Host setup page.
const char *epicSSIDList[] = {
  "Searching for Network...",
  "404 Wi-Fi Not Found",
  "Martin Router King",
  "Wu-Tang LAN",
  "Tell My Wi-Fi Love Her",
  "Virus.exe",
  "The Promised LAN",
  "Drop It Like It's Hotspot",
  "Wi-Fi: Art or Sacrifice?",
  "Pretty Fly for a Wi-Fi",
  "Surveillance Camera #04",
  "FBI Surveillance Van",
  "Loading...",
  "Connecting...",
  "Winternet is Coming",
  "It Hurts When IP",
  "Obi-Wan Kenobi",
  "Silence of the LANs",
  "Buy Your Own Internet",
  "Password is 1234... or not",
  "Bill Wi the Science Fi",
  "The LAN Before Time",
  "Lord of the Pings",
  "Skynet Global Defense",
  "Paid Network (5$/min)",
  "I Can Haz Wireless?",
  "No Free Wi-Fi Here",
  "Get your own Wi-Fi!",
  "Searching for Signal...",
  "The Golden Wi-Fi",
  "Connect and Die",
  "The LAN of the Free"
};

const int EPIC_SSID_COUNT = sizeof(epicSSIDList) / sizeof(epicSSIDList[0]);

const uint16_t NET_PORT = 3333;
IPAddress HOST_IP(192, 168, 10, 1);

WiFiServer gameServer(NET_PORT);
WiFiClient netClient;

// ============================================================================
// DISPLAY / STORAGE
// ============================================================================
// Global display, persistent flash storage, and SD readiness state.
Preferences prefs;
const bool INVERT_DISPLAY_COLORS = true;

Arduino_DataBus *bus = new Arduino_HWSPI(
  PIN_LCD_DC,
  PIN_LCD_CS,
  PIN_LCD_SCLK,
  PIN_LCD_MOSI,
  PIN_LCD_MISO
);

Arduino_GFX *gfx = new Arduino_ILI9488_18bit(bus, PIN_LCD_RST, 0, false);

bool sdReady = false;

// ============================================================================
// APP STATE
// ============================================================================
// Every screen has one AppState so the touch router can dispatch input to the
// correct handler without guessing from what was last drawn.
enum AppState {
  STATE_HOME,
  STATE_GAMES,
  STATE_ROCK_PAPER_SCISSORS,
  STATE_RPS_CHOICE_P1,
  STATE_RPS_CHOICE_P2,
  STATE_RPS_WAITING_CHOICE,
  STATE_RPS_RESULT,
  STATE_RPS_PLACEHOLDER,
  STATE_POCKET_TANKS,
  STATE_PT_PLAYING,
  STATE_PT_RESULT,
  STATE_PT_PLACEHOLDER,
  STATE_EMPTY_GAME,
  STATE_MENU,
  STATE_SETTINGS,
  STATE_EXIT,
  STATE_HOST_SETUP,
  STATE_HOST_IP,
  STATE_JOIN_SETUP,
  STATE_JOIN_IP,
  STATE_WAITING_HOST,
  STATE_CONNECTING_JOIN,
  STATE_PLAYING,
  STATE_RESULT
};

AppState appState = STATE_HOME;

// The WiFi setup screens are shared by Tic Tac Toe and RPSLS. This value tells
// the connection code which game should start after Host/Join connects.
enum NetworkGameType {
  NETWORK_GAME_TTT,
  NETWORK_GAME_RPS
};

NetworkGameType activeNetworkGame = NETWORK_GAME_TTT;

// Tic Tac Toe round state.
char board[3][3];
char currentPlayer = 'X';
bool gameOver = false;
char winner = ' ';

bool localGame = false;
bool isHost = false;
bool networkConnected = false;
char myPlayer = ' ';
bool myTurn = false;

// Host SSID selector state.
static const int MAX_HOST_SSID_VISIBLE = 8;
int selectedHostSSIDIndex = 0;
int hostSSIDListOffset = 0;

// Join scan list state. The scan is copied into this array so the UI can page
// through it without holding WiFi scan resources open.
static const int MAX_JOIN_NETWORKS = 24;
static const int MAX_JOIN_NETWORKS_VISIBLE = 8;
String joinNetworks[MAX_JOIN_NETWORKS];
int joinNetworkCount = 0;
int selectedJoinNetwork = -1;
int joinNetworkListOffset = 0;

// Editable IP fields shared by Settings, Host IP, and Join IP screens.
uint8_t ipParts[4] = {192, 168, 10, 1};
char ipFieldText[4][4] = {"192", "168", "10", "1"};
int activeIpField = 0;
bool activeIpFieldNeedsClear = true;

int scoreX = 0;
int scoreO = 0;
int scoreDraw = 0;

// RPSLS uses numeric choices internally:
// 0 Rock, 1 Paper, 2 Scissors, 3 Lizard, 4 Spock.
const char *rpsChoiceLabels[] = {
  "ROCK",
  "PAPER",
  "SCISSORS",
  "LIZARD",
  "SPOCK"
};

int rpsP1Choice = -1;
int rpsP2Choice = -1;
int rpsWinner = 0;
int rpsScoreP1 = 0;
int rpsScoreP2 = 0;
int rpsScoreDraw = 0;
const char *rpsPlaceholderTitle = "RPS";

// Tanks Wars keeps one terrain height per screen column. Tanks sit on this
// height map, and explosions modify it directly.
static const int PT_TERRAIN_W = 320;
int ptTerrain[PT_TERRAIN_W];
int ptTankX[2] = {42, 278};
int ptCurrentPlayer = 0;
int ptAngle[2] = {45, 45};
int ptPower[2] = {62, 62};
int ptScoreP1 = 0;
int ptScoreP2 = 0;
int ptWinner = 0;
const char *ptPlaceholderTitle = "Tanks Wars";

// Touch edge detection and debounce. Touch actions fire once per press, not on
// every loop while the finger is still down.
bool touchWasDown = false;
unsigned long lastTouchTime = 0;
const unsigned long touchDebounceMs = 80;

// ============================================================================
// LAYOUT
// ============================================================================
// All UI geometry lives here so button hitboxes match the drawings and can be
// adjusted without hunting through the touch handlers.
const int screenW = 320;
const int screenH = 480;

const int topBarH = 90;

const int boardX = 20;
const int boardY = 110;
const int boardSize = 280;
const int cellSize = boardSize / 3;

const int btnLocalX = 30;
const int btnLocalY = 150;
const int btnLocalW = 260;
const int btnLocalH = 54;

const int btnHostX = 30;
const int btnHostY = 210;
const int btnHostW = 260;
const int btnHostH = 54;

const int btnJoinX = 30;
const int btnJoinY = 270;
const int btnJoinW = 260;
const int btnJoinH = 54;

const int btnResetScoreX = 30;
const int btnResetScoreY = 330;
const int btnResetScoreW = 260;
const int btnResetScoreH = 54;

const int btnMenuX = 90;
const int btnMenuY = 420;
const int btnMenuW = 140;
const int btnMenuH = 40;

const int btnPlayAgainX = 50;
const int btnPlayAgainY = 330;
const int btnPlayAgainW = 220;
const int btnPlayAgainH = 45;

const int btnResultMenuX = 50;
const int btnResultMenuY = 390;
const int btnResultMenuW = 220;
const int btnResultMenuH = 45;

const int btnTttHomeX = 30;
const int btnTttHomeY = 390;
const int btnTttHomeW = 260;
const int btnTttHomeH = 54;

const int btnGamesX = 35;
const int btnGamesTttY = 135;
const int btnGamesRpsY = 205;
const int btnGamesPocketTanksY = 275;
const int btnGamesHomeY = 390;
const int btnGamesW = 250;
const int btnGamesH = 52;
const int btnGamesHomeH = 45;

const int btnEmptyBackX = 90;
const int btnEmptyBackY = 420;
const int btnEmptyBackW = 140;
const int btnEmptyBackH = 40;

const int rpsWheelCenterX = 160;
const int rpsWheelCenterY = 250;
const int rpsWheelRadius = 145;
const char *rpsWheelImagePath = "/RPSLS_game/general/rpsls_wheel.raw";
const char *rpsPlayer1WinsPath = "/RPSLS_game/local/player1_wins";
const char *rpsPlayer2WinsPath = "/RPSLS_game/local/player2_wins";
const char *rpsDrawPath = "/RPSLS_game/local/draw";
const char *rpsNetworkWinPath = "/RPSLS_game/win";
const char *rpsNetworkLosePath = "/RPSLS_game/lose";
const int btnRpsMenuX = 90;
const int btnRpsMenuY = 420;
const int btnRpsMenuW = 140;
const int btnRpsMenuH = 40;

const int ptFieldTop = 0;
const int ptFieldBottom = 355;
const int ptTankW = 22;
const int ptTankH = 12;
const int ptExplosionRadius = 24;
const int ptProjectileRadius = 3;
const unsigned long ptProjectileFrameMs = 24;

const int btnPtAngleDownX = 8;
const int btnPtAngleDownY = 370;
const int btnPtAngleUpX = 86;
const int btnPtAngleUpY = 370;
const int btnPtPowerDownX = 164;
const int btnPtPowerDownY = 370;
const int btnPtPowerUpX = 242;
const int btnPtPowerUpY = 370;
const int btnPtControlW = 70;
const int btnPtControlH = 36;

const int btnPtFireX = 20;
const int btnPtFireY = 424;
const int btnPtFireW = 130;
const int btnPtFireH = 40;

const int btnPtMenuX = 170;
const int btnPtMenuY = 424;
const int btnPtMenuW = 130;
const int btnPtMenuH = 40;

const int homeButtonRawW = 320;
const int homeButtonRawH = 90;

const int homeButtonSlotX = 54;
const int homeButtonSlotW = 213;
const int homeButtonSlotH = 47;

const int homeGamesRawX = homeButtonSlotX;
const int homeGamesRawY = 291;
const int homeSettingsRawX = homeButtonSlotX;
const int homeSettingsRawY = 340;
const int homeExitRawX = homeButtonSlotX;
const int homeExitRawY = 388;

const int homeTouchX = 35;
const int homeTouchW = 250;
const int homeTouchH = 55;
const int homeGamesTouchY = 287;
const int homeSettingsTouchY = 336;
const int homeExitTouchY = 384;

const int settingsFieldX = 18;
const int settingsFieldY = 92;
const int settingsFieldW = 62;
const int settingsFieldH = 44;
const int settingsFieldGap = 14;

const int keyPadX = 35;
const int keyPadY = 165;
const int keyPadW = 70;
const int keyPadH = 42;
const int keyPadGapX = 15;
const int keyPadGapY = 11;

const int btnSettingsHomeX = 20;
const int btnSettingsHomeY = 420;
const int btnSettingsHomeW = 130;
const int btnSettingsHomeH = 40;

const int btnSettingsSaveX = 170;
const int btnSettingsSaveY = 420;
const int btnSettingsSaveW = 130;
const int btnSettingsSaveH = 40;

const int joinNetworkX = 20;
const int joinNetworkY = 112;
const int joinNetworkW = 280;
const int joinNetworkH = 32;
const int joinNetworkGap = 5;

const int joinKeyPadX = 35;
const int joinKeyPadY = 282;
const int joinKeyPadW = 70;
const int joinKeyPadH = 30;
const int joinKeyPadGapX = 15;
const int joinKeyPadGapY = 6;

const int btnJoinBackX = 4;
const int btnJoinBackY = 430;
const int btnJoinBackW = 74;
const int btnJoinBackH = 38;

const int btnJoinScanX = 83;
const int btnJoinScanY = 430;
const int btnJoinScanW = 74;
const int btnJoinScanH = 38;

const int btnJoinMoreX = 162;
const int btnJoinMoreY = 430;
const int btnJoinMoreW = 74;
const int btnJoinMoreH = 38;

const int btnJoinConnectX = 241;
const int btnJoinConnectY = 430;
const int btnJoinConnectW = 74;
const int btnJoinConnectH = 38;

const int btnJoinIpBackX = 20;
const int btnJoinIpBackY = 420;
const int btnJoinIpBackW = 130;
const int btnJoinIpBackH = 40;

const int btnJoinIpConnectX = 170;
const int btnJoinIpConnectY = 420;
const int btnJoinIpConnectW = 130;
const int btnJoinIpConnectH = 40;

const int hostSSIDX = 20;
const int hostSSIDY = 112;
const int hostSSIDW = 280;
const int hostSSIDH = 32;
const int hostSSIDGap = 5;

const int btnHostBackX = 12;
const int btnHostBackY = 430;
const int btnHostBackW = 90;
const int btnHostBackH = 38;

const int btnHostMoreX = 115;
const int btnHostMoreY = 430;
const int btnHostMoreW = 90;
const int btnHostMoreH = 38;

const int btnHostNextX = 218;
const int btnHostNextY = 430;
const int btnHostNextW = 90;
const int btnHostNextH = 38;

const int btnHostIpBackX = 20;
const int btnHostIpBackY = 420;
const int btnHostIpBackW = 130;
const int btnHostIpBackH = 40;

const int btnHostIpStartX = 170;
const int btnHostIpStartY = 420;
const int btnHostIpStartW = 130;
const int btnHostIpStartH = 40;

// ============================================================================
// RAW565 VIDEO PLAYER - /intro/frame_000.raw ... /intro/frame_074.raw
// ============================================================================
// RAW565 assets are stored as RGB565 pixels without headers. Drawing in small
// line blocks keeps RAM usage low while still streaming directly from SD.
static const int VIDEO_W = 320;
static const int VIDEO_H = 480;
static const int RAW_BLOCK_LINES = 32;
static const int RAW_FRAME_SIZE = VIDEO_W * VIDEO_H * 2;
static const int INTRO_FIRST_FRAME = 0;
static const int INTRO_TOTAL_FRAMES = 75;
static const int INTRO_TARGET_FPS = 65;
static const int INTRO_ROTATION = 0;
static const unsigned long INTRO_FIRST_FRAME_HOLD_MS = 1000;
static const char *GAMES_BACKGROUND_PATH = "/games_screen/games_background.raw";
static const char *TTT_BACKGROUND_PATH = "/tictactoe_game/tictactoe_background.raw";
static const char *RPS_BACKGROUND_PATH = "/RPSLS_game/main_screen/rock_paper_scissors_background.raw";

static uint16_t rawDrawBuffer[VIDEO_W * RAW_BLOCK_LINES];
static uint16_t rawScaleSourceBuffer[homeButtonRawW * homeButtonRawH];
static uint16_t rawScaleLineBuffer[screenW];

// Draws one unscaled RAW565 image. Used for full-screen backgrounds, intro
// frames, and result screens.
bool drawRaw565ImageFromSD(const char *filename, int16_t x, int16_t y, int imageW, int imageH) {
  File rawFile = SD.open(filename, FILE_READ);

  if (!rawFile) {
    Serial.print("Cannot open RAW: ");
    Serial.println(filename);
    return false;
  }

  uint32_t expectedSize = (uint32_t)imageW * imageH * 2;

  if (rawFile.size() != expectedSize) {
    Serial.print("Invalid RAW size: ");
    Serial.print(filename);
    Serial.print(" size=");
    Serial.println(rawFile.size());
    rawFile.close();
    return false;
  }

  if (imageW > VIDEO_W) {
    Serial.print("RAW image is too wide: ");
    Serial.println(filename);
    rawFile.close();
    return false;
  }

  for (int blockY = 0; blockY < imageH; blockY += RAW_BLOCK_LINES) {
    int linesThisBlock = RAW_BLOCK_LINES;

    if (blockY + linesThisBlock > imageH) {
      linesThisBlock = imageH - blockY;
    }

    int bytesToRead = imageW * linesThisBlock * 2;

    digitalWrite(PIN_LCD_CS, HIGH);

    int bytesRead = rawFile.read((uint8_t *)rawDrawBuffer, bytesToRead);

    if (bytesRead != bytesToRead) {
      rawFile.close();
      return false;
    }

    digitalWrite(PIN_SD_CS, HIGH);
    gfx->draw16bitRGBBitmap(x, y + blockY, rawDrawBuffer, imageW, linesThisBlock);
  }

  rawFile.close();
  return true;
}

bool drawRaw565FromSD(const char *filename, int16_t x, int16_t y) {
  return drawRaw565ImageFromSD(filename, x, y, VIDEO_W, VIDEO_H);
}

// Used by the home screen buttons. The source button RAWs are larger than the
// slots in background.raw, so they are nearest-neighbor scaled line by line.
bool drawScaledRaw565ImageFromSD(const char *filename, int16_t x, int16_t y,
                                 int sourceW, int sourceH,
                                 int destW, int destH) {
  if (destW > screenW) return false;
  if (sourceW != homeButtonRawW || sourceH != homeButtonRawH) return false;

  File rawFile = SD.open(filename, FILE_READ);

  if (!rawFile) {
    Serial.print("Cannot open RAW: ");
    Serial.println(filename);
    return false;
  }

  uint32_t expectedSize = (uint32_t)sourceW * sourceH * 2;

  if (rawFile.size() != expectedSize) {
    Serial.print("Invalid RAW size: ");
    Serial.print(filename);
    Serial.print(" size=");
    Serial.println(rawFile.size());
    rawFile.close();
    return false;
  }

  int bytesRead = rawFile.read((uint8_t *)rawScaleSourceBuffer, expectedSize);
  rawFile.close();

  if (bytesRead != (int)expectedSize) {
    Serial.print("RAW read failed: ");
    Serial.println(filename);
    return false;
  }

  for (int dy = 0; dy < destH; dy++) {
    int sy = ((long)dy * sourceH) / destH;

    for (int dx = 0; dx < destW; dx++) {
      int sx = ((long)dx * sourceW) / destW;
      rawScaleLineBuffer[dx] = rawScaleSourceBuffer[sy * sourceW + sx];
    }

    digitalWrite(PIN_SD_CS, HIGH);
    gfx->draw16bitRGBBitmap(x, y + dy, rawScaleLineBuffer, destW, 1);
  }

  return true;
}

void playVideoRaw(const char *folder, int totalFrames, int targetFps) {
  if (!sdReady) return;

  char path[64];
  unsigned long frameTime = 1000UL / targetFps;
  int lastFrame = INTRO_FIRST_FRAME + totalFrames - 1;

  for (int i = INTRO_FIRST_FRAME; i <= lastFrame; i++) {
    unsigned long frameStart = millis();

    snprintf(path, sizeof(path), "%s/frame_%03d.raw", folder, i);
    drawRaw565FromSD(path, 0, 0);

    if (i == INTRO_FIRST_FRAME) {
      delay(INTRO_FIRST_FRAME_HOLD_MS);
    }

    unsigned long used = millis() - frameStart;

    if (used < frameTime) {
      delay(frameTime - used);
    }
  }
}

void playBootIntro() {
  // Intro files are already generated in portrait orientation.
  gfx->setRotation(INTRO_ROTATION);
  gfx->fillScreen(RGB565_BLACK);

  delay(50);
  playVideoRaw("/intro", INTRO_TOTAL_FRAMES, INTRO_TARGET_FPS);

  gfx->setRotation(0);
  gfx->fillScreen(RGB565_BLACK);
}

// ============================================================================
// SCORE STORAGE
// ============================================================================
// Each game has its own Preferences namespace so score resets do not affect
// other games.
void loadScore() {
  prefs.begin("ttt_score", true);
  scoreX = prefs.getInt("x", 0);
  scoreO = prefs.getInt("o", 0);
  scoreDraw = prefs.getInt("d", 0);
  prefs.end();
}

void saveScore() {
  prefs.begin("ttt_score", false);
  prefs.putInt("x", scoreX);
  prefs.putInt("o", scoreO);
  prefs.putInt("d", scoreDraw);
  prefs.end();
}

void resetScore() {
  scoreX = 0;
  scoreO = 0;
  scoreDraw = 0;
  saveScore();
}

void loadRpsScore() {
  prefs.begin("rps_score", true);
  rpsScoreP1 = prefs.getInt("p1", 0);
  rpsScoreP2 = prefs.getInt("p2", 0);
  rpsScoreDraw = prefs.getInt("d", 0);
  prefs.end();
}

void saveRpsScore() {
  prefs.begin("rps_score", false);
  prefs.putInt("p1", rpsScoreP1);
  prefs.putInt("p2", rpsScoreP2);
  prefs.putInt("d", rpsScoreDraw);
  prefs.end();
}

void resetRpsScore() {
  rpsScoreP1 = 0;
  rpsScoreP2 = 0;
  rpsScoreDraw = 0;
  saveRpsScore();
}

void loadPocketTanksScore() {
  prefs.begin("pt_score", true);
  ptScoreP1 = prefs.getInt("p1", 0);
  ptScoreP2 = prefs.getInt("p2", 0);
  prefs.end();
}

void savePocketTanksScore() {
  prefs.begin("pt_score", false);
  prefs.putInt("p1", ptScoreP1);
  prefs.putInt("p2", ptScoreP2);
  prefs.end();
}

void resetPocketTanksScore() {
  ptScoreP1 = 0;
  ptScoreP2 = 0;
  savePocketTanksScore();
}

// ============================================================================
// NETWORK SETTINGS
// ============================================================================
// The four editable text fields are the source of truth while the keypad is
// open. Saving clamps them to 0..255 and updates HOST_IP.
void updateHostIpFromParts() {
  HOST_IP = IPAddress(ipParts[0], ipParts[1], ipParts[2], ipParts[3]);
}

void updateIpTextFromParts() {
  for (int i = 0; i < 4; i++) {
    snprintf(ipFieldText[i], sizeof(ipFieldText[i]), "%u", ipParts[i]);
  }
}

uint8_t parseIpFieldValue(int field) {
  if (field < 0 || field > 3) return 0;

  int value = atoi(ipFieldText[field]);

  if (value < 0) value = 0;
  if (value > 255) value = 255;

  return (uint8_t)value;
}

void applyIpTextToParts() {
  for (int i = 0; i < 4; i++) {
    ipParts[i] = parseIpFieldValue(i);
  }

  updateIpTextFromParts();
  updateHostIpFromParts();
}

void loadNetworkSettings() {
  prefs.begin("ttt_cfg", true);
  ipParts[0] = prefs.getUChar("ip0", 192);
  ipParts[1] = prefs.getUChar("ip1", 168);
  ipParts[2] = prefs.getUChar("ip2", 10);
  ipParts[3] = prefs.getUChar("ip3", 1);
  prefs.end();

  updateIpTextFromParts();
  updateHostIpFromParts();
}

void saveNetworkSettings() {
  applyIpTextToParts();

  prefs.begin("ttt_cfg", false);
  prefs.putUChar("ip0", ipParts[0]);
  prefs.putUChar("ip1", ipParts[1]);
  prefs.putUChar("ip2", ipParts[2]);
  prefs.putUChar("ip3", ipParts[3]);
  prefs.end();
}

// ============================================================================
// AUDIO
// ============================================================================
// Short audio cues. They are intentionally non-blocking tone() calls.
void beepMove()  { tone(PIN_BUZZER, 1000, 40); }
void beepStart() { tone(PIN_BUZZER, 1400, 70); }
void beepWin()   { tone(PIN_BUZZER, 2200, 180); }
void beepDraw()  { tone(PIN_BUZZER, 1200, 150); }
void beepClick() { tone(PIN_BUZZER, 1600, 60); }

// ============================================================================
// TOUCH
// ============================================================================
// FT6336 touch controller helpers. The raw controller coordinates are mapped
// into the current portrait screen coordinate system.
uint8_t tpReadReg(uint8_t reg) {
  Wire.beginTransmission(FT6336_ADDR);
  Wire.write(reg);
  if (Wire.endTransmission(false) != 0) return 0;

  Wire.requestFrom((int)FT6336_ADDR, 1);
  if (Wire.available()) return Wire.read();

  return 0;
}

bool readTouchScreen(int &sx, int &sy) {
  uint8_t points = tpReadReg(0x02) & 0x0F;
  if (points == 0) return false;

  uint8_t xh = tpReadReg(0x03);
  uint8_t xl = tpReadReg(0x04);
  uint8_t yh = tpReadReg(0x05);
  uint8_t yl = tpReadReg(0x06);

  uint16_t rx = ((xh & 0x0F) << 8) | xl;
  uint16_t ry = ((yh & 0x0F) << 8) | yl;

  sx = map(rx, 0, 320, 0, screenW);
  sy = map(ry, 0, 480, 0, screenH);

  if (sx < 0) sx = 0;
  if (sx >= screenW) sx = screenW - 1;
  if (sy < 0) sy = 0;
  if (sy >= screenH) sy = screenH - 1;

  return true;
}

// ============================================================================
// DRAW HELPERS
// ============================================================================
// Shared primitive drawing helpers used by every screen.
uint16_t rgb888to565(uint8_t r, uint8_t g, uint8_t b) {
  return ((r & 0xF8) << 8) |
         ((g & 0xFC) << 3) |
         (b >> 3);
}

bool inRect(int x, int y, int rx, int ry, int rw, int rh) {
  return (x >= rx && x < rx + rw && y >= ry && y < ry + rh);
}

bool inBoard(int x, int y) {
  return inRect(x, y, boardX, boardY, boardSize, boardSize);
}

void drawCenteredText(const char *txt, int y, int size, uint16_t color) {
  int16_t x1, y1;
  uint16_t w, h;

  gfx->setTextSize(size);
  gfx->getTextBounds((char *)txt, 0, y, &x1, &y1, &w, &h);

  int x = (screenW - w) / 2;

  gfx->setCursor(x, y);
  gfx->setTextColor(color);
  gfx->print(txt);
}

void drawCenteredTextWithShadow(const char *txt, int y, int size, uint16_t color, uint16_t shadowColor) {
  int16_t x1, y1;
  uint16_t w, h;

  gfx->setTextSize(size);
  gfx->getTextBounds((char *)txt, 0, y, &x1, &y1, &w, &h);

  int x = (screenW - w) / 2;

  gfx->setCursor(x + 1, y + 1);
  gfx->setTextColor(shadowColor);
  gfx->print(txt);

  gfx->setCursor(x, y);
  gfx->setTextColor(color);
  gfx->print(txt);
}

void drawPixelText(const char *txt, int x, int y, int size, uint16_t mainColor, uint16_t shadowColor) {
  gfx->setTextSize(size);

  gfx->setCursor(x + 3, y + 3);
  gfx->setTextColor(shadowColor);
  gfx->print(txt);

  gfx->setCursor(x, y);
  gfx->setTextColor(mainColor);
  gfx->print(txt);
}

void drawNeonRect(int x, int y, int w, int h, uint16_t coreColor) {
  uint16_t arcadeBlue = rgb888to565(0, 65, 210);
  uint16_t arcadeOrange = rgb888to565(255, 128, 0);

  gfx->drawRoundRect(x - 3, y - 3, w + 6, h + 6, 8, RGB565_CYAN);
  gfx->drawRoundRect(x - 2, y - 2, w + 4, h + 4, 7, arcadeBlue);
  gfx->drawRoundRect(x - 1, y - 1, w + 2, h + 2, 6, RGB565_WHITE);
  gfx->drawRoundRect(x, y, w, h, 6, coreColor);

  if (w > 8 && h > 8) {
    gfx->drawRoundRect(x + 2, y + 2, w - 4, h - 4, 5, arcadeOrange);
  }
}

void fillArcadeGradient() {
  for (int y = 0; y < screenH; y++) {
    uint8_t b = map(y, 0, screenH, 28, 4);
    uint8_t r = map(y, 0, screenH, 8, 0);
    uint8_t g = map(y, 0, screenH, 5, 0);

    gfx->drawLine(0, y, screenW - 1, y, rgb888to565(r, g, b));
  }
}

void drawArcadeStars() {
  for (int i = 0; i < 100; i++) {
    int x = (i * 47 + 23) % screenW;
    int y = (i * 71 + 11) % 145;
    uint16_t color;

    switch (i % 5) {
      case 0: color = RGB565_YELLOW; break;
      case 1: color = RGB565_CYAN; break;
      case 2: color = RGB565_RED; break;
      case 3: color = rgb888to565(255, 0, 180); break;
      default: color = RGB565_WHITE; break;
    }

    gfx->drawPixel(x, y, color);

    if (i % 7 == 0) {
      gfx->drawLine(x - 2, y, x + 2, y, color);
      gfx->drawLine(x, y - 2, x, y + 2, color);
    }
  }
}

void drawArcadeCabinets() {
  uint16_t cabinetFill = rgb888to565(18, 8, 42);
  uint16_t arcadeBlue = rgb888to565(0, 65, 210);
  uint16_t arcadeMagenta = rgb888to565(255, 0, 180);
  uint16_t arcadeGreen = rgb888to565(0, 255, 90);

  gfx->fillRect(0, 220, 35, 180, cabinetFill);
  gfx->drawRect(0, 220, 35, 180, arcadeMagenta);
  gfx->drawLine(35, 220, 55, 260, arcadeBlue);
  gfx->drawLine(35, 400, 55, 440, arcadeBlue);
  gfx->drawRect(6, 250, 22, 28, RGB565_CYAN);
  gfx->setTextSize(1);
  gfx->setTextColor(arcadeGreen);
  gfx->setCursor(5, 285);
  gfx->print("INSERT");
  gfx->setCursor(8, 295);
  gfx->print("COIN");

  gfx->fillRect(285, 220, 35, 180, cabinetFill);
  gfx->drawRect(285, 220, 35, 180, arcadeMagenta);
  gfx->drawLine(285, 220, 265, 260, arcadeBlue);
  gfx->drawLine(285, 400, 265, 440, arcadeBlue);
  gfx->drawRect(292, 250, 22, 28, RGB565_CYAN);
  gfx->setTextColor(arcadeGreen);
  gfx->setCursor(291, 285);
  gfx->print("1UP");
  gfx->setCursor(289, 295);
  gfx->print("HIGH");
  gfx->setCursor(289, 305);
  gfx->print("SCORE");
}

void drawArcadeFloor() {
  int horizon = 365;
  uint16_t floorLine = rgb888to565(45, 15, 90);
  uint16_t rayLine = rgb888to565(30, 20, 85);

  for (int y = horizon; y < screenH; y += 16) {
    gfx->drawLine(0, y, screenW - 1, y, floorLine);
  }

  for (int x = -120; x < screenW + 120; x += 28) {
    gfx->drawLine(screenW / 2, horizon, x, screenH - 1, rayLine);
  }

  gfx->drawLine(0, horizon, screenW - 1, horizon, rgb888to565(0, 65, 210));
}

void drawJoystickDecor() {
  uint16_t arcadeOrange = rgb888to565(255, 128, 0);
  uint16_t arcadeGray = rgb888to565(150, 150, 170);
  uint16_t darkBase = rgb888to565(20, 20, 40);

  gfx->fillCircle(32, 430, 12, RGB565_RED);
  gfx->drawCircle(32, 430, 13, arcadeOrange);
  gfx->drawLine(32, 442, 28, 465, arcadeGray);
  gfx->drawLine(32, 442, 36, 465, arcadeGray);
  gfx->fillRoundRect(10, 458, 44, 16, 8, darkBase);
  gfx->drawRoundRect(10, 458, 44, 16, 8, RGB565_CYAN);

  gfx->fillCircle(250, 438, 12, rgb888to565(0, 65, 210));
  gfx->drawCircle(250, 438, 13, RGB565_CYAN);
  gfx->fillCircle(285, 438, 12, arcadeOrange);
  gfx->drawCircle(285, 438, 13, RGB565_YELLOW);

  gfx->setTextSize(3);
  gfx->setTextColor(RGB565_RED);
  gfx->setCursor(72, 430);
  gfx->print("X");

  gfx->setTextColor(RGB565_CYAN);
  gfx->setCursor(185, 430);
  gfx->print("O");
}

void drawArcadeTitle() {
  uint16_t signFill = rgb888to565(12, 12, 35);
  uint16_t arcadeOrange = rgb888to565(255, 128, 0);
  uint16_t arcadeBlue = rgb888to565(0, 65, 210);

  gfx->fillRoundRect(13, 20, 294, 74, 10, signFill);
  gfx->drawRoundRect(13, 20, 294, 74, 10, arcadeOrange);
  gfx->drawRoundRect(17, 24, 286, 66, 8, RGB565_CYAN);
  gfx->drawRoundRect(20, 27, 280, 60, 7, RGB565_YELLOW);

  for (int x = 30; x < 292; x += 17) {
    gfx->fillCircle(x, 31, 3, arcadeOrange);
    gfx->drawCircle(x, 31, 4, RGB565_YELLOW);
    gfx->fillCircle(x, 82, 3, arcadeOrange);
    gfx->drawCircle(x, 82, 4, RGB565_YELLOW);
  }

  drawPixelText("TIC", 31, 42, 4, RGB565_RED, RGB565_YELLOW);
  drawPixelText("TAC", 114, 42, 4, RGB565_YELLOW, RGB565_RED);
  drawPixelText("TOE", 207, 42, 4, RGB565_CYAN, arcadeBlue);

  gfx->setTextSize(3);
  gfx->setTextColor(RGB565_YELLOW);
  gfx->setCursor(145, 0);
  gfx->print("*");

  gfx->setTextSize(4);
  gfx->setTextColor(RGB565_RED);
  gfx->setCursor(85, 105);
  gfx->print("X");

  gfx->setTextColor(RGB565_CYAN);
  gfx->setCursor(210, 105);
  gfx->print("O");

  int miniX = 132;
  int miniY = 103;
  int miniCell = 17;
  const char *miniMarks = "XOXXOXOXO";

  gfx->drawRect(miniX, miniY, miniCell * 3, miniCell * 3, RGB565_CYAN);
  gfx->drawLine(miniX + miniCell, miniY, miniX + miniCell, miniY + miniCell * 3, RGB565_CYAN);
  gfx->drawLine(miniX + miniCell * 2, miniY, miniX + miniCell * 2, miniY + miniCell * 3, RGB565_CYAN);
  gfx->drawLine(miniX, miniY + miniCell, miniX + miniCell * 3, miniY + miniCell, RGB565_CYAN);
  gfx->drawLine(miniX, miniY + miniCell * 2, miniX + miniCell * 3, miniY + miniCell * 2, RGB565_CYAN);

  gfx->setTextSize(2);

  for (int i = 0; i < 9; i++) {
    int cellX = miniX + (i % 3) * miniCell + 3;
    int cellY = miniY + (i / 3) * miniCell + 2;

    gfx->setCursor(cellX, cellY);
    gfx->setTextColor(miniMarks[i] == 'X' ? RGB565_RED : RGB565_CYAN);
    gfx->print(miniMarks[i]);
  }
}

void drawGamesArcadeTitle() {
  uint16_t signFill = rgb888to565(12, 12, 35);
  uint16_t arcadeOrange = rgb888to565(255, 128, 0);
  uint16_t arcadeBlue = rgb888to565(0, 65, 210);
  uint16_t arcadeMagenta = rgb888to565(255, 0, 180);

  gfx->fillRoundRect(18, 18, 284, 82, 10, signFill);
  gfx->drawRoundRect(18, 18, 284, 82, 10, arcadeMagenta);
  gfx->drawRoundRect(22, 22, 276, 74, 8, RGB565_CYAN);
  gfx->drawRoundRect(26, 26, 268, 66, 7, arcadeOrange);

  for (int x = 36; x < 286; x += 18) {
    gfx->fillCircle(x, 29, 3, arcadeOrange);
    gfx->drawCircle(x, 29, 4, RGB565_YELLOW);
    gfx->fillCircle(x, 89, 3, arcadeBlue);
    gfx->drawCircle(x, 89, 4, RGB565_CYAN);
  }

  drawPixelText("GAMES", 100, 43, 4, RGB565_YELLOW, RGB565_RED);
  drawPixelText("SELECT GAME", 70, 108, 2, RGB565_CYAN, arcadeBlue);

  gfx->fillCircle(46, 114, 7, RGB565_RED);
  gfx->drawCircle(46, 114, 8, RGB565_YELLOW);
  gfx->fillCircle(274, 114, 7, arcadeBlue);
  gfx->drawCircle(274, 114, 8, RGB565_CYAN);
}

void drawHomeArcadeTitle() {
  uint16_t signFill = rgb888to565(12, 12, 35);
  uint16_t arcadeOrange = rgb888to565(255, 128, 0);
  uint16_t arcadeBlue = rgb888to565(0, 65, 210);
  uint16_t arcadeMagenta = rgb888to565(255, 0, 180);

  gfx->fillRoundRect(18, 18, 284, 82, 10, signFill);
  gfx->drawRoundRect(18, 18, 284, 82, 10, arcadeMagenta);
  gfx->drawRoundRect(22, 22, 276, 74, 8, RGB565_CYAN);
  gfx->drawRoundRect(26, 26, 268, 66, 7, arcadeOrange);

  for (int x = 36; x < 286; x += 18) {
    gfx->fillCircle(x, 29, 3, arcadeOrange);
    gfx->drawCircle(x, 29, 4, RGB565_YELLOW);
    gfx->fillCircle(x, 89, 3, arcadeBlue);
    gfx->drawCircle(x, 89, 4, RGB565_CYAN);
  }

  drawPixelText("HOME", 112, 43, 4, RGB565_YELLOW, RGB565_RED);
  drawPixelText("MAIN MENU", 106, 108, 2, RGB565_CYAN, arcadeBlue);

  gfx->fillCircle(46, 114, 7, RGB565_RED);
  gfx->drawCircle(46, 114, 8, RGB565_YELLOW);
  gfx->fillCircle(274, 114, 7, arcadeBlue);
  gfx->drawCircle(274, 114, 8, RGB565_CYAN);
}

void drawTicTacToeArcadeHome() {
  if (sdReady && SD.exists(TTT_BACKGROUND_PATH)) {
    if (drawRaw565ImageFromSD(TTT_BACKGROUND_PATH, 0, 0, screenW, screenH)) {
      return;
    }
  }

  fillArcadeGradient();
  drawArcadeStars();
  drawArcadeCabinets();
  drawArcadeFloor();
  drawJoystickDecor();
  drawArcadeTitle();
}

void drawGamesArcadeBackground() {
  if (sdReady && SD.exists(GAMES_BACKGROUND_PATH)) {
    if (drawRaw565ImageFromSD(GAMES_BACKGROUND_PATH, 0, 0, screenW, screenH)) {
      return;
    }
  }

  fillArcadeGradient();
  drawArcadeStars();
  drawArcadeCabinets();
  drawArcadeFloor();
  drawGamesArcadeTitle();
}

void drawHomeArcadeBackground() {
  fillArcadeGradient();
  drawArcadeStars();
  drawArcadeCabinets();
  drawArcadeFloor();
  drawHomeArcadeTitle();
}

void drawRpsHomeGradientBackground() {
  for (int y = 0; y < screenH; y++) {
    uint8_t r = map(y, 0, screenH, 5, 0);
    uint8_t g = map(y, 0, screenH, 6, 0);
    uint8_t b = map(y, 0, screenH, 45, 8);

    gfx->drawLine(0, y, screenW - 1, y, rgb888to565(r, g, b));
  }
}

void drawRpsHomeStars() {
  for (int i = 0; i < 130; i++) {
    int x = (i * 41 + 19) % screenW;
    int y = (i * 67 + 11) % screenH;
    uint16_t color;

    switch (i % 6) {
      case 0: color = RGB565_CYAN; break;
      case 1: color = rgb888to565(255, 0, 180); break;
      case 2: color = RGB565_YELLOW; break;
      case 3: color = RGB565_RED; break;
      case 4: color = RGB565_GREEN; break;
      default: color = RGB565_BLUE; break;
    }

    gfx->drawPixel(x, y, color);

    if (i % 13 == 0) {
      gfx->drawLine(x - 3, y, x + 3, y, color);
      gfx->drawLine(x, y - 3, x, y + 3, color);
    }

    if (i % 29 == 0) {
      gfx->fillRect(x, y, 3, 3, color);
    }
  }
}

void drawRpsBackWall() {
  for (int y = 120; y < 260; y += 14) {
    gfx->drawLine(42, y, 277, y, rgb888to565(10, 10, 42));
  }

  for (int y = 128; y < 260; y += 28) {
    for (int x = 50; x < 275; x += 34) {
      gfx->drawLine(x, y, x, y + 14, rgb888to565(8, 8, 35));
    }
  }

  gfx->drawLine(35, 263, 285, 263, rgb888to565(15, 25, 80));
  gfx->drawLine(35, 265, 285, 265, RGB565_BLUE);
}

void drawRpsHomeFloor() {
  int horizon = 270;
  int centerX = screenW / 2;

  for (int y = horizon; y < screenH; y++) {
    uint8_t b = map(y, horizon, screenH, 30, 5);
    gfx->drawLine(0, y, screenW - 1, y, rgb888to565(0, 3, b));
  }

  for (int y = horizon; y < screenH; y += 17) {
    gfx->drawLine(0, y, screenW - 1, y, rgb888to565(20, 20, 90));
  }

  for (int x = -130; x < screenW + 130; x += 27) {
    gfx->drawLine(centerX, horizon, x, screenH - 1, rgb888to565(20, 15, 85));
  }

  for (int i = 0; i < 28; i++) {
    int x = (i * 37 + 7) % screenW;
    int y = 285 + (i * 31) % 170;
    uint16_t color = (i % 3 == 0) ? rgb888to565(255, 0, 180) :
                     (i % 3 == 1) ? RGB565_CYAN : RGB565_BLUE;

    gfx->drawLine(x, y, x + 16 + (i % 5) * 6, y, color);
  }

  for (int y = 286; y < 410; y += 6) {
    gfx->drawLine(150, y, 170, y, rgb888to565(0, 30, 110));
    gfx->drawLine(156, y, 164, y, RGB565_CYAN);
  }
}

void drawRpsLeftCabinet() {
  int x = 0;
  int y = 132;
  uint16_t magenta = rgb888to565(255, 0, 180);
  uint16_t orange = rgb888to565(255, 128, 0);
  uint16_t gray = rgb888to565(150, 150, 170);

  gfx->fillRoundRect(x, y, 42, 150, 4, rgb888to565(5, 5, 24));
  gfx->drawRoundRect(x, y, 42, 150, 4, magenta);
  gfx->drawLine(42, y, 58, y + 32, RGB565_BLUE);
  gfx->drawLine(42, y + 150, 58, y + 118, RGB565_BLUE);
  gfx->fillRect(7, y + 24, 28, 38, rgb888to565(0, 8, 40));
  gfx->drawRect(7, y + 24, 28, 38, RGB565_CYAN);

  gfx->setTextSize(1);
  gfx->setTextColor(magenta);
  gfx->setCursor(6, y + 6);
  gfx->print("INSERT");
  gfx->setCursor(10, y + 17);
  gfx->print("COIN");

  gfx->drawLine(11, y + 55, 30, y + 36, RGB565_GREEN);
  gfx->fillCircle(21, y + 83, 5, RGB565_RED);
  gfx->drawLine(21, y + 88, 21, y + 103, gray);
  gfx->fillCircle(14, y + 112, 3, RGB565_RED);
  gfx->fillCircle(25, y + 113, 3, orange);
  gfx->fillRect(10, y + 128, 22, 16, rgb888to565(2, 3, 18));
  gfx->drawRect(10, y + 128, 22, 16, RGB565_BLUE);
}

void drawRpsRightCabinet() {
  int x = 278;
  int y = 132;
  uint16_t magenta = rgb888to565(255, 0, 180);
  uint16_t orange = rgb888to565(255, 128, 0);
  uint16_t gray = rgb888to565(150, 150, 170);

  gfx->fillRoundRect(x, y, 42, 150, 4, rgb888to565(5, 5, 24));
  gfx->drawRoundRect(x, y, 42, 150, 4, RGB565_BLUE);
  gfx->drawLine(x, y, x - 16, y + 32, magenta);
  gfx->drawLine(x, y + 150, x - 16, y + 118, magenta);
  gfx->fillRect(x + 7, y + 24, 28, 38, rgb888to565(0, 8, 40));
  gfx->drawRect(x + 7, y + 24, 28, 38, RGB565_CYAN);

  gfx->setTextSize(1);
  gfx->setTextColor(magenta);
  gfx->setCursor(x + 8, y + 6);
  gfx->print("HIGH");
  gfx->setCursor(x + 6, y + 17);
  gfx->print("SCORE");
  gfx->setCursor(x + 10, y + 28);
  gfx->print("1984");

  gfx->fillTriangle(x + 22, y + 39, x + 15, y + 58, x + 29, y + 58, RGB565_RED);
  gfx->fillRect(x + 18, y + 54, 8, 7, RGB565_WHITE);
  gfx->fillCircle(x + 22, y + 83, 5, RGB565_RED);
  gfx->drawLine(x + 22, y + 88, x + 22, y + 103, gray);
  gfx->fillCircle(x + 14, y + 112, 3, RGB565_BLUE);
  gfx->fillCircle(x + 28, y + 113, 3, RGB565_YELLOW);
  gfx->fillRect(x + 10, y + 128, 22, 16, rgb888to565(2, 3, 18));
  gfx->drawRect(x + 10, y + 128, 22, 16, RGB565_BLUE);
}

void drawRpsSideDecorations() {
  uint16_t magenta = rgb888to565(255, 0, 180);

  gfx->setTextSize(2);
  gfx->setTextColor(RGB565_CYAN);
  gfx->setCursor(10, 58);
  gfx->print("*");
  gfx->setTextColor(magenta);
  gfx->setCursor(286, 70);
  gfx->print("<3");
  gfx->setTextColor(RGB565_YELLOW);
  gfx->setCursor(270, 22);
  gfx->print("*");
  gfx->setTextColor(RGB565_CYAN);
  gfx->setCursor(36, 18);
  gfx->print("*");
}

void drawRpsOuterTitleFrame(int x, int y, int w, int h) {
  uint16_t magenta = rgb888to565(255, 0, 180);

  gfx->fillRoundRect(x, y, w, h, 12, rgb888to565(3, 2, 25));
  gfx->drawRoundRect(x - 5, y - 5, w + 10, h + 10, 13, magenta);
  gfx->drawRoundRect(x - 3, y - 3, w + 6, h + 6, 12, magenta);
  gfx->drawRoundRect(x - 1, y - 1, w + 2, h + 2, 11, magenta);
  gfx->drawRoundRect(x + 6, y + 6, w - 12, h - 12, 10, RGB565_CYAN);
  gfx->drawRoundRect(x + 9, y + 9, w - 18, h - 18, 8, RGB565_BLUE);
  gfx->fillRect(x + 5, y + 52, 12, 42, rgb888to565(0, 0, 20));
  gfx->fillRect(x + w - 17, y + 52, 12, 42, rgb888to565(0, 0, 20));
  gfx->drawLine(x + 28, y + h - 14, x + w - 28, y + h - 14, magenta);
}

void drawRpsTitleSign() {
  int x = 42;
  int y = 18;
  int w = 236;
  int h = 122;
  uint16_t magenta = rgb888to565(255, 0, 180);
  uint16_t orange = rgb888to565(255, 128, 0);
  uint16_t gray = rgb888to565(150, 150, 170);

  drawRpsOuterTitleFrame(x, y, w, h);
  drawPixelText("ROCK", 91, 32, 4, gray, RGB565_BLACK);
  drawPixelText("PAPER", 64, 64, 4, RGB565_WHITE, RGB565_BLUE);
  drawPixelText("SCISSORS", 46, 96, 3, RGB565_CYAN, RGB565_BLUE);

  gfx->fillRoundRect(87, 133, 146, 25, 6, rgb888to565(4, 2, 12));
  gfx->drawRoundRect(87, 133, 146, 25, 6, magenta);
  gfx->drawRoundRect(90, 136, 140, 19, 5, RGB565_BLUE);

  gfx->setTextSize(2);
  gfx->setTextColor(RGB565_GREEN);
  gfx->setCursor(102, 139);
  gfx->print("LIZARD");
  gfx->setTextColor(orange);
  gfx->setCursor(178, 139);
  gfx->print("SPOCK");
}

void drawRpsBottomRail() {
  uint16_t magenta = rgb888to565(255, 0, 180);
  uint16_t orange = rgb888to565(255, 128, 0);
  uint16_t gray = rgb888to565(150, 150, 170);

  gfx->fillRect(0, 410, screenW, 70, rgb888to565(3, 4, 16));
  gfx->drawLine(0, 410, screenW - 1, 410, magenta);
  gfx->drawLine(0, 413, screenW - 1, 413, RGB565_BLUE);

  gfx->drawLine(45, 430, 45, 462, gray);
  gfx->drawLine(46, 430, 46, 462, RGB565_WHITE);
  gfx->fillCircle(45, 426, 14, RGB565_RED);
  gfx->drawCircle(45, 426, 15, orange);
  gfx->fillCircle(40, 420, 3, RGB565_WHITE);
  gfx->fillRoundRect(17, 456, 56, 18, 9, rgb888to565(5, 7, 22));
  gfx->drawRoundRect(17, 456, 56, 18, 9, RGB565_BLUE);
  gfx->drawRoundRect(25, 459, 40, 12, 6, magenta);

  gfx->fillCircle(252, 452, 12, magenta);
  gfx->drawCircle(252, 452, 13, RGB565_WHITE);
  gfx->fillCircle(286, 452, 12, RGB565_BLUE);
  gfx->drawCircle(286, 452, 13, RGB565_CYAN);
}

void drawRpsArcadeHome() {
  if (sdReady && SD.exists(RPS_BACKGROUND_PATH)) {
    if (drawRaw565ImageFromSD(RPS_BACKGROUND_PATH, 0, 0, screenW, screenH)) {
      return;
    }
  }

  drawRpsHomeGradientBackground();
  drawRpsHomeStars();
  drawRpsBackWall();
  drawRpsHomeFloor();
  drawRpsLeftCabinet();
  drawRpsRightCabinet();
  drawRpsSideDecorations();
  drawRpsTitleSign();
  drawRpsBottomRail();
  gfx->drawRoundRect(2, 2, screenW - 4, screenH - 4, 10, rgb888to565(10, 20, 80));
  gfx->drawRoundRect(5, 5, screenW - 10, screenH - 10, 8, rgb888to565(30, 0, 70));
}

void drawTransparentArcadeButton(int x, int y, int w, int h, const char *label, int textSize) {
  uint16_t mainTextColor = RGB565_YELLOW;
  uint16_t secondTextColor = RGB565_RED;

  if (strcmp(label, "BACK") == 0 || strcmp(label, "HOME") == 0) {
    mainTextColor = RGB565_CYAN;
    secondTextColor = RGB565_YELLOW;
  }

  int16_t x1, y1;
  uint16_t tw, th;
  int fittedSize = textSize;

  do {
    gfx->setTextSize(fittedSize);
    gfx->getTextBounds((char *)label, 0, 0, &x1, &y1, &tw, &th);

    if (tw <= (uint16_t)(w - 8) || fittedSize <= 1) {
      break;
    }

    fittedSize--;
  } while (true);

  int tx = x + (w - tw) / 2;
  int ty = y + (h - th) / 2 + 2;

  gfx->setCursor(tx + 2, ty + 2);
  gfx->setTextColor(secondTextColor);
  gfx->print(label);

  gfx->setCursor(tx, ty);
  gfx->setTextColor(mainTextColor);
  gfx->print(label);
}

void drawButton(int x, int y, int w, int h, uint16_t fillColor, uint16_t borderColor, uint16_t textColor, const char *label, int textSize) {
  // Shared arcade button style. The original fill color still chooses the
  // button mood, but all buttons use the same neon cabinet frame.
  uint16_t darkFill = rgb888to565(0, 6, 20);
  uint16_t coreColor = RGB565_CYAN;
  uint16_t mainTextColor = RGB565_YELLOW;
  uint16_t shadowTextColor = RGB565_RED;

  if (fillColor == RGB565_RED) {
    darkFill = rgb888to565(28, 0, 10);
    coreColor = RGB565_RED;
    mainTextColor = RGB565_YELLOW;
    shadowTextColor = RGB565_RED;
  } else if (fillColor == RGB565_GREEN) {
    darkFill = rgb888to565(0, 24, 16);
    coreColor = RGB565_GREEN;
    mainTextColor = RGB565_YELLOW;
    shadowTextColor = RGB565_RED;
  } else if (fillColor == RGB565_BLACK) {
    darkFill = RGB565_BLACK;
    coreColor = borderColor;
    mainTextColor = textColor;
    shadowTextColor = rgb888to565(0, 65, 210);
  } else {
    darkFill = rgb888to565(0, 8, 30);
    coreColor = RGB565_CYAN;
    mainTextColor = RGB565_CYAN;
    shadowTextColor = rgb888to565(0, 65, 210);
  }

  if (strcmp(label, "BACK") == 0 ||
      strcmp(label, "MENU") == 0 ||
      strcmp(label, "MENIU") == 0 ||
      strcmp(label, "HOME") == 0) {
    mainTextColor = RGB565_CYAN;
    shadowTextColor = rgb888to565(0, 65, 210);
  }

  gfx->fillRoundRect(x, y, w, h, 7, darkFill);
  drawNeonRect(x, y, w, h, coreColor);

  int16_t x1, y1;
  uint16_t tw, th;
  int fittedSize = textSize;

  do {
    gfx->setTextSize(fittedSize);
    gfx->getTextBounds((char *)label, 0, 0, &x1, &y1, &tw, &th);

    if (tw <= (uint16_t)(w - 8) || fittedSize <= 1) {
      break;
    }

    fittedSize--;
  } while (true);

  int tx = x + (w - tw) / 2;
  int ty = y + (h - th) / 2 + 2;

  gfx->setCursor(tx + 2, ty + 2);
  gfx->setTextColor(shadowTextColor);
  gfx->print(label);

  gfx->setCursor(tx, ty);
  gfx->setTextColor(mainTextColor);
  gfx->print(label);
}

void drawTextInRect(int x, int y, int w, int h, const char *label, int textSize, uint16_t color) {
  int16_t x1, y1;
  uint16_t tw, th;

  gfx->setTextSize(textSize);
  gfx->getTextBounds((char *)label, 0, 0, &x1, &y1, &tw, &th);

  int tx = x + (w - tw) / 2;
  int ty = y + (h - th) / 2 + 2;

  gfx->setCursor(tx, ty);
  gfx->setTextColor(color);
  gfx->print(label);
}

void drawRpsSegment(int centerX, int centerY, int radius, float startDeg, float endDeg, uint16_t color) {
  const float degToRad = 0.01745329252f;
  float startRad = startDeg * degToRad;
  int prevX = centerX + (int)(cos(startRad) * radius);
  int prevY = centerY + (int)(sin(startRad) * radius);

  for (float angle = startDeg + 3.0f; angle <= endDeg + 0.1f; angle += 3.0f) {
    float rad = angle * degToRad;
    int x = centerX + (int)(cos(rad) * radius);
    int y = centerY + (int)(sin(rad) * radius);

    gfx->fillTriangle(centerX, centerY, prevX, prevY, x, y, color);
    prevX = x;
    prevY = y;
  }
}

void drawRpsWheelLabel(const char *label, int x, int y, int size) {
  int16_t x1, y1;
  uint16_t w, h;

  gfx->setTextSize(size);
  gfx->getTextBounds((char *)label, 0, 0, &x1, &y1, &w, &h);
  gfx->setCursor(x - (int)w / 2, y - (int)h / 2);
  gfx->setTextColor(RGB565_BLACK);
  gfx->print(label);
}

void drawRpsWheel() {
  // Prefer the SD-rendered wheel; fall back to a simple generated wheel if the
  // asset is missing so the game remains playable.
  if (sdReady && SD.exists(rpsWheelImagePath)) {
    if (drawRaw565ImageFromSD(rpsWheelImagePath, 0, 0, screenW, screenH)) {
      return;
    }
  }

  uint16_t colors[5] = {
    rgb888to565(150, 170, 190),
    rgb888to565(210, 232, 246),
    rgb888to565(0, 135, 215),
    rgb888to565(105, 210, 45),
    rgb888to565(245, 145, 18)
  };

  drawRpsSegment(rpsWheelCenterX, rpsWheelCenterY, rpsWheelRadius, -126, -54, colors[0]);
  drawRpsSegment(rpsWheelCenterX, rpsWheelCenterY, rpsWheelRadius, -54, 18, colors[1]);
  drawRpsSegment(rpsWheelCenterX, rpsWheelCenterY, rpsWheelRadius, 18, 90, colors[2]);
  drawRpsSegment(rpsWheelCenterX, rpsWheelCenterY, rpsWheelRadius, 90, 162, colors[3]);
  drawRpsSegment(rpsWheelCenterX, rpsWheelCenterY, rpsWheelRadius, 162, 234, colors[4]);

  for (int i = 0; i < 4; i++) {
    gfx->drawCircle(rpsWheelCenterX, rpsWheelCenterY, rpsWheelRadius - i, RGB565_WHITE);
  }

  const int boundaryCount = 5;
  float boundaries[boundaryCount] = {-126, -54, 18, 90, 162};
  const float degToRad = 0.01745329252f;

  for (int i = 0; i < boundaryCount; i++) {
    float rad = boundaries[i] * degToRad;
    int x = rpsWheelCenterX + (int)(cos(rad) * rpsWheelRadius);
    int y = rpsWheelCenterY + (int)(sin(rad) * rpsWheelRadius);

    for (int offset = -1; offset <= 1; offset++) {
      gfx->drawLine(rpsWheelCenterX + offset, rpsWheelCenterY, x + offset, y, RGB565_BLACK);
    }
  }

  gfx->fillCircle(rpsWheelCenterX, rpsWheelCenterY, 14, RGB565_BLACK);

  drawRpsWheelLabel("ROCK", 160, 135, 2);
  drawRpsWheelLabel("PAPER", 243, 214, 2);
  drawRpsWheelLabel("SCISSORS", 222, 320, 2);
  drawRpsWheelLabel("LIZARD", 98, 320, 2);
  drawRpsWheelLabel("SPOCK", 77, 214, 2);
}

int rpsChoiceFromTouch(int x, int y) {
  // Invisible buttons: convert touch position to polar angle and map that angle
  // to one of the five wheel slices.
  long dx = x - rpsWheelCenterX;
  long dy = y - rpsWheelCenterY;
  long distanceSquared = dx * dx + dy * dy;
  long radiusSquared = (long)rpsWheelRadius * rpsWheelRadius;

  if (distanceSquared > radiusSquared) return -1;

  float angle = atan2((float)dy, (float)dx) * 57.2957795f;

  if (angle < -126.0f) {
    angle += 360.0f;
  }

  if (angle >= -126.0f && angle < -54.0f) return 0;
  if (angle >= -54.0f && angle < 18.0f) return 1;
  if (angle >= 18.0f && angle < 90.0f) return 2;
  if (angle >= 90.0f && angle < 162.0f) return 3;
  return 4;
}

void drawIpFields() {
  // Shared IP editor fields for Settings, Host, and Join screens.
  for (int i = 0; i < 4; i++) {
    int x = settingsFieldX + i * (settingsFieldW + settingsFieldGap);
    uint16_t fillColor = (i == activeIpField) ? RGB565_BLUE : RGB565_BLACK;
    uint16_t borderColor = (i == activeIpField) ? RGB565_YELLOW : RGB565_CYAN;

    gfx->fillRoundRect(x, settingsFieldY, settingsFieldW, settingsFieldH, 8, fillColor);
    gfx->drawRoundRect(x, settingsFieldY, settingsFieldW, settingsFieldH, 8, borderColor);
    drawTextInRect(x, settingsFieldY, settingsFieldW, settingsFieldH, ipFieldText[i], 2, RGB565_WHITE);

    if (i < 3) {
      int dotX = x + settingsFieldW + 4;
      drawTextInRect(dotX, settingsFieldY, settingsFieldGap, settingsFieldH, ".", 2, RGB565_WHITE);
    }
  }
}

void drawSettingsKeypad() {
  const char *labels[12] = {
    "1", "2", "3",
    "4", "5", "6",
    "7", "8", "9",
    "DEL", "0", "NEXT"
  };

  for (int i = 0; i < 12; i++) {
    int col = i % 3;
    int row = i / 3;
    int x = keyPadX + col * (keyPadW + keyPadGapX);
    int y = keyPadY + row * (keyPadH + keyPadGapY);

    uint16_t fillColor = RGB565_BLUE;
    uint16_t textColor = RGB565_WHITE;

    if (i == 9) fillColor = RGB565_RED;
    if (i == 11) {
      fillColor = RGB565_GREEN;
      textColor = RGB565_BLACK;
    }

    drawButton(x, y, keyPadW, keyPadH, fillColor, RGB565_WHITE, textColor, labels[i], 2);
  }
}

void drawJoinKeypad() {
  const char *labels[12] = {
    "1", "2", "3",
    "4", "5", "6",
    "7", "8", "9",
    "DEL", "0", "NEXT"
  };

  for (int i = 0; i < 12; i++) {
    int col = i % 3;
    int row = i / 3;
    int x = joinKeyPadX + col * (joinKeyPadW + joinKeyPadGapX);
    int y = joinKeyPadY + row * (joinKeyPadH + joinKeyPadGapY);

    uint16_t fillColor = RGB565_BLUE;
    uint16_t textColor = RGB565_WHITE;

    if (i == 9) fillColor = RGB565_RED;
    if (i == 11) {
      fillColor = RGB565_GREEN;
      textColor = RGB565_BLACK;
    }

    drawButton(x, y, joinKeyPadW, joinKeyPadH, fillColor, RGB565_WHITE, textColor, labels[i], 2);
  }
}

void drawJoinNetworkList() {
  // Shows one page of scanned SSIDs. Empty rows remain visible to keep layout
  // stable when fewer than eight networks are found.
  for (int i = 0; i < MAX_JOIN_NETWORKS_VISIBLE; i++) {
    int networkIndex = joinNetworkListOffset + i;
    int y = joinNetworkY + i * (joinNetworkH + joinNetworkGap);
    uint16_t fillColor = (networkIndex == selectedJoinNetwork) ? RGB565_GREEN : RGB565_BLUE;
    uint16_t textColor = (networkIndex == selectedJoinNetwork) ? RGB565_BLACK : RGB565_WHITE;
    char label[32];

    if (networkIndex < joinNetworkCount) {
      snprintf(label, sizeof(label), "%d %s", networkIndex + 1, joinNetworks[networkIndex].c_str());
    } else {
      snprintf(label, sizeof(label), "-");
      fillColor = RGB565_BLACK;
      textColor = RGB565_WHITE;
    }

    drawButton(joinNetworkX, y, joinNetworkW, joinNetworkH,
               fillColor, RGB565_WHITE, textColor, label, 1);
  }
}

void drawHostSSIDList() {
  // Shows one page of selectable host SSID names from epicSSIDList.
  for (int i = 0; i < MAX_HOST_SSID_VISIBLE; i++) {
    int ssidIndex = hostSSIDListOffset + i;
    int y = hostSSIDY + i * (hostSSIDH + hostSSIDGap);
    uint16_t fillColor = (ssidIndex == selectedHostSSIDIndex) ? RGB565_GREEN : RGB565_BLUE;
    uint16_t textColor = (ssidIndex == selectedHostSSIDIndex) ? RGB565_BLACK : RGB565_WHITE;
    char label[36];

    if (ssidIndex < EPIC_SSID_COUNT) {
      snprintf(label, sizeof(label), "%d %s", ssidIndex + 1, epicSSIDList[ssidIndex]);
    } else {
      snprintf(label, sizeof(label), "-");
      fillColor = RGB565_BLACK;
      textColor = RGB565_WHITE;
    }

    drawButton(hostSSIDX, y, hostSSIDW, hostSSIDH,
               fillColor, RGB565_WHITE, textColor, label, 1);
  }
}

// ============================================================================
// GAME LOGIC
// ============================================================================
// Pure game rules and asset-name lookup helpers. These functions do not handle
// touch routing; they only update game state or answer rule questions.
void clearBoard() {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      board[r][c] = ' ';
    }
  }
}

void resetGameLogic() {
  clearBoard();
  currentPlayer = 'X';
  gameOver = false;
  winner = ' ';
  myTurn = localGame || (myPlayer == 'X');
}

bool boardFull() {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (board[r][c] == ' ') return false;
    }
  }

  return true;
}

char checkWinner() {
  for (int r = 0; r < 3; r++) {
    if (board[r][0] != ' ' &&
        board[r][0] == board[r][1] &&
        board[r][1] == board[r][2]) {
      return board[r][0];
    }
  }

  for (int c = 0; c < 3; c++) {
    if (board[0][c] != ' ' &&
        board[0][c] == board[1][c] &&
        board[1][c] == board[2][c]) {
      return board[0][c];
    }
  }

  if (board[0][0] != ' ' &&
      board[0][0] == board[1][1] &&
      board[1][1] == board[2][2]) {
    return board[0][0];
  }

  if (board[0][2] != ' ' &&
      board[0][2] == board[1][1] &&
      board[1][1] == board[2][0]) {
    return board[0][2];
  }

  if (boardFull()) return 'D';

  return ' ';
}

bool rpsChoiceBeats(int firstChoice, int secondChoice) {
  // RPSLS win table: each choice beats exactly two other choices.
  if (firstChoice == 0) return secondChoice == 2 || secondChoice == 3;
  if (firstChoice == 1) return secondChoice == 0 || secondChoice == 4;
  if (firstChoice == 2) return secondChoice == 1 || secondChoice == 3;
  if (firstChoice == 3) return secondChoice == 1 || secondChoice == 4;
  if (firstChoice == 4) return secondChoice == 0 || secondChoice == 2;

  return false;
}

int calculateRpsWinner(int p1Choice, int p2Choice) {
  if (p1Choice == p2Choice) return 0;
  if (rpsChoiceBeats(p1Choice, p2Choice)) return 1;
  return 2;
}

void resetRpsRound() {
  rpsP1Choice = -1;
  rpsP2Choice = -1;
  rpsWinner = 0;
}

const char *getRpsWinImageBaseName(int winningChoice, int losingChoice) {
  // Maps a winning pair to the RAW filename stem used on SD.
  if (winningChoice == 0 && losingChoice == 2) return "win_rock_crushes_scissors";
  if (winningChoice == 0 && losingChoice == 3) return "win_rock_crushes_lizard";
  if (winningChoice == 1 && losingChoice == 0) return "win_paper_covers_rock";
  if (winningChoice == 1 && losingChoice == 4) return "win_paper_releases_spock";
  if (winningChoice == 2 && losingChoice == 1) return "win_scissors_cuts_paper";
  if (winningChoice == 2 && losingChoice == 3) return "win_scissors_cuts_lizard";
  if (winningChoice == 3 && losingChoice == 1) return "win_lizard_eats_paper";
  if (winningChoice == 3 && losingChoice == 4) return "win_lizard_poisons_spock";
  if (winningChoice == 4 && losingChoice == 0) return "win_spock_vaporizes_rock";
  if (winningChoice == 4 && losingChoice == 2) return "win_spock_smashes_scissors";

  return nullptr;
}

const char *getRpsLoseImageBaseName(int winningChoice, int losingChoice) {
  // Network RPSLS is viewpoint-specific. The losing player sees a lose_ image
  // for the same winning pair.
  if (winningChoice == 0 && losingChoice == 2) return "lose_scissors_to_rock";
  if (winningChoice == 0 && losingChoice == 3) return "lose_lizard_to_rock";
  if (winningChoice == 1 && losingChoice == 0) return "lose_rock_to_paper";
  if (winningChoice == 1 && losingChoice == 4) return "lose_spock_to_paper";
  if (winningChoice == 2 && losingChoice == 1) return "lose_paper_to_scissors";
  if (winningChoice == 2 && losingChoice == 3) return "lose_lizard_to_scissors";
  if (winningChoice == 3 && losingChoice == 1) return "lose_paper_to_lizard";
  if (winningChoice == 3 && losingChoice == 4) return "lose_spock_to_lizard";
  if (winningChoice == 4 && losingChoice == 0) return "lose_rock_to_spock";
  if (winningChoice == 4 && losingChoice == 2) return "lose_scissors_to_spock";

  return nullptr;
}

const char *getRpsDrawImageBaseName(int choice) {
  if (choice == 0) return "draw_rock";
  if (choice == 1) return "draw_paper";
  if (choice == 2) return "draw_scissors";
  if (choice == 3) return "draw_lizard";
  if (choice == 4) return "draw_spock";

  return nullptr;
}

bool drawRpsRawResultImage(const char *folder, const char *baseName) {
  if (!sdReady || !baseName) return false;

  char path[96];
  snprintf(path, sizeof(path), "%s/%s.raw", folder, baseName);

  if (!SD.exists(path)) {
    Serial.print("Missing RPSLS result image: ");
    Serial.println(path);
    return false;
  }

  return drawRaw565ImageFromSD(path, 0, 0, screenW, screenH);
}

bool drawRpsDrawImage() {
  if (rpsWinner != 0) return false;

  return drawRpsRawResultImage(rpsDrawPath, getRpsDrawImageBaseName(rpsP1Choice));
}

bool drawRpsWinningImage() {
  if (!sdReady || rpsWinner == 0) return false;

  int winningChoice = (rpsWinner == 1) ? rpsP1Choice : rpsP2Choice;
  int losingChoice = (rpsWinner == 1) ? rpsP2Choice : rpsP1Choice;

  if (!localGame && (myPlayer == '1' || myPlayer == '2')) {
    // In network mode each device sees the result from its own perspective.
    bool localPlayerWon = (myPlayer == '1' && rpsWinner == 1) ||
                          (myPlayer == '2' && rpsWinner == 2);
    const char *baseName = localPlayerWon
                           ? getRpsWinImageBaseName(winningChoice, losingChoice)
                           : getRpsLoseImageBaseName(winningChoice, losingChoice);
    const char *folder = localPlayerWon ? rpsNetworkWinPath : rpsNetworkLosePath;

    return drawRpsRawResultImage(folder, baseName);
  }

  const char *baseName = getRpsWinImageBaseName(winningChoice, losingChoice);
  const char *folder = (rpsWinner == 1) ? rpsPlayer1WinsPath : rpsPlayer2WinsPath;

  return drawRpsRawResultImage(folder, baseName);
}

// ============================================================================
// GAME DRAWING
// ============================================================================
// Rendering helpers for Tic Tac Toe, RPSLS, and Tanks Wars gameplay.
void drawX(int cx, int cy) {
  int margin = 20;

  int x0 = boardX + cx * cellSize + margin;
  int y0 = boardY + cy * cellSize + margin;
  int x1 = boardX + (cx + 1) * cellSize - margin;
  int y1 = boardY + (cy + 1) * cellSize - margin;

  for (int i = -2; i <= 2; i++) {
    gfx->drawLine(x0 + i, y0, x1 + i, y1, RGB565_RED);
    gfx->drawLine(x0 + i, y1, x1 + i, y0, RGB565_RED);
  }
}

void drawO(int cx, int cy) {
  int centerX = boardX + cx * cellSize + cellSize / 2;
  int centerY = boardY + cy * cellSize + cellSize / 2;
  int radius = cellSize / 2 - 20;

  for (int i = 0; i < 4; i++) {
    gfx->drawCircle(centerX, centerY, radius - i, RGB565_CYAN);
  }
}

void drawSingleMark(int col, int row, char player) {
  if (player == 'X') drawX(col, row);
  if (player == 'O') drawO(col, row);
}

void drawGrid() {
  gfx->fillRect(boardX - 2, boardY - 2, boardSize + 4, boardSize + 4, RGB565_WHITE);
  gfx->fillRect(boardX, boardY, boardSize, boardSize, RGB565_BLACK);

  gfx->fillRect(boardX + cellSize - 2, boardY, 4, boardSize, RGB565_WHITE);
  gfx->fillRect(boardX + 2 * cellSize - 2, boardY, 4, boardSize, RGB565_WHITE);

  gfx->fillRect(boardX, boardY + cellSize - 2, boardSize, 4, RGB565_WHITE);
  gfx->fillRect(boardX, boardY + 2 * cellSize - 2, boardSize, 4, RGB565_WHITE);
}

void drawAllMarks() {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (board[r][c] == 'X' || board[r][c] == 'O') {
        drawSingleMark(c, r, board[r][c]);
      }
    }
  }
}

void drawScoreBar() {
  gfx->fillRect(0, 0, screenW, topBarH, RGB565_BLACK);
  gfx->drawLine(0, topBarH - 1, screenW, topBarH - 1, RGB565_WHITE);

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "Scor X:%d  O:%d  E:%d", scoreX, scoreO, scoreDraw);
  drawCenteredText(scoreLine, 10, 2, RGB565_WHITE);

  char turnLine[48];

  if (gameOver) {
    snprintf(turnLine, sizeof(turnLine), "Joc terminat");
  } else if (localGame) {
    snprintf(turnLine, sizeof(turnLine), "Randul: %c", currentPlayer);
  } else if (myTurn) {
    snprintf(turnLine, sizeof(turnLine), "Randul tau: %c", myPlayer);
  } else {
    snprintf(turnLine, sizeof(turnLine), "Asteapta: %c", currentPlayer);
  }

  drawCenteredText(turnLine, 42, 2, (localGame || myTurn) ? RGB565_GREEN : RGB565_YELLOW);
}

int getPocketTanksTerrainY(int x) {
  if (x < 0) x = 0;
  if (x >= PT_TERRAIN_W) x = PT_TERRAIN_W - 1;
  return ptTerrain[x];
}

int getPocketTanksTankY(int tankIndex) {
  int y = getPocketTanksTerrainY(ptTankX[tankIndex]) - ptTankH;

  if (y < 36) y = 36;
  if (y > ptFieldBottom - ptTankH) y = ptFieldBottom - ptTankH;

  return y;
}

uint16_t getPocketTanksTerrainColor(int x) {
  return (x % 3 == 0) ? rgb888to565(80, 164, 74) : rgb888to565(65, 132, 58);
}

void generatePocketTanksTerrain() {
  // Terrain is generated from three random sine waves. This creates smooth hills
  // while still changing the shape every round.
  float phaseA = (float)random(0, 6283) / 1000.0f;
  float phaseB = (float)random(0, 6283) / 1000.0f;
  float phaseC = (float)random(0, 6283) / 1000.0f;
  float freqA = (float)random(24, 47) / 1000.0f;
  float freqB = (float)random(58, 106) / 1000.0f;
  float freqC = (float)random(12, 22) / 1000.0f;
  float ampA = (float)random(16, 32);
  float ampB = (float)random(7, 18);
  float ampC = (float)random(8, 20);
  int baseY = random(278, 306);

  for (int x = 0; x < PT_TERRAIN_W; x++) {
    float waveA = sin((float)x * freqA + phaseA) * ampA;
    float waveB = sin((float)x * freqB + phaseB) * ampB;
    float waveC = sin((float)x * freqC + phaseC) * ampC;
    int y = baseY + (int)waveA + (int)waveB + (int)waveC;

    if (y < 242) y = 242;
    if (y > ptFieldBottom - 18) y = ptFieldBottom - 18;

    ptTerrain[x] = y;
  }

  for (int tank = 0; tank < 2; tank++) {
    // Flatten a small platform under each tank so the starting shot is readable.
    int platformY = ptTerrain[ptTankX[tank]] + random(-8, 9);

    if (platformY < 258) platformY = 258;
    if (platformY > ptFieldBottom - 34) platformY = ptFieldBottom - 34;

    for (int dx = -18; dx <= 18; dx++) {
      int x = ptTankX[tank] + dx;
      if (x >= 0 && x < PT_TERRAIN_W) {
        ptTerrain[x] = platformY;
      }
    }
  }
}

void drawPocketTanksHeader() {
  gfx->fillRect(0, 0, screenW, 54, RGB565_BLACK);

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "P1:%d   P2:%d", ptScoreP1, ptScoreP2);
  drawCenteredText(scoreLine, 8, 1, RGB565_WHITE);

  char turnLine[32];
  snprintf(turnLine, sizeof(turnLine), "PLAYER %d TURN", ptCurrentPlayer + 1);
  drawCenteredText(turnLine, 26, 2, (ptCurrentPlayer == 0) ? RGB565_RED : RGB565_CYAN);
}

void drawPocketTanksTerrain() {
  for (int x = 0; x < PT_TERRAIN_W; x++) {
    int y = ptTerrain[x];
    gfx->fillRect(x, y, 1, ptFieldBottom - y, getPocketTanksTerrainColor(x));
  }
}

void drawPocketTanksTank(int tankIndex) {
  // The active player gets a yellow turret so turn ownership is visible.
  int x = ptTankX[tankIndex];
  int y = getPocketTanksTankY(tankIndex);
  uint16_t bodyColor = (tankIndex == 0) ? RGB565_RED : RGB565_BLUE;
  uint16_t turretColor = (tankIndex == ptCurrentPlayer) ? RGB565_YELLOW : RGB565_WHITE;
  int dir = (tankIndex == 0) ? 1 : -1;
  float angleRad = (float)ptAngle[tankIndex] * 0.01745329252f;
  int barrelX = x + (int)(cos(angleRad) * 23.0f * dir);
  int barrelY = y - 1 - (int)(sin(angleRad) * 23.0f);

  gfx->fillRoundRect(x - ptTankW / 2, y, ptTankW, ptTankH, 4, bodyColor);
  gfx->drawRoundRect(x - ptTankW / 2, y, ptTankW, ptTankH, 4, RGB565_WHITE);
  gfx->fillCircle(x, y, 5, turretColor);

  for (int offset = -1; offset <= 1; offset++) {
    gfx->drawLine(x, y - 1 + offset, barrelX, barrelY + offset, turretColor);
  }
}

void redrawPocketTanksBackgroundArea(int left, int top, int right, int bottom) {
  // Restores only a rectangular patch of sky/terrain. This is used to avoid
  // full-screen flicker during projectile movement and angle updates.
  if (right < 0 || left >= screenW || bottom < 0 || top >= ptFieldBottom) return;

  if (left < 0) left = 0;
  if (right >= screenW) right = screenW - 1;
  if (top < 0) top = 0;
  if (bottom >= ptFieldBottom) bottom = ptFieldBottom - 1;

  for (int x = left; x <= right; x++) {
    int terrainY = getPocketTanksTerrainY(x);

    if (top < terrainY) {
      int skyBottom = bottom;
      if (skyBottom >= terrainY) skyBottom = terrainY - 1;

      if (skyBottom >= top) {
        gfx->fillRect(x, top, 1, skyBottom - top + 1, RGB565_BLACK);
      }
    }

    if (bottom >= terrainY) {
      int groundTop = top;
      if (groundTop < terrainY) groundTop = terrainY;

      if (groundTop <= bottom) {
        gfx->fillRect(x, groundTop, 1, bottom - groundTop + 1, getPocketTanksTerrainColor(x));
      }
    }
  }
}

void redrawPocketTanksTankArea(int tankIndex, int oldAngle, int newAngle) {
  // Clears the bounding box that contains both the old and new barrel positions,
  // then redraws only the affected tank.
  int x = ptTankX[tankIndex];
  int y = getPocketTanksTankY(tankIndex);
  int dir = (tankIndex == 0) ? 1 : -1;
  float oldAngleRad = (float)oldAngle * 0.01745329252f;
  float newAngleRad = (float)newAngle * 0.01745329252f;
  int oldBarrelX = x + (int)(cos(oldAngleRad) * 25.0f * dir);
  int oldBarrelY = y - 1 - (int)(sin(oldAngleRad) * 25.0f);
  int newBarrelX = x + (int)(cos(newAngleRad) * 25.0f * dir);
  int newBarrelY = y - 1 - (int)(sin(newAngleRad) * 25.0f);
  int left = x - ptTankW / 2 - 6;
  int right = x + ptTankW / 2 + 6;
  int top = y - 32;
  int bottom = y + ptTankH + 6;

  if (oldBarrelX < left) left = oldBarrelX - 6;
  if (oldBarrelX > right) right = oldBarrelX + 6;
  if (oldBarrelY < top) top = oldBarrelY - 6;
  if (oldBarrelY > bottom) bottom = oldBarrelY + 6;

  if (newBarrelX < left) left = newBarrelX - 6;
  if (newBarrelX > right) right = newBarrelX + 6;
  if (newBarrelY < top) top = newBarrelY - 6;
  if (newBarrelY > bottom) bottom = newBarrelY + 6;

  redrawPocketTanksBackgroundArea(left, top, right, bottom);
  drawPocketTanksTank(tankIndex);
}

void redrawPocketTanksProjectileArea(int centerX, int centerY) {
  // Restores the old projectile position and then redraws both tanks because the
  // projectile can pass over a tank sprite.
  int patchRadius = ptProjectileRadius + 3;
  int left = centerX - patchRadius;
  int right = centerX + patchRadius;
  int top = centerY - patchRadius;
  int bottom = centerY + patchRadius;

  redrawPocketTanksBackgroundArea(left, top, right, bottom);

  if (top < 54) {
    drawPocketTanksHeader();
  }

  drawPocketTanksTank(0);
  drawPocketTanksTank(1);
}

void drawPocketTanksProjectileFrame(int previousX, int previousY, int currentX, int currentY) {
  // Animation frame path: restore previous dot, draw current dot. The terrain
  // and controls stay untouched for a stable frame rate.
  if (previousX >= 0 && previousY >= 0) {
    redrawPocketTanksProjectileArea(previousX, previousY);
  }

  if (currentX >= 0 && currentX < screenW && currentY >= 0 && currentY < ptFieldBottom) {
    gfx->fillCircle(currentX, currentY, ptProjectileRadius, RGB565_YELLOW);
  }
}

void drawPocketTanksControls() {
  gfx->fillRect(0, ptFieldBottom, screenW, screenH - ptFieldBottom, RGB565_BLACK);
  gfx->drawLine(0, ptFieldBottom, screenW, ptFieldBottom, RGB565_WHITE);

  char line[64];
  snprintf(line, sizeof(line), "P%d  Angle:%d  Power:%d",
           ptCurrentPlayer + 1, ptAngle[ptCurrentPlayer], ptPower[ptCurrentPlayer]);
  drawCenteredText(line, 357, 1, RGB565_YELLOW);

  drawButton(btnPtAngleDownX, btnPtAngleDownY, btnPtControlW, btnPtControlH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "ANG-", 1);
  drawButton(btnPtAngleUpX, btnPtAngleUpY, btnPtControlW, btnPtControlH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "ANG+", 1);
  drawButton(btnPtPowerDownX, btnPtPowerDownY, btnPtControlW, btnPtControlH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "POW-", 1);
  drawButton(btnPtPowerUpX, btnPtPowerUpY, btnPtControlW, btnPtControlH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "POW+", 1);

  drawButton(btnPtFireX, btnPtFireY, btnPtFireW, btnPtFireH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "FIRE", 2);
  drawButton(btnPtMenuX, btnPtMenuY, btnPtMenuW, btnPtMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENU", 2);
}

void drawPocketTanksScene(int projectileX, int projectileY, bool showExplosion, int explosionX, int explosionY) {
  // Full redraw used when entering the screen, changing turns, or showing an
  // explosion. The normal projectile animation uses partial redraws instead.
  gfx->fillScreen(RGB565_BLACK);

  drawPocketTanksHeader();
  drawPocketTanksTerrain();

  drawPocketTanksTank(0);
  drawPocketTanksTank(1);

  if (projectileX >= 0 && projectileX < screenW && projectileY >= 0 && projectileY < ptFieldBottom) {
    gfx->fillCircle(projectileX, projectileY, ptProjectileRadius, RGB565_YELLOW);
  }

  if (showExplosion) {
    gfx->fillCircle(explosionX, explosionY, ptExplosionRadius / 2, RGB565_RED);
    gfx->drawCircle(explosionX, explosionY, ptExplosionRadius, RGB565_YELLOW);
    gfx->drawCircle(explosionX, explosionY, ptExplosionRadius - 3, RGB565_WHITE);
  }

  drawPocketTanksControls();
}

// ============================================================================
// SCREENS
// ============================================================================
// Screen drawing functions are responsible only for visual layout and setting
// appState. Touch behavior lives later in the touch routing section.
void drawMenuScreen() {
  activeNetworkGame = NETWORK_GAME_TTT;
  drawTicTacToeArcadeHome();

  drawTransparentArcadeButton(btnLocalX, btnLocalY, btnLocalW, btnLocalH, "LOCAL", 2);

  drawTransparentArcadeButton(btnHostX, btnHostY, btnHostW, btnHostH, "HOST - X", 2);

  drawTransparentArcadeButton(btnJoinX, btnJoinY, btnJoinW, btnJoinH, "JOIN - O", 2);

  drawTransparentArcadeButton(btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH, "RESET SCOR", 2);

  drawTransparentArcadeButton(btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH, "BACK", 2);

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "SCORE  X:%d  O:%d  D:%d", scoreX, scoreO, scoreDraw);
  drawCenteredTextWithShadow(scoreLine, 462, 1, RGB565_WHITE, RGB565_BLACK);
}

void drawGamesScreen() {
  appState = STATE_GAMES;
  drawGamesArcadeBackground();

  drawTransparentArcadeButton(btnGamesX, btnGamesTttY, btnGamesW, btnGamesH, "TIC TAC TOE", 2);

  drawTransparentArcadeButton(btnGamesX, btnGamesRpsY, btnGamesW, btnGamesH, "ROCK-PAPER-SCISSORS", 2);

  drawTransparentArcadeButton(btnGamesX, btnGamesPocketTanksY, btnGamesW, btnGamesH, "Tanks Wars", 2);

  drawTransparentArcadeButton(btnGamesX, btnGamesHomeY, btnGamesW, btnGamesHomeH, "HOME", 2);
}

void drawRpsMenuScreen() {
  activeNetworkGame = NETWORK_GAME_RPS;
  localGame = false;
  appState = STATE_ROCK_PAPER_SCISSORS;
  drawRpsArcadeHome();

  drawTransparentArcadeButton(btnLocalX, btnLocalY, btnLocalW, btnLocalH, "LOCAL", 2);

  drawTransparentArcadeButton(btnHostX, btnHostY, btnHostW, btnHostH, "HOST - P1", 2);

  drawTransparentArcadeButton(btnJoinX, btnJoinY, btnJoinW, btnJoinH, "JOIN - P2", 2);

  drawTransparentArcadeButton(btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH, "RESET SCOR", 2);

  drawTransparentArcadeButton(btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH, "BACK", 2);

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "SCORE  P1:%d  P2:%d  D:%d", rpsScoreP1, rpsScoreP2, rpsScoreDraw);
  drawCenteredTextWithShadow(scoreLine, 462, 1, RGB565_WHITE, RGB565_BLACK);
}

void drawRpsChoiceScreen(int playerNumber) {
  appState = (playerNumber == 1) ? STATE_RPS_CHOICE_P1 : STATE_RPS_CHOICE_P2;
  gfx->fillScreen(RGB565_BLACK);
  drawRpsWheel();

  if (playerNumber == 1) {
    drawCenteredText("PLAYER 1 CHOICE", 18, 2, RGB565_CYAN);
  } else {
    drawCenteredText("PLAYER 2 CHOICE", 18, 2, RGB565_CYAN);
  }

  drawCenteredText("Pick one segment", 48, 1, RGB565_YELLOW);

  drawButton(btnRpsMenuX, btnRpsMenuY, btnRpsMenuW, btnRpsMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENU", 2);
}

void drawRpsWaitingChoiceScreen() {
  appState = STATE_RPS_WAITING_CHOICE;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("CHOICE SAVED", 92, 2, RGB565_GREEN);
  drawCenteredText("Waiting opponent", 142, 2, RGB565_YELLOW);

  if (myPlayer == '1') {
    drawCenteredText("You are Player 1", 198, 2, RGB565_CYAN);
  } else {
    drawCenteredText("You are Player 2", 198, 2, RGB565_CYAN);
  }

  drawButton(btnRpsMenuX, btnRpsMenuY, btnRpsMenuW, btnRpsMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENU", 2);
}

void drawRpsResultScreen() {
  appState = STATE_RPS_RESULT;

  bool resultImageDrawn = (rpsWinner == 0) ? drawRpsDrawImage() : drawRpsWinningImage();

  if (!resultImageDrawn) {
    gfx->fillScreen(RGB565_BLACK);

    if (rpsWinner == 0) {
      drawCenteredText("Missing draw image", 150, 2, RGB565_RED);
    } else {
      drawCenteredText("Missing result image", 150, 2, RGB565_RED);
    }

    char scoreLine[48];
    snprintf(scoreLine, sizeof(scoreLine), "P1:%d   P2:%d   E:%d", rpsScoreP1, rpsScoreP2, rpsScoreDraw);
    drawCenteredText(scoreLine, 230, 2, RGB565_WHITE);
  }

  drawButton(btnPlayAgainX, btnPlayAgainY, btnPlayAgainW, btnPlayAgainH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "PLAY AGAIN", 2);

  drawButton(btnResultMenuX, btnResultMenuY, btnResultMenuW, btnResultMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENU", 2);
}

void drawRpsPlaceholderScreen(const char *title) {
  rpsPlaceholderTitle = title;
  appState = STATE_RPS_PLACEHOLDER;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText(rpsPlaceholderTitle, 110, 3, RGB565_CYAN);

  drawButton(btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
}

void drawEmptyGameScreen(const char *title, int state) {
  appState = (AppState)state;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText(title, 110, 2, RGB565_CYAN);

  drawButton(btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
}

void drawPocketTanksMenuScreen() {
  localGame = false;
  appState = STATE_POCKET_TANKS;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("Tanks Wars", 35, 3, RGB565_WHITE);
  drawCenteredText("LOCAL ARTILLERY", 75, 2, RGB565_CYAN);

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "P1:%d   P2:%d", ptScoreP1, ptScoreP2);
  drawCenteredText(scoreLine, 120, 2, RGB565_YELLOW);

  drawButton(btnLocalX, btnLocalY, btnLocalW, btnLocalH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "LOCAL", 2);

  drawButton(btnHostX, btnHostY, btnHostW, btnHostH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "HOST", 2);

  drawButton(btnJoinX, btnJoinY, btnJoinW, btnJoinH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "JOIN", 2);

  drawButton(btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH,
             RGB565_RED, RGB565_WHITE, RGB565_WHITE, "RESET SCOR", 2);

  drawButton(btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "BACK", 2);
}

void drawPocketTanksGameScreen() {
  appState = STATE_PT_PLAYING;
  drawPocketTanksScene(-1, -1, false, -1, -1);
}

void drawPocketTanksResultScreen() {
  appState = STATE_PT_RESULT;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("Tanks Wars", 38, 3, RGB565_WHITE);

  if (ptWinner == 1) {
    drawCenteredText("PLAYER 1 WINS", 130, 3, RGB565_RED);
  } else if (ptWinner == 2) {
    drawCenteredText("PLAYER 2 WINS", 130, 3, RGB565_CYAN);
  } else {
    drawCenteredText("ROUND OVER", 130, 3, RGB565_YELLOW);
  }

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "P1:%d   P2:%d", ptScoreP1, ptScoreP2);
  drawCenteredText(scoreLine, 218, 2, RGB565_WHITE);

  drawButton(btnPlayAgainX, btnPlayAgainY, btnPlayAgainW, btnPlayAgainH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "PLAY AGAIN", 2);

  drawButton(btnResultMenuX, btnResultMenuY, btnResultMenuW, btnResultMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENU", 2);
}

void drawPocketTanksPlaceholderScreen(const char *title) {
  ptPlaceholderTitle = title;
  appState = STATE_PT_PLACEHOLDER;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText(ptPlaceholderTitle, 90, 2, RGB565_CYAN);
  drawCenteredText("Network mode", 140, 2, RGB565_YELLOW);
  drawCenteredText("coming soon", 168, 2, RGB565_YELLOW);

  drawButton(btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
}

void drawWaitingHostScreen() {
  bool rpsNetworkGame = (activeNetworkGame == NETWORK_GAME_RPS);

  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText(rpsNetworkGame ? "RPS HOST" : "HOST ACTIV", 28, 3, RGB565_GREEN);
  drawCenteredText(rpsNetworkGame ? "Tu esti P1" : "Tu esti X", 72, 2, RGB565_WHITE);

  drawCenteredText("Asteapta oponentul", 118, 2, RGB565_YELLOW);
  drawCenteredText("sa intre cu JOIN", 145, 2, RGB565_YELLOW);

  drawCenteredText("WiFi:", 195, 2, RGB565_WHITE);
  drawCenteredText(epicSSIDList[selectedHostSSIDIndex], 222, 2, RGB565_CYAN);

  char ipLine[32];
  snprintf(ipLine, sizeof(ipLine), "%u.%u.%u.%u",
           ipParts[0], ipParts[1], ipParts[2], ipParts[3]);
  drawCenteredText("IP:", 270, 2, RGB565_WHITE);
  drawCenteredText(ipLine, 297, 2, RGB565_CYAN);

  drawButton(btnMenuX, btnMenuY, btnMenuW, btnMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENIU", 2);
}

void drawConnectingJoinScreen() {
  bool rpsNetworkGame = (activeNetworkGame == NETWORK_GAME_RPS);

  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText(rpsNetworkGame ? "RPS JOIN" : "JOIN", 70, 3, RGB565_BLUE);
  drawCenteredText(rpsNetworkGame ? "Tu esti P2" : "Tu esti O", 120, 2, RGB565_WHITE);

  drawCenteredText("Connecting...", 190, 2, RGB565_YELLOW);

  if (selectedJoinNetwork >= 0 && selectedJoinNetwork < joinNetworkCount) {
    drawCenteredText(joinNetworks[selectedJoinNetwork].c_str(), 225, 1, RGB565_CYAN);
  }

  char ipLine[32];
  snprintf(ipLine, sizeof(ipLine), "%u.%u.%u.%u",
           ipParts[0], ipParts[1], ipParts[2], ipParts[3]);
  drawCenteredText(ipLine, 255, 2, RGB565_WHITE);

  drawButton(btnMenuX, btnMenuY, btnMenuW, btnMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENIU", 2);
}

void drawGameScreenFull() {
  gfx->fillScreen(RGB565_BLACK);
  drawScoreBar();
  drawGrid();
  drawAllMarks();

  drawButton(btnMenuX, btnMenuY, btnMenuW, btnMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENIU", 2);
}

void drawResultScreen() {
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("REZULTAT", 30, 3, RGB565_WHITE);

  if (winner == 'X') {
    drawCenteredText("A castigat X!", 110, 3, RGB565_RED);
  } else if (winner == 'O') {
    drawCenteredText("A castigat O!", 110, 3, RGB565_CYAN);
  } else {
    drawCenteredText("Egalitate!", 110, 3, RGB565_YELLOW);
  }

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "X:%d   O:%d   E:%d", scoreX, scoreO, scoreDraw);
  drawCenteredText(scoreLine, 210, 2, RGB565_WHITE);

  drawButton(btnPlayAgainX, btnPlayAgainY, btnPlayAgainW, btnPlayAgainH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "JOACA DIN NOU", 2);

  drawButton(btnResultMenuX, btnResultMenuY, btnResultMenuW, btnResultMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "INAPOI LA MENIU", 2);
}

void drawHomeBuildInfo() {
  drawCenteredTextWithShadow(APP_VERSION_TEXT, 444, 1, RGB565_WHITE, RGB565_BLACK);
  drawCenteredTextWithShadow(APP_BUILD_ID_TEXT, 459, 1, RGB565_WHITE, RGB565_BLACK);
}

void drawHomeScreen() {
  appState = STATE_HOME;
  gfx->setRotation(0);

  bool backgroundDrawn = false;

  if (sdReady) {
    // Home screen uses SD artwork first, then falls back to generated arcade UI.
    backgroundDrawn = drawRaw565ImageFromSD("/home_screen/background.raw", 0, 0, screenW, screenH);
  }

  if (!backgroundDrawn) {
    drawHomeArcadeBackground();
  }

  bool gamesDrawn = false;
  bool settingsDrawn = false;
  bool exitDrawn = false;

  if (sdReady) {
    gamesDrawn = drawScaledRaw565ImageFromSD("/home_screen/button_games.raw",
                                             homeGamesRawX, homeGamesRawY,
                                             homeButtonRawW, homeButtonRawH,
                                             homeButtonSlotW, homeButtonSlotH);
    settingsDrawn = drawScaledRaw565ImageFromSD("/home_screen/button_settings.raw",
                                                homeSettingsRawX, homeSettingsRawY,
                                                homeButtonRawW, homeButtonRawH,
                                                homeButtonSlotW, homeButtonSlotH);
    exitDrawn = drawScaledRaw565ImageFromSD("/home_screen/button_exit.raw",
                                            homeExitRawX, homeExitRawY,
                                            homeButtonRawW, homeButtonRawH,
                                            homeButtonSlotW, homeButtonSlotH);
  }

  if (!gamesDrawn) {
    drawButton(homeGamesRawX, homeGamesRawY, homeButtonSlotW, homeButtonSlotH,
               RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "GAMES", 2);
  }

  if (!settingsDrawn) {
    drawButton(homeSettingsRawX, homeSettingsRawY, homeButtonSlotW, homeButtonSlotH,
               RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "SETTINGS", 2);
  }

  if (!exitDrawn) {
    drawButton(homeExitRawX, homeExitRawY, homeButtonSlotW, homeButtonSlotH,
               RGB565_RED, RGB565_WHITE, RGB565_WHITE, "EXIT", 2);
  }

  drawHomeBuildInfo();
}

void drawSettingsScreen() {
  appState = STATE_SETTINGS;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("SETTINGS", 24, 3, RGB565_CYAN);
  drawCenteredText("HOST IP", 62, 2, RGB565_YELLOW);

  drawIpFields();
  drawSettingsKeypad();

  drawButton(btnSettingsHomeX, btnSettingsHomeY, btnSettingsHomeW, btnSettingsHomeH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "HOME", 2);
  drawButton(btnSettingsSaveX, btnSettingsSaveY, btnSettingsSaveW, btnSettingsSaveH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "SAVE", 2);
}

void drawJoinScanningScreen() {
  gfx->fillScreen(RGB565_BLACK);
  drawCenteredText("JOIN", 58, 3, RGB565_CYAN);
  drawCenteredText("Scanning WiFi...", 145, 2, RGB565_YELLOW);
}

void drawJoinSetupScreen() {
  appState = STATE_JOIN_SETUP;
  gfx->fillScreen(RGB565_BLACK);

  // Join starts with WiFi selection. The IP editor is shown only after NEXT.
  drawCenteredText("JOIN", 18, 3, RGB565_CYAN);
  drawCenteredText("Select WiFi", 64, 2, RGB565_YELLOW);
  drawJoinNetworkList();

  drawButton(btnJoinBackX, btnJoinBackY, btnJoinBackW, btnJoinBackH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
  drawButton(btnJoinScanX, btnJoinScanY, btnJoinScanW, btnJoinScanH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "SCAN", 2);
  drawButton(btnJoinMoreX, btnJoinMoreY, btnJoinMoreW, btnJoinMoreH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MORE", 2);
  drawButton(btnJoinConnectX, btnJoinConnectY, btnJoinConnectW, btnJoinConnectH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "NEXT", 2);
}

void drawJoinIpScreen() {
  appState = STATE_JOIN_IP;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("JOIN", 24, 3, RGB565_CYAN);
  drawCenteredText("HOST IP", 62, 2, RGB565_YELLOW);

  drawIpFields();
  drawSettingsKeypad();

  drawButton(btnJoinIpBackX, btnJoinIpBackY, btnJoinIpBackW, btnJoinIpBackH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
  drawButton(btnJoinIpConnectX, btnJoinIpConnectY, btnJoinIpConnectW, btnJoinIpConnectH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "JOIN", 2);
}

void drawHostSetupScreen() {
  appState = STATE_HOST_SETUP;
  gfx->fillScreen(RGB565_BLACK);

  // Host starts by selecting the AP name, then confirms the IP on the next page.
  drawCenteredText("HOST", 18, 3, RGB565_GREEN);
  drawCenteredText("Select SSID", 64, 2, RGB565_YELLOW);
  drawHostSSIDList();

  drawButton(btnHostBackX, btnHostBackY, btnHostBackW, btnHostBackH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
  drawButton(btnHostMoreX, btnHostMoreY, btnHostMoreW, btnHostMoreH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MORE", 2);
  drawButton(btnHostNextX, btnHostNextY, btnHostNextW, btnHostNextH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "NEXT", 2);
}

void drawHostIpScreen() {
  appState = STATE_HOST_IP;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("HOST", 24, 3, RGB565_GREEN);
  drawCenteredText("HOST IP", 62, 2, RGB565_YELLOW);

  drawIpFields();
  drawSettingsKeypad();

  drawButton(btnHostIpBackX, btnHostIpBackY, btnHostIpBackW, btnHostIpBackH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
  drawButton(btnHostIpStartX, btnHostIpStartY, btnHostIpStartW, btnHostIpStartH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "HOST", 2);
}

void startRpsNetworkGame();

// ============================================================================
// NETWORK
// ============================================================================
// Shared WiFi setup and message helpers for network-capable games.
const char *getNetworkGameCode() {
  return (activeNetworkGame == NETWORK_GAME_RPS) ? "RPS" : "TTT";
}

void applyNetworkGameCode(const String &code) {
  if (code == "RPS") {
    activeNetworkGame = NETWORK_GAME_RPS;
  } else if (code == "TTT") {
    activeNetworkGame = NETWORK_GAME_TTT;
  }
}

String buildNetworkMessage(const char *prefix) {
  String msg = prefix;
  msg += ":";
  msg += getNetworkGameCode();
  return msg;
}

void sendNetMessage(const String &msg) {
  if (networkConnected && netClient && netClient.connected()) {
    netClient.println(msg);
  }
}

void stopNetwork() {
  if (netClient) {
    netClient.stop();
  }

  gameServer.stop();
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);

  networkConnected = false;
  isHost = false;
  myPlayer = ' ';
  myTurn = false;
}

void scanJoinNetworks() {
  // Scan once, copy unique SSIDs into joinNetworks, then release scan memory.
  joinNetworkCount = 0;
  selectedJoinNetwork = -1;
  joinNetworkListOffset = 0;

  for (int i = 0; i < MAX_JOIN_NETWORKS; i++) {
    joinNetworks[i] = "";
  }

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  int foundNetworks = WiFi.scanNetworks(false, true);

  for (int i = 0; i < foundNetworks && joinNetworkCount < MAX_JOIN_NETWORKS; i++) {
    String ssid = WiFi.SSID(i);

    if (ssid.length() == 0) continue;

    bool duplicate = false;

    for (int j = 0; j < joinNetworkCount; j++) {
      if (joinNetworks[j] == ssid) {
        duplicate = true;
        break;
      }
    }

    if (duplicate) continue;

    joinNetworks[joinNetworkCount] = ssid;

    if (ssid == AP_SSID) {
      selectedJoinNetwork = joinNetworkCount;
    }

    joinNetworkCount++;
  }

  if (selectedJoinNetwork < 0 && joinNetworkCount > 0) {
    selectedJoinNetwork = 0;
  }

  if (selectedJoinNetwork >= 0) {
    joinNetworkListOffset = (selectedJoinNetwork / MAX_JOIN_NETWORKS_VISIBLE) * MAX_JOIN_NETWORKS_VISIBLE;
  }

  WiFi.scanDelete();
}

void beginSelectedJoinConnection() {
  // Join connects to the selected AP first; checkJoinConnection() opens the TCP
  // game socket once WiFi reports WL_CONNECTED.
  if (selectedJoinNetwork < 0 || selectedJoinNetwork >= joinNetworkCount) return;

  saveNetworkSettings();

  localGame = false;
  isHost = false;
  myPlayer = (activeNetworkGame == NETWORK_GAME_RPS) ? '2' : 'O';
  myTurn = false;
  networkConnected = false;

  appState = STATE_CONNECTING_JOIN;
  drawConnectingJoinScreen();

  WiFi.mode(WIFI_STA);
  WiFi.begin(joinNetworks[selectedJoinNetwork].c_str(), JOIN_WIFI_PASS);
}

void beginHostNetwork() {
  // Host starts a softAP and TCP server. The actual game starts after a client
  // socket connects in checkHostClient().
  saveNetworkSettings();
  stopNetwork();

  localGame = false;
  isHost = true;
  myPlayer = (activeNetworkGame == NETWORK_GAME_RPS) ? '1' : 'X';
  myTurn = (activeNetworkGame == NETWORK_GAME_TTT);

  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(HOST_IP, HOST_IP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(epicSSIDList[selectedHostSSIDIndex], AP_PASS);

  gameServer.begin();

  appState = STATE_WAITING_HOST;
  drawWaitingHostScreen();
}

void startLocalGame() {
  activeNetworkGame = NETWORK_GAME_TTT;
  stopNetwork();

  localGame = true;
  resetGameLogic();

  appState = STATE_PLAYING;
  beepStart();
  drawGameScreenFull();
}

void startHostMode() {
  stopNetwork();

  localGame = false;
  isHost = false;
  myPlayer = 'X';
  myTurn = true;

  activeIpField = 0;
  activeIpFieldNeedsClear = true;
  updateIpTextFromParts();

  drawHostSetupScreen();
}

void startJoinMode() {
  stopNetwork();

  localGame = false;
  isHost = false;
  myPlayer = 'O';
  myTurn = false;

  activeIpField = 0;
  activeIpFieldNeedsClear = true;
  updateIpTextFromParts();

  drawJoinScanningScreen();
  scanJoinNetworks();
  drawJoinSetupScreen();
}

void startNetworkGame() {
  // Host and Join both call this after START/NEW messages. Branch by game type.
  localGame = false;

  if (activeNetworkGame == NETWORK_GAME_RPS) {
    startRpsNetworkGame();
    return;
  }

  resetGameLogic();

  appState = STATE_PLAYING;
  beepStart();
  drawGameScreenFull();
}

void checkHostClient() {
  // Non-blocking accept for the host screen. Once a client arrives, both devices
  // enter the same game mode.
  if (!isHost || networkConnected) return;

  WiFiClient newClient = gameServer.available();

  if (newClient) {
    netClient = newClient;
    netClient.setTimeout(10);
    networkConnected = true;

    sendNetMessage(buildNetworkMessage("START"));
    startNetworkGame();
  }
}

void checkJoinConnection() {
  // Non-blocking join progress. First wait for WiFi, then open the TCP socket.
  if (isHost || networkConnected || appState != STATE_CONNECTING_JOIN) return;

  if (WiFi.status() == WL_CONNECTED) {
    netClient.connect(HOST_IP, NET_PORT);

    if (netClient && netClient.connected()) {
      netClient.setTimeout(10);
      networkConnected = true;
    }
  }
}

// ============================================================================
// GAME ACTIONS
// ============================================================================
// Functions in this section change game state in response to validated actions.
// The touch handlers call these after they decide which button/cell was pressed.
void startRpsLocalGame() {
  activeNetworkGame = NETWORK_GAME_RPS;
  stopNetwork();
  localGame = true;
  beepStart();
  resetRpsRound();
  drawRpsChoiceScreen(1);
}

void completeRpsRoundAndShowResult() {
  // Used by both local and network RPSLS after both choices are known.
  if (appState == STATE_RPS_RESULT) return;
  if (rpsP1Choice < 0 || rpsP1Choice > 4) return;
  if (rpsP2Choice < 0 || rpsP2Choice > 4) return;

  rpsWinner = calculateRpsWinner(rpsP1Choice, rpsP2Choice);

  if (rpsWinner == 0) {
    rpsScoreDraw++;
    beepDraw();
  } else {
    if (rpsWinner == 1) {
      rpsScoreP1++;
    } else {
      rpsScoreP2++;
    }

    beepWin();
  }

  saveRpsScore();
  drawRpsResultScreen();
}

void finishRpsLocalGame() {
  completeRpsRoundAndShowResult();
}

void startRpsNetworkGame() {
  activeNetworkGame = NETWORK_GAME_RPS;
  localGame = false;
  resetRpsRound();
  beepStart();

  if (myPlayer == '2') {
    drawRpsChoiceScreen(2);
  } else {
    drawRpsChoiceScreen(1);
  }
}

bool hasLocalRpsNetworkChoice() {
  if (myPlayer == '1') return rpsP1Choice >= 0;
  if (myPlayer == '2') return rpsP2Choice >= 0;
  return false;
}

void finishRpsNetworkGameIfReady() {
  // Network RPSLS waits after the local secret choice until the remote choice
  // arrives over TCP.
  if (appState == STATE_RPS_RESULT) return;

  if (rpsP1Choice >= 0 && rpsP2Choice >= 0) {
    completeRpsRoundAndShowResult();
    return;
  }

  if (hasLocalRpsNetworkChoice()) {
    drawRpsWaitingChoiceScreen();
  }
}

void applyRemoteRpsChoice(int choice) {
  // Remote choices are stored in the opposite player slot from this device.
  if (choice < 0 || choice > 4) return;

  activeNetworkGame = NETWORK_GAME_RPS;

  if (myPlayer == '1') {
    rpsP2Choice = choice;
  } else {
    rpsP1Choice = choice;
  }

  finishRpsNetworkGameIfReady();
}

void applyLocalRpsNetworkChoice(int choice) {
  if (!networkConnected) return;
  if (choice < 0 || choice > 4) return;

  if (myPlayer == '1') {
    if (rpsP1Choice >= 0) return;
    rpsP1Choice = choice;
  } else {
    if (rpsP2Choice >= 0) return;
    rpsP2Choice = choice;
  }

  sendNetMessage("RPS_CHOICE:" + String(choice));
  finishRpsNetworkGameIfReady();
}

void resetPocketTanksRound() {
  // New local artillery round: reset controls and regenerate terrain.
  ptCurrentPlayer = 0;
  ptWinner = 0;
  ptAngle[0] = 45;
  ptAngle[1] = 45;
  ptPower[0] = 62;
  ptPower[1] = 62;
  generatePocketTanksTerrain();
}

void startPocketTanksLocalGame() {
  stopNetwork();
  localGame = true;
  resetPocketTanksRound();
  beepStart();
  drawPocketTanksGameScreen();
}

void switchPocketTanksTurn() {
  // A missed shot or terrain hit passes control to the other player.
  ptCurrentPlayer = 1 - ptCurrentPlayer;
  drawPocketTanksGameScreen();
}

void carvePocketTanksCrater(int centerX, int centerY) {
  // Explosion removes terrain by pushing the height map downward inside a circle.
  for (int x = centerX - ptExplosionRadius; x <= centerX + ptExplosionRadius; x++) {
    if (x < 0 || x >= PT_TERRAIN_W) continue;

    int dx = x - centerX;
    int depth = (int)sqrt((float)(ptExplosionRadius * ptExplosionRadius - dx * dx));
    int craterY = centerY + depth;

    if (craterY > ptTerrain[x]) {
      ptTerrain[x] = craterY;

      if (ptTerrain[x] > ptFieldBottom) {
        ptTerrain[x] = ptFieldBottom;
      }
    }
  }
}

bool pocketTanksProjectileHitsTank(int projectileX, int projectileY, int tankIndex) {
  // Circular hit test keeps collision cheap and forgiving on a small screen.
  int tankCenterX = ptTankX[tankIndex];
  int tankCenterY = getPocketTanksTankY(tankIndex) + ptTankH / 2;
  int dx = projectileX - tankCenterX;
  int dy = projectileY - tankCenterY;

  return (dx * dx + dy * dy) <= 18 * 18;
}

void explodePocketTanksAt(int x, int y) {
  carvePocketTanksCrater(x, y);
  tone(PIN_BUZZER, 900, 120);
  drawPocketTanksScene(-1, -1, true, x, y);
  delay(300);
}

void finishPocketTanksGame(int winnerIndex) {
  ptWinner = winnerIndex + 1;

  if (ptWinner == 1) {
    ptScoreP1++;
  } else {
    ptScoreP2++;
  }

  savePocketTanksScore();
  beepWin();
  drawPocketTanksResultScreen();
}

void adjustPocketTanksAngle(int delta) {
  int oldAngle = ptAngle[ptCurrentPlayer];

  ptAngle[ptCurrentPlayer] += delta;

  if (ptAngle[ptCurrentPlayer] < 5) ptAngle[ptCurrentPlayer] = 5;
  if (ptAngle[ptCurrentPlayer] > 85) ptAngle[ptCurrentPlayer] = 85;

  redrawPocketTanksTankArea(ptCurrentPlayer, oldAngle, ptAngle[ptCurrentPlayer]);
  drawPocketTanksControls();
}

void adjustPocketTanksPower(int delta) {
  ptPower[ptCurrentPlayer] += delta;

  if (ptPower[ptCurrentPlayer] < 20) ptPower[ptCurrentPlayer] = 20;
  if (ptPower[ptCurrentPlayer] > 100) ptPower[ptCurrentPlayer] = 100;

  drawPocketTanksControls();
}

void firePocketTanksShot() {
  // Simple projectile physics: initial velocity from angle/power plus gravity.
  // Rendering uses partial redraws for smooth motion.
  int shooter = ptCurrentPlayer;
  int target = 1 - shooter;
  int dir = (shooter == 0) ? 1 : -1;
  int tankY = getPocketTanksTankY(shooter);
  float angleRad = (float)ptAngle[shooter] * 0.01745329252f;
  float speed = 2.0f + (float)ptPower[shooter] * 0.15f;
  float projectileX = (float)ptTankX[shooter] + cos(angleRad) * 20.0f * (float)dir;
  float projectileY = (float)tankY - sin(angleRad) * 20.0f;
  float velocityX = cos(angleRad) * speed * (float)dir;
  float velocityY = -sin(angleRad) * speed;
  int previousX = -1;
  int previousY = -1;

  beepMove();
  drawPocketTanksGameScreen();

  for (int frame = 0; frame < 230; frame++) {
    unsigned long frameStart = millis();

    projectileX += velocityX;
    projectileY += velocityY;
    velocityY += 0.24f;

    int x = (int)(projectileX + 0.5f);
    int y = (int)(projectileY + 0.5f);

    if (x < 0 || x >= screenW || y > ptFieldBottom) {
      if (previousX >= 0 && previousY >= 0) {
        redrawPocketTanksProjectileArea(previousX, previousY);
      }

      switchPocketTanksTurn();
      return;
    }

    if (y >= 0 && pocketTanksProjectileHitsTank(x, y, target)) {
      if (previousX >= 0 && previousY >= 0) {
        redrawPocketTanksProjectileArea(previousX, previousY);
      }

      explodePocketTanksAt(x, y);
      finishPocketTanksGame(shooter);
      return;
    }

    if (y >= 0 && y >= getPocketTanksTerrainY(x)) {
      if (previousX >= 0 && previousY >= 0) {
        redrawPocketTanksProjectileArea(previousX, previousY);
      }

      explodePocketTanksAt(x, y);
      switchPocketTanksTurn();
      return;
    }

    if (y >= 0) {
      drawPocketTanksProjectileFrame(previousX, previousY, x, y);
      previousX = x;
      previousY = y;
    } else if (previousX >= 0 && previousY >= 0) {
      redrawPocketTanksProjectileArea(previousX, previousY);
      previousX = -1;
      previousY = -1;
    }

    unsigned long elapsed = millis() - frameStart;

    if (elapsed < ptProjectileFrameMs) {
      delay(ptProjectileFrameMs - elapsed);
    }
  }

  if (previousX >= 0 && previousY >= 0) {
    redrawPocketTanksProjectileArea(previousX, previousY);
  }

  switchPocketTanksTurn();
}

void finishGame(char result) {
  // Tic Tac Toe round completion and persistent score update.
  gameOver = true;
  winner = result;

  if (winner == 'X') {
    scoreX++;
    beepWin();
  } else if (winner == 'O') {
    scoreO++;
    beepWin();
  } else if (winner == 'D') {
    scoreDraw++;
    beepDraw();
  }

  saveScore();

  appState = STATE_RESULT;
  drawResultScreen();
}

void applyMove(int col, int row) {
  // Applies a Tic Tac Toe move locally. Network moves arrive through the same
  // function after being parsed from MOVE: messages.
  if (gameOver) return;
  if (col < 0 || col > 2 || row < 0 || row > 2) return;
  if (board[row][col] != ' ') return;

  char playerToPlace = currentPlayer;

  board[row][col] = playerToPlace;
  drawSingleMark(col, row, playerToPlace);
  beepMove();

  char result = checkWinner();

  if (result != ' ') {
    finishGame(result);
    return;
  }

  currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  myTurn = localGame || (currentPlayer == myPlayer);

  drawScoreBar();
}

void handleBoardTouch(int x, int y) {
  if (!localGame && !networkConnected) return;
  if (!localGame && !myTurn) return;
  if (!inBoard(x, y) || gameOver) return;

  int col = (x - boardX) / cellSize;
  int row = (y - boardY) / cellSize;

  if (row < 0 || row > 2 || col < 0 || col > 2) return;
  if (board[row][col] != ' ') return;

  if (!localGame) {
    String msg = "MOVE:" + String(col) + "," + String(row);
    sendNetMessage(msg);
  }

  applyMove(col, row);
}

void returnToMenu(bool notifyPeer) {
  // Returns to the current game's mode menu. notifyPeer is used when leaving a
  // live network game so the other device is not stranded.
  if (notifyPeer && !localGame) {
    sendNetMessage("LEAVE");
  }

  localGame = false;
  stopNetwork();

  if (activeNetworkGame == NETWORK_GAME_RPS) {
    drawRpsMenuScreen();
  } else {
    appState = STATE_MENU;
    drawMenuScreen();
  }
}

void returnToHome(bool notifyPeer) {
  if (notifyPeer && !localGame) {
    sendNetMessage("LEAVE");
  }

  localGame = false;
  stopNetwork();

  drawHomeScreen();
}

// ============================================================================
// NETWORK MESSAGES
// ============================================================================
// Text protocol over TCP. Messages are line-based and intentionally simple:
// START:<game>, NEW:<game>, MOVE:col,row, RPS_CHOICE:n, LEAVE.
void handleNetMessage(String msg) {
  msg.trim();

  if (msg == "START") {
    startNetworkGame();
    return;
  }

  if (msg.startsWith("START:")) {
    applyNetworkGameCode(msg.substring(6));
    startNetworkGame();
    return;
  }

  if (msg == "NEW") {
    startNetworkGame();
    return;
  }

  if (msg.startsWith("NEW:")) {
    applyNetworkGameCode(msg.substring(4));
    startNetworkGame();
    return;
  }

  if (msg == "LEAVE") {
    returnToMenu(false);
    return;
  }

  if (msg.startsWith("RPS_CHOICE:")) {
    activeNetworkGame = NETWORK_GAME_RPS;
    int choice = msg.substring(11).toInt();
    applyRemoteRpsChoice(choice);
    return;
  }

  if (msg.startsWith("MOVE:")) {
    if (activeNetworkGame != NETWORK_GAME_TTT) return;

    int comma = msg.indexOf(',');

    if (comma > 5) {
      int col = msg.substring(5, comma).toInt();
      int row = msg.substring(comma + 1).toInt();

      applyMove(col, row);
    }
  }
}

void pollNetwork() {
  // Called every loop. It detects disconnects and drains all complete messages.
  if (!networkConnected) return;

  if (!netClient || !netClient.connected()) {
    networkConnected = false;

    if (appState == STATE_PLAYING || appState == STATE_RESULT ||
        appState == STATE_RPS_CHOICE_P1 || appState == STATE_RPS_CHOICE_P2 ||
        appState == STATE_RPS_WAITING_CHOICE || appState == STATE_RPS_RESULT) {
      gfx->fillScreen(RGB565_BLACK);
      drawCenteredText("Conexiune pierduta", 180, 2, RGB565_RED);
      delay(1200);
      returnToMenu(false);
    }

    return;
  }

  while (netClient.available()) {
    String msg = netClient.readStringUntil('\n');
    handleNetMessage(msg);
  }
}

// ============================================================================
// TOUCH ROUTING
// ============================================================================
// Each handler belongs to one screen. handleTouch() at the end dispatches by
// appState, keeping screen-specific hitboxes local to their screen.
void handleMenuTouch(int x, int y) {
  if (inRect(x, y, btnLocalX, btnLocalY, btnLocalW, btnLocalH)) {
    activeNetworkGame = NETWORK_GAME_TTT;
    startLocalGame();
    return;
  }

  if (inRect(x, y, btnHostX, btnHostY, btnHostW, btnHostH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_TTT;
    startHostMode();
    return;
  }

  if (inRect(x, y, btnJoinX, btnJoinY, btnJoinW, btnJoinH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_TTT;
    startJoinMode();
    return;
  }

  if (inRect(x, y, btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH)) {
    beepClick();
    resetScore();
    drawMenuScreen();
    return;
  }

  if (inRect(x, y, btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH)) {
    beepClick();
    drawGamesScreen();
    return;
  }
}

void handleHomeTouch(int x, int y) {
  if (inRect(x, y, homeTouchX, homeGamesTouchY, homeTouchW, homeTouchH)) {
    beepClick();
    drawGamesScreen();
    return;
  }

  if (inRect(x, y, homeTouchX, homeSettingsTouchY, homeTouchW, homeTouchH)) {
    beepClick();
    drawSettingsScreen();
    return;
  }

  if (inRect(x, y, homeTouchX, homeExitTouchY, homeTouchW, homeTouchH)) {
    beepClick();
    stopNetwork();
    gfx->fillScreen(RGB565_BLACK);
    delay(250);
    ESP.restart();
    return;
  }
}

void handleGamesTouch(int x, int y) {
  if (inRect(x, y, btnGamesX, btnGamesTttY, btnGamesW, btnGamesH)) {
    beepClick();
    appState = STATE_MENU;
    drawMenuScreen();
    return;
  }

  if (inRect(x, y, btnGamesX, btnGamesRpsY, btnGamesW, btnGamesH)) {
    beepClick();
    drawRpsMenuScreen();
    return;
  }

  if (inRect(x, y, btnGamesX, btnGamesPocketTanksY, btnGamesW, btnGamesH)) {
    beepClick();
    drawPocketTanksMenuScreen();
    return;
  }

  if (inRect(x, y, btnGamesX, btnGamesHomeY, btnGamesW, btnGamesHomeH)) {
    beepClick();
    returnToHome(false);
    return;
  }
}

void handleEmptyGameTouch(int x, int y) {
  if (inRect(x, y, btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH)) {
    beepClick();
    drawGamesScreen();
    return;
  }
}

void handlePocketTanksMenuTouch(int x, int y) {
  if (inRect(x, y, btnLocalX, btnLocalY, btnLocalW, btnLocalH)) {
    startPocketTanksLocalGame();
    return;
  }

  if (inRect(x, y, btnHostX, btnHostY, btnHostW, btnHostH)) {
    beepClick();
    drawPocketTanksPlaceholderScreen("Tanks Wars Host");
    return;
  }

  if (inRect(x, y, btnJoinX, btnJoinY, btnJoinW, btnJoinH)) {
    beepClick();
    drawPocketTanksPlaceholderScreen("Tanks Wars Join");
    return;
  }

  if (inRect(x, y, btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH)) {
    beepClick();
    resetPocketTanksScore();
    drawPocketTanksMenuScreen();
    return;
  }

  if (inRect(x, y, btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH)) {
    beepClick();
    drawGamesScreen();
    return;
  }
}

void handlePocketTanksPlaceholderTouch(int x, int y) {
  if (inRect(x, y, btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH)) {
    beepClick();
    drawPocketTanksMenuScreen();
    return;
  }
}

void handlePocketTanksPlayingTouch(int x, int y) {
  // Tanks Wars controls are button-only for now: angle, power, fire, menu.
  if (inRect(x, y, btnPtAngleDownX, btnPtAngleDownY, btnPtControlW, btnPtControlH)) {
    beepClick();
    adjustPocketTanksAngle(-5);
    return;
  }

  if (inRect(x, y, btnPtAngleUpX, btnPtAngleUpY, btnPtControlW, btnPtControlH)) {
    beepClick();
    adjustPocketTanksAngle(5);
    return;
  }

  if (inRect(x, y, btnPtPowerDownX, btnPtPowerDownY, btnPtControlW, btnPtControlH)) {
    beepClick();
    adjustPocketTanksPower(-5);
    return;
  }

  if (inRect(x, y, btnPtPowerUpX, btnPtPowerUpY, btnPtControlW, btnPtControlH)) {
    beepClick();
    adjustPocketTanksPower(5);
    return;
  }

  if (inRect(x, y, btnPtFireX, btnPtFireY, btnPtFireW, btnPtFireH)) {
    firePocketTanksShot();
    return;
  }

  if (inRect(x, y, btnPtMenuX, btnPtMenuY, btnPtMenuW, btnPtMenuH)) {
    beepClick();
    drawPocketTanksMenuScreen();
    return;
  }
}

void handlePocketTanksResultTouch(int x, int y) {
  if (inRect(x, y, btnPlayAgainX, btnPlayAgainY, btnPlayAgainW, btnPlayAgainH)) {
    startPocketTanksLocalGame();
    return;
  }

  if (inRect(x, y, btnResultMenuX, btnResultMenuY, btnResultMenuW, btnResultMenuH)) {
    beepClick();
    drawPocketTanksMenuScreen();
    return;
  }
}

void handleRpsMenuTouch(int x, int y) {
  if (inRect(x, y, btnLocalX, btnLocalY, btnLocalW, btnLocalH)) {
    startRpsLocalGame();
    return;
  }

  if (inRect(x, y, btnHostX, btnHostY, btnHostW, btnHostH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_RPS;
    startHostMode();
    return;
  }

  if (inRect(x, y, btnJoinX, btnJoinY, btnJoinW, btnJoinH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_RPS;
    startJoinMode();
    return;
  }

  if (inRect(x, y, btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH)) {
    beepClick();
    resetRpsScore();
    drawRpsMenuScreen();
    return;
  }

  if (inRect(x, y, btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH)) {
    beepClick();
    drawGamesScreen();
    return;
  }
}

void handleRpsChoiceTouch(int x, int y) {
  // The RPSLS wheel is drawn as an image, but the five touch areas are computed
  // from the same wheel geometry.
  if (inRect(x, y, btnRpsMenuX, btnRpsMenuY, btnRpsMenuW, btnRpsMenuH)) {
    beepClick();
    if (localGame) {
      drawRpsMenuScreen();
    } else {
      returnToMenu(true);
    }
    return;
  }

  int choice = rpsChoiceFromTouch(x, y);
  if (choice < 0) return;

  beepMove();

  if (!localGame) {
    applyLocalRpsNetworkChoice(choice);
    return;
  }

  if (appState == STATE_RPS_CHOICE_P1) {
    rpsP1Choice = choice;
    drawRpsChoiceScreen(2);
    return;
  }

  rpsP2Choice = choice;
  finishRpsLocalGame();
}

void handleRpsWaitingChoiceTouch(int x, int y) {
  if (inRect(x, y, btnRpsMenuX, btnRpsMenuY, btnRpsMenuW, btnRpsMenuH)) {
    beepClick();
    returnToMenu(true);
    return;
  }
}

void handleRpsResultTouch(int x, int y) {
  if (inRect(x, y, btnPlayAgainX, btnPlayAgainY, btnPlayAgainW, btnPlayAgainH)) {
    if (localGame) {
      startRpsLocalGame();
    } else {
      beepStart();
      sendNetMessage(buildNetworkMessage("NEW"));
      startNetworkGame();
    }
    return;
  }

  if (inRect(x, y, btnResultMenuX, btnResultMenuY, btnResultMenuW, btnResultMenuH)) {
    beepClick();
    if (localGame) {
      drawRpsMenuScreen();
    } else {
      returnToMenu(true);
    }
    return;
  }
}

void handleRpsPlaceholderTouch(int x, int y) {
  if (inRect(x, y, btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH)) {
    beepClick();
    drawRpsMenuScreen();
    return;
  }
}

void appendDigitToActiveIpField(int digit) {
  if (activeIpField < 0 || activeIpField > 3) return;

  if (activeIpFieldNeedsClear) {
    ipFieldText[activeIpField][0] = '\0';
    activeIpFieldNeedsClear = false;
  }

  size_t len = strlen(ipFieldText[activeIpField]);

  if (len >= 3) return;

  ipFieldText[activeIpField][len] = (char)('0' + digit);
  ipFieldText[activeIpField][len + 1] = '\0';
}

void deleteDigitFromActiveIpField() {
  if (activeIpField < 0 || activeIpField > 3) return;

  if (activeIpFieldNeedsClear) {
    ipFieldText[activeIpField][0] = '\0';
    activeIpFieldNeedsClear = false;
    return;
  }

  size_t len = strlen(ipFieldText[activeIpField]);

  if (len > 0) {
    ipFieldText[activeIpField][len - 1] = '\0';
  }
}

void selectNextIpField() {
  activeIpField = (activeIpField + 1) % 4;
  activeIpFieldNeedsClear = true;
}

void handleIpKeypadAction(int keyIndex) {
  if (keyIndex == 9) {
    deleteDigitFromActiveIpField();
  } else if (keyIndex == 11) {
    selectNextIpField();
  } else {
    int digit = (keyIndex == 10) ? 0 : (keyIndex + 1);
    appendDigitToActiveIpField(digit);
  }
}

void handleSettingsTouch(int x, int y) {
  // Settings uses the shared IP keypad and persists immediately on SAVE/HOME.
  for (int i = 0; i < 4; i++) {
    int fieldX = settingsFieldX + i * (settingsFieldW + settingsFieldGap);

    if (inRect(x, y, fieldX, settingsFieldY, settingsFieldW, settingsFieldH)) {
      beepClick();
      activeIpField = i;
      activeIpFieldNeedsClear = true;
      drawIpFields();
      return;
    }
  }

  for (int i = 0; i < 12; i++) {
    int col = i % 3;
    int row = i / 3;
    int keyX = keyPadX + col * (keyPadW + keyPadGapX);
    int keyY = keyPadY + row * (keyPadH + keyPadGapY);

    if (!inRect(x, y, keyX, keyY, keyPadW, keyPadH)) continue;

    beepClick();

    handleIpKeypadAction(i);

    drawIpFields();
    return;
  }

  if (inRect(x, y, btnSettingsSaveX, btnSettingsSaveY, btnSettingsSaveW, btnSettingsSaveH)) {
    beepClick();
    saveNetworkSettings();
    activeIpFieldNeedsClear = true;
    drawSettingsScreen();
    return;
  }

  if (inRect(x, y, btnSettingsHomeX, btnSettingsHomeY, btnSettingsHomeW, btnSettingsHomeH)) {
    beepClick();
    saveNetworkSettings();
    drawHomeScreen();
    return;
  }
}

void handleJoinSetupTouch(int x, int y) {
  // Join page 1: select a WiFi network, rescan, page through results, or go NEXT.
  for (int i = 0; i < MAX_JOIN_NETWORKS_VISIBLE; i++) {
    int networkIndex = joinNetworkListOffset + i;
    int networkY = joinNetworkY + i * (joinNetworkH + joinNetworkGap);

    if (networkIndex >= joinNetworkCount) continue;

    if (inRect(x, y, joinNetworkX, networkY, joinNetworkW, joinNetworkH)) {
      beepClick();
      selectedJoinNetwork = networkIndex;
      drawJoinNetworkList();
      return;
    }
  }

  if (inRect(x, y, btnJoinBackX, btnJoinBackY, btnJoinBackW, btnJoinBackH)) {
    beepClick();
    returnToMenu(false);
    return;
  }

  if (inRect(x, y, btnJoinScanX, btnJoinScanY, btnJoinScanW, btnJoinScanH)) {
    beepClick();
    drawJoinScanningScreen();
    scanJoinNetworks();
    drawJoinSetupScreen();
    return;
  }

  if (inRect(x, y, btnJoinMoreX, btnJoinMoreY, btnJoinMoreW, btnJoinMoreH)) {
    beepClick();

    if (joinNetworkCount > MAX_JOIN_NETWORKS_VISIBLE) {
      joinNetworkListOffset += MAX_JOIN_NETWORKS_VISIBLE;

      if (joinNetworkListOffset >= joinNetworkCount) {
        joinNetworkListOffset = 0;
      }
    }

    drawJoinSetupScreen();
    return;
  }

  if (inRect(x, y, btnJoinConnectX, btnJoinConnectY, btnJoinConnectW, btnJoinConnectH)) {
    if (selectedJoinNetwork >= 0 && selectedJoinNetwork < joinNetworkCount) {
      beepClick();
      activeIpField = 0;
      activeIpFieldNeedsClear = true;
      updateIpTextFromParts();
      drawJoinIpScreen();
    } else {
      beepClick();
      drawJoinSetupScreen();
    }
    return;
  }
}

void handleJoinIpTouch(int x, int y) {
  // Join page 2: confirm/edit Host IP before opening the connection.
  for (int i = 0; i < 4; i++) {
    int fieldX = settingsFieldX + i * (settingsFieldW + settingsFieldGap);

    if (inRect(x, y, fieldX, settingsFieldY, settingsFieldW, settingsFieldH)) {
      beepClick();
      activeIpField = i;
      activeIpFieldNeedsClear = true;
      drawIpFields();
      return;
    }
  }

  for (int i = 0; i < 12; i++) {
    int col = i % 3;
    int row = i / 3;
    int keyX = keyPadX + col * (keyPadW + keyPadGapX);
    int keyY = keyPadY + row * (keyPadH + keyPadGapY);

    if (!inRect(x, y, keyX, keyY, keyPadW, keyPadH)) continue;

    beepClick();
    handleIpKeypadAction(i);
    drawIpFields();
    return;
  }

  if (inRect(x, y, btnJoinIpBackX, btnJoinIpBackY, btnJoinIpBackW, btnJoinIpBackH)) {
    beepClick();
    drawJoinSetupScreen();
    return;
  }

  if (inRect(x, y, btnJoinIpConnectX, btnJoinIpConnectY, btnJoinIpConnectW, btnJoinIpConnectH)) {
    beepStart();
    beginSelectedJoinConnection();
    return;
  }
}

void handleHostSetupTouch(int x, int y) {
  // Host page 1: select the softAP SSID from the curated list.
  for (int i = 0; i < MAX_HOST_SSID_VISIBLE; i++) {
    int ssidIndex = hostSSIDListOffset + i;
    int ssidY = hostSSIDY + i * (hostSSIDH + hostSSIDGap);

    if (ssidIndex >= EPIC_SSID_COUNT) continue;

    if (inRect(x, y, hostSSIDX, ssidY, hostSSIDW, hostSSIDH)) {
      beepClick();
      selectedHostSSIDIndex = ssidIndex;
      drawHostSSIDList();
      return;
    }
  }

  if (inRect(x, y, btnHostBackX, btnHostBackY, btnHostBackW, btnHostBackH)) {
    beepClick();
    returnToMenu(false);
    return;
  }

  if (inRect(x, y, btnHostMoreX, btnHostMoreY, btnHostMoreW, btnHostMoreH)) {
    beepClick();
    hostSSIDListOffset += MAX_HOST_SSID_VISIBLE;

    if (hostSSIDListOffset >= EPIC_SSID_COUNT) {
      hostSSIDListOffset = 0;
    }

    drawHostSetupScreen();
    return;
  }

  if (inRect(x, y, btnHostNextX, btnHostNextY, btnHostNextW, btnHostNextH)) {
    beepClick();
    activeIpField = 0;
    activeIpFieldNeedsClear = true;
    updateIpTextFromParts();
    drawHostIpScreen();
    return;
  }
}

void handleHostIpTouch(int x, int y) {
  // Host page 2: confirm/edit Host IP before starting softAP mode.
  for (int i = 0; i < 4; i++) {
    int fieldX = settingsFieldX + i * (settingsFieldW + settingsFieldGap);

    if (inRect(x, y, fieldX, settingsFieldY, settingsFieldW, settingsFieldH)) {
      beepClick();
      activeIpField = i;
      activeIpFieldNeedsClear = true;
      drawIpFields();
      return;
    }
  }

  for (int i = 0; i < 12; i++) {
    int col = i % 3;
    int row = i / 3;
    int keyX = keyPadX + col * (keyPadW + keyPadGapX);
    int keyY = keyPadY + row * (keyPadH + keyPadGapY);

    if (!inRect(x, y, keyX, keyY, keyPadW, keyPadH)) continue;

    beepClick();
    handleIpKeypadAction(i);
    drawIpFields();
    return;
  }

  if (inRect(x, y, btnHostIpBackX, btnHostIpBackY, btnHostIpBackW, btnHostIpBackH)) {
    beepClick();
    drawHostSetupScreen();
    return;
  }

  if (inRect(x, y, btnHostIpStartX, btnHostIpStartY, btnHostIpStartW, btnHostIpStartH)) {
    beepStart();
    beginHostNetwork();
    return;
  }
}

void handleWaitingTouch(int x, int y) {
  if (inRect(x, y, btnMenuX, btnMenuY, btnMenuW, btnMenuH)) {
    beepClick();
    returnToMenu(false);
  }
}

void handlePlayingTouch(int x, int y) {
  if (inRect(x, y, btnMenuX, btnMenuY, btnMenuW, btnMenuH)) {
    beepClick();
    returnToMenu(true);
    return;
  }

  handleBoardTouch(x, y);
}

void handleResultTouch(int x, int y) {
  if (inRect(x, y, btnPlayAgainX, btnPlayAgainY, btnPlayAgainW, btnPlayAgainH)) {
    if (localGame) {
      startLocalGame();
    } else {
      beepStart();
      sendNetMessage(buildNetworkMessage("NEW"));
      startNetworkGame();
    }

    return;
  }

  if (inRect(x, y, btnResultMenuX, btnResultMenuY, btnResultMenuW, btnResultMenuH)) {
    beepClick();
    returnToMenu(true);
    return;
  }
}

void handleTouch(int x, int y) {
  // Central dispatcher. It should be the only place that decides which screen
  // handler receives a touch.
  if (appState == STATE_HOME) {
    handleHomeTouch(x, y);
  } else if (appState == STATE_GAMES) {
    handleGamesTouch(x, y);
  } else if (appState == STATE_ROCK_PAPER_SCISSORS) {
    handleRpsMenuTouch(x, y);
  } else if (appState == STATE_RPS_CHOICE_P1 || appState == STATE_RPS_CHOICE_P2) {
    handleRpsChoiceTouch(x, y);
  } else if (appState == STATE_RPS_WAITING_CHOICE) {
    handleRpsWaitingChoiceTouch(x, y);
  } else if (appState == STATE_RPS_RESULT) {
    handleRpsResultTouch(x, y);
  } else if (appState == STATE_RPS_PLACEHOLDER) {
    handleRpsPlaceholderTouch(x, y);
  } else if (appState == STATE_POCKET_TANKS) {
    handlePocketTanksMenuTouch(x, y);
  } else if (appState == STATE_PT_PLAYING) {
    handlePocketTanksPlayingTouch(x, y);
  } else if (appState == STATE_PT_RESULT) {
    handlePocketTanksResultTouch(x, y);
  } else if (appState == STATE_PT_PLACEHOLDER) {
    handlePocketTanksPlaceholderTouch(x, y);
  } else if (appState == STATE_EMPTY_GAME) {
    handleEmptyGameTouch(x, y);
  } else if (appState == STATE_MENU) {
    handleMenuTouch(x, y);
  } else if (appState == STATE_SETTINGS) {
    handleSettingsTouch(x, y);
  } else if (appState == STATE_HOST_SETUP) {
    handleHostSetupTouch(x, y);
  } else if (appState == STATE_HOST_IP) {
    handleHostIpTouch(x, y);
  } else if (appState == STATE_JOIN_SETUP) {
    handleJoinSetupTouch(x, y);
  } else if (appState == STATE_JOIN_IP) {
    handleJoinIpTouch(x, y);
  } else if (appState == STATE_WAITING_HOST || appState == STATE_CONNECTING_JOIN) {
    handleWaitingTouch(x, y);
  } else if (appState == STATE_PLAYING) {
    handlePlayingTouch(x, y);
  } else if (appState == STATE_RESULT) {
    handleResultTouch(x, y);
  }
}

// ============================================================================
// SETUP / LOOP
// ============================================================================
// setup() initializes hardware/resources once. loop() keeps networking and touch
// input responsive with short, non-blocking polling.
void setup() {
  Serial.begin(115200);
  delay(1000);
  randomSeed(esp_random());

  pinMode(PIN_BUZZER, OUTPUT);

  pinMode(PIN_LCD_RST, OUTPUT);
  digitalWrite(PIN_LCD_RST, HIGH);
  delay(100);
  digitalWrite(PIN_LCD_RST, LOW);
  delay(100);
  digitalWrite(PIN_LCD_RST, HIGH);
  delay(200);

  pinMode(PIN_TP_INT, INPUT_PULLUP);
  pinMode(PIN_TP_RST, OUTPUT);
  digitalWrite(PIN_TP_RST, LOW);
  delay(20);
  digitalWrite(PIN_TP_RST, HIGH);
  delay(200);

  Wire.begin(PIN_SDA, PIN_SCL);
  Wire.setClock(400000);

  if (!gfx->begin()) {
    Serial.println("Error: GFX initialization failed!");
    while (1) delay(100);
  }

  gfx->invertDisplay(INVERT_DISPLAY_COLORS);
  gfx->setRotation(0);
  gfx->fillScreen(RGB565_BLACK);

  pinMode(PIN_LCD_CS, OUTPUT);
  digitalWrite(PIN_LCD_CS, HIGH);

  pinMode(PIN_SD_CS, OUTPUT);
  digitalWrite(PIN_SD_CS, HIGH);

  SPI.begin(PIN_LCD_SCLK, PIN_LCD_MISO, PIN_LCD_MOSI, -1);

  if (!SD.begin(PIN_SD_CS, SPI, SD_SPI_FREQ)) {
    Serial.println("Error: microSD initialization failed.");
    sdReady = false;
  } else {
    Serial.println("microSD OK");
    sdReady = true;

    if (SD.exists("/intro/frame_000.raw")) {
      playBootIntro();
    } else {
      Serial.println("Missing /intro/frame_000.raw");
    }
  }

  loadScore();
  loadRpsScore();
  loadPocketTanksScore();
  loadNetworkSettings();
  clearBoard();
  WiFi.mode(WIFI_OFF);

  drawHomeScreen();
}

void loop() {
  checkHostClient();
  checkJoinConnection();
  pollNetwork();

  int tx, ty;
  bool touched = readTouchScreen(tx, ty);

  if (touched && !touchWasDown) {
    unsigned long now = millis();

    if (now - lastTouchTime > touchDebounceMs) {
      lastTouchTime = now;
      touchWasDown = true;

      Serial.print("Touch: ");
      Serial.print(tx);
      Serial.print(", ");
      Serial.println(ty);

      handleTouch(tx, ty);
    }
  }

  if (!touched) {
    touchWasDown = false;
  }

  delay(10);
}
