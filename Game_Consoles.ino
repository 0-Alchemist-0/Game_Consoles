// ============================================================================
// CHANGELOG
// ============================================================================
// Version 9.0 - 2026-07-01 11:34 - Added Reset Score buttons and high-score
// display lines to every game main menu, with persistent high scores for
// Breakout, Pong, and Snake.
// Version 8.9 - 2026-07-01 10:56 - Converted remaining menu and page UI text
// to English across Tic Tac Toe, shared network screens, and result screens.
// Version 8.8 - 2026-07-01 10:01 - Reworked Home Settings into Music and WiFi
// subpages, with Music ON/OFF, SFX ON/OFF, editable Host IP, and persisted
// default WiFi SSID selection.
// Version 8.7 - 2026-07-01 09:49 - Added a looping non-game background
// chiptune inspired by the attached arcade melody, with automatic mute during
// gameplay and short audio cues taking priority.
// Version 8.6 - 2026-06-19 07:21 - Switched Frogger Host/Join to use the standard
// WiFi TCP flow (same as Tic Tac Toe) instead of ESP-NOW.  Both players run
// traffic locally, exchange frog-state/goal/over messages over TCP, and the
// FROG_STATE parsing is now symmetric so both host and join apply remote state.
// Version 8.5 - 2026-06-18 14:50 - Reworked Frogger Host/Join to use the
// attached ESP-NOW peer-to-peer concept with local frog simulation, HELLO/ACK/
// START pairing, and compact frog, goal, and game-over packets.
// Version 8.4 - 2026-06-18 14:34 - Reworked Frogger network gameplay using the
// attached local-simulation model: each console moves its own frog and exchanges
// compact frog states over the existing TCP link.
// Version 8.3 - 2026-06-18 14:14 - Reverted Frogger JOIN local lane animation
// changes after they broke second-console gameplay.
// Version 8.2 - 2026-06-18 14:08 - Prevented Frogger JOIN lane position jumps
// by using remote lane coordinates only during full redraw synchronization.
// Version 8.1 - 2026-06-18 14:06 - Reduced Frogger JOIN flicker by animating
// lanes locally and using remote states only for sync plus player redraws.
// Version 8.0 - 2026-06-18 13:51 - Reduced Frogger network state backlog and
// added input sequence tracking so P2 movement is not overwritten by old states.
// Version 7.9 - 2026-06-18 13:34 - Fixed Frogger network controls by forcing
// P1/P2 player roles, immediate network respawn, and lighter remote input redraws.
// Version 7.8 - 2026-06-18 13:28 - Fixed Frogger network movement feedback by
// redrawing player inputs immediately and moving the first road car off-center.
// Version 7.7 - 2026-06-18 13:22 - Fixed the Frogger network compile error by
// declaring sendFroggerState before updateFroggerGame uses it.
// Version 7.6 - 2026-06-18 13:08 - Added host-authoritative Frogger network
// gameplay with two visible colored players sharing the same lanes and logs.
// Version 7.5 - 2026-06-18 12:29 - Added Frogger to the Games menu with a
// dedicated mode menu and local playable road, river, logs, cars, goals, and
// high score gameplay.
// Version 7.4 - 2026-06-18 10:41 - Added host-authoritative Ranch Rush network
// gameplay with two visible differently colored players and synced ranch state.
// Version 7.3 - 2026-06-18 10:26 - Fixed Ranch Rush lasso persistence by using
// a gameplay cowboy sprite without the decorative menu lasso loop.
// Version 7.2 - 2026-06-18 10:15 - Implemented local Ranch Rush gameplay with
// lane movement, lasso catching, animal spawning, lives, levels, high score,
// dirty-rect rendering, restart, and menu return.
// Version 7.1 - 2026-06-18 10:07 - Added Ranch Rush to the Games menu with a
// ranch-themed mode menu, Local/Host/Join/Back navigation, and shared network
// setup placeholders.
// Version 7.0 - 2026-06-18 09:27 - Added network Snake gameplay with
// host-authoritative two-player movement, synced state packets, shared food,
// different snake colors, and remote direction control.
// Version 6.9 - 2026-06-18 08:18 - Reduced Snake movement flicker by switching
// from full-board redraws to incremental cell updates during movement.
// Version 6.8 - 2026-06-18 08:06 - Implemented local Snake gameplay with a
// timed grid loop, food spawning, collision detection, score HUD, touch
// direction controls, restart, and menu return.
// Version 6.7 - 2026-06-18 07:46 - Added Snake to the Games menu with a
// dedicated Local, Host, Join, and Back mode menu wired into the shared
// network setup flow.
// Version 6.6 - 2026-06-18 07:11 - Improved network Pong Player 2 paddle
// collision by preserving client-owned paddle state, adding remote-paddle hit
// forgiveness, and predicting local bounce.
// Version 6.5 - 2026-06-17 23:14 - Smoothed network Pong ball movement by
// sending velocity in PN_STATE, throttling host broadcasts, and predicting
// ball motion locally between received state packets.
// Version 6.4 - 2026-06-17 22:44 - Added Host/Join network gameplay for
// Pong with host-authoritative ball physics and synced paddle/score state.
// Version 6.3 - 2026-06-17 22:28 - Added Pong to the Games menu with a
// local playable portrait paddle game and arcade-style menu.
// Version 6.2 - 2026-06-17 22:07 - Added Host/Join network gameplay for
// Breakout where the first player to lose all three lives loses the match.
// Version 6.1 - 2026-06-17 21:59 - Matched Breakout menu buttons to the
// Tic Tac Toe transparent arcade text style by removing extra slot panels.
// Version 6.0 - 2026-06-17 21:42 - Added a generated arcade fallback
// background for the Breakout menu and switched its menu buttons to the
// transparent Tic Tac Toe arcade text style.
// Version 5.9 - 2026-06-17 20:37 - Implemented local portrait Breakout
// gameplay with bricks, paddle, touch controls, lives, score, and restart.
// Version 5.8 - 2026-06-17 20:15 - Added a generated arcade fallback
// background for the Tanks Wars menu and switched its menu buttons to the
// transparent Tic Tac Toe arcade text style.
// Version 5.7 - 2026-06-17 20:09 - Added a second Games page with Breakout and
// a Breakout mode menu containing Local, Host, Join, and Back.
// Version 5.6 - 2026-06-17 19:30 - Added Host/Join network gameplay for Tanks
// Wars with synced terrain seed, controls, turns, and firing.
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
#include <string.h>
#include <esp_now.h>
#include <esp_wifi.h>
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
const char *APP_VERSION_TEXT = "Version 9.0";
const char *APP_BUILD_ID_TEXT = "Build ID GC-V90-2026070111";



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
bool musicEnabled = true;
bool sfxEnabled = true;

// ============================================================================
// APP STATE
// ============================================================================
// Every screen has one AppState so the touch router can dispatch input to the
// correct handler without guessing from what was last drawn.
enum AppState {
  STATE_HOME,
  STATE_GAMES,
  STATE_GAMES_MORE,
  STATE_GAMES_EXTRA,
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
  STATE_BREAKOUT,
  STATE_BREAKOUT_PLAYING,
  STATE_BREAKOUT_PLACEHOLDER,
  STATE_PONG,
  STATE_PONG_PLAYING,
  STATE_PONG_PLACEHOLDER,
  STATE_SNAKE,
  STATE_SNAKE_PLAYING,
  STATE_SNAKE_PLACEHOLDER,
  STATE_RANCH_RUSH,
  STATE_RR_PLAYING,
  STATE_RR_PLACEHOLDER,
  STATE_FROGGER,
  STATE_FROGGER_PLAYING,
  STATE_FROGGER_PLACEHOLDER,
  STATE_EMPTY_GAME,
  STATE_MENU,
  STATE_SETTINGS,
  STATE_SETTINGS_MUSIC,
  STATE_SETTINGS_WIFI,
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
  NETWORK_GAME_RPS,
  NETWORK_GAME_PT,
  NETWORK_GAME_BREAKOUT,
  NETWORK_GAME_PONG,
  NETWORK_GAME_SNAKE,
  NETWORK_GAME_RANCH_RUSH,
  NETWORK_GAME_FROGGER
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
unsigned long ptNetworkSeed = 1;
const char *ptPlaceholderTitle = "Tanks Wars";

// Breakout is implemented in portrait mode for the current 320x480 setup.
// The bottom strip is reserved for touch controls, keeping gameplay above it.
static const int BREAKOUT_SCREEN_W = 320;
static const int BREAKOUT_SCREEN_H = 480;
static const int BREAKOUT_HUD_H = 34;
static const int BREAKOUT_PLAY_BOTTOM = 396;
static const int BREAKOUT_BRICK_COLS = 8;
static const int BREAKOUT_BRICK_ROWS = 6;
static const int BREAKOUT_BRICK_W = 34;
static const int BREAKOUT_BRICK_H = 16;
static const int BREAKOUT_BRICK_GAP = 3;
static const int BREAKOUT_BRICK_X0 = 20;
static const int BREAKOUT_BRICK_Y0 = 54;
static const int BREAKOUT_BALL_R = 4;
static const int BREAKOUT_PADDLE_W = 72;
static const int BREAKOUT_PADDLE_H = 10;
static const int BREAKOUT_PADDLE_Y = 360;
static const int BREAKOUT_PADDLE_SPEED = 8;
static const unsigned long BREAKOUT_FRAME_MS = 20;

const int btnBreakoutLeftX = 18;
const int btnBreakoutLeftY = 410;
const int btnBreakoutLeftW = 88;
const int btnBreakoutLeftH = 52;

const int btnBreakoutRightX = 214;
const int btnBreakoutRightY = 410;
const int btnBreakoutRightW = 88;
const int btnBreakoutRightH = 52;

const int btnBreakoutMenuX = 116;
const int btnBreakoutMenuY = 422;
const int btnBreakoutMenuW = 88;
const int btnBreakoutMenuH = 36;

bool breakoutBricks[BREAKOUT_BRICK_ROWS][BREAKOUT_BRICK_COLS];
float breakoutBallX = 0.0;
float breakoutBallY = 0.0;
float breakoutBallVX = 0.0;
float breakoutBallVY = 0.0;
int breakoutOldBallX = -1;
int breakoutOldBallY = -1;
int breakoutPaddleX = 0;
int breakoutOldPaddleX = -1;
int breakoutScore = 0;
uint32_t breakoutHiScore = 0;
int breakoutLives = 3;
bool breakoutGameOver = false;
bool breakoutWin = false;
bool breakoutNetworkLossSent = false;
bool breakoutTouchDown = false;
int breakoutTouchX = -1;
int breakoutTouchY = -1;
unsigned long breakoutLastFrame = 0;

// Pong local mode uses a bottom player paddle and a simple CPU paddle at the
// top of the portrait court. First side to five points wins the match.
static const int PONG_HUD_H = 34;
static const int PONG_PLAY_TOP = 40;
static const int PONG_PLAY_BOTTOM = 396;
static const int PONG_PADDLE_W = 76;
static const int PONG_PADDLE_H = 9;
static const int PONG_PLAYER_Y = 356;
static const int PONG_CPU_Y = 58;
static const int PONG_BALL_R = 4;
static const int PONG_SCORE_LIMIT = 5;
static const int PONG_PLAYER_SPEED = 9;
static const int PONG_CPU_SPEED = 5;
static const int PONG_REMOTE_HIT_MARGIN = 14;
static const unsigned long PONG_FRAME_MS = 20;
static const unsigned long PONG_NET_STATE_MS = 33;

const int btnPongLeftX = 18;
const int btnPongLeftY = 410;
const int btnPongLeftW = 88;
const int btnPongLeftH = 52;

const int btnPongRightX = 214;
const int btnPongRightY = 410;
const int btnPongRightW = 88;
const int btnPongRightH = 52;

const int btnPongMenuX = 116;
const int btnPongMenuY = 422;
const int btnPongMenuW = 88;
const int btnPongMenuH = 36;

float pongBallX = 0.0;
float pongBallY = 0.0;
float pongBallVX = 0.0;
float pongBallVY = 0.0;
int pongOldBallX = -1;
int pongOldBallY = -1;
int pongPlayerX = 0;
int pongCpuX = 0;
int pongOldPlayerX = -1;
int pongOldCpuX = -1;
int pongPlayerScore = 0;
int pongCpuScore = 0;
int pongWinsP1 = 0;
int pongWinsP2 = 0;
int pongWinner = 0;
bool pongGameOver = false;
bool pongPlayerWon = false;
bool pongTouchDown = false;
int pongTouchX = -1;
int pongTouchY = -1;
unsigned long pongLastFrame = 0;
int pongLastSentPaddleX = -1;
unsigned long pongLastStateSendTime = 0;

// Snake uses a 20 x 22 grid in the upper play area and a simple directional pad
// in the bottom strip. Network mode is host-authoritative with two visible
// snakes and a shared food item.
static const int SNAKE_GRID_COLS = 20;
static const int SNAKE_GRID_ROWS = 22;
static const int SNAKE_CELL = 14;
static const int SNAKE_BOARD_X = 20;
static const int SNAKE_BOARD_Y = 50;
static const int SNAKE_MAX_LEN = SNAKE_GRID_COLS * SNAKE_GRID_ROWS;
static const unsigned long SNAKE_FRAME_MS = 145;

static const int SNAKE_DIR_UP = 0;
static const int SNAKE_DIR_RIGHT = 1;
static const int SNAKE_DIR_DOWN = 2;
static const int SNAKE_DIR_LEFT = 3;

const int btnSnakeMenuX = 230;
const int btnSnakeMenuY = 6;
const int btnSnakeMenuW = 78;
const int btnSnakeMenuH = 28;

const int btnSnakeUpX = 124;
const int btnSnakeUpY = 365;
const int btnSnakeDirW = 72;
const int btnSnakeDirH = 42;
const int btnSnakeLeftX = 36;
const int btnSnakeLeftY = 412;
const int btnSnakeDownX = 124;
const int btnSnakeDownY = 412;
const int btnSnakeRightX = 212;
const int btnSnakeRightY = 412;

int snakeX[SNAKE_MAX_LEN];
int snakeY[SNAKE_MAX_LEN];
int snakeLength = 0;
int snakeDir = SNAKE_DIR_RIGHT;
int snakeNextDir = SNAKE_DIR_RIGHT;
int snakeFoodX = 0;
int snakeFoodY = 0;
int snakeScore = 0;
uint32_t snakeHiScore = 0;
bool snakeGameOver = false;
unsigned long snakeLastFrame = 0;

int snakeNetX[2][SNAKE_MAX_LEN];
int snakeNetY[2][SNAKE_MAX_LEN];
int snakeNetLength[2] = {0, 0};
int snakeNetDir[2] = {SNAKE_DIR_RIGHT, SNAKE_DIR_LEFT};
int snakeNetNextDir[2] = {SNAKE_DIR_RIGHT, SNAKE_DIR_LEFT};
int snakeNetScore[2] = {0, 0};
bool snakeNetAlive[2] = {false, false};
bool snakeNetGameOver = false;
int snakeNetWinner = 0;
uint8_t snakeDrawOwner[SNAKE_MAX_LEN];
uint8_t snakeDrawHead[SNAKE_MAX_LEN];
int snakeDrawFoodCell = -1;
bool snakeDrawReady = false;

// Ranch Rush local gameplay is a lane-based lasso game ported from the
// standalone sketch into this multi-game console shell.
static const int RR_LANES = 5;
static const int RR_MAX_ANIMALS = 10;
static const int RR_FRAME_MS = 33;
static const unsigned long RR_NET_STATE_MS = 33;
static const int RR_HUD_H = 50;
static const int RR_FIELD_TOP = 60;
static const int RR_FIELD_BOT = 400;
static const int RR_BTN_AREA_TOP = 410;
static const int RR_LANE_SPACING = 60;
static const int RR_LANE_START_Y = RR_FIELD_TOP + 35;

const int btnRrMenuX = 250;
const int btnRrMenuY = 7;
const int btnRrMenuW = 62;
const int btnRrMenuH = 30;

struct RanchAnimal {
  float x;
  int lane;
  float speed;
  bool active;
  uint8_t type;
};

struct RanchPrevAnimal {
  int x;
  int y;
  bool wasActive;
};

int rrLaneY[RR_LANES];
RanchAnimal rrAnimals[RR_MAX_ANIMALS];
RanchPrevAnimal rrPrevAnimals[RR_MAX_ANIMALS];
int rrPlayerLane = 2;
int rrPrevPlayerLane = -1;
int rrPlayerX = 45;
int rrScore = 0;
uint32_t rrHiScore = 0;
int rrLives = 3;
int rrLevel = 1;
bool rrLassoActive = false;
float rrLassoX = 0.0f;
int rrLassoLane = 0;
unsigned long rrLassoStart = 0;
float rrPrevLassoX = 0.0f;
int rrPrevLassoLane = -1;
bool rrPrevLassoActive = false;
unsigned long rrLastSpawn = 0;
unsigned long rrLastFrame = 0;
bool rrGameOver = false;
const int rrNetPlayerX[2] = {45, 96};
int rrNetPlayerLane[2] = {2, 2};
int rrNetPrevPlayerLane[2] = {-1, -1};
int rrNetScore[2] = {0, 0};
int rrNetLives[2] = {3, 3};
bool rrNetLassoActive[2] = {false, false};
float rrNetLassoX[2] = {0.0f, 0.0f};
int rrNetLassoLane[2] = {0, 0};
unsigned long rrNetLassoStart[2] = {0, 0};
float rrNetPrevLassoX[2] = {0.0f, 0.0f};
int rrNetPrevLassoLane[2] = {-1, -1};
bool rrNetPrevLassoActive[2] = {false, false};
bool rrNetGameOver = false;
int rrNetWinner = 0;
bool rrRanchSceneReady = false;
unsigned long rrLastStateSendTime = 0;

// Frogger local gameplay: cross three road lanes, ride logs through three
// water lanes, and fill all five goals to advance to the next level.
static const int FROG_ROWS = 9;
static const int FROG_LANES = 6;
static const int FROG_MAX_OBJECTS = 4;
static const int FROG_GOALS = 5;
static const int FROG_HUD_H = 46;
static const int FROG_FIELD_TOP = 48;
static const int FROG_LANE_H = 38;
static const int FROG_BTN_TOP = FROG_FIELD_TOP + FROG_ROWS * FROG_LANE_H + 2;
static const int FROG_W = 26;
static const int FROG_H = 26;
static const int FROG_STEP_X = 32;
static const unsigned long FROG_FRAME_MS = 33;
static const unsigned long FROG_NET_STATE_MS = 60;

const int btnFrogMenuX = 230;
const int btnFrogMenuY = 6;
const int btnFrogMenuW = 78;
const int btnFrogMenuH = 28;

struct FroggerObject {
  float x;
  int w;
};

struct FroggerLane {
  int row;
  float speed;
  bool isWater;
  uint16_t objColor;
  int numObj;
  FroggerObject objs[FROG_MAX_OBJECTS];
};

int frogRowY[FROG_ROWS];
int frogGoalX[FROG_GOALS];
bool frogGoalFilled[FROG_GOALS];
FroggerLane frogLanes[FROG_LANES];
float frogX = 0.0f;
int frogRow = 0;
float frogPrevX = 0.0f;
int frogPrevRow = 0;
bool frogAlive = true;
bool frogJustJumped = false;
int frogScore = 0;
int frogLives = 3;
int frogLevel = 1;
uint32_t frogHiScore = 0;
bool frogGameOver = false;
bool frogDying = false;
unsigned long frogDeathTime = 0;
unsigned long frogLastFrame = 0;
float frogNetX[2] = {0.0f, 0.0f};
float frogNetPrevX[2] = {0.0f, 0.0f};
int frogNetRow[2] = {0, 0};
int frogNetPrevRow[2] = {0, 0};
bool frogNetAlive[2] = {true, true};
bool frogNetDying[2] = {false, false};
bool frogNetJustJumped[2] = {false, false};
unsigned long frogNetDeathTime[2] = {0, 0};
int frogNetScore[2] = {0, 0};
int frogNetLives[2] = {3, 3};
bool frogNetGameOver = false;
int frogNetWinner = 0;
bool frogNetSceneReady = false;
unsigned long frogLastStateSendTime = 0;
int frogNetInputSeq[2] = {0, 0};
int frogLocalInputSeq = 0;

// Frogger uses ESP-NOW for Host/Join because it needs fast symmetric movement:
// each console simulates its own frog and only broadcasts compact events/state.
static const uint8_t FROG_PKT_HELLO = 0;
static const uint8_t FROG_PKT_ACK = 1;
static const uint8_t FROG_PKT_START = 2;
static const uint8_t FROG_PKT_STATE = 3;
static const uint8_t FROG_PKT_GOAL = 4;
static const uint8_t FROG_PKT_OVER = 5;
static const int FROG_ESPNOW_CHANNEL = 1;
static const int FROG_ESPNOW_RX_SIZE = 16;
static const int FROG_ESPNOW_MAX_PACKET = 24;

#pragma pack(push, 1)
struct FrogEspNowHelloPacket {
  uint8_t type;
};

struct FrogEspNowAckPacket {
  uint8_t type;
};

struct FrogEspNowStartPacket {
  uint8_t type;
  uint8_t level;
};

struct FrogEspNowStatePacket {
  uint8_t type;
  uint8_t player;
  float x;
  uint8_t row;
  int16_t score;
  uint8_t lives;
  uint8_t alive;
};

struct FrogEspNowGoalPacket {
  uint8_t type;
  uint8_t slot;
  uint8_t player;
};

struct FrogEspNowOverPacket {
  uint8_t type;
  uint8_t winner;
  int16_t score0;
  int16_t score1;
};
#pragma pack(pop)

struct FrogEspNowRxEntry {
  uint8_t data[FROG_ESPNOW_MAX_PACKET];
  uint8_t mac[6];
  int len;
};

volatile int frogEspRxHead = 0;
volatile int frogEspRxTail = 0;
FrogEspNowRxEntry frogEspRxBuffer[FROG_ESPNOW_RX_SIZE];
uint8_t frogEspPeerMac[6] = {0, 0, 0, 0, 0, 0};
uint8_t frogEspBroadcastMac[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
bool frogEspReady = false;
bool frogEspPeerKnown = false;
unsigned long frogEspLastHelloTime = 0;
unsigned long frogEspLastPeerRxTime = 0;

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
const int btnGamesNavLeftX = 35;
const int btnGamesNavRightX = 170;
const int btnGamesNavW = 115;
const int btnGamesSnakeY = 135;
const int btnGamesBreakoutY = 205;
const int btnGamesPongY = 275;
const int btnGamesRanchRushY = 335;

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

const int btnSettingsMusicX = 60;
const int btnSettingsMusicY = 165;
const int btnSettingsMusicW = 200;
const int btnSettingsMusicH = 56;

const int btnSettingsWifiX = 60;
const int btnSettingsWifiY = 245;
const int btnSettingsWifiW = 200;
const int btnSettingsWifiH = 56;

const int btnMusicToggleX = 45;
const int btnMusicToggleY = 150;
const int btnMusicToggleW = 230;
const int btnMusicToggleH = 62;

const int btnSfxToggleX = 45;
const int btnSfxToggleY = 250;
const int btnSfxToggleW = 230;
const int btnSfxToggleH = 62;

const int btnWifiPrevX = 12;
const int btnWifiSsidY = 54;
const int btnWifiPrevW = 62;
const int btnWifiSsidX = 80;
const int btnWifiSsidW = 160;
const int btnWifiNextX = 246;
const int btnWifiNextW = 62;
const int btnWifiSsidH = 30;

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

void loadBreakoutScore() {
  prefs.begin("breakout", true);
  breakoutHiScore = prefs.getULong("hiscore", 0);
  prefs.end();
}

void saveBreakoutScore() {
  prefs.begin("breakout", false);
  prefs.putULong("hiscore", breakoutHiScore);
  prefs.end();
}

void resetBreakoutScore() {
  breakoutHiScore = 0;
  saveBreakoutScore();
}

void loadPongScore() {
  prefs.begin("pong_score", true);
  pongWinsP1 = prefs.getInt("p1", 0);
  pongWinsP2 = prefs.getInt("p2", 0);
  prefs.end();
}

void savePongScore() {
  prefs.begin("pong_score", false);
  prefs.putInt("p1", pongWinsP1);
  prefs.putInt("p2", pongWinsP2);
  prefs.end();
}

void resetPongScore() {
  pongWinsP1 = 0;
  pongWinsP2 = 0;
  savePongScore();
}

void loadSnakeScore() {
  prefs.begin("snake", true);
  snakeHiScore = prefs.getULong("hiscore", 0);
  prefs.end();
}

void saveSnakeScore() {
  prefs.begin("snake", false);
  prefs.putULong("hiscore", snakeHiScore);
  prefs.end();
}

void resetSnakeScore() {
  snakeHiScore = 0;
  saveSnakeScore();
}

void loadRanchRushScore() {
  prefs.begin("ranch", true);
  rrHiScore = prefs.getULong("hiscore_ranch", 0);
  prefs.end();
}

void saveRanchRushScore() {
  prefs.begin("ranch", false);
  prefs.putULong("hiscore_ranch", rrHiScore);
  prefs.end();
}

void resetRanchRushScore() {
  rrHiScore = 0;
  saveRanchRushScore();
}

void loadFroggerScore() {
  prefs.begin("frogger", true);
  frogHiScore = prefs.getULong("hiscore_frog", 0);
  prefs.end();
}

void saveFroggerScore() {
  prefs.begin("frogger", false);
  prefs.putULong("hiscore_frog", frogHiScore);
  prefs.end();
}

void resetFroggerScore() {
  frogHiScore = 0;
  saveFroggerScore();
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
  selectedHostSSIDIndex = prefs.getUChar("ssid", 0);
  prefs.end();

  if (selectedHostSSIDIndex < 0 || selectedHostSSIDIndex >= EPIC_SSID_COUNT) {
    selectedHostSSIDIndex = 0;
  }

  hostSSIDListOffset = (selectedHostSSIDIndex / MAX_HOST_SSID_VISIBLE) * MAX_HOST_SSID_VISIBLE;

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
  prefs.putUChar("ssid", (uint8_t)selectedHostSSIDIndex);
  prefs.end();
}

void loadConsoleSettings() {
  prefs.begin("console", true);
  musicEnabled = prefs.getBool("music", true);
  sfxEnabled = prefs.getBool("sfx", true);
  prefs.end();
}

void saveConsoleSettings() {
  prefs.begin("console", false);
  prefs.putBool("music", musicEnabled);
  prefs.putBool("sfx", sfxEnabled);
  prefs.end();
}

// ============================================================================
// AUDIO
// ============================================================================
// Short audio cues and menu music all share the buzzer, so cue tones briefly
// mute the menu loop instead of fighting it.
struct MenuMusicNote {
  uint16_t freq;
  uint16_t durationMs;
  uint16_t gapMs;
};

const MenuMusicNote menuMusic[] = {
  {659, 115, 25}, {784, 115, 25}, {988, 145, 35}, {784, 95, 25},
  {880, 115, 25}, {1047, 115, 25}, {1175, 155, 35}, {1047, 95, 25},
  {988, 130, 25}, {880, 110, 25}, {784, 140, 35}, {0, 80, 20},
  {523, 105, 25}, {659, 105, 25}, {784, 125, 25}, {988, 165, 45},
  {1047, 120, 25}, {988, 105, 25}, {880, 120, 25}, {784, 160, 40},
  {659, 120, 25}, {784, 120, 25}, {880, 120, 25}, {1047, 170, 45},
  {1175, 105, 25}, {1319, 105, 25}, {1175, 120, 25}, {988, 165, 45},
  {784, 120, 25}, {880, 120, 25}, {988, 120, 25}, {1319, 210, 80},
  {0, 160, 30}
};

const int menuMusicNoteCount = sizeof(menuMusic) / sizeof(menuMusic[0]);
int menuMusicIndex = 0;
bool menuMusicActive = false;
unsigned long menuMusicNextTime = 0;
unsigned long menuMusicMutedUntil = 0;

bool isGameplayStateForMenuMusic() {
  switch (appState) {
    case STATE_PLAYING:
    case STATE_RPS_CHOICE_P1:
    case STATE_RPS_CHOICE_P2:
    case STATE_RPS_WAITING_CHOICE:
    case STATE_PT_PLAYING:
    case STATE_BREAKOUT_PLAYING:
    case STATE_PONG_PLAYING:
    case STATE_SNAKE_PLAYING:
    case STATE_RR_PLAYING:
    case STATE_FROGGER_PLAYING:
      return true;
    default:
      return false;
  }
}

void stopMenuMusic() {
  if (menuMusicActive) {
    noTone(PIN_BUZZER);
    menuMusicActive = false;
  }

  menuMusicNextTime = millis() + 120;
}

void updateMenuMusic() {
  unsigned long now = millis();

  if (!musicEnabled) {
    stopMenuMusic();
    menuMusicIndex = 0;
    return;
  }

  if (isGameplayStateForMenuMusic()) {
    stopMenuMusic();
    menuMusicIndex = 0;
    return;
  }

  if (now < menuMusicMutedUntil) {
    if (menuMusicActive) {
      noTone(PIN_BUZZER);
      menuMusicActive = false;
    }

    return;
  }

  if (now < menuMusicNextTime) return;

  const MenuMusicNote &note = menuMusic[menuMusicIndex];

  if (note.freq == 0) {
    noTone(PIN_BUZZER);
    menuMusicActive = false;
  } else {
    tone(PIN_BUZZER, note.freq, note.durationMs);
    menuMusicActive = true;
  }

  menuMusicNextTime = now + note.durationMs + note.gapMs;
  menuMusicIndex++;

  if (menuMusicIndex >= menuMusicNoteCount) {
    menuMusicIndex = 0;
  }
}

void playPriorityTone(uint16_t freq, uint16_t durationMs) {
  if (!sfxEnabled) return;

  menuMusicActive = false;
  menuMusicMutedUntil = millis() + durationMs + 90;
  tone(PIN_BUZZER, freq, durationMs);
}

// Short audio cues. They are intentionally non-blocking tone() calls.
void beepMove()  { playPriorityTone(1000, 40); }
void beepStart() { playPriorityTone(1400, 70); }
void beepWin()   { playPriorityTone(2200, 180); }
void beepDraw()  { playPriorityTone(1200, 150); }
void beepClick() { playPriorityTone(1600, 60); }

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

void drawTanksWarsTitleSign() {
  uint16_t signFill = rgb888to565(12, 10, 28);
  uint16_t arcadeOrange = rgb888to565(255, 128, 0);
  uint16_t arcadeBlue = rgb888to565(0, 65, 210);
  uint16_t arcadeMagenta = rgb888to565(255, 0, 180);
  uint16_t tankGreen = rgb888to565(80, 180, 70);

  gfx->fillRoundRect(16, 18, 288, 96, 10, signFill);
  gfx->drawRoundRect(16, 18, 288, 96, 10, tankGreen);
  gfx->drawRoundRect(20, 22, 280, 88, 8, RGB565_CYAN);
  gfx->drawRoundRect(24, 26, 272, 80, 7, arcadeOrange);

  for (int x = 36; x < 286; x += 20) {
    gfx->fillCircle(x, 31, 3, arcadeOrange);
    gfx->drawCircle(x, 31, 4, RGB565_YELLOW);
    gfx->fillCircle(x, 101, 3, arcadeBlue);
    gfx->drawCircle(x, 101, 4, RGB565_CYAN);
  }

  drawPixelText("TANKS", 66, 39, 4, RGB565_YELLOW, RGB565_RED);
  drawPixelText("WARS", 92, 73, 4, RGB565_CYAN, arcadeBlue);

  gfx->fillCircle(44, 120, 6, arcadeMagenta);
  gfx->drawCircle(44, 120, 7, RGB565_YELLOW);
  gfx->fillCircle(276, 120, 6, arcadeMagenta);
  gfx->drawCircle(276, 120, 7, RGB565_YELLOW);
}

void drawTanksWarsTankDecor(int x, int y, bool facingRight, uint16_t bodyColor) {
  int dir = facingRight ? 1 : -1;
  uint16_t trackColor = rgb888to565(22, 24, 28);

  gfx->fillRoundRect(x - 22, y + 8, 44, 10, 5, trackColor);
  gfx->drawRoundRect(x - 22, y + 8, 44, 10, 5, RGB565_WHITE);

  for (int i = -14; i <= 14; i += 14) {
    gfx->fillCircle(x + i, y + 13, 4, rgb888to565(70, 80, 80));
  }

  gfx->fillRoundRect(x - 16, y, 32, 12, 4, bodyColor);
  gfx->drawRoundRect(x - 16, y, 32, 12, 4, RGB565_WHITE);
  gfx->fillCircle(x, y, 6, RGB565_YELLOW);

  for (int offset = -1; offset <= 1; offset++) {
    gfx->drawLine(x, y - 1 + offset, x + dir * 28, y - 16 + offset, RGB565_YELLOW);
  }
}

void drawTanksWarsBattlefieldDecor() {
  uint16_t ridgeA = rgb888to565(28, 78, 48);
  uint16_t ridgeB = rgb888to565(42, 118, 58);
  uint16_t arcadeBlue = rgb888to565(0, 65, 210);

  for (int x = 0; x < screenW; x += 8) {
    int y = 338 + (int)(sin((float)x * 0.055f) * 12.0f);
    gfx->fillRect(x, y, 8, 28, (x % 16 == 0) ? ridgeA : ridgeB);
  }

  for (int x = 0; x < screenW; x += 22) {
    gfx->drawLine(160, 365, x, screenH - 1, rgb888to565(18, 22, 70));
  }

  gfx->drawLine(0, 365, screenW - 1, 365, arcadeBlue);

  drawTanksWarsTankDecor(58, 320, true, RGB565_RED);
  drawTanksWarsTankDecor(262, 320, false, RGB565_BLUE);

  for (int i = 0; i < 14; i++) {
    int px = 86 + i * 11;
    int py = 260 - (int)(sin((float)i * 0.24f) * 24.0f);
    gfx->drawPixel(px, py, RGB565_YELLOW);

    if (i % 3 == 0) {
      gfx->drawCircle(px, py, 2, RGB565_RED);
    }
  }
}

void drawTanksWarsArcadeHome() {
  fillArcadeGradient();
  drawArcadeStars();
  drawArcadeCabinets();
  drawArcadeFloor();
  drawTanksWarsBattlefieldDecor();
  drawTanksWarsTitleSign();
}

void drawBreakoutTitleSign() {
  uint16_t signFill = rgb888to565(12, 10, 28);
  uint16_t arcadeOrange = rgb888to565(255, 128, 0);
  uint16_t arcadeBlue = rgb888to565(0, 65, 210);
  uint16_t arcadeMagenta = rgb888to565(255, 0, 180);

  gfx->fillRoundRect(16, 18, 288, 96, 10, signFill);
  gfx->drawRoundRect(16, 18, 288, 96, 10, arcadeMagenta);
  gfx->drawRoundRect(20, 22, 280, 88, 8, RGB565_CYAN);
  gfx->drawRoundRect(24, 26, 272, 80, 7, arcadeOrange);

  for (int x = 36; x < 286; x += 20) {
    gfx->fillCircle(x, 31, 3, arcadeOrange);
    gfx->drawCircle(x, 31, 4, RGB565_YELLOW);
    gfx->fillCircle(x, 101, 3, arcadeBlue);
    gfx->drawCircle(x, 101, 4, RGB565_CYAN);
  }

  drawPixelText("BREAK", 51, 38, 4, RGB565_YELLOW, RGB565_RED);
  drawPixelText("OUT", 116, 72, 4, RGB565_CYAN, arcadeBlue);
}

void drawBreakoutBrickWallDecor() {
  uint16_t brickColors[] = {
    rgb888to565(230, 40, 30),
    rgb888to565(240, 130, 20),
    rgb888to565(240, 220, 20),
    rgb888to565(30, 220, 40),
    rgb888to565(20, 90, 220)
  };

  int brickW = 38;
  int brickH = 14;
  int startY = 128;

  for (int row = 0; row < 5; row++) {
    int offset = (row % 2 == 0) ? 10 : 30;

    for (int x = offset; x < screenW - 10; x += brickW + 4) {
      uint16_t color = brickColors[row];
      gfx->fillRoundRect(x, startY + row * 18, brickW, brickH, 3, color);
      gfx->drawRoundRect(x, startY + row * 18, brickW, brickH, 3, RGB565_BLACK);
      gfx->drawLine(x + 3, startY + row * 18 + 2, x + brickW - 5,
                    startY + row * 18 + 2, RGB565_WHITE);
    }
  }
}

void drawBreakoutPlayfieldDecor() {
  uint16_t arcadeBlue = rgb888to565(0, 65, 210);
  uint16_t arcadeMagenta = rgb888to565(255, 0, 180);
  uint16_t darkPanel = rgb888to565(3, 5, 22);

  gfx->fillRoundRect(40, 224, 240, 118, 8, darkPanel);
  gfx->drawRoundRect(40, 224, 240, 118, 8, arcadeBlue);
  gfx->drawRoundRect(44, 228, 232, 110, 7, arcadeMagenta);

  for (int i = 0; i < 8; i++) {
    int x = 72 + i * 24;
    int y = 250 + (int)(sin((float)i * 0.75f) * 28.0f);
    gfx->drawPixel(x, y, RGB565_WHITE);
    gfx->drawCircle(x, y, 2, RGB565_CYAN);
  }

  gfx->fillCircle(222, 244, 7, RGB565_WHITE);
  gfx->drawCircle(222, 244, 8, RGB565_YELLOW);

  gfx->fillRoundRect(112, 315, 96, 12, 6, RGB565_RED);
  gfx->drawRoundRect(112, 315, 96, 12, 6, RGB565_WHITE);
  gfx->fillRect(124, 318, 72, 5, RGB565_YELLOW);

  gfx->setTextSize(1);
  gfx->setTextColor(RGB565_CYAN);
  gfx->setCursor(81, 118);
  gfx->print("BRICK SMASHER  1UP");
}

void drawBreakoutArcadeHome() {
  fillArcadeGradient();
  drawArcadeStars();
  drawArcadeCabinets();
  drawArcadeFloor();
  drawBreakoutBrickWallDecor();
  drawBreakoutPlayfieldDecor();
  drawBreakoutTitleSign();
}

void drawPongTitleSign() {
  uint16_t signFill = rgb888to565(12, 10, 28);
  uint16_t arcadeOrange = rgb888to565(255, 128, 0);
  uint16_t arcadeBlue = rgb888to565(0, 65, 210);
  uint16_t arcadeMagenta = rgb888to565(255, 0, 180);

  gfx->fillRoundRect(18, 18, 284, 92, 10, signFill);
  gfx->drawRoundRect(18, 18, 284, 92, 10, arcadeBlue);
  gfx->drawRoundRect(22, 22, 276, 84, 8, RGB565_CYAN);
  gfx->drawRoundRect(26, 26, 268, 76, 7, arcadeOrange);

  for (int x = 38; x < 286; x += 20) {
    gfx->fillCircle(x, 30, 3, arcadeMagenta);
    gfx->drawCircle(x, 30, 4, RGB565_YELLOW);
    gfx->fillCircle(x, 98, 3, arcadeBlue);
    gfx->drawCircle(x, 98, 4, RGB565_CYAN);
  }

  drawPixelText("PONG", 84, 48, 5, RGB565_YELLOW, RGB565_RED);
}

void drawPongCourtDecor() {
  uint16_t courtLine = RGB565_CYAN;
  uint16_t arcadeMagenta = rgb888to565(255, 0, 180);
  uint16_t darkPanel = rgb888to565(2, 4, 18);

  gfx->fillRoundRect(42, 132, 236, 210, 8, darkPanel);
  gfx->drawRoundRect(42, 132, 236, 210, 8, courtLine);
  gfx->drawRoundRect(47, 137, 226, 200, 6, arcadeMagenta);

  for (int x = 58; x < 262; x += 22) {
    gfx->drawLine(x, 235, x + 10, 235, RGB565_WHITE);
  }

  gfx->fillRoundRect(122, 155, 76, 9, 4, RGB565_RED);
  gfx->drawRoundRect(122, 155, 76, 9, 4, RGB565_WHITE);
  gfx->fillRoundRect(122, 310, 76, 9, 4, RGB565_GREEN);
  gfx->drawRoundRect(122, 310, 76, 9, 4, RGB565_WHITE);

  gfx->fillCircle(160, 234, 7, RGB565_WHITE);
  gfx->drawCircle(160, 234, 8, RGB565_YELLOW);

  gfx->setTextSize(1);
  gfx->setTextColor(RGB565_CYAN);
  gfx->setCursor(92, 118);
  gfx->print("CPU VS PLAYER");
}

void drawPongArcadeHome() {
  fillArcadeGradient();
  drawArcadeStars();
  drawArcadeCabinets();
  drawArcadeFloor();
  drawPongCourtDecor();
  drawPongTitleSign();
}

void drawSnakeTitleSign() {
  uint16_t signFill = rgb888to565(12, 10, 28);
  uint16_t arcadeOrange = rgb888to565(255, 128, 0);
  uint16_t arcadeBlue = rgb888to565(0, 65, 210);
  uint16_t arcadeMagenta = rgb888to565(255, 0, 180);

  gfx->fillRoundRect(18, 18, 284, 92, 10, signFill);
  gfx->drawRoundRect(18, 18, 284, 92, 10, RGB565_GREEN);
  gfx->drawRoundRect(22, 22, 276, 84, 8, RGB565_CYAN);
  gfx->drawRoundRect(26, 26, 268, 76, 7, arcadeOrange);

  for (int x = 38; x < 286; x += 20) {
    gfx->fillCircle(x, 30, 3, arcadeMagenta);
    gfx->drawCircle(x, 30, 4, RGB565_YELLOW);
    gfx->fillCircle(x, 98, 3, arcadeBlue);
    gfx->drawCircle(x, 98, 4, RGB565_CYAN);
  }

  drawPixelText("SNAKE", 58, 48, 5, RGB565_GREEN, arcadeBlue);
}

void drawSnakeBoardDecor() {
  uint16_t gridColor = rgb888to565(20, 90, 55);
  uint16_t darkPanel = rgb888to565(2, 14, 10);
  uint16_t foodColor = RGB565_RED;

  gfx->fillRoundRect(42, 132, 236, 210, 8, darkPanel);
  gfx->drawRoundRect(42, 132, 236, 210, 8, RGB565_GREEN);
  gfx->drawRoundRect(47, 137, 226, 200, 6, RGB565_CYAN);

  for (int x = 58; x <= 262; x += 24) {
    gfx->drawLine(x, 148, x, 326, gridColor);
  }

  for (int y = 148; y <= 326; y += 24) {
    gfx->drawLine(58, y, 262, y, gridColor);
  }

  int snakeX[] = {96, 120, 144, 168, 192, 216};
  int snakeY[] = {254, 254, 254, 230, 230, 230};

  for (int i = 0; i < 6; i++) {
    gfx->fillRoundRect(snakeX[i] - 9, snakeY[i] - 9, 18, 18, 5, RGB565_GREEN);
    gfx->drawRoundRect(snakeX[i] - 9, snakeY[i] - 9, 18, 18, 5, RGB565_WHITE);
  }

  gfx->fillCircle(216, 230, 3, RGB565_BLACK);
  gfx->fillCircle(220, 230, 3, RGB565_BLACK);
  gfx->fillCircle(108, 194, 7, foodColor);
  gfx->drawCircle(108, 194, 8, RGB565_YELLOW);

  gfx->setTextSize(1);
  gfx->setTextColor(RGB565_CYAN);
  gfx->setCursor(92, 118);
  gfx->print("GROW  SURVIVE  SCORE");
}

void drawSnakeArcadeHome() {
  fillArcadeGradient();
  drawArcadeStars();
  drawArcadeCabinets();
  drawArcadeFloor();
  drawSnakeBoardDecor();
  drawSnakeTitleSign();
}

void drawRanchRushFence(int y) {
  uint16_t fence = rgb888to565(214, 186, 170);

  gfx->fillRect(0, y, screenW, 5, fence);
  gfx->fillRect(0, y + 16, screenW, 5, fence);

  for (int x = 10; x < screenW; x += 40) {
    gfx->fillRect(x, y - 3, 5, 27, fence);
  }
}

void drawRanchRushTitleSign() {
  uint16_t signFill = rgb888to565(40, 30, 10);
  uint16_t ranchBrown = rgb888to565(138, 65, 17);
  uint16_t ranchOrange = rgb888to565(255, 160, 0);
  uint16_t ranchGreen = rgb888to565(92, 196, 100);

  gfx->fillRoundRect(18, 18, 284, 92, 10, signFill);
  gfx->drawRoundRect(18, 18, 284, 92, 10, ranchBrown);
  gfx->drawRoundRect(22, 22, 276, 84, 8, ranchOrange);
  gfx->drawRoundRect(26, 26, 268, 76, 7, ranchGreen);

  for (int x = 38; x < 286; x += 20) {
    gfx->fillCircle(x, 30, 3, ranchOrange);
    gfx->drawCircle(x, 30, 4, RGB565_YELLOW);
    gfx->fillCircle(x, 98, 3, ranchBrown);
    gfx->drawCircle(x, 98, 4, ranchOrange);
  }

  drawPixelText("RANCH", 50, 38, 4, RGB565_YELLOW, ranchBrown);
  drawPixelText("RUSH", 87, 72, 4, RGB565_WHITE, ranchOrange);
}

void drawRanchRushCowboyDecor(int x, int y) {
  uint16_t ranchBrown = rgb888to565(138, 65, 17);
  uint16_t horse = RGB565_YELLOW;
  uint16_t shirt = rgb888to565(60, 100, 255);
  uint16_t skin = rgb888to565(255, 160, 0);

  gfx->fillRect(x - 18, y + 8, 34, 14, horse);
  gfx->fillCircle(x + 14, y + 12, 7, horse);
  gfx->fillRect(x - 12, y + 21, 3, 10, horse);
  gfx->fillRect(x - 2, y + 21, 3, 10, horse);
  gfx->fillRect(x + 8, y + 21, 3, 10, horse);
  gfx->drawLine(x - 18, y + 11, x - 28, y + 4, horse);
  gfx->drawLine(x - 19, y + 13, x - 30, y + 10, horse);

  gfx->fillCircle(x - 3, y - 1, 5, skin);
  gfx->fillRect(x - 8, y + 4, 11, 12, shirt);
  gfx->fillRect(x - 13, y - 9, 20, 3, ranchBrown);
  gfx->fillRect(x - 8, y - 15, 10, 7, ranchBrown);
  gfx->drawLine(x + 3, y + 7, x + 54, y - 4, RGB565_WHITE);
  gfx->drawCircle(x + 58, y - 5, 12, RGB565_WHITE);
}

void drawRanchRushAnimalDecor(int x, int y) {
  uint16_t ranchBrown = rgb888to565(138, 65, 17);

  gfx->fillRect(x - 12, y + 8, 28, 13, ranchBrown);
  gfx->fillCircle(x + 16, y + 12, 6, ranchBrown);
  gfx->fillCircle(x + 22, y + 8, 5, ranchBrown);
  gfx->fillRect(x - 6, y + 20, 3, 10, ranchBrown);
  gfx->fillRect(x + 4, y + 20, 3, 10, ranchBrown);
  gfx->fillRect(x + 12, y + 20, 3, 10, ranchBrown);
  gfx->drawLine(x + 20, y + 4, x + 15, y - 3, RGB565_WHITE);
  gfx->drawLine(x + 24, y + 4, x + 30, y - 3, RGB565_WHITE);
  gfx->drawLine(x - 12, y + 11, x - 22, y + 5, ranchBrown);
  gfx->fillRect(x - 4, y + 10, 4, 4, RGB565_BLACK);
  gfx->fillRect(x + 8, y + 12, 3, 3, RGB565_BLACK);
}

void drawRanchRushFieldDecor() {
  uint16_t sky = rgb888to565(100, 180, 255);
  uint16_t field = rgb888to565(75, 145, 35);
  uint16_t darkField = rgb888to565(51, 100, 0);
  uint16_t green2 = rgb888to565(92, 196, 100);
  uint16_t dirt = rgb888to565(160, 120, 60);

  gfx->fillRect(0, 112, screenW, 68, sky);
  gfx->fillRect(0, 180, screenW, 190, field);
  gfx->fillRect(0, 330, screenW, 40, dirt);
  drawRanchRushFence(132);
  drawRanchRushFence(338);

  for (int i = 0; i < 5; i++) {
    int y = 190 + i * 33;
    gfx->drawLine(0, y, screenW - 1, y, green2);
  }

  for (int i = 0; i < 36; i++) {
    int x = (i * 47 + 9) % screenW;
    int y = 188 + ((i * 31 + 17) % 138);
    gfx->drawPixel(x, y, darkField);
    gfx->drawPixel(x + 1, y + 1, green2);
  }

  drawRanchRushCowboyDecor(72, 248);
  drawRanchRushAnimalDecor(230, 230);
  drawRanchRushAnimalDecor(256, 286);

  gfx->setTextSize(1);
  gfx->setTextColor(RGB565_YELLOW);
  gfx->setCursor(69, 118);
  gfx->print("LANES  LASSO  CATTLE");
}

void drawRanchRushArcadeHome() {
  fillArcadeGradient();
  drawArcadeStars();
  drawArcadeCabinets();
  drawArcadeFloor();
  drawRanchRushFieldDecor();
  drawRanchRushTitleSign();
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
      strcmp(label, "MENU") == 0 ||
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

uint32_t highestOfTwo(uint32_t a, uint32_t b) {
  return (a > b) ? a : b;
}

uint32_t highestOfThree(uint32_t a, uint32_t b, uint32_t c) {
  return highestOfTwo(highestOfTwo(a, b), c);
}

void drawGameMenuHighScore(uint32_t highScore) {
  char line[40];
  snprintf(line, sizeof(line), "HIGH SCORE  %lu", (unsigned long)highScore);
  drawCenteredTextWithShadow(line, 462, 1, RGB565_WHITE, RGB565_BLACK);
}

void drawGameMenuScoreAndHigh(const char *scoreLine, uint32_t highScore) {
  drawCenteredTextWithShadow(scoreLine, 448, 1, RGB565_WHITE, RGB565_BLACK);
  drawGameMenuHighScore(highScore);
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
  snprintf(scoreLine, sizeof(scoreLine), "Score X:%d  O:%d  D:%d", scoreX, scoreO, scoreDraw);
  drawCenteredText(scoreLine, 10, 2, RGB565_WHITE);

  char turnLine[48];

  if (gameOver) {
    snprintf(turnLine, sizeof(turnLine), "Game over");
  } else if (localGame) {
    snprintf(turnLine, sizeof(turnLine), "Turn: %c", currentPlayer);
  } else if (myTurn) {
    snprintf(turnLine, sizeof(turnLine), "Your turn: %c", myPlayer);
  } else {
    snprintf(turnLine, sizeof(turnLine), "Waiting: %c", currentPlayer);
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

  if (!localGame && activeNetworkGame == NETWORK_GAME_PT) {
    snprintf(turnLine, sizeof(turnLine), myTurn ? "YOUR TURN P%d" : "WAIT P%d", ptCurrentPlayer + 1);
  } else {
    snprintf(turnLine, sizeof(turnLine), "PLAYER %d TURN", ptCurrentPlayer + 1);
  }

  drawCenteredText(turnLine, 26, 2, (localGame || myTurn) ? RGB565_GREEN : RGB565_YELLOW);
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
  if (!localGame && activeNetworkGame == NETWORK_GAME_PT && !myTurn) {
    snprintf(line, sizeof(line), "Waiting  P%d  A:%d  P:%d",
             ptCurrentPlayer + 1, ptAngle[ptCurrentPlayer], ptPower[ptCurrentPlayer]);
  } else {
    snprintf(line, sizeof(line), "P%d  Angle:%d  Power:%d",
             ptCurrentPlayer + 1, ptAngle[ptCurrentPlayer], ptPower[ptCurrentPlayer]);
  }

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

  drawTransparentArcadeButton(btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH, "RESET SCORE", 2);

  drawTransparentArcadeButton(btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH, "BACK", 2);

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "SCORE  X:%d  O:%d  D:%d", scoreX, scoreO, scoreDraw);
  drawGameMenuScoreAndHigh(scoreLine, highestOfThree(scoreX, scoreO, scoreDraw));
}

void drawGamesScreen() {
  appState = STATE_GAMES;
  drawGamesArcadeBackground();

  drawTransparentArcadeButton(btnGamesX, btnGamesTttY, btnGamesW, btnGamesH, "TIC TAC TOE", 2);

  drawTransparentArcadeButton(btnGamesX, btnGamesRpsY, btnGamesW, btnGamesH, "ROCK-PAPER-SCISSORS", 2);

  drawTransparentArcadeButton(btnGamesX, btnGamesPocketTanksY, btnGamesW, btnGamesH, "Tanks Wars", 2);

  drawTransparentArcadeButton(btnGamesNavLeftX, btnGamesHomeY, btnGamesNavW, btnGamesHomeH, "HOME", 2);

  drawTransparentArcadeButton(btnGamesNavRightX, btnGamesHomeY, btnGamesNavW, btnGamesHomeH, "MORE", 2);
}

void drawGamesMoreScreen() {
  appState = STATE_GAMES_MORE;
  drawGamesArcadeBackground();

  drawTransparentArcadeButton(btnGamesX, btnGamesSnakeY, btnGamesW, btnGamesH, "SNAKE", 2);

  drawTransparentArcadeButton(btnGamesX, btnGamesBreakoutY, btnGamesW, btnGamesH, "BREAKOUT", 2);

  drawTransparentArcadeButton(btnGamesX, btnGamesPongY, btnGamesW, btnGamesH, "PONG", 2);

  drawTransparentArcadeButton(btnGamesX, btnGamesRanchRushY, btnGamesW, btnGamesH, "RANCH RUSH", 2);

  drawTransparentArcadeButton(btnGamesNavLeftX, btnGamesHomeY, btnGamesNavW, btnGamesHomeH, "BACK", 2);

  drawTransparentArcadeButton(btnGamesNavRightX, btnGamesHomeY, btnGamesNavW, btnGamesHomeH, "MORE", 2);
}

void drawGamesExtraScreen() {
  appState = STATE_GAMES_EXTRA;
  drawGamesArcadeBackground();

  drawTransparentArcadeButton(btnGamesX, btnGamesRpsY, btnGamesW, btnGamesH, "FROGGER", 2);

  drawTransparentArcadeButton(btnGamesNavLeftX, btnGamesHomeY, btnGamesNavW, btnGamesHomeH, "BACK", 2);

  drawTransparentArcadeButton(btnGamesNavRightX, btnGamesHomeY, btnGamesNavW, btnGamesHomeH, "HOME", 2);
}

void drawRpsMenuScreen() {
  activeNetworkGame = NETWORK_GAME_RPS;
  localGame = false;
  appState = STATE_ROCK_PAPER_SCISSORS;
  drawRpsArcadeHome();

  drawTransparentArcadeButton(btnLocalX, btnLocalY, btnLocalW, btnLocalH, "LOCAL", 2);

  drawTransparentArcadeButton(btnHostX, btnHostY, btnHostW, btnHostH, "HOST - P1", 2);

  drawTransparentArcadeButton(btnJoinX, btnJoinY, btnJoinW, btnJoinH, "JOIN - P2", 2);

  drawTransparentArcadeButton(btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH, "RESET SCORE", 2);

  drawTransparentArcadeButton(btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH, "BACK", 2);

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "SCORE  P1:%d  P2:%d  D:%d", rpsScoreP1, rpsScoreP2, rpsScoreDraw);
  drawGameMenuScoreAndHigh(scoreLine, highestOfThree(rpsScoreP1, rpsScoreP2, rpsScoreDraw));
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
    snprintf(scoreLine, sizeof(scoreLine), "P1:%d   P2:%d   D:%d", rpsScoreP1, rpsScoreP2, rpsScoreDraw);
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

// ============================================================================
// BREAKOUT GAME
// ============================================================================
// Portrait adaptation of the standalone Breakout sketch. The game uses a
// fixed-time update, simple AABB collisions, and large touch zones for control.
uint16_t breakoutBrickColor(int row) {
  if (row == 0) return rgb888to565(230, 40, 30);
  if (row == 1) return rgb888to565(240, 130, 20);
  if (row == 2) return rgb888to565(240, 220, 20);
  if (row == 3) return rgb888to565(30, 220, 40);
  if (row == 4) return rgb888to565(20, 90, 220);
  return rgb888to565(150, 70, 230);
}

void drawBreakoutHud() {
  gfx->fillRect(0, 0, BREAKOUT_SCREEN_W, BREAKOUT_HUD_H, RGB565_BLACK);
  gfx->drawLine(0, BREAKOUT_HUD_H, BREAKOUT_SCREEN_W - 1, BREAKOUT_HUD_H, RGB565_BLUE);

  gfx->setTextSize(2);
  gfx->setTextColor(RGB565_GREEN);
  gfx->setCursor(8, 9);
  gfx->print("SCORE ");
  gfx->print(breakoutScore);

  gfx->setTextColor(RGB565_RED);
  gfx->setCursor(210, 9);
  gfx->print("LIVES ");
  gfx->print(breakoutLives);
}

void drawBreakoutControls() {
  gfx->fillRect(0, BREAKOUT_PLAY_BOTTOM + 1, BREAKOUT_SCREEN_W,
                BREAKOUT_SCREEN_H - BREAKOUT_PLAY_BOTTOM - 1, RGB565_BLACK);
  gfx->drawLine(0, BREAKOUT_PLAY_BOTTOM, BREAKOUT_SCREEN_W - 1,
                BREAKOUT_PLAY_BOTTOM, RGB565_BLUE);

  drawButton(btnBreakoutLeftX, btnBreakoutLeftY, btnBreakoutLeftW, btnBreakoutLeftH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "<", 3);

  drawButton(btnBreakoutRightX, btnBreakoutRightY, btnBreakoutRightW, btnBreakoutRightH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, ">", 3);

  drawButton(btnBreakoutMenuX, btnBreakoutMenuY, btnBreakoutMenuW, btnBreakoutMenuH,
             RGB565_RED, RGB565_WHITE, RGB565_WHITE, "MENU", 2);
}

void drawBreakoutBrick(int row, int col) {
  int bx = BREAKOUT_BRICK_X0 + col * (BREAKOUT_BRICK_W + BREAKOUT_BRICK_GAP);
  int by = BREAKOUT_BRICK_Y0 + row * (BREAKOUT_BRICK_H + BREAKOUT_BRICK_GAP);

  if (breakoutBricks[row][col]) {
    gfx->fillRect(bx, by, BREAKOUT_BRICK_W, BREAKOUT_BRICK_H, breakoutBrickColor(row));
    gfx->drawRect(bx, by, BREAKOUT_BRICK_W, BREAKOUT_BRICK_H, RGB565_BLACK);
  } else {
    gfx->fillRect(bx, by, BREAKOUT_BRICK_W, BREAKOUT_BRICK_H, RGB565_BLACK);
  }
}

void drawBreakoutBricks() {
  for (int r = 0; r < BREAKOUT_BRICK_ROWS; r++) {
    for (int c = 0; c < BREAKOUT_BRICK_COLS; c++) {
      drawBreakoutBrick(r, c);
    }
  }
}

bool breakoutHasBricksLeft() {
  for (int r = 0; r < BREAKOUT_BRICK_ROWS; r++) {
    for (int c = 0; c < BREAKOUT_BRICK_COLS; c++) {
      if (breakoutBricks[r][c]) return true;
    }
  }

  return false;
}

void resetBreakoutBall() {
  breakoutBallX = BREAKOUT_SCREEN_W / 2;
  breakoutBallY = BREAKOUT_PADDLE_Y - 22;
  breakoutBallVX = 2.8;
  breakoutBallVY = -3.4;
  breakoutOldBallX = -1;
  breakoutOldBallY = -1;
}

void drawBreakoutEntities() {
  if (breakoutOldBallX >= 0) {
    gfx->fillCircle(breakoutOldBallX, breakoutOldBallY, BREAKOUT_BALL_R + 1, RGB565_BLACK);
  }

  if (breakoutOldPaddleX >= 0 && breakoutOldPaddleX != breakoutPaddleX) {
    gfx->fillRect(breakoutOldPaddleX, BREAKOUT_PADDLE_Y,
                  BREAKOUT_PADDLE_W, BREAKOUT_PADDLE_H, RGB565_BLACK);
  }

  gfx->fillRect(breakoutPaddleX, BREAKOUT_PADDLE_Y,
                BREAKOUT_PADDLE_W, BREAKOUT_PADDLE_H, RGB565_WHITE);
  gfx->fillRect(breakoutPaddleX + 5, BREAKOUT_PADDLE_Y + 2,
                BREAKOUT_PADDLE_W - 10, BREAKOUT_PADDLE_H - 4, RGB565_RED);

  gfx->fillCircle((int)breakoutBallX, (int)breakoutBallY,
                  BREAKOUT_BALL_R, RGB565_WHITE);

  breakoutOldPaddleX = breakoutPaddleX;
  breakoutOldBallX = (int)breakoutBallX;
  breakoutOldBallY = (int)breakoutBallY;
}

void drawBreakoutEndOverlay() {
  gfx->fillRoundRect(24, 178, 272, 124, 10, RGB565_BLACK);
  gfx->drawRoundRect(24, 178, 272, 124, 10, RGB565_YELLOW);

  const char *title = breakoutWin ? "YOU WIN" : (localGame ? "GAME OVER" : "YOU LOSE");

  drawCenteredText(title, 205, 3, breakoutWin ? RGB565_GREEN : RGB565_YELLOW);

  char scoreLine[32];
  snprintf(scoreLine, sizeof(scoreLine), "Score %d", breakoutScore);
  drawCenteredText(scoreLine, 248, 2, RGB565_WHITE);
  drawCenteredText(localGame ? "Tap to restart" : "Tap play again", 280, 1, RGB565_CYAN);
}

void finishBreakoutRound(bool won) {
  if (breakoutGameOver) return;

  breakoutGameOver = true;
  breakoutWin = won;

  if ((uint32_t)breakoutScore > breakoutHiScore) {
    breakoutHiScore = breakoutScore;
    saveBreakoutScore();
  }

  drawBreakoutHud();
  drawBreakoutEndOverlay();

  if (!localGame && !won && !breakoutNetworkLossSent) {
    breakoutNetworkLossSent = true;
    sendNetMessage("BR_LOSE");
  }

  if (won) {
    beepWin();
  } else {
    beepDraw();
  }
}

void resetBreakoutBrickWall() {
  for (int r = 0; r < BREAKOUT_BRICK_ROWS; r++) {
    for (int c = 0; c < BREAKOUT_BRICK_COLS; c++) {
      breakoutBricks[r][c] = true;
    }
  }
}

void newBreakoutGame() {
  breakoutScore = 0;
  breakoutLives = 3;
  breakoutGameOver = false;
  breakoutWin = false;
  breakoutNetworkLossSent = false;
  breakoutPaddleX = (BREAKOUT_SCREEN_W - BREAKOUT_PADDLE_W) / 2;
  breakoutOldPaddleX = -1;
  resetBreakoutBrickWall();

  gfx->fillScreen(RGB565_BLACK);
  drawBreakoutHud();
  drawBreakoutBricks();
  drawBreakoutControls();
  resetBreakoutBall();
  drawBreakoutEntities();
  breakoutLastFrame = millis();
}

void updateBreakoutGame() {
  if (appState != STATE_BREAKOUT_PLAYING) return;

  unsigned long now = millis();
  if (now - breakoutLastFrame < BREAKOUT_FRAME_MS) return;
  breakoutLastFrame = now;

  if (breakoutGameOver) return;

  if (breakoutTouchDown &&
      inRect(breakoutTouchX, breakoutTouchY,
             btnBreakoutLeftX, btnBreakoutLeftY, btnBreakoutLeftW, btnBreakoutLeftH)) {
    breakoutPaddleX -= BREAKOUT_PADDLE_SPEED;
  }

  if (breakoutTouchDown &&
      inRect(breakoutTouchX, breakoutTouchY,
             btnBreakoutRightX, btnBreakoutRightY, btnBreakoutRightW, btnBreakoutRightH)) {
    breakoutPaddleX += BREAKOUT_PADDLE_SPEED;
  }

  breakoutPaddleX = constrain(breakoutPaddleX, 4,
                              BREAKOUT_SCREEN_W - BREAKOUT_PADDLE_W - 4);

  breakoutBallX += breakoutBallVX;
  breakoutBallY += breakoutBallVY;

  if (breakoutBallX <= BREAKOUT_BALL_R) {
    breakoutBallX = BREAKOUT_BALL_R;
    breakoutBallVX = -breakoutBallVX;
    beepClick();
  } else if (breakoutBallX >= BREAKOUT_SCREEN_W - BREAKOUT_BALL_R) {
    breakoutBallX = BREAKOUT_SCREEN_W - BREAKOUT_BALL_R;
    breakoutBallVX = -breakoutBallVX;
    beepClick();
  }

  if (breakoutBallY <= BREAKOUT_HUD_H + BREAKOUT_BALL_R) {
    breakoutBallY = BREAKOUT_HUD_H + BREAKOUT_BALL_R;
    breakoutBallVY = -breakoutBallVY;
    beepClick();
  }

  if (breakoutBallVY > 0 &&
      breakoutBallY + BREAKOUT_BALL_R >= BREAKOUT_PADDLE_Y &&
      breakoutBallY - BREAKOUT_BALL_R <= BREAKOUT_PADDLE_Y + BREAKOUT_PADDLE_H &&
      breakoutBallX >= breakoutPaddleX - BREAKOUT_BALL_R &&
      breakoutBallX <= breakoutPaddleX + BREAKOUT_PADDLE_W + BREAKOUT_BALL_R) {
    breakoutBallY = BREAKOUT_PADDLE_Y - BREAKOUT_BALL_R;
    breakoutBallVY = -breakoutBallVY;

    float offset = (breakoutBallX - (breakoutPaddleX + BREAKOUT_PADDLE_W / 2.0)) /
                   (BREAKOUT_PADDLE_W / 2.0);
    breakoutBallVX = offset * 4.0;
    beepMove();
  }

  bool hitBrick = false;
  for (int r = 0; r < BREAKOUT_BRICK_ROWS && !hitBrick; r++) {
    for (int c = 0; c < BREAKOUT_BRICK_COLS && !hitBrick; c++) {
      if (!breakoutBricks[r][c]) continue;

      int bx = BREAKOUT_BRICK_X0 + c * (BREAKOUT_BRICK_W + BREAKOUT_BRICK_GAP);
      int by = BREAKOUT_BRICK_Y0 + r * (BREAKOUT_BRICK_H + BREAKOUT_BRICK_GAP);

      if (breakoutBallX + BREAKOUT_BALL_R >= bx &&
          breakoutBallX - BREAKOUT_BALL_R <= bx + BREAKOUT_BRICK_W &&
          breakoutBallY + BREAKOUT_BALL_R >= by &&
          breakoutBallY - BREAKOUT_BALL_R <= by + BREAKOUT_BRICK_H) {
        breakoutBricks[r][c] = false;
        breakoutScore += 10;

        if ((uint32_t)breakoutScore > breakoutHiScore) {
          breakoutHiScore = breakoutScore;
          saveBreakoutScore();
        }

        breakoutBallVY = -breakoutBallVY;
        drawBreakoutBrick(r, c);
        drawBreakoutHud();
        beepStart();
        hitBrick = true;
      }
    }
  }

  if (hitBrick && !breakoutHasBricksLeft()) {
    if (localGame) {
      drawBreakoutEntities();
      finishBreakoutRound(true);
    } else {
      resetBreakoutBrickWall();
      breakoutOldBallX = -1;
      breakoutOldBallY = -1;
      breakoutOldPaddleX = -1;
      gfx->fillScreen(RGB565_BLACK);
      drawBreakoutHud();
      drawBreakoutBricks();
      drawBreakoutControls();
      resetBreakoutBall();
      drawBreakoutEntities();
    }
    return;
  }

  if (breakoutBallY - BREAKOUT_BALL_R > BREAKOUT_PLAY_BOTTOM) {
    if (breakoutOldBallX >= 0) {
      gfx->fillCircle(breakoutOldBallX, breakoutOldBallY, BREAKOUT_BALL_R + 1, RGB565_BLACK);
    }

    breakoutLives--;
    drawBreakoutHud();

    if (breakoutLives <= 0) {
      finishBreakoutRound(false);
      return;
    }

    resetBreakoutBall();
  }

  drawBreakoutEntities();
}

void startBreakoutLocalGame() {
  activeNetworkGame = NETWORK_GAME_BREAKOUT;
  stopNetwork();
  localGame = true;
  appState = STATE_BREAKOUT_PLAYING;
  beepStart();
  newBreakoutGame();
}

void startBreakoutNetworkGame() {
  activeNetworkGame = NETWORK_GAME_BREAKOUT;
  localGame = false;
  myTurn = true;
  appState = STATE_BREAKOUT_PLAYING;
  beepStart();
  newBreakoutGame();
}

void applyRemoteBreakoutLoss() {
  activeNetworkGame = NETWORK_GAME_BREAKOUT;

  if (appState != STATE_BREAKOUT_PLAYING || breakoutGameOver) {
    return;
  }

  finishBreakoutRound(true);
}

void drawBreakoutMenuScreen() {
  activeNetworkGame = NETWORK_GAME_BREAKOUT;
  localGame = false;
  appState = STATE_BREAKOUT;
  drawBreakoutArcadeHome();

  drawTransparentArcadeButton(btnLocalX, btnLocalY, btnLocalW, btnLocalH, "LOCAL", 2);

  drawTransparentArcadeButton(btnHostX, btnHostY, btnHostW, btnHostH, "HOST", 2);

  drawTransparentArcadeButton(btnJoinX, btnJoinY, btnJoinW, btnJoinH, "JOIN", 2);

  drawTransparentArcadeButton(btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH, "RESET SCORE", 2);

  drawTransparentArcadeButton(btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH, "BACK", 2);

  drawGameMenuHighScore(breakoutHiScore);
}

void drawBreakoutPlaceholderScreen(const char *title) {
  appState = STATE_BREAKOUT_PLACEHOLDER;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText(title, 105, 2, RGB565_CYAN);
  drawCenteredText("coming soon", 150, 2, RGB565_YELLOW);

  drawButton(btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
}

// ============================================================================
// PONG GAME
// ============================================================================
// Pong runs locally against CPU or over network. Network mode uses host-owned
// world coordinates and synchronizes paddle, ball, and score state to the joiner.
void drawPongHud() {
  gfx->fillRect(0, 0, screenW, PONG_HUD_H, RGB565_BLACK);
  gfx->drawLine(0, PONG_HUD_H, screenW - 1, PONG_HUD_H, RGB565_CYAN);

  char line[48];
  if (localGame) {
    snprintf(line, sizeof(line), "PLAYER %d   CPU %d", pongPlayerScore, pongCpuScore);
  } else {
    snprintf(line, sizeof(line), "P1 %d   P2 %d", pongPlayerScore, pongCpuScore);
  }

  drawCenteredText(line, 9, 2, RGB565_WHITE);
}

void drawPongControls() {
  gfx->fillRect(0, PONG_PLAY_BOTTOM + 1, screenW,
                screenH - PONG_PLAY_BOTTOM - 1, RGB565_BLACK);
  gfx->drawLine(0, PONG_PLAY_BOTTOM, screenW - 1, PONG_PLAY_BOTTOM, RGB565_CYAN);

  drawButton(btnPongLeftX, btnPongLeftY, btnPongLeftW, btnPongLeftH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "<", 3);

  drawButton(btnPongRightX, btnPongRightY, btnPongRightW, btnPongRightH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, ">", 3);

  drawButton(btnPongMenuX, btnPongMenuY, btnPongMenuW, btnPongMenuH,
             RGB565_RED, RGB565_WHITE, RGB565_WHITE, "MENU", 2);
}

void drawPongCourt() {
  gfx->fillScreen(RGB565_BLACK);
  drawPongHud();

  gfx->drawRect(0, PONG_PLAY_TOP, screenW, PONG_PLAY_BOTTOM - PONG_PLAY_TOP, RGB565_CYAN);

  for (int x = 12; x < screenW - 12; x += 24) {
    gfx->drawLine(x, (PONG_PLAY_TOP + PONG_PLAY_BOTTOM) / 2,
                  x + 12, (PONG_PLAY_TOP + PONG_PLAY_BOTTOM) / 2, RGB565_WHITE);
  }

  drawPongControls();
}

void resetPongBall(int verticalDirection) {
  pongBallX = screenW / 2;
  pongBallY = (PONG_PLAY_TOP + PONG_PLAY_BOTTOM) / 2;
  pongBallVX = (random(0, 2) == 0) ? -2.4 : 2.4;
  pongBallVY = verticalDirection * 3.2;
  pongOldBallX = -1;
  pongOldBallY = -1;
}

void drawPongEntities() {
  if (pongOldBallX >= 0) {
    gfx->fillCircle(pongOldBallX, pongOldBallY, PONG_BALL_R + 1, RGB565_BLACK);
  }

  if (pongOldCpuX >= 0 && pongOldCpuX != pongCpuX) {
    gfx->fillRect(pongOldCpuX, PONG_CPU_Y, PONG_PADDLE_W, PONG_PADDLE_H, RGB565_BLACK);
  }

  if (pongOldPlayerX >= 0 && pongOldPlayerX != pongPlayerX) {
    gfx->fillRect(pongOldPlayerX, PONG_PLAYER_Y, PONG_PADDLE_W, PONG_PADDLE_H, RGB565_BLACK);
  }

  gfx->fillRoundRect(pongCpuX, PONG_CPU_Y, PONG_PADDLE_W, PONG_PADDLE_H, 4, RGB565_RED);
  gfx->drawRoundRect(pongCpuX, PONG_CPU_Y, PONG_PADDLE_W, PONG_PADDLE_H, 4, RGB565_WHITE);

  gfx->fillRoundRect(pongPlayerX, PONG_PLAYER_Y, PONG_PADDLE_W, PONG_PADDLE_H, 4, RGB565_GREEN);
  gfx->drawRoundRect(pongPlayerX, PONG_PLAYER_Y, PONG_PADDLE_W, PONG_PADDLE_H, 4, RGB565_WHITE);

  gfx->fillCircle((int)pongBallX, (int)pongBallY, PONG_BALL_R, RGB565_WHITE);

  pongOldCpuX = pongCpuX;
  pongOldPlayerX = pongPlayerX;
  pongOldBallX = (int)pongBallX;
  pongOldBallY = (int)pongBallY;
}

void drawPongEndOverlay() {
  gfx->fillRoundRect(24, 178, 272, 124, 10, RGB565_BLACK);
  gfx->drawRoundRect(24, 178, 272, 124, 10, RGB565_YELLOW);

  const char *title = "CPU WINS";

  if (localGame) {
    title = (pongWinner == 1) ? "YOU WIN" : "CPU WINS";
  } else {
    title = pongPlayerWon ? "YOU WIN" : "YOU LOSE";
  }

  drawCenteredText(title, 205, 3, pongPlayerWon ? RGB565_GREEN : RGB565_RED);

  char line[32];
  snprintf(line, sizeof(line), "%d - %d", pongPlayerScore, pongCpuScore);
  drawCenteredText(line, 248, 2, RGB565_WHITE);
  drawCenteredText(localGame ? "Tap to restart" : "Tap play again", 280, 1, RGB565_CYAN);
}

void finishPongGame(int winnerPlayer) {
  if (pongGameOver) return;

  pongWinner = winnerPlayer;
  pongGameOver = true;
  pongPlayerWon = localGame ? (winnerPlayer == 1) :
                  ((myPlayer == '1' && winnerPlayer == 1) ||
                   (myPlayer == '2' && winnerPlayer == 2));

  if (winnerPlayer == 1) {
    pongWinsP1++;
    savePongScore();
  } else if (winnerPlayer == 2) {
    pongWinsP2++;
    savePongScore();
  }

  drawPongHud();
  drawPongEndOverlay();

  if (pongPlayerWon) {
    beepWin();
  } else {
    beepDraw();
  }
}

void newPongMatch() {
  pongPlayerScore = 0;
  pongCpuScore = 0;
  pongWinner = 0;
  pongGameOver = false;
  pongPlayerWon = false;
  pongPlayerX = (screenW - PONG_PADDLE_W) / 2;
  pongCpuX = (screenW - PONG_PADDLE_W) / 2;
  pongOldPlayerX = -1;
  pongOldCpuX = -1;
  pongLastSentPaddleX = -1;
  pongLastStateSendTime = 0;

  drawPongCourt();
  resetPongBall(1);
  drawPongEntities();
  pongLastFrame = millis();
}

int getLocalPongPaddleX() {
  if (!localGame && myPlayer == '2') {
    return pongCpuX;
  }

  return pongPlayerX;
}

void setLocalPongPaddleX(int value) {
  value = constrain(value, 4, screenW - PONG_PADDLE_W - 4);

  if (!localGame && myPlayer == '2') {
    pongCpuX = value;
  } else {
    pongPlayerX = value;
  }
}

void sendLocalPongPaddleIfNeeded() {
  if (localGame || !networkConnected) return;

  int x = getLocalPongPaddleX();

  if (x == pongLastSentPaddleX) return;

  pongLastSentPaddleX = x;
  sendNetMessage("PN_PAD:" + String(x));
}

void sendPongState(bool force = false) {
  if (localGame || !isHost || !networkConnected) return;

  unsigned long now = millis();

  if (!force && now - pongLastStateSendTime < PONG_NET_STATE_MS) {
    return;
  }

  pongLastStateSendTime = now;

  String msg = "PN_STATE:";
  msg += String((int)pongBallX);
  msg += ",";
  msg += String((int)pongBallY);
  msg += ",";
  msg += String((int)(pongBallVX * 100.0f));
  msg += ",";
  msg += String((int)(pongBallVY * 100.0f));
  msg += ",";
  msg += String(pongPlayerX);
  msg += ",";
  msg += String(pongCpuX);
  msg += ",";
  msg += String(pongPlayerScore);
  msg += ",";
  msg += String(pongCpuScore);
  msg += ",";
  msg += String(pongWinner);
  sendNetMessage(msg);
}

bool readCsvInt(const String &payload, int &start, int &value) {
  int comma = payload.indexOf(',', start);
  String part;

  if (comma < 0) {
    part = payload.substring(start);
    start = payload.length();
  } else {
    part = payload.substring(start, comma);
    start = comma + 1;
  }

  if (part.length() == 0) return false;

  value = part.toInt();
  return true;
}

void applyRemotePongPaddle(int x) {
  activeNetworkGame = NETWORK_GAME_PONG;
  x = constrain(x, 4, screenW - PONG_PADDLE_W - 4);

  if (isHost) {
    pongCpuX = x;
  } else {
    pongPlayerX = x;
  }
}

void applyRemotePongState(const String &payload) {
  activeNetworkGame = NETWORK_GAME_PONG;

  int start = 0;
  int ballX, ballY, ballVX100, ballVY100, p1X, p2X, p1Score, p2Score, winner;

  if (!readCsvInt(payload, start, ballX)) return;
  if (!readCsvInt(payload, start, ballY)) return;
  if (!readCsvInt(payload, start, ballVX100)) return;
  if (!readCsvInt(payload, start, ballVY100)) return;
  if (!readCsvInt(payload, start, p1X)) return;
  if (!readCsvInt(payload, start, p2X)) return;
  if (!readCsvInt(payload, start, p1Score)) return;
  if (!readCsvInt(payload, start, p2Score)) return;
  if (!readCsvInt(payload, start, winner)) return;

  bool redrawCourt = (p1Score != pongPlayerScore) ||
                     (p2Score != pongCpuScore) ||
                     (winner != pongWinner);

  pongBallX = ballX;
  pongBallY = ballY;
  pongBallVX = (float)ballVX100 / 100.0f;
  pongBallVY = (float)ballVY100 / 100.0f;
  pongPlayerX = constrain(p1X, 4, screenW - PONG_PADDLE_W - 4);

  // Player 2 owns the upper paddle locally. Keeping it from being overwritten
  // by slightly older host state avoids visible paddle snap-back near hits.
  if (myPlayer != '2') {
    pongCpuX = constrain(p2X, 4, screenW - PONG_PADDLE_W - 4);
  }

  pongPlayerScore = p1Score;
  pongCpuScore = p2Score;

  if (redrawCourt) {
    pongOldBallX = -1;
    pongOldBallY = -1;
    pongOldPlayerX = -1;
    pongOldCpuX = -1;
    drawPongCourt();
  }

  if (winner > 0) {
    finishPongGame(winner);
    return;
  }
}

void predictPongClientPaddleBounce() {
  if (localGame || isHost || myPlayer != '2') return;
  if (pongBallVY >= 0) return;
  if (pongBallY - PONG_BALL_R > PONG_CPU_Y + PONG_PADDLE_H) return;
  if (pongBallY + PONG_BALL_R < PONG_CPU_Y) return;
  if (pongBallX < pongCpuX - PONG_BALL_R - PONG_REMOTE_HIT_MARGIN) return;
  if (pongBallX > pongCpuX + PONG_PADDLE_W + PONG_BALL_R + PONG_REMOTE_HIT_MARGIN) return;

  pongBallY = PONG_CPU_Y + PONG_PADDLE_H + PONG_BALL_R;
  pongBallVY = fabs(pongBallVY);

  float offset = (pongBallX - (pongCpuX + PONG_PADDLE_W / 2.0)) / (PONG_PADDLE_W / 2.0);
  pongBallVX = offset * 3.8;
}

void updatePongGame() {
  if (appState != STATE_PONG_PLAYING) return;

  unsigned long now = millis();
  if (now - pongLastFrame < PONG_FRAME_MS) return;
  pongLastFrame = now;

  if (pongGameOver) return;

  int localPaddleX = getLocalPongPaddleX();

  if (pongTouchDown &&
      inRect(pongTouchX, pongTouchY, btnPongLeftX, btnPongLeftY, btnPongLeftW, btnPongLeftH)) {
    localPaddleX -= PONG_PLAYER_SPEED;
  }

  if (pongTouchDown &&
      inRect(pongTouchX, pongTouchY, btnPongRightX, btnPongRightY, btnPongRightW, btnPongRightH)) {
    localPaddleX += PONG_PLAYER_SPEED;
  }

  if (pongTouchDown && pongTouchY > 255 && pongTouchY < PONG_PLAY_BOTTOM) {
    localPaddleX = pongTouchX - PONG_PADDLE_W / 2;
  }

  setLocalPongPaddleX(localPaddleX);
  sendLocalPongPaddleIfNeeded();

  if (!localGame && !isHost) {
    pongBallX += pongBallVX;
    pongBallY += pongBallVY;

    if (pongBallX <= PONG_BALL_R) {
      pongBallX = PONG_BALL_R;
      pongBallVX = fabs(pongBallVX);
    } else if (pongBallX >= screenW - PONG_BALL_R) {
      pongBallX = screenW - PONG_BALL_R;
      pongBallVX = -fabs(pongBallVX);
    }

    if (pongBallY < PONG_PLAY_TOP) {
      pongBallY = PONG_PLAY_TOP;
    } else if (pongBallY > PONG_PLAY_BOTTOM) {
      pongBallY = PONG_PLAY_BOTTOM;
    }

    predictPongClientPaddleBounce();
    drawPongEntities();
    return;
  }

  if (localGame) {
    int cpuTargetX = (int)pongBallX - PONG_PADDLE_W / 2;
    if (pongCpuX + PONG_PADDLE_W / 2 < cpuTargetX + PONG_PADDLE_W / 2) {
      pongCpuX += PONG_CPU_SPEED;
    } else if (pongCpuX + PONG_PADDLE_W / 2 > cpuTargetX + PONG_PADDLE_W / 2) {
      pongCpuX -= PONG_CPU_SPEED;
    }

    pongCpuX = constrain(pongCpuX, 4, screenW - PONG_PADDLE_W - 4);
  }

  pongBallX += pongBallVX;
  pongBallY += pongBallVY;

  if (pongBallX <= PONG_BALL_R) {
    pongBallX = PONG_BALL_R;
    pongBallVX = -pongBallVX;
    beepClick();
  } else if (pongBallX >= screenW - PONG_BALL_R) {
    pongBallX = screenW - PONG_BALL_R;
    pongBallVX = -pongBallVX;
    beepClick();
  }

  int cpuHitMargin = (!localGame && isHost) ? PONG_REMOTE_HIT_MARGIN : 0;

  if (pongBallVY < 0 &&
      pongBallY - PONG_BALL_R <= PONG_CPU_Y + PONG_PADDLE_H &&
      pongBallY + PONG_BALL_R >= PONG_CPU_Y &&
      pongBallX >= pongCpuX - PONG_BALL_R - cpuHitMargin &&
      pongBallX <= pongCpuX + PONG_PADDLE_W + PONG_BALL_R + cpuHitMargin) {
    pongBallY = PONG_CPU_Y + PONG_PADDLE_H + PONG_BALL_R;
    pongBallVY = fabs(pongBallVY);
    float offset = (pongBallX - (pongCpuX + PONG_PADDLE_W / 2.0)) / (PONG_PADDLE_W / 2.0);
    pongBallVX = offset * 3.8;
    beepMove();
  }

  if (pongBallVY > 0 &&
      pongBallY + PONG_BALL_R >= PONG_PLAYER_Y &&
      pongBallY - PONG_BALL_R <= PONG_PLAYER_Y + PONG_PADDLE_H &&
      pongBallX >= pongPlayerX - PONG_BALL_R &&
      pongBallX <= pongPlayerX + PONG_PADDLE_W + PONG_BALL_R) {
    pongBallY = PONG_PLAYER_Y - PONG_BALL_R;
    pongBallVY = -fabs(pongBallVY);
    float offset = (pongBallX - (pongPlayerX + PONG_PADDLE_W / 2.0)) / (PONG_PADDLE_W / 2.0);
    pongBallVX = offset * 3.8;
    beepMove();
  }

  if (pongBallY < PONG_PLAY_TOP) {
    pongPlayerScore++;
    drawPongCourt();

    if (pongPlayerScore >= PONG_SCORE_LIMIT) {
      finishPongGame(1);
      sendPongState(true);
      return;
    }

    resetPongBall(-1);
    sendPongState(true);
  } else if (pongBallY > PONG_PLAY_BOTTOM) {
    pongCpuScore++;
    drawPongCourt();

    if (pongCpuScore >= PONG_SCORE_LIMIT) {
      finishPongGame(2);
      sendPongState(true);
      return;
    }

    resetPongBall(1);
    sendPongState(true);
  }

  drawPongEntities();
  sendPongState();
}

void startPongLocalGame() {
  activeNetworkGame = NETWORK_GAME_PONG;
  stopNetwork();
  localGame = true;
  appState = STATE_PONG_PLAYING;
  beepStart();
  newPongMatch();
}

void startPongNetworkGame() {
  activeNetworkGame = NETWORK_GAME_PONG;
  localGame = false;
  myTurn = true;
  appState = STATE_PONG_PLAYING;
  beepStart();
  newPongMatch();

  if (!isHost) {
    drawCenteredText("Waiting host", 184, 2, RGB565_YELLOW);
  } else {
    sendPongState(true);
  }
}

void drawPongMenuScreen() {
  activeNetworkGame = NETWORK_GAME_PONG;
  localGame = false;
  appState = STATE_PONG;
  drawPongArcadeHome();

  drawTransparentArcadeButton(btnLocalX, btnLocalY, btnLocalW, btnLocalH, "LOCAL", 2);

  drawTransparentArcadeButton(btnHostX, btnHostY, btnHostW, btnHostH, "HOST", 2);

  drawTransparentArcadeButton(btnJoinX, btnJoinY, btnJoinW, btnJoinH, "JOIN", 2);

  drawTransparentArcadeButton(btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH, "RESET SCORE", 2);

  drawTransparentArcadeButton(btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH, "BACK", 2);

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "SCORE  P1:%d  P2:%d", pongWinsP1, pongWinsP2);
  drawGameMenuScoreAndHigh(scoreLine, highestOfTwo(pongWinsP1, pongWinsP2));
}

void drawPongPlaceholderScreen(const char *title) {
  appState = STATE_PONG_PLACEHOLDER;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText(title, 105, 2, RGB565_CYAN);
  drawCenteredText("coming soon", 150, 2, RGB565_YELLOW);

  drawButton(btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
}

void drawSnakeMenuScreen() {
  activeNetworkGame = NETWORK_GAME_SNAKE;
  localGame = false;
  appState = STATE_SNAKE;
  drawSnakeArcadeHome();

  drawTransparentArcadeButton(btnLocalX, btnLocalY, btnLocalW, btnLocalH, "LOCAL", 2);

  drawTransparentArcadeButton(btnHostX, btnHostY, btnHostW, btnHostH, "HOST", 2);

  drawTransparentArcadeButton(btnJoinX, btnJoinY, btnJoinW, btnJoinH, "JOIN", 2);

  drawTransparentArcadeButton(btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH, "RESET SCORE", 2);

  drawTransparentArcadeButton(btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH, "BACK", 2);

  drawGameMenuHighScore(snakeHiScore);
}

void drawSnakePlaceholderScreen(const char *title) {
  appState = STATE_SNAKE_PLACEHOLDER;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText(title, 105, 3, RGB565_GREEN);
  drawCenteredText("coming soon", 152, 2, RGB565_YELLOW);

  drawButton(btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
}

void drawSnakeHud() {
  gfx->fillRect(0, 0, screenW, 42, RGB565_BLACK);
  gfx->drawLine(0, 42, screenW - 1, 42, RGB565_GREEN);

  char line[32];

  if (localGame) {
    snprintf(line, sizeof(line), "SNAKE  SCORE:%d", snakeScore);
  } else {
    snprintf(line, sizeof(line), "P1:%d  P2:%d", snakeNetScore[0], snakeNetScore[1]);
  }

  gfx->setTextSize(2);
  gfx->setTextColor(RGB565_WHITE);
  gfx->setCursor(10, 12);
  gfx->print(line);

  drawButton(btnSnakeMenuX, btnSnakeMenuY, btnSnakeMenuW, btnSnakeMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENU", 1);
}

void drawSnakeControls() {
  gfx->fillRect(0, 358, screenW, screenH - 358, RGB565_BLACK);
  gfx->drawLine(0, 358, screenW - 1, 358, RGB565_GREEN);

  drawButton(btnSnakeUpX, btnSnakeUpY, btnSnakeDirW, btnSnakeDirH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "UP", 2);
  drawButton(btnSnakeLeftX, btnSnakeLeftY, btnSnakeDirW, btnSnakeDirH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "LEFT", 1);
  drawButton(btnSnakeDownX, btnSnakeDownY, btnSnakeDirW, btnSnakeDirH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "DOWN", 1);
  drawButton(btnSnakeRightX, btnSnakeRightY, btnSnakeDirW, btnSnakeDirH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "RIGHT", 1);
}

void drawSnakeBoardFrame() {
  int boardW = SNAKE_GRID_COLS * SNAKE_CELL;
  int boardH = SNAKE_GRID_ROWS * SNAKE_CELL;

  gfx->fillRect(SNAKE_BOARD_X - 2, SNAKE_BOARD_Y - 2, boardW + 4, boardH + 4, RGB565_GREEN);
  gfx->fillRect(SNAKE_BOARD_X, SNAKE_BOARD_Y, boardW, boardH, RGB565_BLACK);

  uint16_t gridColor = rgb888to565(6, 38, 20);

  for (int c = 1; c < SNAKE_GRID_COLS; c++) {
    int x = SNAKE_BOARD_X + c * SNAKE_CELL;
    gfx->drawLine(x, SNAKE_BOARD_Y, x, SNAKE_BOARD_Y + boardH - 1, gridColor);
  }

  for (int r = 1; r < SNAKE_GRID_ROWS; r++) {
    int y = SNAKE_BOARD_Y + r * SNAKE_CELL;
    gfx->drawLine(SNAKE_BOARD_X, y, SNAKE_BOARD_X + boardW - 1, y, gridColor);
  }
}

void drawSnakeCell(int col, int row, uint16_t fillColor, uint16_t borderColor) {
  int x = SNAKE_BOARD_X + col * SNAKE_CELL + 1;
  int y = SNAKE_BOARD_Y + row * SNAKE_CELL + 1;

  gfx->fillRoundRect(x, y, SNAKE_CELL - 2, SNAKE_CELL - 2, 3, fillColor);
  gfx->drawRoundRect(x, y, SNAKE_CELL - 2, SNAKE_CELL - 2, 3, borderColor);
}

void drawSnakePlayerCell(int col, int row, int playerIndex, bool isHead) {
  uint16_t fillColor;
  uint16_t borderColor;

  if (playerIndex == 0) {
    fillColor = isHead ? RGB565_YELLOW : RGB565_GREEN;
    borderColor = isHead ? RGB565_WHITE : RGB565_CYAN;
  } else {
    fillColor = isHead ? rgb888to565(255, 0, 180) : RGB565_BLUE;
    borderColor = isHead ? RGB565_WHITE : RGB565_CYAN;
  }

  drawSnakeCell(col, row, fillColor, borderColor);
}

void clearSnakeCell(int col, int row) {
  int x = SNAKE_BOARD_X + col * SNAKE_CELL + 1;
  int y = SNAKE_BOARD_Y + row * SNAKE_CELL + 1;

  gfx->fillRect(x, y, SNAKE_CELL - 2, SNAKE_CELL - 2, RGB565_BLACK);
}

bool snakeCellOccupied(int col, int row, int limit) {
  for (int i = 0; i < limit; i++) {
    if (snakeX[i] == col && snakeY[i] == row) {
      return true;
    }
  }

  return false;
}

void placeSnakeFood() {
  for (int attempt = 0; attempt < 300; attempt++) {
    int col = random(0, SNAKE_GRID_COLS);
    int row = random(0, SNAKE_GRID_ROWS);

    if (!snakeCellOccupied(col, row, snakeLength)) {
      snakeFoodX = col;
      snakeFoodY = row;
      return;
    }
  }

  for (int row = 0; row < SNAKE_GRID_ROWS; row++) {
    for (int col = 0; col < SNAKE_GRID_COLS; col++) {
      if (!snakeCellOccupied(col, row, snakeLength)) {
        snakeFoodX = col;
        snakeFoodY = row;
        return;
      }
    }
  }
}

void drawSnakeFood() {
  int cx = SNAKE_BOARD_X + snakeFoodX * SNAKE_CELL + SNAKE_CELL / 2;
  int cy = SNAKE_BOARD_Y + snakeFoodY * SNAKE_CELL + SNAKE_CELL / 2;

  gfx->fillCircle(cx, cy, 5, RGB565_RED);
  gfx->drawCircle(cx, cy, 6, RGB565_YELLOW);
}

void drawSnakeBody() {
  for (int i = snakeLength - 1; i >= 0; i--) {
    if (i == 0) {
      drawSnakeCell(snakeX[i], snakeY[i], RGB565_YELLOW, RGB565_WHITE);
    } else {
      drawSnakeCell(snakeX[i], snakeY[i], RGB565_GREEN, RGB565_CYAN);
    }
  }
}

void drawSnakePlayArea() {
  drawSnakeBoardFrame();
  drawSnakeFood();
  drawSnakeBody();
}

int snakeCellIndex(int col, int row) {
  return row * SNAKE_GRID_COLS + col;
}

bool snakeNetworkCellOccupied(int col, int row, int ignorePlayer, int ignoreTailIfNotGrowing) {
  for (int p = 0; p < 2; p++) {
    int limit = snakeNetLength[p];

    if (p == ignorePlayer && ignoreTailIfNotGrowing) {
      limit--;
    }

    for (int i = 0; i < limit; i++) {
      if (snakeNetX[p][i] == col && snakeNetY[p][i] == row) {
        return true;
      }
    }
  }

  return false;
}

void placeSnakeNetworkFood() {
  for (int attempt = 0; attempt < 300; attempt++) {
    int col = random(0, SNAKE_GRID_COLS);
    int row = random(0, SNAKE_GRID_ROWS);

    if (!snakeNetworkCellOccupied(col, row, -1, false)) {
      snakeFoodX = col;
      snakeFoodY = row;
      return;
    }
  }

  for (int row = 0; row < SNAKE_GRID_ROWS; row++) {
    for (int col = 0; col < SNAKE_GRID_COLS; col++) {
      if (!snakeNetworkCellOccupied(col, row, -1, false)) {
        snakeFoodX = col;
        snakeFoodY = row;
        return;
      }
    }
  }
}

void resetSnakeDrawCache() {
  for (int i = 0; i < SNAKE_MAX_LEN; i++) {
    snakeDrawOwner[i] = 0;
    snakeDrawHead[i] = 0;
  }

  snakeDrawFoodCell = -1;
  snakeDrawReady = false;
}

void drawSnakeNetworkGameOverOverlay() {
  gfx->fillRoundRect(28, 162, 264, 150, 10, RGB565_BLACK);
  gfx->drawRoundRect(28, 162, 264, 150, 10, RGB565_RED);
  gfx->drawRoundRect(33, 167, 254, 140, 8, RGB565_YELLOW);

  if (snakeNetWinner == 1) {
    drawCenteredText("P1 WINS", 188, 3, RGB565_GREEN);
  } else if (snakeNetWinner == 2) {
    drawCenteredText("P2 WINS", 188, 3, RGB565_CYAN);
  } else {
    drawCenteredText("DRAW", 188, 3, RGB565_YELLOW);
  }

  char line[32];
  snprintf(line, sizeof(line), "P1:%d   P2:%d", snakeNetScore[0], snakeNetScore[1]);
  drawCenteredText(line, 238, 2, RGB565_WHITE);
  drawCenteredText("Tap to restart", 272, 1, RGB565_CYAN);
}

void drawSnakeNetworkState(bool fullRedraw) {
  static uint8_t newOwner[SNAKE_MAX_LEN];
  static uint8_t newHead[SNAKE_MAX_LEN];

  for (int i = 0; i < SNAKE_MAX_LEN; i++) {
    newOwner[i] = 0;
    newHead[i] = 0;
  }

  for (int p = 0; p < 2; p++) {
    for (int i = 0; i < snakeNetLength[p]; i++) {
      int idx = snakeCellIndex(snakeNetX[p][i], snakeNetY[p][i]);

      if (idx >= 0 && idx < SNAKE_MAX_LEN) {
        newOwner[idx] = p + 1;
        newHead[idx] = (i == 0) ? 1 : 0;
      }
    }
  }

  if (fullRedraw || !snakeDrawReady) {
    drawSnakeHud();
    drawSnakeBoardFrame();
    drawSnakeControls();
    resetSnakeDrawCache();
    snakeDrawReady = true;
  }

  for (int idx = 0; idx < SNAKE_MAX_LEN; idx++) {
    if (snakeDrawOwner[idx] == newOwner[idx] && snakeDrawHead[idx] == newHead[idx]) {
      continue;
    }

    int col = idx % SNAKE_GRID_COLS;
    int row = idx / SNAKE_GRID_COLS;

    clearSnakeCell(col, row);

    if (newOwner[idx] > 0) {
      drawSnakePlayerCell(col, row, newOwner[idx] - 1, newHead[idx] == 1);
    }

    snakeDrawOwner[idx] = newOwner[idx];
    snakeDrawHead[idx] = newHead[idx];
  }

  int newFoodCell = snakeCellIndex(snakeFoodX, snakeFoodY);

  if (snakeDrawFoodCell != newFoodCell) {
    if (snakeDrawFoodCell >= 0 && snakeDrawFoodCell < SNAKE_MAX_LEN &&
        newOwner[snakeDrawFoodCell] == 0) {
      clearSnakeCell(snakeDrawFoodCell % SNAKE_GRID_COLS,
                     snakeDrawFoodCell / SNAKE_GRID_COLS);
    }

    snakeDrawFoodCell = newFoodCell;
  }

  if (newFoodCell >= 0 && newFoodCell < SNAKE_MAX_LEN && newOwner[newFoodCell] == 0) {
    drawSnakeFood();
  }

  if (snakeNetGameOver) {
    drawSnakeHud();
    drawSnakeNetworkGameOverOverlay();
  }
}

void drawSnakeGameOverOverlay() {
  gfx->fillRoundRect(28, 168, 264, 132, 10, RGB565_BLACK);
  gfx->drawRoundRect(28, 168, 264, 132, 10, RGB565_RED);
  gfx->drawRoundRect(33, 173, 254, 122, 8, RGB565_YELLOW);

  drawCenteredText("GAME OVER", 190, 3, RGB565_RED);

  char line[32];
  snprintf(line, sizeof(line), "SCORE: %d", snakeScore);
  drawCenteredText(line, 238, 2, RGB565_WHITE);
  drawCenteredText("Tap to restart", 270, 1, RGB565_CYAN);
}

void drawSnakeGameScreen() {
  appState = STATE_SNAKE_PLAYING;
  gfx->fillScreen(RGB565_BLACK);
  drawSnakeHud();
  drawSnakePlayArea();
  drawSnakeControls();

  if (snakeGameOver) {
    drawSnakeGameOverOverlay();
  }
}

void newSnakeGame() {
  activeNetworkGame = NETWORK_GAME_SNAKE;
  localGame = true;
  snakeLength = 5;
  snakeDir = SNAKE_DIR_RIGHT;
  snakeNextDir = SNAKE_DIR_RIGHT;
  snakeScore = 0;
  snakeGameOver = false;

  int startX = SNAKE_GRID_COLS / 2;
  int startY = SNAKE_GRID_ROWS / 2;

  for (int i = 0; i < snakeLength; i++) {
    snakeX[i] = startX - i;
    snakeY[i] = startY;
  }

  placeSnakeFood();
  snakeLastFrame = millis();
  drawSnakeGameScreen();
}

bool snakeDirectionsAreOpposite(int a, int b) {
  return (a == SNAKE_DIR_UP && b == SNAKE_DIR_DOWN) ||
         (a == SNAKE_DIR_DOWN && b == SNAKE_DIR_UP) ||
         (a == SNAKE_DIR_LEFT && b == SNAKE_DIR_RIGHT) ||
         (a == SNAKE_DIR_RIGHT && b == SNAKE_DIR_LEFT);
}

void setSnakeDirection(int dir) {
  if (snakeDirectionsAreOpposite(dir, snakeDir)) return;
  snakeNextDir = dir;
}

void finishSnakeGame() {
  snakeGameOver = true;

  if ((uint32_t)snakeScore > snakeHiScore) {
    snakeHiScore = snakeScore;
    saveSnakeScore();
  }

  beepDraw();
  drawSnakeHud();
  drawSnakeGameOverOverlay();
}

void updateSnakeGame() {
  if (appState != STATE_SNAKE_PLAYING) return;

  if (!localGame) {
    if (!isHost || snakeNetGameOver) return;

    unsigned long now = millis();
    unsigned long frameMs = SNAKE_FRAME_MS - (unsigned long)constrain((snakeNetScore[0] + snakeNetScore[1]) * 2, 0, 45);

    if (now - snakeLastFrame < frameMs) return;
    snakeLastFrame = now;

    int nextX[2];
    int nextY[2];
    bool willGrow[2];
    bool willDie[2] = {false, false};

    for (int p = 0; p < 2; p++) {
      snakeNetDir[p] = snakeNetNextDir[p];
      nextX[p] = snakeNetX[p][0];
      nextY[p] = snakeNetY[p][0];

      if (snakeNetDir[p] == SNAKE_DIR_UP) nextY[p]--;
      if (snakeNetDir[p] == SNAKE_DIR_RIGHT) nextX[p]++;
      if (snakeNetDir[p] == SNAKE_DIR_DOWN) nextY[p]++;
      if (snakeNetDir[p] == SNAKE_DIR_LEFT) nextX[p]--;

      willGrow[p] = (nextX[p] == snakeFoodX && nextY[p] == snakeFoodY);

      if (nextX[p] < 0 || nextX[p] >= SNAKE_GRID_COLS ||
          nextY[p] < 0 || nextY[p] >= SNAKE_GRID_ROWS) {
        willDie[p] = true;
      }
    }

    if (!willDie[0] && !willDie[1]) {
      if (nextX[0] == nextX[1] && nextY[0] == nextY[1]) {
        willDie[0] = true;
        willDie[1] = true;
      }

      if (nextX[0] == snakeNetX[1][0] && nextY[0] == snakeNetY[1][0] &&
          nextX[1] == snakeNetX[0][0] && nextY[1] == snakeNetY[0][0]) {
        willDie[0] = true;
        willDie[1] = true;
      }
    }

    for (int p = 0; p < 2; p++) {
      if (willDie[p]) continue;

      int ownLimit = willGrow[p] ? snakeNetLength[p] : snakeNetLength[p] - 1;

      for (int i = 0; i < ownLimit; i++) {
        if (snakeNetX[p][i] == nextX[p] && snakeNetY[p][i] == nextY[p]) {
          willDie[p] = true;
          break;
        }
      }

      int other = 1 - p;
      int otherLimit = willGrow[other] ? snakeNetLength[other] : snakeNetLength[other] - 1;

      for (int i = 0; i < otherLimit && !willDie[p]; i++) {
        if (snakeNetX[other][i] == nextX[p] && snakeNetY[other][i] == nextY[p]) {
          willDie[p] = true;
        }
      }
    }

    for (int p = 0; p < 2; p++) {
      if (willDie[p]) {
        snakeNetAlive[p] = false;
        continue;
      }

      if (willGrow[p] && snakeNetLength[p] < SNAKE_MAX_LEN) {
        snakeNetLength[p]++;
        snakeNetScore[p]++;
      }

      for (int i = snakeNetLength[p] - 1; i > 0; i--) {
        snakeNetX[p][i] = snakeNetX[p][i - 1];
        snakeNetY[p][i] = snakeNetY[p][i - 1];
      }

      snakeNetX[p][0] = nextX[p];
      snakeNetY[p][0] = nextY[p];
    }

    if (!snakeNetAlive[0] || !snakeNetAlive[1]) {
      snakeNetGameOver = true;

      if (snakeNetAlive[0] && !snakeNetAlive[1]) {
        snakeNetWinner = 1;
      } else if (!snakeNetAlive[0] && snakeNetAlive[1]) {
        snakeNetWinner = 2;
      } else {
        snakeNetWinner = 3;
      }

      beepDraw();
    } else if (willGrow[0] || willGrow[1]) {
      placeSnakeNetworkFood();
      beepMove();
    }

    drawSnakeHud();
    drawSnakeNetworkState(false);
    sendSnakeState();
    return;
  }

  if (snakeGameOver) return;

  unsigned long now = millis();
  unsigned long frameMs = SNAKE_FRAME_MS - (unsigned long)constrain(snakeScore * 3, 0, 55);

  if (now - snakeLastFrame < frameMs) return;
  snakeLastFrame = now;

  snakeDir = snakeNextDir;

  int oldHeadX = snakeX[0];
  int oldHeadY = snakeY[0];
  int oldTailX = snakeX[snakeLength - 1];
  int oldTailY = snakeY[snakeLength - 1];
  int nextX = snakeX[0];
  int nextY = snakeY[0];

  if (snakeDir == SNAKE_DIR_UP) nextY--;
  if (snakeDir == SNAKE_DIR_RIGHT) nextX++;
  if (snakeDir == SNAKE_DIR_DOWN) nextY++;
  if (snakeDir == SNAKE_DIR_LEFT) nextX--;

  bool willGrow = (nextX == snakeFoodX && nextY == snakeFoodY);
  int bodyCheckLimit = willGrow ? snakeLength : snakeLength - 1;

  if (nextX < 0 || nextX >= SNAKE_GRID_COLS ||
      nextY < 0 || nextY >= SNAKE_GRID_ROWS ||
      snakeCellOccupied(nextX, nextY, bodyCheckLimit)) {
    finishSnakeGame();
    return;
  }

  if (willGrow && snakeLength < SNAKE_MAX_LEN) {
    snakeLength++;
    snakeScore++;

    if ((uint32_t)snakeScore > snakeHiScore) {
      snakeHiScore = snakeScore;
      saveSnakeScore();
    }

    beepMove();
  }

  for (int i = snakeLength - 1; i > 0; i--) {
    snakeX[i] = snakeX[i - 1];
    snakeY[i] = snakeY[i - 1];
  }

  snakeX[0] = nextX;
  snakeY[0] = nextY;

  if (willGrow) {
    if (snakeLength >= SNAKE_MAX_LEN) {
      finishSnakeGame();
      return;
    }

    placeSnakeFood();
    drawSnakeHud();
  } else {
    clearSnakeCell(oldTailX, oldTailY);
  }

  drawSnakeCell(oldHeadX, oldHeadY, RGB565_GREEN, RGB565_CYAN);
  drawSnakeFood();
  drawSnakeCell(snakeX[0], snakeY[0], RGB565_YELLOW, RGB565_WHITE);
}

void setSnakeNetworkDirection(int playerIndex, int dir) {
  if (playerIndex < 0 || playerIndex > 1) return;
  if (snakeDirectionsAreOpposite(dir, snakeNetDir[playerIndex])) return;
  if (snakeDirectionsAreOpposite(dir, snakeNetNextDir[playerIndex])) return;

  snakeNetNextDir[playerIndex] = dir;
}

void applySnakeDirectionInput(int dir) {
  if (localGame) {
    setSnakeDirection(dir);
    return;
  }

  int playerIndex = (myPlayer == '2') ? 1 : 0;
  setSnakeNetworkDirection(playerIndex, dir);

  if (!isHost) {
    sendNetMessage("SN_DIR:" + String(dir));
  }
}

void sendSnakeState() {
  if (localGame || !isHost || !networkConnected) return;

  String msg = "SN_STATE:";
  msg.reserve(80 + (snakeNetLength[0] + snakeNetLength[1]) * 4);

  msg += String(snakeNetGameOver ? 1 : 0);
  msg += ",";
  msg += String(snakeNetWinner);
  msg += ",";
  msg += String(snakeFoodX);
  msg += ",";
  msg += String(snakeFoodY);
  msg += ",";
  msg += String(snakeNetScore[0]);
  msg += ",";
  msg += String(snakeNetScore[1]);
  msg += ",";
  msg += String(snakeNetAlive[0] ? 1 : 0);
  msg += ",";
  msg += String(snakeNetAlive[1] ? 1 : 0);

  for (int p = 0; p < 2; p++) {
    msg += ",";
    msg += String(snakeNetLength[p]);

    for (int i = 0; i < snakeNetLength[p]; i++) {
      msg += ",";
      msg += String(snakeCellIndex(snakeNetX[p][i], snakeNetY[p][i]));
    }
  }

  sendNetMessage(msg);
}

void applyRemoteSnakeState(const String &payload) {
  activeNetworkGame = NETWORK_GAME_SNAKE;

  int start = 0;
  int gameOverValue, winnerValue, foodX, foodY, scoreP1, scoreP2, aliveP1, aliveP2;

  if (!readCsvInt(payload, start, gameOverValue)) return;
  if (!readCsvInt(payload, start, winnerValue)) return;
  if (!readCsvInt(payload, start, foodX)) return;
  if (!readCsvInt(payload, start, foodY)) return;
  if (!readCsvInt(payload, start, scoreP1)) return;
  if (!readCsvInt(payload, start, scoreP2)) return;
  if (!readCsvInt(payload, start, aliveP1)) return;
  if (!readCsvInt(payload, start, aliveP2)) return;

  snakeNetGameOver = (gameOverValue != 0);
  snakeNetWinner = winnerValue;
  snakeFoodX = constrain(foodX, 0, SNAKE_GRID_COLS - 1);
  snakeFoodY = constrain(foodY, 0, SNAKE_GRID_ROWS - 1);
  snakeNetScore[0] = scoreP1;
  snakeNetScore[1] = scoreP2;
  snakeNetAlive[0] = (aliveP1 != 0);
  snakeNetAlive[1] = (aliveP2 != 0);

  for (int p = 0; p < 2; p++) {
    int len;

    if (!readCsvInt(payload, start, len)) return;

    snakeNetLength[p] = constrain(len, 0, SNAKE_MAX_LEN);

    for (int i = 0; i < snakeNetLength[p]; i++) {
      int cell;

      if (!readCsvInt(payload, start, cell)) return;

      cell = constrain(cell, 0, SNAKE_MAX_LEN - 1);
      snakeNetX[p][i] = cell % SNAKE_GRID_COLS;
      snakeNetY[p][i] = cell / SNAKE_GRID_COLS;
    }

    if (snakeNetLength[p] > 1) {
      int dx = snakeNetX[p][0] - snakeNetX[p][1];
      int dy = snakeNetY[p][0] - snakeNetY[p][1];

      if (dx > 0) snakeNetDir[p] = SNAKE_DIR_RIGHT;
      else if (dx < 0) snakeNetDir[p] = SNAKE_DIR_LEFT;
      else if (dy > 0) snakeNetDir[p] = SNAKE_DIR_DOWN;
      else if (dy < 0) snakeNetDir[p] = SNAKE_DIR_UP;

      if (snakeDirectionsAreOpposite(snakeNetNextDir[p], snakeNetDir[p])) {
        snakeNetNextDir[p] = snakeNetDir[p];
      }
    }
  }

  drawSnakeHud();
  drawSnakeNetworkState(false);
}

void newSnakeNetworkGame() {
  activeNetworkGame = NETWORK_GAME_SNAKE;
  localGame = false;
  appState = STATE_SNAKE_PLAYING;
  snakeNetLength[0] = 5;
  snakeNetLength[1] = 5;
  snakeNetDir[0] = SNAKE_DIR_RIGHT;
  snakeNetDir[1] = SNAKE_DIR_LEFT;
  snakeNetNextDir[0] = SNAKE_DIR_RIGHT;
  snakeNetNextDir[1] = SNAKE_DIR_LEFT;
  snakeNetScore[0] = 0;
  snakeNetScore[1] = 0;
  snakeNetAlive[0] = true;
  snakeNetAlive[1] = true;
  snakeNetGameOver = false;
  snakeNetWinner = 0;

  for (int i = 0; i < snakeNetLength[0]; i++) {
    snakeNetX[0][i] = 5 - i;
    snakeNetY[0][i] = 7;
    snakeNetX[1][i] = 14 + i;
    snakeNetY[1][i] = 15;
  }

  placeSnakeNetworkFood();
  resetSnakeDrawCache();
  snakeLastFrame = millis();
  gfx->fillScreen(RGB565_BLACK);
  drawSnakeNetworkState(true);
}

void startSnakeLocalGame() {
  activeNetworkGame = NETWORK_GAME_SNAKE;
  stopNetwork();
  localGame = true;
  beepStart();
  newSnakeGame();
}

void startSnakeNetworkGame() {
  activeNetworkGame = NETWORK_GAME_SNAKE;
  localGame = false;
  appState = STATE_SNAKE_PLAYING;
  beepStart();

  if (isHost) {
    newSnakeNetworkGame();
    sendSnakeState();
    return;
  }

  snakeNetLength[0] = 0;
  snakeNetLength[1] = 0;
  snakeNetDir[0] = SNAKE_DIR_RIGHT;
  snakeNetDir[1] = SNAKE_DIR_LEFT;
  snakeNetNextDir[0] = SNAKE_DIR_RIGHT;
  snakeNetNextDir[1] = SNAKE_DIR_LEFT;
  snakeNetScore[0] = 0;
  snakeNetScore[1] = 0;
  snakeNetAlive[0] = true;
  snakeNetAlive[1] = true;
  snakeNetGameOver = false;
  snakeNetWinner = 0;
  resetSnakeDrawCache();
  gfx->fillScreen(RGB565_BLACK);
  drawSnakeHud();
  drawSnakeBoardFrame();
  drawSnakeControls();
  drawCenteredText("Waiting host", 184, 2, RGB565_YELLOW);
}

void drawRanchRushMenuScreen() {
  activeNetworkGame = NETWORK_GAME_RANCH_RUSH;
  localGame = false;
  appState = STATE_RANCH_RUSH;
  drawRanchRushArcadeHome();

  drawTransparentArcadeButton(btnLocalX, btnLocalY, btnLocalW, btnLocalH, "LOCAL", 2);

  drawTransparentArcadeButton(btnHostX, btnHostY, btnHostW, btnHostH, "HOST", 2);

  drawTransparentArcadeButton(btnJoinX, btnJoinY, btnJoinW, btnJoinH, "JOIN", 2);

  drawTransparentArcadeButton(btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH, "RESET SCORE", 2);

  drawTransparentArcadeButton(btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH, "BACK", 2);

  drawGameMenuHighScore(rrHiScore);
}

void drawRanchRushPlaceholderScreen(const char *title) {
  appState = STATE_RR_PLACEHOLDER;
  gfx->fillScreen(RGB565_BLACK);
  drawRanchRushFieldDecor();

  gfx->fillRoundRect(28, 92, 264, 170, 10, rgb888to565(40, 30, 10));
  gfx->drawRoundRect(28, 92, 264, 170, 10, rgb888to565(255, 160, 0));
  gfx->drawRoundRect(34, 98, 252, 158, 8, RGB565_YELLOW);

  drawCenteredText(title, 128, 2, RGB565_YELLOW);
  drawCenteredText("coming soon", 172, 2, RGB565_WHITE);
  drawCenteredText("Lasso cattle mode", 204, 1, RGB565_CYAN);

  drawButton(btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
}

void drawRanchRushLaneLines() {
  uint16_t green2 = rgb888to565(92, 196, 100);

  for (int i = 0; i < RR_LANES; i++) {
    gfx->drawLine(0, rrLaneY[i] + 40, screenW - 1, rrLaneY[i] + 40, green2);
  }
}

void drawRanchRushField() {
  uint16_t field = rgb888to565(75, 145, 35);
  uint16_t darkField = rgb888to565(51, 100, 0);
  uint16_t green2 = rgb888to565(92, 196, 100);

  gfx->fillRect(0, RR_FIELD_TOP, screenW, RR_FIELD_BOT - RR_FIELD_TOP, field);
  drawRanchRushFence(RR_FIELD_TOP);
  drawRanchRushFence(RR_FIELD_BOT - 22);
  drawRanchRushLaneLines();

  for (int i = 0; i < 30; i++) {
    int gx = random(0, screenW);
    int gy = random(RR_FIELD_TOP + 25, RR_FIELD_BOT - 25);
    gfx->drawPixel(gx, gy, darkField);
    gfx->drawPixel(gx + 1, gy + 1, green2);
  }
}

void drawRanchRushHud() {
  uint16_t hudBg = rgb888to565(40, 30, 10);
  uint16_t border = rgb888to565(120, 80, 20);

  gfx->fillRect(0, 0, screenW, RR_HUD_H, hudBg);
  gfx->drawLine(0, RR_HUD_H, screenW - 1, RR_HUD_H, border);

  gfx->setTextColor(RGB565_YELLOW);
  gfx->setTextSize(2);
  gfx->setCursor(10, 6);
  gfx->print("RANCH RUSH");

  gfx->setTextSize(1);
  gfx->setTextColor(RGB565_WHITE);

  if (localGame) {
    gfx->setCursor(8, 30);
    gfx->print("Score:");
    gfx->setCursor(104, 30);
    gfx->print("Lives:");
    gfx->setCursor(176, 30);
    gfx->print("Lv:");
    gfx->setCursor(224, 30);
    gfx->print("Hi:");
  } else {
    gfx->setCursor(8, 30);
    gfx->print("P1:");
    gfx->setCursor(100, 30);
    gfx->print("P2:");
    gfx->setCursor(192, 30);
    gfx->print("Lv:");
    gfx->setCursor(224, 30);
    gfx->print(myPlayer == '2' ? "Me2" : "Me1");
  }

  drawButton(btnRrMenuX, btnRrMenuY, btnRrMenuW, btnRrMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENU", 1);
}

void drawRanchRushHudValues() {
  uint16_t hudBg = rgb888to565(40, 30, 10);

  gfx->setTextSize(1);

  if (localGame) {
    gfx->fillRect(50, 28, 48, 12, hudBg);
    gfx->setTextColor(RGB565_GREEN);
    gfx->setCursor(50, 30);
    gfx->print(rrScore);

    gfx->fillRect(144, 28, 28, 12, hudBg);
    gfx->setTextColor(rrLives <= 1 ? RGB565_RED : RGB565_GREEN);
    gfx->setCursor(144, 30);
    gfx->print(rrLives);

    gfx->fillRect(194, 28, 22, 12, hudBg);
    gfx->setTextColor(rgb888to565(255, 160, 0));
    gfx->setCursor(194, 30);
    gfx->print(rrLevel);

    gfx->fillRect(242, 28, 40, 12, hudBg);
    gfx->setTextColor(RGB565_YELLOW);
    gfx->setCursor(242, 30);
    gfx->print(rrHiScore);
    return;
  }

  gfx->fillRect(30, 28, 64, 12, hudBg);
  gfx->setTextColor(RGB565_GREEN);
  gfx->setCursor(30, 30);
  gfx->print(rrNetScore[0]);
  gfx->print("/");
  gfx->print(rrNetLives[0]);

  gfx->fillRect(122, 28, 64, 12, hudBg);
  gfx->setTextColor(RGB565_CYAN);
  gfx->setCursor(122, 30);
  gfx->print(rrNetScore[1]);
  gfx->print("/");
  gfx->print(rrNetLives[1]);

  gfx->fillRect(210, 28, 14, 12, hudBg);
  gfx->setTextColor(rgb888to565(255, 160, 0));
  gfx->setCursor(210, 30);
  gfx->print(rrLevel);
}

void drawRanchRushControls() {
  uint16_t hudBg = rgb888to565(40, 30, 10);
  uint16_t border = rgb888to565(120, 80, 20);

  gfx->fillRect(0, RR_BTN_AREA_TOP, screenW, screenH - RR_BTN_AREA_TOP, hudBg);
  gfx->drawLine(0, RR_BTN_AREA_TOP, screenW - 1, RR_BTN_AREA_TOP, border);

  drawButton(15, RR_BTN_AREA_TOP + 10, 90, 50,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "UP", 2);
  drawButton(115, RR_BTN_AREA_TOP + 10, 90, 50,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "DWN", 2);
  drawButton(215, RR_BTN_AREA_TOP + 10, 90, 50,
             RGB565_RED, RGB565_WHITE, RGB565_WHITE, "LASO", 2);
}

void clearRanchRushSprite(int x, int y, int w, int h) {
  gfx->fillRect(x, y, w, h, rgb888to565(75, 145, 35));
}

uint16_t ranchRushPlayerHorseColor(int playerIndex) {
  return (playerIndex == 1) ? RGB565_CYAN : RGB565_YELLOW;
}

uint16_t ranchRushPlayerShirtColor(int playerIndex) {
  return (playerIndex == 1) ? RGB565_RED : rgb888to565(60, 100, 255);
}

uint16_t ranchRushPlayerLassoColor(int playerIndex) {
  return (playerIndex == 1) ? RGB565_YELLOW : RGB565_WHITE;
}

void drawRanchRushPlayerAt(int x, int lane, int playerIndex) {
  int y = rrLaneY[lane];
  uint16_t ranchBrown = rgb888to565(138, 65, 17);
  uint16_t horse = ranchRushPlayerHorseColor(playerIndex);
  uint16_t shirt = ranchRushPlayerShirtColor(playerIndex);
  uint16_t skin = rgb888to565(255, 160, 0);

  gfx->fillRect(x - 18, y + 8, 34, 14, horse);
  gfx->fillCircle(x + 14, y + 12, 7, horse);

  gfx->fillRect(x - 12, y + 21, 3, 10, horse);
  gfx->fillRect(x - 2, y + 21, 3, 10, horse);
  gfx->fillRect(x + 8, y + 21, 3, 10, horse);

  gfx->drawLine(x - 18, y + 11, x - 28, y + 4, horse);
  gfx->drawLine(x - 19, y + 13, x - 30, y + 10, horse);

  gfx->fillCircle(x - 3, y - 1, 5, skin);
  gfx->fillRect(x - 8, y + 4, 11, 12, shirt);

  gfx->fillRect(x - 13, y - 9, 20, 3, ranchBrown);
  gfx->fillRect(x - 8, y - 15, 10, 7, ranchBrown);

  gfx->drawLine(x + 3, y + 7, x + 20, y + 2, RGB565_WHITE);
}

void drawRanchRushPlayer(int lane) {
  drawRanchRushPlayerAt(rrPlayerX, lane, 0);
}

void drawRanchRushNetworkPlayer(int playerIndex) {
  if (playerIndex < 0 || playerIndex > 1) return;
  drawRanchRushPlayerAt(rrNetPlayerX[playerIndex], rrNetPlayerLane[playerIndex], playerIndex);
}

void clearRanchRushPlayerAt(int x, int lane) {
  int y = rrLaneY[lane];
  clearRanchRushSprite(x - 32, y - 17, 66, 52);
}

void clearRanchRushPlayer(int lane) {
  clearRanchRushPlayerAt(rrPlayerX, lane);
}

void clearRanchRushNetworkPlayer(int playerIndex, int lane) {
  if (playerIndex < 0 || playerIndex > 1) return;
  clearRanchRushPlayerAt(rrNetPlayerX[playerIndex], lane);
}

void drawRanchRushAnimal(const RanchAnimal &animal) {
  if (!animal.active) return;

  int x = (int)animal.x;
  int y = rrLaneY[animal.lane];
  uint16_t ranchBrown = rgb888to565(138, 65, 17);
  uint16_t darkBrown = rgb888to565(81, 40, 0);
  uint16_t bodyColor = ranchBrown;
  uint16_t headColor = ranchBrown;

  if (animal.type == 1) {
    bodyColor = darkBrown;
    headColor = darkBrown;
  } else if (animal.type == 2) {
    bodyColor = RGB565_WHITE;
    headColor = RGB565_WHITE;
  }

  gfx->fillRect(x - 12, y + 8, 28, 13, bodyColor);
  gfx->fillCircle(x + 16, y + 12, 6, bodyColor);
  gfx->fillCircle(x + 22, y + 8, 5, headColor);

  gfx->fillRect(x - 6, y + 20, 3, 10, bodyColor);
  gfx->fillRect(x + 4, y + 20, 3, 10, bodyColor);
  gfx->fillRect(x + 12, y + 20, 3, 10, bodyColor);

  if (animal.type == 0 || animal.type == 1) {
    gfx->drawLine(x + 20, y + 4, x + 15, y - 3, RGB565_WHITE);
    gfx->drawLine(x + 24, y + 4, x + 30, y - 3, RGB565_WHITE);
  } else {
    gfx->drawLine(x + 21, y + 3, x + 19, y - 2, headColor);
    gfx->drawLine(x + 23, y + 3, x + 25, y - 2, headColor);
  }

  gfx->drawLine(x - 12, y + 11, x - 22, y + 5, bodyColor);

  if (animal.type == 0) {
    gfx->fillRect(x - 4, y + 10, 4, 4, RGB565_BLACK);
    gfx->fillRect(x + 8, y + 12, 3, 3, RGB565_BLACK);
  }
}

void clearRanchRushAnimal(int x, int y) {
  clearRanchRushSprite(x - 24, y - 5, 58, 38);
}

void drawRanchRushLassoAt(int playerX, int lane, float lassoX, uint16_t color) {
  int y = rrLaneY[lane];
  int px = playerX + 18;
  int lx = (int)lassoX;

  gfx->drawLine(px, y + 8, lx, y + 8, color);
  gfx->drawCircle(lx, y + 8, 10, color);
  gfx->drawCircle(lx, y + 8, 11, color);
}

void clearRanchRushLassoAt(int playerX, int lane, float lassoX) {
  int y = rrLaneY[lane];
  int px = playerX + 18;
  int lx = (int)lassoX;
  int x0 = min(px, lx) - 14;
  int x1 = max(px, lx) + 14;

  clearRanchRushSprite(x0, y - 4, x1 - x0, 26);
}

void drawRanchRushLasso() {
  if (!rrLassoActive) return;
  drawRanchRushLassoAt(rrPlayerX, rrLassoLane, rrLassoX, RGB565_WHITE);
}

void clearRanchRushLasso() {
  if (!rrPrevLassoActive) return;
  clearRanchRushLassoAt(rrPlayerX, rrPrevLassoLane, rrPrevLassoX);
}

void drawRanchRushNetworkLasso(int playerIndex) {
  if (playerIndex < 0 || playerIndex > 1) return;
  if (!rrNetLassoActive[playerIndex]) return;

  drawRanchRushLassoAt(rrNetPlayerX[playerIndex],
                       rrNetLassoLane[playerIndex],
                       rrNetLassoX[playerIndex],
                       ranchRushPlayerLassoColor(playerIndex));
}

void clearRanchRushNetworkLasso(int playerIndex) {
  if (playerIndex < 0 || playerIndex > 1) return;
  if (!rrNetPrevLassoActive[playerIndex]) return;

  clearRanchRushLassoAt(rrNetPlayerX[playerIndex],
                        rrNetPrevLassoLane[playerIndex],
                        rrNetPrevLassoX[playerIndex]);
}

void drawRanchRushGameOverOverlay() {
  if (!localGame) {
    gfx->fillRoundRect(28, 122, 264, 230, 10, rgb888to565(40, 30, 10));
    gfx->drawRoundRect(28, 122, 264, 230, 10, RGB565_RED);
    gfx->drawRoundRect(34, 128, 252, 218, 8, RGB565_YELLOW);

    const char *title = "DRAW";
    uint16_t titleColor = RGB565_YELLOW;
    int localPlayer = (myPlayer == '2') ? 2 : 1;

    if (rrNetWinner == localPlayer) {
      title = "YOU WIN";
      titleColor = RGB565_GREEN;
    } else if (rrNetWinner == 1 || rrNetWinner == 2) {
      title = "YOU LOSE";
      titleColor = RGB565_RED;
    }

    drawCenteredText(title, 154, 3, titleColor);

    char line[48];
    snprintf(line, sizeof(line), "P1:%d   P2:%d", rrNetScore[0], rrNetScore[1]);
    drawCenteredText(line, 214, 2, RGB565_WHITE);

    snprintf(line, sizeof(line), "Lives %d - %d", rrNetLives[0], rrNetLives[1]);
    drawCenteredText(line, 246, 2, RGB565_CYAN);
    drawCenteredText("Tap play again", 292, 1, RGB565_CYAN);
    return;
  }

  if (rrScore > 0 && (uint32_t)rrScore >= rrHiScore) {
    rrHiScore = rrScore;
    saveRanchRushScore();
  }

  gfx->fillRoundRect(28, 122, 264, 230, 10, rgb888to565(40, 30, 10));
  gfx->drawRoundRect(28, 122, 264, 230, 10, RGB565_RED);
  gfx->drawRoundRect(34, 128, 252, 218, 8, RGB565_YELLOW);

  drawCenteredText("GAME OVER", 154, 3, RGB565_RED);

  char line[40];
  snprintf(line, sizeof(line), "Score: %d", rrScore);
  drawCenteredText(line, 214, 2, RGB565_GREEN);

  snprintf(line, sizeof(line), "High: %lu", (unsigned long)rrHiScore);
  drawCenteredText(line, 246, 2, RGB565_YELLOW);
  drawCenteredText("Tap to restart", 292, 1, RGB565_CYAN);
}

void drawRanchRushFullScene() {
  gfx->fillScreen(RGB565_BLACK);
  drawRanchRushField();
  drawRanchRushHud();
  drawRanchRushHudValues();
  drawRanchRushControls();

  for (int i = 0; i < RR_MAX_ANIMALS; i++) {
    if (rrAnimals[i].active) {
      drawRanchRushAnimal(rrAnimals[i]);
      rrPrevAnimals[i].x = (int)rrAnimals[i].x;
      rrPrevAnimals[i].y = rrLaneY[rrAnimals[i].lane];
      rrPrevAnimals[i].wasActive = true;
    } else {
      rrPrevAnimals[i].wasActive = false;
    }
  }

  if (localGame) {
    drawRanchRushPlayer(rrPlayerLane);
    rrPrevPlayerLane = rrPlayerLane;
    rrPrevLassoActive = rrLassoActive;
    rrPrevLassoX = rrLassoX;
    rrPrevLassoLane = rrLassoLane;
    drawRanchRushLasso();
  } else {
    for (int p = 0; p < 2; p++) {
      drawRanchRushNetworkPlayer(p);
      rrNetPrevPlayerLane[p] = rrNetPlayerLane[p];
      rrNetPrevLassoActive[p] = rrNetLassoActive[p];
      rrNetPrevLassoX[p] = rrNetLassoX[p];
      rrNetPrevLassoLane[p] = rrNetLassoLane[p];
      drawRanchRushNetworkLasso(p);
    }
  }

  rrRanchSceneReady = true;
}

void drawRanchRushGameFrame() {
  if (localGame) {
    clearRanchRushLasso();

    if (rrPrevPlayerLane >= 0 && rrPrevPlayerLane != rrPlayerLane) {
      clearRanchRushPlayer(rrPrevPlayerLane);
    }
  } else {
    for (int p = 0; p < 2; p++) {
      clearRanchRushNetworkLasso(p);

      if (rrNetPrevPlayerLane[p] >= 0 && rrNetPrevPlayerLane[p] != rrNetPlayerLane[p]) {
        clearRanchRushNetworkPlayer(p, rrNetPrevPlayerLane[p]);
      }
    }
  }

  for (int i = 0; i < RR_MAX_ANIMALS; i++) {
    if (rrPrevAnimals[i].wasActive) {
      clearRanchRushAnimal(rrPrevAnimals[i].x, rrPrevAnimals[i].y);
    }
  }

  drawRanchRushLaneLines();

  for (int i = 0; i < RR_MAX_ANIMALS; i++) {
    if (rrAnimals[i].active) {
      drawRanchRushAnimal(rrAnimals[i]);
      rrPrevAnimals[i].x = (int)rrAnimals[i].x;
      rrPrevAnimals[i].y = rrLaneY[rrAnimals[i].lane];
      rrPrevAnimals[i].wasActive = true;
    } else {
      rrPrevAnimals[i].wasActive = false;
    }
  }

  if (localGame) {
    drawRanchRushPlayer(rrPlayerLane);
    rrPrevPlayerLane = rrPlayerLane;

    drawRanchRushLasso();
    rrPrevLassoActive = rrLassoActive;
    rrPrevLassoX = rrLassoX;
    rrPrevLassoLane = rrLassoLane;
  } else {
    for (int p = 0; p < 2; p++) {
      drawRanchRushNetworkPlayer(p);
      rrNetPrevPlayerLane[p] = rrNetPlayerLane[p];

      drawRanchRushNetworkLasso(p);
      rrNetPrevLassoActive[p] = rrNetLassoActive[p];
      rrNetPrevLassoX[p] = rrNetLassoX[p];
      rrNetPrevLassoLane[p] = rrNetLassoLane[p];
    }
  }

  drawRanchRushHudValues();
}

void initRanchRushLanes() {
  for (int i = 0; i < RR_LANES; i++) {
    rrLaneY[i] = RR_LANE_START_Y + i * RR_LANE_SPACING;
  }
}

void resetRanchRushRenderCache() {
  rrPrevPlayerLane = -1;
  rrPrevLassoActive = false;

  for (int i = 0; i < RR_MAX_ANIMALS; i++) {
    rrPrevAnimals[i].wasActive = false;
  }

  for (int p = 0; p < 2; p++) {
    rrNetPrevPlayerLane[p] = -1;
    rrNetPrevLassoActive[p] = false;
  }

  rrRanchSceneReady = false;
}

void newRanchRushGame() {
  activeNetworkGame = NETWORK_GAME_RANCH_RUSH;
  localGame = true;
  appState = STATE_RR_PLAYING;
  rrScore = 0;
  rrLives = 3;
  rrLevel = 1;
  rrPlayerLane = 2;
  rrLassoActive = false;
  rrPrevLassoActive = false;
  rrPrevPlayerLane = -1;
  rrLastSpawn = millis();
  rrLastFrame = millis();
  rrGameOver = false;

  initRanchRushLanes();
  resetRanchRushRenderCache();

  for (int i = 0; i < RR_MAX_ANIMALS; i++) {
    rrAnimals[i].active = false;
  }

  drawRanchRushFullScene();
}

void spawnRanchRushAnimal() {
  for (int i = 0; i < RR_MAX_ANIMALS; i++) {
    if (!rrAnimals[i].active) {
      rrAnimals[i].active = true;
      rrAnimals[i].x = screenW + random(20, 100);
      rrAnimals[i].lane = random(0, RR_LANES);
      rrAnimals[i].speed = 1.5f + rrLevel * 0.5f + random(0, 10) * 0.1f;
      rrAnimals[i].type = random(0, 3);
      return;
    }
  }
}

void startRanchRushLasso() {
  if (rrLassoActive) return;

  rrLassoActive = true;
  rrLassoX = rrPlayerX + 30;
  rrLassoLane = rrPlayerLane;
  rrLassoStart = millis();
  beepClick();
}

void finishRanchRushGame() {
  rrGameOver = true;
  beepDraw();
  drawRanchRushGameOverOverlay();
}

void loseRanchRushLife() {
  rrLives--;
  beepDraw();

  if (rrLives <= 0) {
    finishRanchRushGame();
  }
}

void updateRanchRushLasso() {
  if (!rrLassoActive) return;

  rrLassoX += 14;

  if (rrLassoX > screenW - 10 || millis() - rrLassoStart > 550) {
    rrLassoActive = false;
    return;
  }

  for (int i = 0; i < RR_MAX_ANIMALS; i++) {
    if (!rrAnimals[i].active) continue;
    if (rrAnimals[i].lane != rrLassoLane) continue;

    float dx = rrAnimals[i].x - rrLassoX;

    if (fabs(dx) < 22.0f) {
      rrAnimals[i].active = false;

      int points = 10;
      if (rrAnimals[i].type == 1) {
        points = 20;
      } else if (rrAnimals[i].type == 2) {
        points = 15;
      }

      rrScore += points;

      if ((uint32_t)rrScore > rrHiScore) {
        rrHiScore = rrScore;
      }

      beepMove();
      rrLassoActive = false;

      if (rrScore > 0 && rrScore % 100 == 0) {
        rrLevel++;
        beepWin();
      }

      return;
    }
  }
}

void updateRanchRushAnimals() {
  for (int i = 0; i < RR_MAX_ANIMALS; i++) {
    if (!rrAnimals[i].active) continue;

    rrAnimals[i].x -= rrAnimals[i].speed;

    if (rrAnimals[i].x < -30) {
      rrAnimals[i].active = false;
      loseRanchRushLife();
      if (rrGameOver) return;
      continue;
    }

    if (rrAnimals[i].lane == rrPlayerLane &&
        rrAnimals[i].x < rrPlayerX + 25 &&
        rrAnimals[i].x > rrPlayerX - 20) {
      rrAnimals[i].active = false;
      loseRanchRushLife();
      if (rrGameOver) return;
    }
  }
}

int ranchRushLocalNetworkPlayerIndex() {
  return (myPlayer == '2') ? 1 : 0;
}

void startRanchRushNetworkLasso(int playerIndex) {
  if (playerIndex < 0 || playerIndex > 1) return;
  if (rrNetLassoActive[playerIndex]) return;

  rrNetLassoActive[playerIndex] = true;
  rrNetLassoX[playerIndex] = rrNetPlayerX[playerIndex] + 30;
  rrNetLassoLane[playerIndex] = rrNetPlayerLane[playerIndex];
  rrNetLassoStart[playerIndex] = millis();
}

void applyRanchRushNetworkInput(int playerIndex, int action, bool localFeedback) {
  if (playerIndex < 0 || playerIndex > 1) return;
  if (rrNetGameOver) return;

  if (action == 0) {
    if (rrNetPlayerLane[playerIndex] > 0) {
      rrNetPlayerLane[playerIndex]--;
      if (localFeedback) beepClick();
    }
  } else if (action == 1) {
    if (rrNetPlayerLane[playerIndex] < RR_LANES - 1) {
      rrNetPlayerLane[playerIndex]++;
      if (localFeedback) beepClick();
    }
  } else if (action == 2) {
    startRanchRushNetworkLasso(playerIndex);
    if (localFeedback) beepClick();
  }
}

void sendRanchRushState(bool force);

void sendRanchRushInput(int action) {
  if (localGame || !networkConnected) return;

  String msg = "RR_INPUT:";
  msg += String(ranchRushLocalNetworkPlayerIndex());
  msg += ",";
  msg += String(action);
  sendNetMessage(msg);
}

void applyRanchRushPlayerAction(int action) {
  if (localGame) {
    if (action == 0) {
      if (rrPlayerLane > 0) {
        rrPlayerLane--;
        beepClick();
      }
    } else if (action == 1) {
      if (rrPlayerLane < RR_LANES - 1) {
        rrPlayerLane++;
        beepClick();
      }
    } else if (action == 2) {
      startRanchRushLasso();
    }

    return;
  }

  int playerIndex = ranchRushLocalNetworkPlayerIndex();
  applyRanchRushNetworkInput(playerIndex, action, true);

  if (!isHost) {
    sendRanchRushInput(action);
  } else {
    sendRanchRushState(true);
  }

  if (rrRanchSceneReady && !rrNetGameOver) {
    drawRanchRushGameFrame();
  }
}

void finishRanchRushNetworkGame() {
  if (rrNetGameOver) return;

  rrNetGameOver = true;

  if (rrNetLives[0] <= 0 && rrNetLives[1] <= 0) {
    rrNetWinner = 3;
  } else if (rrNetLives[0] <= 0) {
    rrNetWinner = 2;
  } else if (rrNetLives[1] <= 0) {
    rrNetWinner = 1;
  } else {
    rrNetWinner = 3;
  }

  myTurn = false;
  beepDraw();
  drawRanchRushGameFrame();
  drawRanchRushGameOverOverlay();
}

void loseRanchRushNetworkLife(int playerIndex) {
  if (playerIndex < 0 || playerIndex > 1) return;
  if (rrNetLives[playerIndex] <= 0) return;

  rrNetLives[playerIndex]--;
  beepDraw();

  if (rrNetLives[0] <= 0 || rrNetLives[1] <= 0) {
    finishRanchRushNetworkGame();
  }
}

void updateRanchRushNetworkLevel() {
  int totalScore = rrNetScore[0] + rrNetScore[1];
  int newLevel = 1 + totalScore / 100;

  if (newLevel > rrLevel) {
    rrLevel = newLevel;
    beepWin();
  }
}

void updateRanchRushNetworkLassos() {
  for (int p = 0; p < 2; p++) {
    if (!rrNetLassoActive[p]) continue;

    rrNetLassoX[p] += 14.0f;

    if (rrNetLassoX[p] > screenW - 10 || millis() - rrNetLassoStart[p] > 550) {
      rrNetLassoActive[p] = false;
      continue;
    }

    for (int i = 0; i < RR_MAX_ANIMALS; i++) {
      if (!rrAnimals[i].active) continue;
      if (rrAnimals[i].lane != rrNetLassoLane[p]) continue;

      float dx = rrAnimals[i].x - rrNetLassoX[p];

      if (fabs(dx) < 22.0f) {
        rrAnimals[i].active = false;

        int points = 10;
        if (rrAnimals[i].type == 1) {
          points = 20;
        } else if (rrAnimals[i].type == 2) {
          points = 15;
        }

        rrNetScore[p] += points;
        rrNetLassoActive[p] = false;
        beepMove();
        updateRanchRushNetworkLevel();
        break;
      }
    }
  }
}

void updateRanchRushNetworkAnimals() {
  for (int i = 0; i < RR_MAX_ANIMALS; i++) {
    if (!rrAnimals[i].active) continue;

    rrAnimals[i].x -= rrAnimals[i].speed;

    if (rrAnimals[i].x < -30) {
      rrAnimals[i].active = false;
      loseRanchRushNetworkLife(0);

      if (!rrNetGameOver) {
        loseRanchRushNetworkLife(1);
      }

      if (rrNetGameOver) return;
      continue;
    }

    for (int p = 0; p < 2; p++) {
      if (rrAnimals[i].lane == rrNetPlayerLane[p] &&
          rrAnimals[i].x < rrNetPlayerX[p] + 25 &&
          rrAnimals[i].x > rrNetPlayerX[p] - 20) {
        rrAnimals[i].active = false;
        loseRanchRushNetworkLife(p);

        if (rrNetGameOver) return;
        break;
      }
    }
  }
}

void sendRanchRushState(bool force) {
  if (localGame || !isHost || !networkConnected) return;

  unsigned long now = millis();

  if (!force && now - rrLastStateSendTime < RR_NET_STATE_MS) {
    return;
  }

  rrLastStateSendTime = now;

  String msg = "RR_STATE:";
  msg.reserve(260);

  msg += String(rrNetGameOver ? 1 : 0);
  msg += ",";
  msg += String(rrNetWinner);
  msg += ",";
  msg += String(rrNetScore[0]);
  msg += ",";
  msg += String(rrNetScore[1]);
  msg += ",";
  msg += String(rrNetLives[0]);
  msg += ",";
  msg += String(rrNetLives[1]);
  msg += ",";
  msg += String(rrLevel);
  msg += ",";
  msg += String(rrNetPlayerLane[0]);
  msg += ",";
  msg += String(rrNetPlayerLane[1]);

  for (int p = 0; p < 2; p++) {
    msg += ",";
    msg += String(rrNetLassoActive[p] ? 1 : 0);
    msg += ",";
    msg += String((int)rrNetLassoX[p]);
    msg += ",";
    msg += String(rrNetLassoLane[p]);
  }

  for (int i = 0; i < RR_MAX_ANIMALS; i++) {
    msg += ",";
    msg += String(rrAnimals[i].active ? 1 : 0);
    msg += ",";
    msg += String((int)rrAnimals[i].x);
    msg += ",";
    msg += String(rrAnimals[i].lane);
    msg += ",";
    msg += String(rrAnimals[i].type);
  }

  sendNetMessage(msg);
}

void applyRemoteRanchRushState(const String &payload) {
  activeNetworkGame = NETWORK_GAME_RANCH_RUSH;
  localGame = false;
  appState = STATE_RR_PLAYING;
  initRanchRushLanes();

  int start = 0;
  int gameOverValue, winnerValue, scoreP1, scoreP2, livesP1, livesP2, levelValue, laneP1, laneP2;

  if (!readCsvInt(payload, start, gameOverValue)) return;
  if (!readCsvInt(payload, start, winnerValue)) return;
  if (!readCsvInt(payload, start, scoreP1)) return;
  if (!readCsvInt(payload, start, scoreP2)) return;
  if (!readCsvInt(payload, start, livesP1)) return;
  if (!readCsvInt(payload, start, livesP2)) return;
  if (!readCsvInt(payload, start, levelValue)) return;
  if (!readCsvInt(payload, start, laneP1)) return;
  if (!readCsvInt(payload, start, laneP2)) return;

  bool wasGameOver = rrNetGameOver;
  rrNetGameOver = (gameOverValue != 0);
  rrNetWinner = winnerValue;
  rrNetScore[0] = scoreP1;
  rrNetScore[1] = scoreP2;
  rrNetLives[0] = livesP1;
  rrNetLives[1] = livesP2;
  rrLevel = levelValue;
  rrNetPlayerLane[0] = constrain(laneP1, 0, RR_LANES - 1);
  rrNetPlayerLane[1] = constrain(laneP2, 0, RR_LANES - 1);

  for (int p = 0; p < 2; p++) {
    int lassoActive, lassoX, lassoLane;

    if (!readCsvInt(payload, start, lassoActive)) return;
    if (!readCsvInt(payload, start, lassoX)) return;
    if (!readCsvInt(payload, start, lassoLane)) return;

    rrNetLassoActive[p] = (lassoActive != 0);
    rrNetLassoX[p] = (float)lassoX;
    rrNetLassoLane[p] = constrain(lassoLane, 0, RR_LANES - 1);
  }

  for (int i = 0; i < RR_MAX_ANIMALS; i++) {
    int active, x, lane, type;

    if (!readCsvInt(payload, start, active)) return;
    if (!readCsvInt(payload, start, x)) return;
    if (!readCsvInt(payload, start, lane)) return;
    if (!readCsvInt(payload, start, type)) return;

    rrAnimals[i].active = (active != 0);
    rrAnimals[i].x = (float)x;
    rrAnimals[i].lane = constrain(lane, 0, RR_LANES - 1);
    rrAnimals[i].type = constrain(type, 0, 2);
  }

  if (!rrRanchSceneReady || (!wasGameOver && rrNetGameOver)) {
    drawRanchRushFullScene();
  } else {
    drawRanchRushGameFrame();
  }

  if (rrNetGameOver) {
    if (!wasGameOver) {
      int localPlayer = (myPlayer == '2') ? 2 : 1;
      if (rrNetWinner == localPlayer) {
        beepWin();
      } else {
        beepDraw();
      }
    }

    drawRanchRushGameOverOverlay();
  }
}

void updateRanchRushGame() {
  if (appState != STATE_RR_PLAYING) return;

  if (!localGame) {
    if (!isHost || rrNetGameOver) return;

    unsigned long now = millis();

    if (now - rrLastFrame < RR_FRAME_MS) return;
    rrLastFrame = now;

    int spawnDelay = 1400 - rrLevel * 130;
    if (spawnDelay < 400) {
      spawnDelay = 400;
    }

    if (now - rrLastSpawn > (unsigned long)spawnDelay) {
      spawnRanchRushAnimal();
      rrLastSpawn = now;
    }

    updateRanchRushNetworkAnimals();

    if (!rrNetGameOver) {
      updateRanchRushNetworkLassos();
      drawRanchRushGameFrame();
    }

    sendRanchRushState(rrNetGameOver);
    return;
  }

  if (rrGameOver) return;

  unsigned long now = millis();

  if (now - rrLastFrame < RR_FRAME_MS) return;
  rrLastFrame = now;

  int spawnDelay = 1400 - rrLevel * 130;
  if (spawnDelay < 400) {
    spawnDelay = 400;
  }

  if (now - rrLastSpawn > (unsigned long)spawnDelay) {
    spawnRanchRushAnimal();
    rrLastSpawn = now;
  }

  updateRanchRushAnimals();
  if (rrGameOver) return;

  updateRanchRushLasso();
  drawRanchRushGameFrame();
}

void startRanchRushLocalGame() {
  activeNetworkGame = NETWORK_GAME_RANCH_RUSH;
  stopNetwork();
  localGame = true;
  beepStart();
  newRanchRushGame();
}

void newRanchRushNetworkGame() {
  activeNetworkGame = NETWORK_GAME_RANCH_RUSH;
  localGame = false;
  appState = STATE_RR_PLAYING;
  myTurn = true;
  rrLevel = 1;
  rrNetScore[0] = 0;
  rrNetScore[1] = 0;
  rrNetLives[0] = 3;
  rrNetLives[1] = 3;
  rrNetPlayerLane[0] = 2;
  rrNetPlayerLane[1] = 2;
  rrNetLassoActive[0] = false;
  rrNetLassoActive[1] = false;
  rrNetGameOver = false;
  rrNetWinner = 0;
  rrLastSpawn = millis();
  rrLastFrame = millis();
  rrLastStateSendTime = 0;

  initRanchRushLanes();
  resetRanchRushRenderCache();

  for (int i = 0; i < RR_MAX_ANIMALS; i++) {
    rrAnimals[i].active = false;
  }

  drawRanchRushFullScene();
}

void startRanchRushNetworkGame() {
  activeNetworkGame = NETWORK_GAME_RANCH_RUSH;
  localGame = false;
  myTurn = true;
  beepStart();

  if (isHost) {
    newRanchRushNetworkGame();
    sendRanchRushState(true);
    return;
  }

  rrLevel = 1;
  rrNetScore[0] = 0;
  rrNetScore[1] = 0;
  rrNetLives[0] = 3;
  rrNetLives[1] = 3;
  rrNetPlayerLane[0] = 2;
  rrNetPlayerLane[1] = 2;
  rrNetLassoActive[0] = false;
  rrNetLassoActive[1] = false;
  rrNetGameOver = false;
  rrNetWinner = 0;
  initRanchRushLanes();
  resetRanchRushRenderCache();

  for (int i = 0; i < RR_MAX_ANIMALS; i++) {
    rrAnimals[i].active = false;
  }

  appState = STATE_RR_PLAYING;
  drawRanchRushFullScene();
  drawCenteredText("Waiting host", 184, 2, RGB565_YELLOW);
  rrRanchSceneReady = false;
}

uint16_t froggerRowBg(int row) {
  if (row == 0) return rgb888to565(30, 120, 30);
  if (row >= 1 && row <= 3) return rgb888to565(60, 60, 60);
  if (row == 4) return rgb888to565(50, 140, 50);
  if (row >= 5 && row <= 7) return rgb888to565(20, 70, 190);
  return rgb888to565(15, 70, 15);
}

int froggerLaneIndexForRow(int row) {
  for (int i = 0; i < FROG_LANES; i++) {
    if (frogLanes[i].row == row) return i;
  }

  return -1;
}

void initFroggerLayout() {
  for (int r = 0; r < FROG_ROWS; r++) {
    frogRowY[r] = FROG_FIELD_TOP + (FROG_ROWS - 1 - r) * FROG_LANE_H;
  }

  for (int g = 0; g < FROG_GOALS; g++) {
    frogGoalX[g] = (screenW / FROG_GOALS) * g + (screenW / FROG_GOALS) / 2;
  }
}

void initFroggerLanes() {
  float speedMul = 1.0f + (frogLevel - 1) * 0.18f;

  frogLanes[0].row = 1;
  frogLanes[0].speed = -1.4f * speedMul;
  frogLanes[0].isWater = false;
  frogLanes[0].objColor = rgb888to565(230, 200, 0);
  frogLanes[0].numObj = 3;
  frogLanes[0].objs[0] = {30.0f, 40};
  frogLanes[0].objs[1] = {190.0f, 40};
  frogLanes[0].objs[2] = {280.0f, 40};

  frogLanes[1].row = 2;
  frogLanes[1].speed = 1.0f * speedMul;
  frogLanes[1].isWater = false;
  frogLanes[1].objColor = rgb888to565(60, 110, 230);
  frogLanes[1].numObj = 2;
  frogLanes[1].objs[0] = {10.0f, 58};
  frogLanes[1].objs[1] = {200.0f, 58};

  frogLanes[2].row = 3;
  frogLanes[2].speed = -2.0f * speedMul;
  frogLanes[2].isWater = false;
  frogLanes[2].objColor = rgb888to565(220, 40, 40);
  frogLanes[2].numObj = 3;
  frogLanes[2].objs[0] = {20.0f, 36};
  frogLanes[2].objs[1] = {140.0f, 36};
  frogLanes[2].objs[2] = {270.0f, 36};

  frogLanes[3].row = 5;
  frogLanes[3].speed = 0.9f * speedMul;
  frogLanes[3].isWater = true;
  frogLanes[3].objColor = rgb888to565(139, 90, 43);
  frogLanes[3].numObj = 3;
  frogLanes[3].objs[0] = {0.0f, 62};
  frogLanes[3].objs[1] = {140.0f, 62};
  frogLanes[3].objs[2] = {280.0f, 62};

  frogLanes[4].row = 6;
  frogLanes[4].speed = -1.2f * speedMul;
  frogLanes[4].isWater = true;
  frogLanes[4].objColor = rgb888to565(139, 90, 43);
  frogLanes[4].numObj = 3;
  frogLanes[4].objs[0] = {10.0f, 48};
  frogLanes[4].objs[1] = {140.0f, 48};
  frogLanes[4].objs[2] = {270.0f, 48};

  frogLanes[5].row = 7;
  frogLanes[5].speed = 0.7f * speedMul;
  frogLanes[5].isWater = true;
  frogLanes[5].objColor = rgb888to565(139, 90, 43);
  frogLanes[5].numObj = 2;
  frogLanes[5].objs[0] = {10.0f, 92};
  frogLanes[5].objs[1] = {200.0f, 92};
}

void drawFroggerArcadeHome() {
  uint16_t road = rgb888to565(50, 50, 55);
  uint16_t water = rgb888to565(14, 50, 145);
  uint16_t grass = rgb888to565(24, 110, 35);

  gfx->fillScreen(RGB565_BLACK);
  gfx->fillRect(0, 0, screenW, 130, water);
  gfx->fillRect(0, 130, screenW, 130, road);
  gfx->fillRect(0, 260, screenW, screenH - 260, grass);

  for (int x = 0; x < screenW; x += 44) {
    gfx->drawFastHLine(x, 88, 20, rgb888to565(80, 150, 255));
    gfx->drawFastHLine(x + 12, 110, 18, rgb888to565(80, 150, 255));
    gfx->drawFastHLine(x, 194, 22, RGB565_WHITE);
    gfx->drawFastHLine(x + 18, 236, 18, RGB565_WHITE);
  }

  gfx->fillRoundRect(38, 24, 244, 78, 10, RGB565_BLACK);
  gfx->drawRoundRect(38, 24, 244, 78, 10, RGB565_GREEN);
  gfx->drawRoundRect(44, 30, 232, 66, 8, RGB565_YELLOW);
  drawPixelText("FROGGER", 54, 48, 3, RGB565_GREEN, RGB565_BLACK);

  gfx->fillCircle(60, 300, 18, RGB565_GREEN);
  gfx->fillCircle(52, 288, 6, RGB565_WHITE);
  gfx->fillCircle(68, 288, 6, RGB565_WHITE);
  gfx->fillCircle(52, 288, 2, RGB565_BLACK);
  gfx->fillCircle(68, 288, 2, RGB565_BLACK);

  gfx->fillRect(188, 158, 54, 24, rgb888to565(230, 200, 0));
  gfx->fillCircle(198, 183, 4, RGB565_BLACK);
  gfx->fillCircle(232, 183, 4, RGB565_BLACK);
  gfx->fillRect(44, 74, 82, 22, rgb888to565(139, 90, 43));
  gfx->fillRect(178, 102, 72, 22, rgb888to565(139, 90, 43));
}

void drawFroggerMenuScreen() {
  activeNetworkGame = NETWORK_GAME_FROGGER;
  localGame = false;
  appState = STATE_FROGGER;
  drawFroggerArcadeHome();

  drawTransparentArcadeButton(btnLocalX, btnLocalY, btnLocalW, btnLocalH, "LOCAL", 2);
  drawTransparentArcadeButton(btnHostX, btnHostY, btnHostW, btnHostH, "HOST", 2);
  drawTransparentArcadeButton(btnJoinX, btnJoinY, btnJoinW, btnJoinH, "JOIN", 2);
  drawTransparentArcadeButton(btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH, "RESET SCORE", 2);
  drawTransparentArcadeButton(btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH, "BACK", 2);

  drawGameMenuHighScore(frogHiScore);
}

void drawFroggerPlaceholderScreen(const char *title) {
  appState = STATE_FROGGER_PLACEHOLDER;
  gfx->fillScreen(RGB565_BLACK);
  drawFroggerArcadeHome();

  gfx->fillRoundRect(28, 116, 264, 150, 10, RGB565_BLACK);
  gfx->drawRoundRect(28, 116, 264, 150, 10, RGB565_GREEN);
  drawCenteredText(title, 150, 3, RGB565_GREEN);
  drawCenteredText("coming soon", 204, 2, RGB565_WHITE);

  drawButton(btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
}

void drawFroggerObstacle(const FroggerLane &lane, int index) {
  int ox = (int)lane.objs[index].x;
  int oy = frogRowY[lane.row];
  int ow = lane.objs[index].w;
  int drawX = max(0, ox);
  int drawEnd = min(screenW, ox + ow);
  int drawW = drawEnd - drawX;

  if (drawW <= 0) return;

  if (lane.isWater) {
    uint16_t logDark = rgb888to565(100, 60, 20);
    gfx->fillRect(drawX, oy + 3, drawW, FROG_LANE_H - 6, rgb888to565(139, 90, 43));

    for (int g = ox + 12; g < ox + ow; g += 20) {
      if (g >= 0 && g < screenW) {
        gfx->drawFastVLine(g, oy + 5, FROG_LANE_H - 10, logDark);
      }
    }

    if (drawX == ox) {
      gfx->fillRoundRect(drawX, oy + 3, 6, FROG_LANE_H - 6, 2, logDark);
    }

    if (drawEnd == ox + ow) {
      gfx->fillRoundRect(drawEnd - 6, oy + 3, 6, FROG_LANE_H - 6, 2, logDark);
    }

    return;
  }

  int bodyY = oy + 8;
  int bodyH = FROG_LANE_H - 16;
  gfx->fillRect(drawX, bodyY, drawW, bodyH, lane.objColor);

  int roofX = ox + 6;
  int roofW = ow - 12;
  int roofDrawX = max(0, roofX);
  int roofDrawW = min(screenW, roofX + roofW) - roofDrawX;

  if (roofDrawW > 0) {
    gfx->fillRect(roofDrawX, oy + 4, roofDrawW, FROG_LANE_H - 8, lane.objColor);
  }

  int wheelY = oy + FROG_LANE_H - 10;
  if (ox + 6 >= 0 && ox + 6 < screenW) {
    gfx->fillCircle(ox + 6, wheelY, 3, RGB565_BLACK);
  }

  if (ox + ow - 6 >= 0 && ox + ow - 6 < screenW) {
    gfx->fillCircle(ox + ow - 6, wheelY, 3, RGB565_BLACK);
  }

  int windowX = ox + ow / 2 - 5;
  int windowDrawX = max(0, windowX);
  int windowDrawW = min(screenW, windowX + 10) - windowDrawX;

  if (windowDrawW > 0) {
    gfx->fillRect(windowDrawX, oy + 6, windowDrawW, 8, rgb888to565(180, 220, 255));
  }
}

void drawFroggerFrogWithColors(float xFloat, int row, uint16_t frog, uint16_t darkFrog) {
  if (row < 0 || row >= FROG_ROWS) return;

  int x = (int)xFloat;
  int y = frogRowY[row] + (FROG_LANE_H - FROG_H) / 2;

  gfx->fillRect(x - 3, y + 17, 7, 9, darkFrog);
  gfx->fillRect(x + FROG_W - 4, y + 17, 7, 9, darkFrog);
  gfx->fillRect(x - 5, y + 22, 5, 4, darkFrog);
  gfx->fillRect(x + FROG_W, y + 22, 5, 4, darkFrog);
  gfx->fillRoundRect(x + 3, y + 4, FROG_W - 6, FROG_H - 6, 7, frog);
  gfx->fillRect(x - 1, y + 7, 5, 5, darkFrog);
  gfx->fillRect(x + FROG_W - 4, y + 7, 5, 5, darkFrog);
  gfx->fillCircle(x + 6, y + 2, 4, frog);
  gfx->fillCircle(x + FROG_W - 6, y + 2, 4, frog);
  gfx->fillCircle(x + 6, y + 2, 3, RGB565_WHITE);
  gfx->fillCircle(x + FROG_W - 6, y + 2, 3, RGB565_WHITE);
  gfx->fillCircle(x + 6, y + 2, 1, RGB565_BLACK);
  gfx->fillCircle(x + FROG_W - 6, y + 2, 1, RGB565_BLACK);
  gfx->drawPixel(x + FROG_W / 2 - 2, y + 6, darkFrog);
  gfx->drawPixel(x + FROG_W / 2 + 1, y + 6, darkFrog);
}

void drawFroggerFrog(float xFloat, int row) {
  drawFroggerFrogWithColors(xFloat, row, rgb888to565(40, 200, 40), rgb888to565(0, 130, 0));
}

void drawFroggerNetworkFrog(int playerIndex) {
  if (playerIndex < 0 || playerIndex > 1) return;
  if (!frogNetAlive[playerIndex] || frogNetDying[playerIndex]) return;

  if (playerIndex == 0) {
    drawFroggerFrogWithColors(frogNetX[playerIndex], frogNetRow[playerIndex],
                              rgb888to565(40, 220, 50), rgb888to565(0, 130, 0));
  } else {
    drawFroggerFrogWithColors(frogNetX[playerIndex], frogNetRow[playerIndex],
                              rgb888to565(0, 220, 255), rgb888to565(0, 90, 170));
  }
}

void clearFroggerFrog(float xFloat, int row) {
  if (row < 0 || row >= FROG_ROWS) return;

  int x = (int)xFloat;
  int y = frogRowY[row] + (FROG_LANE_H - FROG_H) / 2;
  gfx->fillRect(x - 6, y - 3, FROG_W + 12, FROG_H + 6, froggerRowBg(row));

  if (row >= 5 && row <= 7) {
    int laneIndex = froggerLaneIndexForRow(row);

    if (laneIndex >= 0) {
      for (int i = 0; i < frogLanes[laneIndex].numObj; i++) {
        int ox = (int)frogLanes[laneIndex].objs[i].x;
        int ow = frogLanes[laneIndex].objs[i].w;

        if (ox + ow > x - 6 && ox < x + FROG_W + 6) {
          drawFroggerObstacle(frogLanes[laneIndex], i);
        }
      }
    }
  }
}

void drawFroggerGoalSlots() {
  int y = frogRowY[FROG_ROWS - 1];
  uint16_t grass = rgb888to565(30, 120, 30);
  uint16_t darkGrass = rgb888to565(15, 70, 15);
  uint16_t water = rgb888to565(20, 70, 190);
  uint16_t lily = rgb888to565(0, 160, 60);
  uint16_t frog = rgb888to565(40, 200, 40);
  uint16_t darkFrog = rgb888to565(0, 130, 0);

  gfx->fillRect(0, y, screenW, FROG_LANE_H, darkGrass);

  for (int i = 0; i < FROG_GOALS - 1; i++) {
    int sep = (frogGoalX[i] + frogGoalX[i + 1]) / 2;
    gfx->fillRect(sep - 2, y, 4, FROG_LANE_H, grass);
  }

  gfx->fillRect(0, y, 6, FROG_LANE_H, grass);
  gfx->fillRect(screenW - 6, y, 6, FROG_LANE_H, grass);

  for (int goal = 0; goal < FROG_GOALS; goal++) {
    int cx = frogGoalX[goal];
    int cy = y + FROG_LANE_H / 2;

    if (frogGoalFilled[goal]) {
      gfx->fillCircle(cx, cy, 14, lily);
      gfx->fillRoundRect(cx - 8, cy - 6, 16, 14, 4, frog);
      gfx->fillCircle(cx - 3, cy - 4, 2, RGB565_WHITE);
      gfx->fillCircle(cx + 3, cy - 4, 2, RGB565_WHITE);
    } else {
      gfx->fillCircle(cx, cy, 14, water);
      gfx->fillCircle(cx, cy, 12, lily);
      gfx->drawLine(cx, cy - 10, cx, cy + 10, darkFrog);
      gfx->drawLine(cx - 8, cy, cx + 8, cy, darkFrog);
    }
  }
}

void drawFroggerHud() {
  uint16_t hudBg = rgb888to565(0, 0, 40);
  uint16_t border = rgb888to565(50, 50, 220);

  gfx->fillRect(0, 0, screenW, FROG_HUD_H, hudBg);
  gfx->drawFastHLine(0, FROG_HUD_H, screenW, border);
  gfx->setTextColor(RGB565_GREEN);
  gfx->setTextSize(2);
  gfx->setCursor(55, 4);
  gfx->print("FROGGER");

  gfx->setTextSize(1);
  gfx->setTextColor(RGB565_WHITE);

  if (!localGame && activeNetworkGame == NETWORK_GAME_FROGGER) {
    gfx->setCursor(8, 28);
    gfx->print("P1:");
    gfx->setCursor(78, 28);
    gfx->print("L:");
    gfx->setCursor(114, 28);
    gfx->print("P2:");
    gfx->setCursor(184, 28);
    gfx->print("L:");
    gfx->setCursor(224, 28);
    gfx->print("Lv:");
  } else {
    gfx->setCursor(8, 28);
    gfx->print("Score:");
    gfx->setCursor(108, 28);
    gfx->print("Lives:");
    gfx->setCursor(176, 28);
    gfx->print("Lv:");
    gfx->setCursor(214, 28);
    gfx->print("Hi:");
  }

  drawButton(btnFrogMenuX, btnFrogMenuY, btnFrogMenuW, btnFrogMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENU", 1);
}

void drawFroggerHudValues() {
  uint16_t hudBg = rgb888to565(0, 0, 40);

  gfx->setTextSize(1);

  if (!localGame && activeNetworkGame == NETWORK_GAME_FROGGER) {
    gfx->fillRect(28, 26, 46, 12, hudBg);
    gfx->setTextColor(RGB565_GREEN);
    gfx->setCursor(28, 28);
    gfx->print(frogNetScore[0]);

    gfx->fillRect(90, 26, 18, 12, hudBg);
    gfx->setTextColor(frogNetLives[0] <= 1 ? RGB565_RED : RGB565_GREEN);
    gfx->setCursor(90, 28);
    gfx->print(frogNetLives[0]);

    gfx->fillRect(134, 26, 46, 12, hudBg);
    gfx->setTextColor(RGB565_CYAN);
    gfx->setCursor(134, 28);
    gfx->print(frogNetScore[1]);

    gfx->fillRect(196, 26, 18, 12, hudBg);
    gfx->setTextColor(frogNetLives[1] <= 1 ? RGB565_RED : RGB565_CYAN);
    gfx->setCursor(196, 28);
    gfx->print(frogNetLives[1]);

    gfx->fillRect(246, 26, 28, 12, hudBg);
    gfx->setTextColor(rgb888to565(255, 160, 0));
    gfx->setCursor(246, 28);
    gfx->print(frogLevel);
    return;
  }

  gfx->fillRect(48, 26, 52, 12, hudBg);
  gfx->setTextColor(RGB565_YELLOW);
  gfx->setCursor(48, 28);
  gfx->print(frogScore);

  gfx->fillRect(146, 26, 25, 12, hudBg);
  gfx->setTextColor(frogLives <= 1 ? RGB565_RED : RGB565_GREEN);
  gfx->setCursor(146, 28);
  gfx->print(frogLives);

  gfx->fillRect(194, 26, 18, 12, hudBg);
  gfx->setTextColor(rgb888to565(255, 160, 0));
  gfx->setCursor(194, 28);
  gfx->print(frogLevel);

  gfx->fillRect(234, 26, 52, 12, hudBg);
  gfx->setTextColor(RGB565_YELLOW);
  gfx->setCursor(234, 28);
  gfx->print(frogHiScore);
}

void drawFroggerControls() {
  uint16_t hudBg = rgb888to565(0, 0, 40);
  uint16_t border = rgb888to565(50, 50, 220);
  int buttonW = 68;
  int buttonH = 38;
  int gap = (screenW - 4 * buttonW) / 5;
  const char *labels[] = {"LEFT", "UP", "DOWN", "RIGHT"};
  uint16_t colors[] = {RGB565_GREEN, RGB565_YELLOW, RGB565_YELLOW, RGB565_GREEN};

  gfx->fillRect(0, FROG_BTN_TOP, screenW, screenH - FROG_BTN_TOP, hudBg);
  gfx->drawFastHLine(0, FROG_BTN_TOP, screenW, border);

  for (int i = 0; i < 4; i++) {
    int x = gap + i * (buttonW + gap);
    int y = FROG_BTN_TOP + (screenH - FROG_BTN_TOP - buttonH) / 2;
    gfx->drawRoundRect(x, y, buttonW, buttonH, 5, colors[i]);
    gfx->setTextColor(colors[i]);
    gfx->setTextSize(1);
    int tw = strlen(labels[i]) * 6;
    gfx->setCursor(x + (buttonW - tw) / 2, y + buttonH / 2 - 4);
    gfx->print(labels[i]);
  }
}

void drawFroggerFieldBg() {
  uint16_t roadLine = rgb888to565(180, 180, 180);
  uint16_t waterDark = rgb888to565(10, 45, 140);

  for (int r = 0; r < FROG_ROWS; r++) {
    gfx->fillRect(0, frogRowY[r], screenW, FROG_LANE_H, froggerRowBg(r));
  }

  for (int r = 1; r <= 3; r++) {
    int y = frogRowY[r] + FROG_LANE_H - 1;

    if (r < 3) {
      for (int x = 5; x < screenW; x += 24) {
        gfx->drawFastHLine(x, y, 12, roadLine);
      }
    }
  }

  gfx->drawFastHLine(0, frogRowY[1] + FROG_LANE_H, screenW, roadLine);
  gfx->drawFastHLine(0, frogRowY[3], screenW, roadLine);

  for (int r = 5; r <= 7; r++) {
    for (int x = 0; x < screenW; x += 35) {
      gfx->drawFastHLine(x, frogRowY[r] + FROG_LANE_H - 3, 18, waterDark);
    }
  }

  drawFroggerGoalSlots();
}

void drawFroggerFullScene() {
  gfx->fillScreen(RGB565_BLACK);
  drawFroggerHud();
  drawFroggerHudValues();
  drawFroggerFieldBg();

  for (int lane = 0; lane < FROG_LANES; lane++) {
    for (int obj = 0; obj < frogLanes[lane].numObj; obj++) {
      drawFroggerObstacle(frogLanes[lane], obj);
    }
  }

  if (!localGame && activeNetworkGame == NETWORK_GAME_FROGGER) {
    for (int p = 0; p < 2; p++) {
      drawFroggerNetworkFrog(p);
      frogNetPrevX[p] = frogNetX[p];
      frogNetPrevRow[p] = frogNetRow[p];
    }

    frogNetSceneReady = true;
  } else {
    drawFroggerFrog(frogX, frogRow);
    frogPrevX = frogX;
    frogPrevRow = frogRow;
  }

  drawFroggerControls();
}

void resetFroggerFrog() {
  frogX = (float)((screenW - FROG_W) / 2);
  frogRow = 0;
  frogAlive = true;
  frogJustJumped = false;
}

void resetFroggerGame() {
  frogScore = 0;
  frogLives = 3;
  frogLevel = 1;
  frogGameOver = false;
  frogDying = false;

  for (int i = 0; i < FROG_GOALS; i++) {
    frogGoalFilled[i] = false;
  }

  resetFroggerFrog();
  initFroggerLanes();
}

void froggerDie() {
  if (!frogAlive || frogDying || frogGameOver) return;

  frogAlive = false;
  frogDying = true;
  frogDeathTime = millis();
  playPriorityTone(180, 200);

  int y = frogRowY[frogRow] + (FROG_LANE_H - FROG_H) / 2;
  int x = (int)frogX;

  for (int flash = 0; flash < 3; flash++) {
    gfx->fillRect(x, y, FROG_W, FROG_H, RGB565_RED);
    delay(70);
    gfx->fillRect(x, y, FROG_W, FROG_H, froggerRowBg(frogRow));
    delay(70);
  }
}

void drawFroggerGameOverOverlay() {
  if (!localGame && activeNetworkGame == NETWORK_GAME_FROGGER) {
    gfx->fillRoundRect(28, 122, 264, 230, 10, rgb888to565(0, 0, 40));
    gfx->drawRoundRect(28, 122, 264, 230, 10, RGB565_RED);
    gfx->drawRoundRect(34, 128, 252, 218, 8, RGB565_CYAN);

    int localPlayer = (myPlayer == '2') ? 2 : 1;

    if (frogNetWinner == 3) {
      drawCenteredText("DRAW", 154, 3, RGB565_YELLOW);
    } else if (frogNetWinner == localPlayer) {
      drawCenteredText("YOU WIN", 154, 3, RGB565_GREEN);
    } else {
      drawCenteredText("YOU LOSE", 154, 3, RGB565_RED);
    }

    char line[48];
    snprintf(line, sizeof(line), "P1:%d  P2:%d", frogNetScore[0], frogNetScore[1]);
    drawCenteredText(line, 220, 2, RGB565_WHITE);
    snprintf(line, sizeof(line), "Level: %d", frogLevel);
    drawCenteredText(line, 252, 2, RGB565_YELLOW);
    drawCenteredText("Tap to restart", 292, 1, RGB565_CYAN);
    return;
  }

  if ((uint32_t)frogScore >= frogHiScore) {
    frogHiScore = frogScore;
    saveFroggerScore();
  }

  gfx->fillRoundRect(28, 122, 264, 230, 10, rgb888to565(0, 0, 40));
  gfx->drawRoundRect(28, 122, 264, 230, 10, RGB565_RED);
  gfx->drawRoundRect(34, 128, 252, 218, 8, RGB565_GREEN);

  drawCenteredText("GAME OVER", 154, 3, RGB565_RED);

  char line[40];
  snprintf(line, sizeof(line), "Level: %d", frogLevel);
  drawCenteredText(line, 214, 2, RGB565_YELLOW);
  snprintf(line, sizeof(line), "Score: %d", frogScore);
  drawCenteredText(line, 246, 2, RGB565_GREEN);
  drawCenteredText("Tap to restart", 292, 1, RGB565_CYAN);
}

void finishFroggerGame() {
  frogGameOver = true;
  frogDying = false;
  drawFroggerGameOverOverlay();
}

void handleFroggerDying() {
  if (!frogDying) return;
  if (millis() - frogDeathTime < 800) return;

  frogLives--;

  if (frogLives <= 0) {
    finishFroggerGame();
    return;
  }

  frogDying = false;
  resetFroggerFrog();
  drawFroggerFieldBg();

  for (int lane = 0; lane < FROG_LANES; lane++) {
    for (int obj = 0; obj < frogLanes[lane].numObj; obj++) {
      drawFroggerObstacle(frogLanes[lane], obj);
    }
  }

  drawFroggerFrog(frogX, frogRow);
  frogPrevX = frogX;
  frogPrevRow = frogRow;
  drawFroggerHudValues();
}

void checkFroggerCollisions() {
  if (!frogAlive || frogDying || frogGameOver) return;

  if (frogRow >= 1 && frogRow <= 3) {
    int laneIndex = froggerLaneIndexForRow(frogRow);

    if (laneIndex >= 0) {
      for (int i = 0; i < frogLanes[laneIndex].numObj; i++) {
        float ox = frogLanes[laneIndex].objs[i].x;
        int ow = frogLanes[laneIndex].objs[i].w;

        if (frogX + FROG_W - 4 > ox && frogX + 4 < ox + ow) {
          froggerDie();
          return;
        }
      }
    }
  }

  if (frogRow >= 5 && frogRow <= 7) {
    bool onLog = false;
    int laneIndex = froggerLaneIndexForRow(frogRow);

    if (laneIndex >= 0) {
      for (int i = 0; i < frogLanes[laneIndex].numObj; i++) {
        float ox = frogLanes[laneIndex].objs[i].x;
        int ow = frogLanes[laneIndex].objs[i].w;
        float frogCenter = frogX + FROG_W / 2.0f;

        if (frogCenter > ox + 4 && frogCenter < ox + ow - 4) {
          onLog = true;
          frogX += frogLanes[laneIndex].speed;
          break;
        }
      }
    }

    if (!onLog && !frogJustJumped) {
      froggerDie();
      return;
    }

    if (frogX + FROG_W < -5 || frogX > screenW + 5) {
      froggerDie();
      return;
    }

    frogX = constrain(frogX, -2.0f, (float)(screenW - FROG_W + 2));
  }

  if (frogRow == FROG_ROWS - 1) {
    float frogCenter = frogX + FROG_W / 2.0f;
    bool landed = false;

    for (int goal = 0; goal < FROG_GOALS; goal++) {
      if (!frogGoalFilled[goal] && fabs(frogCenter - frogGoalX[goal]) < 30.0f) {
        frogGoalFilled[goal] = true;
        frogScore += 50;

        if ((uint32_t)frogScore > frogHiScore) {
          frogHiScore = frogScore;
        }

        playPriorityTone(1400, 80);
        drawFroggerGoalSlots();
        landed = true;
        break;
      }
    }

    if (!landed && !frogJustJumped) {
      froggerDie();
      return;
    }

    if (!landed) {
      frogJustJumped = false;
      return;
    }

    bool allFilled = true;
    for (int goal = 0; goal < FROG_GOALS; goal++) {
      if (!frogGoalFilled[goal]) {
        allFilled = false;
        break;
      }
    }

    if (allFilled) {
      frogLevel++;
      frogScore += 100;

      if ((uint32_t)frogScore > frogHiScore) {
        frogHiScore = frogScore;
      }

      for (int goal = 0; goal < FROG_GOALS; goal++) {
        frogGoalFilled[goal] = false;
      }

      initFroggerLanes();
      playPriorityTone(1800, 100);
      delay(300);
      drawFroggerFieldBg();

      for (int lane = 0; lane < FROG_LANES; lane++) {
        for (int obj = 0; obj < frogLanes[lane].numObj; obj++) {
          drawFroggerObstacle(frogLanes[lane], obj);
        }
      }
    }

    resetFroggerFrog();
    frogScore += 10;
  }

  frogJustJumped = false;
}

void updateFroggerLane(int laneIndex) {
  FroggerLane &lane = frogLanes[laneIndex];
  int y = frogRowY[lane.row];

  for (int i = 0; i < lane.numObj; i++) {
    float oldX = lane.objs[i].x;
    lane.objs[i].x += lane.speed;
    int w = lane.objs[i].w;

    if (lane.speed > 0 && lane.objs[i].x > screenW + 15) {
      lane.objs[i].x = (float)(-(w + 15));
    } else if (lane.speed < 0 && lane.objs[i].x + w < -15) {
      lane.objs[i].x = (float)(screenW + 15);
    }

    float newX = lane.objs[i].x;
    float delta = newX - oldX;

    if (fabs(delta) > (float)w) {
      int clearX = max(0, (int)oldX);
      int clearEnd = min(screenW, (int)oldX + w);
      if (clearEnd > clearX) {
        gfx->fillRect(clearX, y, clearEnd - clearX, FROG_LANE_H, froggerRowBg(lane.row));
      }
    } else if (delta > 0.1f) {
      int clearX = max(0, (int)oldX);
      int clearEnd = min(screenW, (int)newX);
      if (clearEnd > clearX) {
        gfx->fillRect(clearX, y, clearEnd - clearX, FROG_LANE_H, froggerRowBg(lane.row));
      }
    } else if (delta < -0.1f) {
      int clearX = max(0, (int)(newX + w));
      int clearEnd = min(screenW, (int)(oldX + w));
      if (clearEnd > clearX) {
        gfx->fillRect(clearX, y, clearEnd - clearX, FROG_LANE_H, froggerRowBg(lane.row));
      }
    }

    drawFroggerObstacle(lane, i);
  }
}

void drawFroggerGameFrame() {
  bool rowChanged = (frogRow != frogPrevRow);
  bool hopped = (fabs(frogX - frogPrevX) > (float)FROG_STEP_X * 0.5f);

  if (rowChanged || hopped) {
    clearFroggerFrog(frogPrevX, frogPrevRow);
  }

  bool frogDrawn = false;

  for (int lane = 0; lane < FROG_LANES; lane++) {
    updateFroggerLane(lane);

    if (frogLanes[lane].row == frogRow) {
      drawFroggerFrog(frogX, frogRow);
      frogDrawn = true;
    }
  }

  if (!frogDrawn && (rowChanged || hopped)) {
    drawFroggerFrog(frogX, frogRow);
  }

  frogPrevX = frogX;
  frogPrevRow = frogRow;
  drawFroggerHudValues();
}

void sendFroggerState(bool force);
void sendFroggerGoalClaim(int slot);
void sendFroggerGameOver();
void sendFroggerEspNowStart();
void processFroggerEspNow();
void updateFroggerEspNowNetwork();
void stopFroggerEspNow();
void finishFroggerNetworkGame();
void newFroggerNetworkGame();
void redrawFroggerNetworkPlayersOnly();

void updateFroggerGame() {
  if (appState != STATE_FROGGER_PLAYING) return;

  if (!localGame) {
    processFroggerEspNow();

    if (frogNetGameOver) {
      return;
    }

    unsigned long now = millis();

    if (now - frogLastFrame < FROG_FRAME_MS) return;
    frogLastFrame = now;

    checkFroggerNetworkPlayerCollisions(froggerLocalNetworkPlayerIndex());

    if (frogNetGameOver) {
      return;
    }

    drawFroggerNetworkGameFrame();
    sendFroggerState(false);
    return;
  }

  if (frogDying) {
    handleFroggerDying();
    return;
  }

  if (frogGameOver) return;

  unsigned long now = millis();

  if (now - frogLastFrame < FROG_FRAME_MS) return;
  frogLastFrame = now;

  checkFroggerCollisions();
  if (frogDying || frogGameOver) return;

  drawFroggerGameFrame();
}

void moveFroggerFrog(int action) {
  if (frogDying || frogGameOver) return;

  if (action == 0) {
    if (frogX > 0) {
      frogX -= FROG_STEP_X;
      playPriorityTone(800, 30);
    }
  } else if (action == 1) {
    if (frogRow < FROG_ROWS - 1) {
      frogRow++;
      frogScore++;
      frogJustJumped = true;
      playPriorityTone(800, 30);
    }
  } else if (action == 2) {
    if (frogRow > 0) {
      frogRow--;
      frogJustJumped = true;
      playPriorityTone(800, 30);
    }
  } else if (action == 3) {
    if (frogX < screenW - FROG_W) {
      frogX += FROG_STEP_X;
      playPriorityTone(800, 30);
    }
  }

  frogX = constrain(frogX, 0.0f, (float)(screenW - FROG_W));
  checkFroggerCollisions();

  if (!frogDying && !frogGameOver) {
    clearFroggerFrog(frogPrevX, frogPrevRow);
    drawFroggerFrog(frogX, frogRow);
    frogPrevX = frogX;
    frogPrevRow = frogRow;
    drawFroggerHudValues();
  }
}

int froggerLocalNetworkPlayerIndex() {
  return (myPlayer == '2') ? 1 : 0;
}

int froggerGoalMask() {
  int mask = 0;

  for (int goal = 0; goal < FROG_GOALS; goal++) {
    if (frogGoalFilled[goal]) {
      mask |= (1 << goal);
    }
  }

  return mask;
}

void setFroggerGoalMask(int mask) {
  for (int goal = 0; goal < FROG_GOALS; goal++) {
    frogGoalFilled[goal] = ((mask & (1 << goal)) != 0);
  }
}

void onFroggerEspNowRecv(const esp_now_recv_info_t *info, const uint8_t *data, int len) {
  if (!info || !data || len <= 0) return;

  int next = (frogEspRxHead + 1) % FROG_ESPNOW_RX_SIZE;
  if (next == frogEspRxTail) return;

  int copyLen = (len > FROG_ESPNOW_MAX_PACKET) ? FROG_ESPNOW_MAX_PACKET : len;
  memcpy(frogEspRxBuffer[frogEspRxHead].data, data, copyLen);
  memcpy(frogEspRxBuffer[frogEspRxHead].mac, info->src_addr, 6);
  frogEspRxBuffer[frogEspRxHead].len = copyLen;
  frogEspRxHead = next;
}

void onFroggerEspNowSent(const wifi_tx_info_t *info, esp_now_send_status_t status) {
  (void)info;
  (void)status;
}

bool froggerEspNowReceive(uint8_t *data, int maxLen, uint8_t *mac, int &lenOut) {
  if (frogEspRxTail == frogEspRxHead) return false;

  int copyLen = frogEspRxBuffer[frogEspRxTail].len;
  if (copyLen > maxLen) {
    copyLen = maxLen;
  }

  memcpy(data, frogEspRxBuffer[frogEspRxTail].data, copyLen);
  if (mac) {
    memcpy(mac, frogEspRxBuffer[frogEspRxTail].mac, 6);
  }

  frogEspRxTail = (frogEspRxTail + 1) % FROG_ESPNOW_RX_SIZE;
  lenOut = copyLen;
  return true;
}

void froggerEspNowAddPeer(const uint8_t *mac) {
  if (!frogEspReady || !mac) return;

  memcpy(frogEspPeerMac, mac, 6);
  frogEspPeerKnown = true;

  if (esp_now_is_peer_exist(mac)) return;

  esp_now_peer_info_t peerInfo;
  memset(&peerInfo, 0, sizeof(peerInfo));
  memcpy(peerInfo.peer_addr, mac, 6);
  peerInfo.channel = FROG_ESPNOW_CHANNEL;
  peerInfo.encrypt = false;

  esp_now_add_peer(&peerInfo);
}

bool froggerEspNowSend(const void *packet, int len) {
  if (!frogEspReady || !frogEspPeerKnown || !packet || len <= 0) return false;
  return esp_now_send(frogEspPeerMac, (const uint8_t *)packet, len) == ESP_OK;
}

bool froggerEspNowBroadcast(const void *packet, int len) {
  if (!frogEspReady || !packet || len <= 0) return false;
  return esp_now_send(frogEspBroadcastMac, (const uint8_t *)packet, len) == ESP_OK;
}

bool initFroggerEspNow() {
  frogEspReady = false;
  frogEspPeerKnown = false;
  frogEspRxHead = 0;
  frogEspRxTail = 0;
  frogEspLastHelloTime = 0;
  frogEspLastPeerRxTime = 0;

  esp_now_deinit();

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(20);
  esp_wifi_set_channel(FROG_ESPNOW_CHANNEL, WIFI_SECOND_CHAN_NONE);
  esp_wifi_set_ps(WIFI_PS_NONE);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Frogger ESP-NOW init failed");
    return false;
  }

  esp_now_register_recv_cb(onFroggerEspNowRecv);
  esp_now_register_send_cb(onFroggerEspNowSent);

  esp_now_peer_info_t peerInfo;
  memset(&peerInfo, 0, sizeof(peerInfo));
  memcpy(peerInfo.peer_addr, frogEspBroadcastMac, 6);
  peerInfo.channel = FROG_ESPNOW_CHANNEL;
  peerInfo.encrypt = false;
  esp_now_add_peer(&peerInfo);

  frogEspReady = true;
  Serial.println("Frogger ESP-NOW ready");
  return true;
}

void stopFroggerEspNow() {
  if (frogEspReady || frogEspPeerKnown) {
    esp_now_deinit();
  }

  frogEspReady = false;
  frogEspPeerKnown = false;
  frogEspRxHead = 0;
  frogEspRxTail = 0;
}

void sendFroggerEspNowHello() {
  FrogEspNowHelloPacket packet;
  packet.type = FROG_PKT_HELLO;
  froggerEspNowBroadcast(&packet, sizeof(packet));
}

void sendFroggerEspNowAck() {
  FrogEspNowAckPacket packet;
  packet.type = FROG_PKT_ACK;
  froggerEspNowSend(&packet, sizeof(packet));
}

void sendFroggerEspNowStart() {
  FrogEspNowStartPacket packet;
  packet.type = FROG_PKT_START;
  packet.level = (uint8_t)constrain(frogLevel, 1, 99);
  froggerEspNowSend(&packet, sizeof(packet));
}

void resetFroggerNetworkPlayer(int playerIndex) {
  if (playerIndex < 0 || playerIndex > 1) return;

  frogNetX[playerIndex] = (float)((screenW - FROG_W) / 2);
  frogNetRow[playerIndex] = 0;
  frogNetAlive[playerIndex] = true;
  frogNetDying[playerIndex] = false;
  frogNetJustJumped[playerIndex] = false;
  frogNetDeathTime[playerIndex] = 0;
}

void resetFroggerNetworkPlayers() {
  resetFroggerNetworkPlayer(0);
  resetFroggerNetworkPlayer(1);
}

void froggerNetworkDie(int playerIndex) {
  if (playerIndex < 0 || playerIndex > 1) return;
  if (!frogNetAlive[playerIndex] || frogNetGameOver) return;

  frogNetLives[playerIndex]--;
  playPriorityTone(180, 120);

  if (frogNetLives[playerIndex] <= 0) {
    frogNetLives[playerIndex] = 0;
    frogNetAlive[playerIndex] = false;
    frogNetDying[playerIndex] = false;
    finishFroggerNetworkGame();
    return;
  }

  resetFroggerNetworkPlayer(playerIndex);
}

void finishFroggerNetworkGame() {
  if (frogNetGameOver) return;

  frogNetGameOver = true;

  if (frogNetLives[0] <= 0 && frogNetLives[1] <= 0) {
    frogNetWinner = 3;
  } else if (frogNetLives[0] <= 0) {
    frogNetWinner = 2;
  } else if (frogNetLives[1] <= 0) {
    frogNetWinner = 1;
  } else {
    frogNetWinner = 3;
  }

  myTurn = false;
  drawFroggerFullScene();
  drawFroggerGameOverOverlay();
  sendFroggerGameOver();
  sendFroggerState(true);
}

void handleFroggerNetworkDying() {
  if (frogNetGameOver) return;

  bool changed = false;

  for (int p = 0; p < 2; p++) {
    if (!frogNetDying[p]) continue;
    if (millis() - frogNetDeathTime[p] < 800) continue;

    frogNetLives[p]--;
    changed = true;

    if (frogNetLives[p] <= 0) {
      frogNetDying[p] = false;
      frogNetAlive[p] = false;
      continue;
    }

    resetFroggerNetworkPlayer(p);
  }

  if (frogNetLives[0] <= 0 || frogNetLives[1] <= 0) {
    finishFroggerNetworkGame();
    return;
  }

  if (changed) {
    drawFroggerFullScene();
  }
}

void checkFroggerNetworkPlayerCollisions(int playerIndex) {
  if (playerIndex < 0 || playerIndex > 1) return;
  if (!frogNetAlive[playerIndex] || frogNetDying[playerIndex] || frogNetGameOver) return;

  int row = frogNetRow[playerIndex];

  if (row >= 1 && row <= 3) {
    int laneIndex = froggerLaneIndexForRow(row);

    if (laneIndex >= 0) {
      for (int i = 0; i < frogLanes[laneIndex].numObj; i++) {
        float ox = frogLanes[laneIndex].objs[i].x;
        int ow = frogLanes[laneIndex].objs[i].w;

        if (frogNetX[playerIndex] + FROG_W - 4 > ox && frogNetX[playerIndex] + 4 < ox + ow) {
          froggerNetworkDie(playerIndex);
          return;
        }
      }
    }
  }

  if (row >= 5 && row <= 7) {
    bool onLog = false;
    int laneIndex = froggerLaneIndexForRow(row);

    if (laneIndex >= 0) {
      for (int i = 0; i < frogLanes[laneIndex].numObj; i++) {
        float ox = frogLanes[laneIndex].objs[i].x;
        int ow = frogLanes[laneIndex].objs[i].w;
        float frogCenter = frogNetX[playerIndex] + FROG_W / 2.0f;

        if (frogCenter > ox + 4 && frogCenter < ox + ow - 4) {
          onLog = true;
          frogNetX[playerIndex] += frogLanes[laneIndex].speed;
          break;
        }
      }
    }

    if (!onLog && !frogNetJustJumped[playerIndex]) {
      froggerNetworkDie(playerIndex);
      return;
    }

    if (frogNetX[playerIndex] + FROG_W < -5 || frogNetX[playerIndex] > screenW + 5) {
      froggerNetworkDie(playerIndex);
      return;
    }

    frogNetX[playerIndex] = constrain(frogNetX[playerIndex], -2.0f, (float)(screenW - FROG_W + 2));
  }

  if (row == FROG_ROWS - 1) {
    float frogCenter = frogNetX[playerIndex] + FROG_W / 2.0f;
    bool landed = false;

    for (int goal = 0; goal < FROG_GOALS; goal++) {
      if (!frogGoalFilled[goal] && fabs(frogCenter - frogGoalX[goal]) < 30.0f) {
        frogGoalFilled[goal] = true;
        frogNetScore[playerIndex] += 50;
        landed = true;
        sendFroggerGoalClaim(goal);
        playPriorityTone(1400, 60);
        break;
      }
    }

    if (!landed && !frogNetJustJumped[playerIndex]) {
      froggerNetworkDie(playerIndex);
      return;
    }

    if (!landed) {
      frogNetJustJumped[playerIndex] = false;
      return;
    }

    bool allFilled = true;
    for (int goal = 0; goal < FROG_GOALS; goal++) {
      if (!frogGoalFilled[goal]) {
        allFilled = false;
        break;
      }
    }

    if (allFilled) {
      frogLevel++;
      frogNetScore[playerIndex] += 100;

      for (int goal = 0; goal < FROG_GOALS; goal++) {
        frogGoalFilled[goal] = false;
      }

      initFroggerLanes();
      resetFroggerNetworkPlayers();
      playPriorityTone(1800, 80);
      return;
    }

    resetFroggerNetworkPlayer(playerIndex);
    frogNetScore[playerIndex] += 10;
  }

  frogNetJustJumped[playerIndex] = false;
}

void applyFroggerNetworkInput(int playerIndex, int action, bool localFeedback) {
  if (playerIndex < 0 || playerIndex > 1) return;
  if (frogNetDying[playerIndex] || frogNetGameOver) return;

  bool moved = false;

  if (action == 0) {
    if (frogNetX[playerIndex] > 0) {
      frogNetX[playerIndex] -= FROG_STEP_X;
      moved = true;
    }
  } else if (action == 1) {
    if (frogNetRow[playerIndex] < FROG_ROWS - 1) {
      frogNetRow[playerIndex]++;
      frogNetScore[playerIndex]++;
      frogNetJustJumped[playerIndex] = true;
      moved = true;
    }
  } else if (action == 2) {
    if (frogNetRow[playerIndex] > 0) {
      frogNetRow[playerIndex]--;
      frogNetJustJumped[playerIndex] = true;
      moved = true;
    }
  } else if (action == 3) {
    if (frogNetX[playerIndex] < screenW - FROG_W) {
      frogNetX[playerIndex] += FROG_STEP_X;
      moved = true;
    }
  }

  frogNetX[playerIndex] = constrain(frogNetX[playerIndex], 0.0f, (float)(screenW - FROG_W));

  if (moved && localFeedback) {
    playPriorityTone(800, 30);
  }
}

void sendFroggerInput(int action) {
  if (localGame || !networkConnected) return;

  frogLocalInputSeq++;

  String msg = "FROG_INPUT:";
  msg += String(froggerLocalNetworkPlayerIndex());
  msg += ",";
  msg += String(action);
  msg += ",";
  msg += String(frogLocalInputSeq);
  sendNetMessage(msg);
}

void applyFroggerPlayerAction(int action) {
  if (localGame) {
    moveFroggerFrog(action);
    return;
  }

  if (!networkConnected && !frogEspReady) return;
  if (frogNetGameOver) return;

  int playerIndex = froggerLocalNetworkPlayerIndex();
  frogLocalInputSeq++;
  frogNetInputSeq[playerIndex] = frogLocalInputSeq;
  applyFroggerNetworkInput(playerIndex, action, true);
  checkFroggerNetworkPlayerCollisions(playerIndex);
  redrawFroggerNetworkPlayersOnly();
  sendFroggerState(true);

}

void drawFroggerNetworkGameFrame() {
  if (frogNetSceneReady) {
    for (int p = 0; p < 2; p++) {
      clearFroggerFrog(frogNetPrevX[p], frogNetPrevRow[p]);
    }
  }

  for (int lane = 0; lane < FROG_LANES; lane++) {
    updateFroggerLane(lane);
  }

  for (int p = 0; p < 2; p++) {
    drawFroggerNetworkFrog(p);
    frogNetPrevX[p] = frogNetX[p];
    frogNetPrevRow[p] = frogNetRow[p];
  }

  frogNetSceneReady = true;
  drawFroggerHudValues();
}

void redrawFroggerNetworkPlayersOnly() {
  if (!frogNetSceneReady) {
    drawFroggerFullScene();
    return;
  }

  for (int p = 0; p < 2; p++) {
    clearFroggerFrog(frogNetPrevX[p], frogNetPrevRow[p]);
  }

  for (int p = 0; p < 2; p++) {
    drawFroggerNetworkFrog(p);
    frogNetPrevX[p] = frogNetX[p];
    frogNetPrevRow[p] = frogNetRow[p];
  }

  drawFroggerHudValues();
}

void drawFroggerRemoteStateFrame(int oldObjX[FROG_LANES][FROG_MAX_OBJECTS]) {
  if (frogNetSceneReady) {
    for (int p = 0; p < 2; p++) {
      clearFroggerFrog(frogNetPrevX[p], frogNetPrevRow[p]);
    }
  }

  for (int lane = 0; lane < FROG_LANES; lane++) {
    int row = frogLanes[lane].row;
    int y = frogRowY[row];

    for (int obj = 0; obj < frogLanes[lane].numObj; obj++) {
      int w = frogLanes[lane].objs[obj].w;
      int oldX = oldObjX[lane][obj];
      int newX = (int)frogLanes[lane].objs[obj].x;
      int clearX = max(0, min(oldX, newX) - 3);
      int clearEnd = min(screenW, max(oldX + w, newX + w) + 3);

      if (clearEnd > clearX) {
        gfx->fillRect(clearX, y, clearEnd - clearX, FROG_LANE_H, froggerRowBg(row));
      }

      drawFroggerObstacle(frogLanes[lane], obj);
    }
  }

  for (int p = 0; p < 2; p++) {
    drawFroggerNetworkFrog(p);
    frogNetPrevX[p] = frogNetX[p];
    frogNetPrevRow[p] = frogNetRow[p];
  }

  frogNetSceneReady = true;
  drawFroggerHudValues();
}

void sendFroggerState(bool force) {
  if (localGame) return;

  bool useEspNow = frogEspReady;
  if (useEspNow && !frogEspPeerKnown) return;
  if (!useEspNow && !networkConnected) return;

  unsigned long now = millis();

  if (!force && now - frogLastStateSendTime < FROG_NET_STATE_MS) {
    return;
  }

  frogLastStateSendTime = now;

  int playerIndex = froggerLocalNetworkPlayerIndex();

  if (useEspNow) {
    FrogEspNowStatePacket packet;
    packet.type = FROG_PKT_STATE;
    packet.player = (uint8_t)(playerIndex + 1);
    packet.x = frogNetX[playerIndex];
    packet.row = (uint8_t)constrain(frogNetRow[playerIndex], 0, FROG_ROWS - 1);
    packet.score = (int16_t)constrain(frogNetScore[playerIndex], -32768, 32767);
    packet.lives = (uint8_t)constrain(frogNetLives[playerIndex], 0, 255);
    packet.alive = (frogNetAlive[playerIndex] && !frogNetDying[playerIndex]) ? 1 : 0;
    froggerEspNowSend(&packet, sizeof(packet));
    return;
  }

  String msg = "FROG_STATE:";
  msg.reserve(96);

  msg += String(playerIndex);
  msg += ",";
  msg += String(frogNetGameOver ? 1 : 0);
  msg += ",";
  msg += String(frogNetWinner);
  msg += ",";
  msg += String(frogLevel);
  msg += ",";
  msg += String(froggerGoalMask());
  msg += ",";
  msg += String(frogNetScore[playerIndex]);
  msg += ",";
  msg += String(frogNetLives[playerIndex]);
  msg += ",";
  msg += String((int)frogNetX[playerIndex]);
  msg += ",";
  msg += String(frogNetRow[playerIndex]);
  msg += ",";
  msg += String(frogNetAlive[playerIndex] ? 1 : 0);
  msg += ",";
  msg += String(frogNetDying[playerIndex] ? 1 : 0);
  msg += ",";
  msg += String(frogNetInputSeq[playerIndex]);

  sendNetMessage(msg);
}

void sendFroggerGoalClaim(int slot) {
  if (localGame) return;
  if (slot < 0 || slot >= FROG_GOALS) return;

  if (frogEspReady && frogEspPeerKnown) {
    FrogEspNowGoalPacket packet;
    packet.type = FROG_PKT_GOAL;
    packet.slot = (uint8_t)slot;
    packet.player = (uint8_t)(froggerLocalNetworkPlayerIndex() + 1);
    froggerEspNowSend(&packet, sizeof(packet));
    return;
  }

  if (networkConnected) {
    String msg = "FROG_GOAL:";
    msg += String(slot);
    msg += ",";
    msg += String(froggerLocalNetworkPlayerIndex() + 1);
    sendNetMessage(msg);
  }
}

void sendFroggerGameOver() {
  if (localGame) return;

  if (frogEspReady && frogEspPeerKnown) {
    FrogEspNowOverPacket packet;
    packet.type = FROG_PKT_OVER;
    packet.winner = (uint8_t)constrain(frogNetWinner, 0, 3);
    packet.score0 = (int16_t)constrain(frogNetScore[0], -32768, 32767);
    packet.score1 = (int16_t)constrain(frogNetScore[1], -32768, 32767);
    froggerEspNowSend(&packet, sizeof(packet));
    return;
  }

  if (networkConnected) {
    String msg = "FROG_OVER:";
    msg += String(frogNetWinner);
    msg += ",";
    msg += String(frogNetScore[0]);
    msg += ",";
    msg += String(frogNetScore[1]);
    sendNetMessage(msg);
  }
}

void applyRemoteFroggerState(const String &payload) {
  activeNetworkGame = NETWORK_GAME_FROGGER;
  localGame = false;
  appState = STATE_FROGGER_PLAYING;

  int start = 0;
  int playerIndex, gameOverValue, winnerValue, levelValue, goalMaskValue;
  int scoreValue, livesValue, xValue, rowValue, aliveValue, dyingValue, seqValue;

  if (!readCsvInt(payload, start, playerIndex)) return;
  if (!readCsvInt(payload, start, gameOverValue)) return;
  if (!readCsvInt(payload, start, winnerValue)) return;
  if (!readCsvInt(payload, start, levelValue)) return;
  if (!readCsvInt(payload, start, goalMaskValue)) return;
  if (!readCsvInt(payload, start, scoreValue)) return;
  if (!readCsvInt(payload, start, livesValue)) return;
  if (!readCsvInt(payload, start, xValue)) return;
  if (!readCsvInt(payload, start, rowValue)) return;
  if (!readCsvInt(payload, start, aliveValue)) return;
  if (!readCsvInt(payload, start, dyingValue)) return;
  if (!readCsvInt(payload, start, seqValue)) return;

  if (playerIndex < 0 || playerIndex > 1) return;
  if (playerIndex == froggerLocalNetworkPlayerIndex()) return;

  bool wasGameOver = frogNetGameOver;
  int oldLevel = frogLevel;
  int oldGoalMask = froggerGoalMask();
  int mergedGoalMask = (levelValue == oldLevel) ? (goalMaskValue | oldGoalMask) : goalMaskValue;

  frogNetGameOver = frogNetGameOver || (gameOverValue != 0);
  if (winnerValue != 0) {
    frogNetWinner = winnerValue;
  }

  frogLevel = constrain(levelValue, 1, 99);
  if (oldLevel != frogLevel) {
    initFroggerLanes();
  }

  setFroggerGoalMask(mergedGoalMask);

  frogNetScore[playerIndex] = scoreValue;
  frogNetLives[playerIndex] = livesValue;
  frogNetX[playerIndex] = (float)constrain(xValue, -8, screenW + 8);
  frogNetRow[playerIndex] = constrain(rowValue, 0, FROG_ROWS - 1);
  frogNetAlive[playerIndex] = (aliveValue != 0);
  frogNetDying[playerIndex] = (dyingValue != 0);
  frogNetInputSeq[playerIndex] = seqValue;

  if (!frogNetSceneReady || oldLevel != frogLevel || (!wasGameOver && frogNetGameOver)) {
    drawFroggerFullScene();
  } else {
    if (oldGoalMask != froggerGoalMask()) {
      drawFroggerGoalSlots();
    }

    redrawFroggerNetworkPlayersOnly();
  }

  if (frogNetGameOver) {
    if (!wasGameOver) {
      int localPlayer = (myPlayer == '2') ? 2 : 1;
      if (frogNetWinner == localPlayer) {
        beepWin();
      } else {
        beepDraw();
      }
    }

    drawFroggerGameOverOverlay();
  }
}

void newFroggerNetworkGame() {
  activeNetworkGame = NETWORK_GAME_FROGGER;
  localGame = false;
  appState = STATE_FROGGER_PLAYING;
  myTurn = true;
  frogLevel = constrain(frogLevel, 1, 99);
  frogNetScore[0] = 0;
  frogNetScore[1] = 0;
  frogNetLives[0] = 3;
  frogNetLives[1] = 3;
  frogNetGameOver = false;
  frogNetWinner = 0;
  frogNetInputSeq[0] = 0;
  frogNetInputSeq[1] = 0;
  frogLocalInputSeq = 0;

  for (int goal = 0; goal < FROG_GOALS; goal++) {
    frogGoalFilled[goal] = false;
  }

  initFroggerLayout();
  initFroggerLanes();
  resetFroggerNetworkPlayers();
  frogLastFrame = millis();
  frogLastStateSendTime = 0;
  frogNetSceneReady = false;
  drawFroggerFullScene();
}

void processFroggerEspNow() {
  if (!frogEspReady) return;

  uint8_t buffer[FROG_ESPNOW_MAX_PACKET];
  uint8_t mac[6];
  int len = 0;

  while (froggerEspNowReceive(buffer, sizeof(buffer), mac, len)) {
    if (len < 1) continue;

    uint8_t type = buffer[0];
    frogEspLastPeerRxTime = millis();

    bool waitingForPeer = (appState == STATE_WAITING_HOST || appState == STATE_CONNECTING_JOIN);

    if (type == FROG_PKT_HELLO) {
      froggerEspNowAddPeer(mac);

      if (isHost) {
        if (waitingForPeer) {
          frogLevel = 1;
        }

        sendFroggerEspNowAck();
        sendFroggerEspNowStart();

        if (waitingForPeer) {
          newFroggerNetworkGame();
          sendFroggerState(true);
        }
      }

      continue;
    }

    if (!isHost && type == FROG_PKT_ACK) {
      froggerEspNowAddPeer(mac);

      if (waitingForPeer) {
        playPriorityTone(1200, 50);
      }

      continue;
    }

    if (type == FROG_PKT_START && len >= (int)sizeof(FrogEspNowStartPacket)) {
      froggerEspNowAddPeer(mac);
      FrogEspNowStartPacket *packet = (FrogEspNowStartPacket *)buffer;
      frogLevel = constrain((int)packet->level, 1, 99);
      newFroggerNetworkGame();
      sendFroggerState(true);
      continue;
    }

    if (type == FROG_PKT_STATE && len >= (int)sizeof(FrogEspNowStatePacket)) {
      if (appState != STATE_FROGGER_PLAYING) continue;

      FrogEspNowStatePacket *packet = (FrogEspNowStatePacket *)buffer;
      int playerIndex = (int)packet->player - 1;

      if (playerIndex < 0 || playerIndex > 1) continue;
      if (playerIndex == froggerLocalNetworkPlayerIndex()) continue;

      frogNetX[playerIndex] = constrain(packet->x, -8.0f, (float)(screenW + 8));
      frogNetRow[playerIndex] = constrain((int)packet->row, 0, FROG_ROWS - 1);
      frogNetScore[playerIndex] = packet->score;
      frogNetLives[playerIndex] = packet->lives;
      frogNetAlive[playerIndex] = (packet->alive != 0);
      frogNetDying[playerIndex] = false;
      continue;
    }

    if (type == FROG_PKT_GOAL && len >= (int)sizeof(FrogEspNowGoalPacket)) {
      if (appState != STATE_FROGGER_PLAYING) continue;

      FrogEspNowGoalPacket *packet = (FrogEspNowGoalPacket *)buffer;
      int slot = packet->slot;

      if (slot >= 0 && slot < FROG_GOALS && !frogGoalFilled[slot]) {
        frogGoalFilled[slot] = true;

        bool allFilled = true;
        for (int goal = 0; goal < FROG_GOALS; goal++) {
          if (!frogGoalFilled[goal]) {
            allFilled = false;
            break;
          }
        }

        if (allFilled) {
          frogLevel++;

          for (int goal = 0; goal < FROG_GOALS; goal++) {
            frogGoalFilled[goal] = false;
          }

          initFroggerLanes();
          resetFroggerNetworkPlayers();
          frogNetSceneReady = false;
          drawFroggerFullScene();
        } else {
          drawFroggerGoalSlots();
          redrawFroggerNetworkPlayersOnly();
        }
      }

      continue;
    }

    if (type == FROG_PKT_OVER && len >= (int)sizeof(FrogEspNowOverPacket)) {
      FrogEspNowOverPacket *packet = (FrogEspNowOverPacket *)buffer;

      frogNetScore[0] = packet->score0;
      frogNetScore[1] = packet->score1;
      frogNetWinner = packet->winner;
      frogNetGameOver = true;
      myTurn = false;

      if (appState == STATE_FROGGER_PLAYING) {
        drawFroggerFullScene();
        drawFroggerGameOverOverlay();
      }

      continue;
    }
  }
}

void updateFroggerEspNowNetwork() {
  if (activeNetworkGame != NETWORK_GAME_FROGGER || !frogEspReady) return;

  processFroggerEspNow();

  if (appState != STATE_WAITING_HOST && appState != STATE_CONNECTING_JOIN) return;

  unsigned long now = millis();
  unsigned long helloInterval = isHost ? 500UL : 600UL;

  if (now - frogEspLastHelloTime >= helloInterval) {
    frogEspLastHelloTime = now;
    sendFroggerEspNowHello();
  }
}

void startFroggerLocalGame() {
  activeNetworkGame = NETWORK_GAME_FROGGER;
  stopNetwork();
  localGame = true;
  appState = STATE_FROGGER_PLAYING;
  initFroggerLayout();
  resetFroggerGame();
  playPriorityTone(900, 60);
  drawFroggerFullScene();
  frogLastFrame = millis();
}

void startFroggerNetworkGame() {
  activeNetworkGame = NETWORK_GAME_FROGGER;
  localGame = false;
  myTurn = true;
  beepStart();

  if (isHost) {
    myPlayer = '1';
    frogLevel = 1;
    newFroggerNetworkGame();
    sendFroggerState(true);
    return;
  }

  myPlayer = '2';
  frogLevel = 1;
  frogNetScore[0] = 0;
  frogNetScore[1] = 0;
  frogNetLives[0] = 3;
  frogNetLives[1] = 3;
  frogNetGameOver = false;
  frogNetWinner = 0;
  frogNetInputSeq[0] = 0;
  frogNetInputSeq[1] = 0;
  frogLocalInputSeq = 0;

  for (int goal = 0; goal < FROG_GOALS; goal++) {
    frogGoalFilled[goal] = false;
  }

  initFroggerLayout();
  initFroggerLanes();
  resetFroggerNetworkPlayers();
  frogNetSceneReady = false;
  appState = STATE_FROGGER_PLAYING;
  drawFroggerFullScene();
  drawCenteredText("Waiting host", 184, 2, RGB565_YELLOW);
  frogNetSceneReady = false;
}

void drawFroggerEspNowWaitingScreen() {
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText(isHost ? "FROG HOST" : "FROG JOIN", 54, 3, isHost ? RGB565_GREEN : RGB565_BLUE);
  drawCenteredText(isHost ? "Player 1" : "Player 2", 105, 2, RGB565_WHITE);
  drawCenteredText("ESP-NOW", 165, 3, RGB565_CYAN);
  drawCenteredText("Waiting peer...", 220, 2, RGB565_YELLOW);
  drawCenteredText("No router needed", 252, 1, RGB565_WHITE);

  if (!frogEspReady) {
    drawCenteredText("ESP-NOW ERROR", 300, 2, RGB565_RED);
  }

  drawButton(btnMenuX, btnMenuY, btnMenuW, btnMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENU", 2);
}

void startFroggerHostEspNowMode() {
  stopNetwork();

  activeNetworkGame = NETWORK_GAME_FROGGER;
  localGame = false;
  isHost = true;
  myPlayer = '1';
  myTurn = true;
  networkConnected = false;
  frogLevel = 1;

  initFroggerLayout();
  initFroggerEspNow();

  appState = STATE_WAITING_HOST;
  beepStart();
  drawFroggerEspNowWaitingScreen();
}

void startFroggerJoinEspNowMode() {
  stopNetwork();

  activeNetworkGame = NETWORK_GAME_FROGGER;
  localGame = false;
  isHost = false;
  myPlayer = '2';
  myTurn = true;
  networkConnected = false;
  frogLevel = 1;

  initFroggerLayout();
  initFroggerEspNow();

  appState = STATE_CONNECTING_JOIN;
  beepStart();
  drawFroggerEspNowWaitingScreen();
}

void drawPocketTanksMenuScreen() {
  activeNetworkGame = NETWORK_GAME_PT;
  localGame = false;
  appState = STATE_POCKET_TANKS;
  drawTanksWarsArcadeHome();

  drawTransparentArcadeButton(btnLocalX, btnLocalY, btnLocalW, btnLocalH, "LOCAL", 2);

  drawTransparentArcadeButton(btnHostX, btnHostY, btnHostW, btnHostH, "HOST", 2);

  drawTransparentArcadeButton(btnJoinX, btnJoinY, btnJoinW, btnJoinH, "JOIN", 2);

  drawTransparentArcadeButton(btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH, "RESET SCORE", 2);

  drawTransparentArcadeButton(btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH, "BACK", 2);

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "SCORE  P1:%d  P2:%d", ptScoreP1, ptScoreP2);
  drawGameMenuScoreAndHigh(scoreLine, highestOfTwo(ptScoreP1, ptScoreP2));
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
  drawCenteredText("Use HOST or JOIN", 140, 2, RGB565_YELLOW);
  drawCenteredText("from the menu", 168, 2, RGB565_YELLOW);

  drawButton(btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
}

void drawWaitingHostScreen() {
  bool rpsNetworkGame = (activeNetworkGame == NETWORK_GAME_RPS);
  bool tanksNetworkGame = (activeNetworkGame == NETWORK_GAME_PT);
  bool breakoutNetworkGame = (activeNetworkGame == NETWORK_GAME_BREAKOUT);
  bool pongNetworkGame = (activeNetworkGame == NETWORK_GAME_PONG);
  bool snakeNetworkGame = (activeNetworkGame == NETWORK_GAME_SNAKE);
  bool ranchNetworkGame = (activeNetworkGame == NETWORK_GAME_RANCH_RUSH);
  bool froggerNetworkGame = (activeNetworkGame == NETWORK_GAME_FROGGER);

  gfx->fillScreen(RGB565_BLACK);

  if (pongNetworkGame) {
    drawCenteredText("PONG HOST", 28, 3, RGB565_GREEN);
  } else if (snakeNetworkGame) {
    drawCenteredText("SNAKE HOST", 28, 3, RGB565_GREEN);
  } else if (ranchNetworkGame) {
    drawCenteredText("RANCH HOST", 28, 3, RGB565_GREEN);
  } else if (froggerNetworkGame) {
    drawCenteredText("FROG HOST", 28, 3, RGB565_GREEN);
  } else if (breakoutNetworkGame) {
    drawCenteredText("BREAKOUT HOST", 28, 2, RGB565_GREEN);
  } else if (tanksNetworkGame) {
    drawCenteredText("TANKS HOST", 28, 3, RGB565_GREEN);
  } else {
    drawCenteredText(rpsNetworkGame ? "RPS HOST" : "HOST ACTIVE", 28, 3, RGB565_GREEN);
  }

  drawCenteredText((rpsNetworkGame || tanksNetworkGame || breakoutNetworkGame || pongNetworkGame || snakeNetworkGame || ranchNetworkGame || froggerNetworkGame) ? "You are P1" : "You are X", 72, 2, RGB565_WHITE);

  drawCenteredText("Waiting opponent", 118, 2, RGB565_YELLOW);
  drawCenteredText("to join", 145, 2, RGB565_YELLOW);

  drawCenteredText("WiFi:", 195, 2, RGB565_WHITE);
  drawCenteredText(epicSSIDList[selectedHostSSIDIndex], 222, 2, RGB565_CYAN);

  char ipLine[32];
  snprintf(ipLine, sizeof(ipLine), "%u.%u.%u.%u",
           ipParts[0], ipParts[1], ipParts[2], ipParts[3]);
  drawCenteredText("IP:", 270, 2, RGB565_WHITE);
  drawCenteredText(ipLine, 297, 2, RGB565_CYAN);

  drawButton(btnMenuX, btnMenuY, btnMenuW, btnMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENU", 2);
}

void drawConnectingJoinScreen() {
  bool rpsNetworkGame = (activeNetworkGame == NETWORK_GAME_RPS);
  bool tanksNetworkGame = (activeNetworkGame == NETWORK_GAME_PT);
  bool breakoutNetworkGame = (activeNetworkGame == NETWORK_GAME_BREAKOUT);
  bool pongNetworkGame = (activeNetworkGame == NETWORK_GAME_PONG);
  bool snakeNetworkGame = (activeNetworkGame == NETWORK_GAME_SNAKE);
  bool ranchNetworkGame = (activeNetworkGame == NETWORK_GAME_RANCH_RUSH);
  bool froggerNetworkGame = (activeNetworkGame == NETWORK_GAME_FROGGER);

  gfx->fillScreen(RGB565_BLACK);

  if (pongNetworkGame) {
    drawCenteredText("PONG JOIN", 70, 3, RGB565_BLUE);
  } else if (snakeNetworkGame) {
    drawCenteredText("SNAKE JOIN", 70, 3, RGB565_BLUE);
  } else if (ranchNetworkGame) {
    drawCenteredText("RANCH JOIN", 70, 3, RGB565_BLUE);
  } else if (froggerNetworkGame) {
    drawCenteredText("FROG JOIN", 70, 3, RGB565_BLUE);
  } else if (breakoutNetworkGame) {
    drawCenteredText("BREAKOUT JOIN", 70, 2, RGB565_BLUE);
  } else if (tanksNetworkGame) {
    drawCenteredText("TANKS JOIN", 70, 3, RGB565_BLUE);
  } else {
    drawCenteredText(rpsNetworkGame ? "RPS JOIN" : "JOIN", 70, 3, RGB565_BLUE);
  }

  drawCenteredText((rpsNetworkGame || tanksNetworkGame || breakoutNetworkGame || pongNetworkGame || snakeNetworkGame || ranchNetworkGame || froggerNetworkGame) ? "You are P2" : "You are O", 120, 2, RGB565_WHITE);

  drawCenteredText("Connecting...", 190, 2, RGB565_YELLOW);

  if (selectedJoinNetwork >= 0 && selectedJoinNetwork < joinNetworkCount) {
    drawCenteredText(joinNetworks[selectedJoinNetwork].c_str(), 225, 1, RGB565_CYAN);
  }

  char ipLine[32];
  snprintf(ipLine, sizeof(ipLine), "%u.%u.%u.%u",
           ipParts[0], ipParts[1], ipParts[2], ipParts[3]);
  drawCenteredText(ipLine, 255, 2, RGB565_WHITE);

  drawButton(btnMenuX, btnMenuY, btnMenuW, btnMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENU", 2);
}

void drawGameScreenFull() {
  gfx->fillScreen(RGB565_BLACK);
  drawScoreBar();
  drawGrid();
  drawAllMarks();

  drawButton(btnMenuX, btnMenuY, btnMenuW, btnMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENU", 2);
}

void drawResultScreen() {
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("RESULT", 30, 3, RGB565_WHITE);

  if (winner == 'X') {
    drawCenteredText("X wins!", 110, 3, RGB565_RED);
  } else if (winner == 'O') {
    drawCenteredText("O wins!", 110, 3, RGB565_CYAN);
  } else {
    drawCenteredText("Draw!", 110, 3, RGB565_YELLOW);
  }

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "X:%d   O:%d   D:%d", scoreX, scoreO, scoreDraw);
  drawCenteredText(scoreLine, 210, 2, RGB565_WHITE);

  drawButton(btnPlayAgainX, btnPlayAgainY, btnPlayAgainW, btnPlayAgainH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "PLAY AGAIN", 2);

  drawButton(btnResultMenuX, btnResultMenuY, btnResultMenuW, btnResultMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK TO MENU", 2);
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
  drawCenteredText("Choose category", 78, 2, RGB565_YELLOW);

  drawButton(btnSettingsMusicX, btnSettingsMusicY, btnSettingsMusicW, btnSettingsMusicH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MUSIC", 2);
  drawButton(btnSettingsWifiX, btnSettingsWifiY, btnSettingsWifiW, btnSettingsWifiH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "WiFi", 2);

  drawButton(btnSettingsHomeX, btnSettingsHomeY, btnSettingsHomeW, btnSettingsHomeH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "HOME", 2);
}

void drawMusicSettingsScreen() {
  appState = STATE_SETTINGS_MUSIC;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("MUSIC", 30, 3, RGB565_CYAN);
  drawCenteredText("Audio options", 76, 2, RGB565_YELLOW);

  drawButton(btnMusicToggleX, btnMusicToggleY, btnMusicToggleW, btnMusicToggleH,
             musicEnabled ? RGB565_GREEN : RGB565_RED,
             RGB565_WHITE,
             musicEnabled ? RGB565_BLACK : RGB565_WHITE,
             musicEnabled ? "MUSIC ON" : "MUSIC OFF",
             2);

  drawButton(btnSfxToggleX, btnSfxToggleY, btnSfxToggleW, btnSfxToggleH,
             sfxEnabled ? RGB565_GREEN : RGB565_RED,
             RGB565_WHITE,
             sfxEnabled ? RGB565_BLACK : RGB565_WHITE,
             sfxEnabled ? "SFX ON" : "SFX OFF",
             2);

  drawButton(btnSettingsHomeX, btnSettingsHomeY, btnSettingsHomeW, btnSettingsHomeH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
}

void drawSettingsWifiSelector() {
  gfx->fillRect(0, btnWifiSsidY - 2, screenW, btnWifiSsidH + 4, RGB565_BLACK);

  drawButton(btnWifiPrevX, btnWifiSsidY, btnWifiPrevW, btnWifiSsidH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "PREV", 1);

  char ssidLabel[26];
  snprintf(ssidLabel, sizeof(ssidLabel), "%d %s", selectedHostSSIDIndex + 1, epicSSIDList[selectedHostSSIDIndex]);
  drawButton(btnWifiSsidX, btnWifiSsidY, btnWifiSsidW, btnWifiSsidH,
             RGB565_BLACK, RGB565_CYAN, RGB565_WHITE, ssidLabel, 1);

  drawButton(btnWifiNextX, btnWifiSsidY, btnWifiNextW, btnWifiSsidH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "NEXT", 1);
}

void drawWifiSettingsScreen() {
  appState = STATE_SETTINGS_WIFI;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("WiFi", 18, 3, RGB565_CYAN);
  drawCenteredText("Default Network", 42, 1, RGB565_YELLOW);
  drawSettingsWifiSelector();

  drawCenteredText("HOST IP", 78, 1, RGB565_YELLOW);
  drawIpFields();
  drawSettingsKeypad();

  drawButton(btnSettingsHomeX, btnSettingsHomeY, btnSettingsHomeW, btnSettingsHomeH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BACK", 2);
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
void startPocketTanksNetworkGame();
void startBreakoutNetworkGame();
void startPongNetworkGame();
void startSnakeNetworkGame();
void startRanchRushNetworkGame();
void startFroggerNetworkGame();

// ============================================================================
// NETWORK
// ============================================================================
// Shared WiFi setup and message helpers for network-capable games.
const char *getNetworkGameCode() {
  if (activeNetworkGame == NETWORK_GAME_RPS) return "RPS";
  if (activeNetworkGame == NETWORK_GAME_PT) return "PT";
  if (activeNetworkGame == NETWORK_GAME_BREAKOUT) return "BRK";
  if (activeNetworkGame == NETWORK_GAME_PONG) return "PONG";
  if (activeNetworkGame == NETWORK_GAME_SNAKE) return "SNK";
  if (activeNetworkGame == NETWORK_GAME_RANCH_RUSH) return "RANCH";
  if (activeNetworkGame == NETWORK_GAME_FROGGER) return "FROG";
  return "TTT";
}

void applyNetworkGameCode(const String &code) {
  String gameCode = code;
  int separator = gameCode.indexOf(':');

  if (separator >= 0) {
    gameCode = gameCode.substring(0, separator);
  }

  if (gameCode == "RPS") {
    activeNetworkGame = NETWORK_GAME_RPS;
  } else if (gameCode == "PT") {
    activeNetworkGame = NETWORK_GAME_PT;

    if (separator >= 0) {
      unsigned long receivedSeed = (unsigned long)code.substring(separator + 1).toInt();

      if (receivedSeed > 0) {
        ptNetworkSeed = receivedSeed;
      }
    }
  } else if (gameCode == "BRK") {
    activeNetworkGame = NETWORK_GAME_BREAKOUT;
  } else if (gameCode == "PONG") {
    activeNetworkGame = NETWORK_GAME_PONG;
  } else if (gameCode == "SNK") {
    activeNetworkGame = NETWORK_GAME_SNAKE;
  } else if (gameCode == "RANCH") {
    activeNetworkGame = NETWORK_GAME_RANCH_RUSH;
  } else if (gameCode == "FROG") {
    activeNetworkGame = NETWORK_GAME_FROGGER;
  } else if (gameCode == "TTT") {
    activeNetworkGame = NETWORK_GAME_TTT;
  }
}

void preparePocketTanksNetworkSeed() {
  ptNetworkSeed = (unsigned long)random(1, 2000000000L);

  if (ptNetworkSeed == 0) {
    ptNetworkSeed = 1;
  }
}

String buildNetworkMessage(const char *prefix) {
  String msg = prefix;
  msg += ":";
  msg += getNetworkGameCode();

  if (activeNetworkGame == NETWORK_GAME_PT &&
      (strcmp(prefix, "START") == 0 || strcmp(prefix, "NEW") == 0)) {
    if (ptNetworkSeed == 0) {
      preparePocketTanksNetworkSeed();
    }

    msg += ":";
    msg += String(ptNetworkSeed);
  }

  return msg;
}

void sendNetMessage(const String &msg) {
  if (networkConnected && netClient && netClient.connected()) {
    netClient.println(msg);
  }
}

void stopNetwork() {
  stopFroggerEspNow();

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
  myPlayer = (activeNetworkGame == NETWORK_GAME_TTT) ? 'O' : '2';
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
  myPlayer = (activeNetworkGame == NETWORK_GAME_TTT) ? 'X' : '1';
  myTurn = (activeNetworkGame == NETWORK_GAME_TTT ||
            activeNetworkGame == NETWORK_GAME_PT ||
            activeNetworkGame == NETWORK_GAME_BREAKOUT ||
            activeNetworkGame == NETWORK_GAME_PONG ||
            activeNetworkGame == NETWORK_GAME_SNAKE ||
            activeNetworkGame == NETWORK_GAME_RANCH_RUSH ||
            activeNetworkGame == NETWORK_GAME_FROGGER);

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

  if (activeNetworkGame == NETWORK_GAME_PT) {
    startPocketTanksNetworkGame();
    return;
  }

  if (activeNetworkGame == NETWORK_GAME_BREAKOUT) {
    startBreakoutNetworkGame();
    return;
  }

  if (activeNetworkGame == NETWORK_GAME_PONG) {
    startPongNetworkGame();
    return;
  }

  if (activeNetworkGame == NETWORK_GAME_SNAKE) {
    startSnakeNetworkGame();
    return;
  }

  if (activeNetworkGame == NETWORK_GAME_RANCH_RUSH) {
    startRanchRushNetworkGame();
    return;
  }

  if (activeNetworkGame == NETWORK_GAME_FROGGER) {
    startFroggerNetworkGame();
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

    if (activeNetworkGame == NETWORK_GAME_PT) {
      preparePocketTanksNetworkSeed();
    }

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

void updatePocketTanksNetworkTurn() {
  if (activeNetworkGame != NETWORK_GAME_PT || localGame) {
    myTurn = true;
    return;
  }

  myTurn = (myPlayer == '1' && ptCurrentPlayer == 0) ||
           (myPlayer == '2' && ptCurrentPlayer == 1);
}

void sendPocketTanksControlMessage(const char *type, int playerIndex, int value) {
  if (localGame || !networkConnected) return;

  String msg = "PT_";
  msg += type;
  msg += ":";
  msg += String(playerIndex);
  msg += ",";
  msg += String(value);
  sendNetMessage(msg);
}

void setPocketTanksAngleForPlayer(int playerIndex, int value, bool redraw) {
  if (playerIndex < 0 || playerIndex > 1) return;

  if (value < 5) value = 5;
  if (value > 85) value = 85;

  int oldAngle = ptAngle[playerIndex];
  ptAngle[playerIndex] = value;

  if (redraw && appState == STATE_PT_PLAYING) {
    redrawPocketTanksTankArea(playerIndex, oldAngle, ptAngle[playerIndex]);
    drawPocketTanksControls();
  }
}

void setPocketTanksPowerForPlayer(int playerIndex, int value, bool redraw) {
  if (playerIndex < 0 || playerIndex > 1) return;

  if (value < 20) value = 20;
  if (value > 100) value = 100;

  ptPower[playerIndex] = value;

  if (redraw && appState == STATE_PT_PLAYING) {
    drawPocketTanksControls();
  }
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
  updatePocketTanksNetworkTurn();
}

void resetPocketTanksRoundWithSeed(unsigned long seed) {
  if (seed == 0) {
    seed = 1;
  }

  ptNetworkSeed = seed;
  randomSeed(ptNetworkSeed);
  resetPocketTanksRound();
}

void startPocketTanksLocalGame() {
  activeNetworkGame = NETWORK_GAME_PT;
  stopNetwork();
  localGame = true;
  resetPocketTanksRound();
  beepStart();
  drawPocketTanksGameScreen();
}

void startPocketTanksNetworkGame() {
  activeNetworkGame = NETWORK_GAME_PT;
  localGame = false;

  if (ptNetworkSeed == 0) {
    preparePocketTanksNetworkSeed();
  }

  resetPocketTanksRoundWithSeed(ptNetworkSeed);
  beepStart();
  drawPocketTanksGameScreen();
}

void switchPocketTanksTurn() {
  // A missed shot or terrain hit passes control to the other player.
  ptCurrentPlayer = 1 - ptCurrentPlayer;
  updatePocketTanksNetworkTurn();
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
  playPriorityTone(900, 120);
  drawPocketTanksScene(-1, -1, true, x, y);
  delay(300);
}

void finishPocketTanksGame(int winnerIndex) {
  ptWinner = winnerIndex + 1;
  myTurn = false;

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
  int playerIndex = ptCurrentPlayer;
  int oldAngle = ptAngle[playerIndex];

  setPocketTanksAngleForPlayer(playerIndex, ptAngle[playerIndex] + delta, true);

  if (ptAngle[playerIndex] != oldAngle) {
    sendPocketTanksControlMessage("ANGLE", playerIndex, ptAngle[playerIndex]);
  }
}

void adjustPocketTanksPower(int delta) {
  int playerIndex = ptCurrentPlayer;
  int oldPower = ptPower[playerIndex];

  setPocketTanksPowerForPlayer(playerIndex, ptPower[playerIndex] + delta, true);

  if (ptPower[playerIndex] != oldPower) {
    sendPocketTanksControlMessage("POWER", playerIndex, ptPower[playerIndex]);
  }
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

void sendPocketTanksFireMessage() {
  if (localGame || !networkConnected) return;

  String msg = "PT_FIRE:";
  msg += String(ptCurrentPlayer);
  msg += ",";
  msg += String(ptAngle[ptCurrentPlayer]);
  msg += ",";
  msg += String(ptPower[ptCurrentPlayer]);
  sendNetMessage(msg);
}

void applyRemotePocketTanksAngle(int playerIndex, int value) {
  activeNetworkGame = NETWORK_GAME_PT;
  setPocketTanksAngleForPlayer(playerIndex, value, true);
}

void applyRemotePocketTanksPower(int playerIndex, int value) {
  activeNetworkGame = NETWORK_GAME_PT;
  setPocketTanksPowerForPlayer(playerIndex, value, true);
}

void applyRemotePocketTanksFire(int shooter, int angle, int power) {
  if (shooter < 0 || shooter > 1) return;

  activeNetworkGame = NETWORK_GAME_PT;
  ptCurrentPlayer = shooter;
  setPocketTanksAngleForPlayer(shooter, angle, false);
  setPocketTanksPowerForPlayer(shooter, power, false);
  updatePocketTanksNetworkTurn();
  firePocketTanksShot();
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
    if (activeNetworkGame == NETWORK_GAME_FROGGER) {
      if (!frogNetGameOver) {
        frogNetWinner = (froggerLocalNetworkPlayerIndex() == 0) ? 2 : 1;
        frogNetGameOver = true;
      }
      sendFroggerGameOver();
    }
    sendNetMessage("LEAVE");
  }

  localGame = false;
  stopNetwork();

  if (activeNetworkGame == NETWORK_GAME_RPS) {
    drawRpsMenuScreen();
  } else if (activeNetworkGame == NETWORK_GAME_PT) {
    drawPocketTanksMenuScreen();
  } else if (activeNetworkGame == NETWORK_GAME_BREAKOUT) {
    drawBreakoutMenuScreen();
  } else if (activeNetworkGame == NETWORK_GAME_PONG) {
    drawPongMenuScreen();
  } else if (activeNetworkGame == NETWORK_GAME_SNAKE) {
    drawSnakeMenuScreen();
  } else if (activeNetworkGame == NETWORK_GAME_RANCH_RUSH) {
    drawRanchRushMenuScreen();
  } else if (activeNetworkGame == NETWORK_GAME_FROGGER) {
    drawFroggerMenuScreen();
  } else {
    appState = STATE_MENU;
    drawMenuScreen();
  }
}

void returnToHome(bool notifyPeer) {
  if (notifyPeer && !localGame) {
    if (activeNetworkGame == NETWORK_GAME_FROGGER) {
      if (!frogNetGameOver) {
        frogNetWinner = (froggerLocalNetworkPlayerIndex() == 0) ? 2 : 1;
        frogNetGameOver = true;
      }
      sendFroggerGameOver();
    }
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
// START:<game>, NEW:<game>, MOVE:col,row, RPS_CHOICE:n, PT_* messages,
// PN_* messages, SN_* messages, RR_* messages, FROG_* messages, BR_LOSE,
// LEAVE.
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

  if (msg == "BR_LOSE") {
    activeNetworkGame = NETWORK_GAME_BREAKOUT;
    applyRemoteBreakoutLoss();
    return;
  }

  if (msg.startsWith("PN_PAD:")) {
    activeNetworkGame = NETWORK_GAME_PONG;
    applyRemotePongPaddle(msg.substring(7).toInt());
    return;
  }

  if (msg.startsWith("PN_STATE:")) {
    activeNetworkGame = NETWORK_GAME_PONG;
    applyRemotePongState(msg.substring(9));
    return;
  }

  if (msg.startsWith("SN_DIR:")) {
    activeNetworkGame = NETWORK_GAME_SNAKE;

    if (isHost) {
      setSnakeNetworkDirection(1, msg.substring(7).toInt());
    }

    return;
  }

  if (msg.startsWith("SN_STATE:")) {
    activeNetworkGame = NETWORK_GAME_SNAKE;

    if (!isHost) {
      applyRemoteSnakeState(msg.substring(9));
    }

    return;
  }

  if (msg.startsWith("RR_INPUT:")) {
    activeNetworkGame = NETWORK_GAME_RANCH_RUSH;

    if (isHost) {
      int comma = msg.indexOf(',');

      if (comma > 9) {
        int playerIndex = msg.substring(9, comma).toInt();
        int action = msg.substring(comma + 1).toInt();
        applyRanchRushNetworkInput(playerIndex, action, false);
        sendRanchRushState(true);
      }
    }

    return;
  }

  if (msg.startsWith("RR_STATE:")) {
    activeNetworkGame = NETWORK_GAME_RANCH_RUSH;

    if (!isHost) {
      applyRemoteRanchRushState(msg.substring(9));
    }

    return;
  }

  if (msg.startsWith("FROG_INPUT:")) {
    activeNetworkGame = NETWORK_GAME_FROGGER;

    if (isHost) {
      int comma = msg.indexOf(',');
      int secondComma = msg.indexOf(',', comma + 1);

      if (comma > 11) {
        int playerIndex = msg.substring(11, comma).toInt();
        int action = (secondComma > comma) ? msg.substring(comma + 1, secondComma).toInt()
                                           : msg.substring(comma + 1).toInt();
        int seqValue = (secondComma > comma) ? msg.substring(secondComma + 1).toInt()
                                             : (frogNetInputSeq[constrain(playerIndex, 0, 1)] + 1);

        if (playerIndex >= 0 && playerIndex <= 1 && seqValue > frogNetInputSeq[playerIndex]) {
          frogNetInputSeq[playerIndex] = seqValue;
        }

        applyFroggerNetworkInput(playerIndex, action, false);
        checkFroggerNetworkPlayerCollisions(playerIndex);
        redrawFroggerNetworkPlayersOnly();
        sendFroggerState(true);
      }
    }

    return;
  }

  if (msg.startsWith("FROG_STATE:")) {
    activeNetworkGame = NETWORK_GAME_FROGGER;
    applyRemoteFroggerState(msg.substring(11));
    return;
  }

  if (msg.startsWith("FROG_GOAL:")) {
    activeNetworkGame = NETWORK_GAME_FROGGER;
    int comma = msg.indexOf(',', 10);
    if (comma > 10) {
      int slot = msg.substring(10, comma).toInt();
      int player = msg.substring(comma + 1).toInt();
      if (slot >= 0 && slot < FROG_GOALS && !frogGoalFilled[slot]) {
        frogGoalFilled[slot] = true;
        bool allFilled = true;
        for (int g = 0; g < FROG_GOALS; g++) {
          if (!frogGoalFilled[g]) { allFilled = false; break; }
        }
        if (allFilled) {
          frogLevel++;
          for (int g = 0; g < FROG_GOALS; g++) frogGoalFilled[g] = false;
          initFroggerLanes();
          resetFroggerNetworkPlayers();
          frogNetSceneReady = false;
          drawFroggerFullScene();
        } else {
          drawFroggerGoalSlots();
          redrawFroggerNetworkPlayersOnly();
        }
      }
    }
    return;
  }

  if (msg.startsWith("FROG_OVER:")) {
    activeNetworkGame = NETWORK_GAME_FROGGER;
    int c1 = msg.indexOf(',', 10);
    int c2 = (c1 > 10) ? msg.indexOf(',', c1 + 1) : -1;
    if (c1 > 10 && c2 > c1) {
      frogNetWinner = msg.substring(10, c1).toInt();
      frogNetScore[0] = msg.substring(c1 + 1, c2).toInt();
      frogNetScore[1] = msg.substring(c2 + 1).toInt();
      frogNetGameOver = true;
      myTurn = false;
      if (appState == STATE_FROGGER_PLAYING) {
        drawFroggerFullScene();
        drawFroggerGameOverOverlay();
      }
    }
    return;
  }

  if (msg.startsWith("PT_ANGLE:")) {
    int comma = msg.indexOf(',');

    if (comma > 9) {
      int playerIndex = msg.substring(9, comma).toInt();
      int value = msg.substring(comma + 1).toInt();
      applyRemotePocketTanksAngle(playerIndex, value);
    }

    return;
  }

  if (msg.startsWith("PT_POWER:")) {
    int comma = msg.indexOf(',');

    if (comma > 9) {
      int playerIndex = msg.substring(9, comma).toInt();
      int value = msg.substring(comma + 1).toInt();
      applyRemotePocketTanksPower(playerIndex, value);
    }

    return;
  }

  if (msg.startsWith("PT_FIRE:")) {
    int firstComma = msg.indexOf(',');
    int secondComma = msg.indexOf(',', firstComma + 1);

    if (firstComma > 8 && secondComma > firstComma) {
      int shooter = msg.substring(8, firstComma).toInt();
      int angle = msg.substring(firstComma + 1, secondComma).toInt();
      int power = msg.substring(secondComma + 1).toInt();
      applyRemotePocketTanksFire(shooter, angle, power);
    }

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
        appState == STATE_RPS_WAITING_CHOICE || appState == STATE_RPS_RESULT ||
        appState == STATE_PT_PLAYING || appState == STATE_PT_RESULT ||
        appState == STATE_BREAKOUT_PLAYING ||
        appState == STATE_PONG_PLAYING ||
        appState == STATE_SNAKE_PLAYING ||
        appState == STATE_SNAKE_PLACEHOLDER ||
        appState == STATE_RR_PLAYING ||
        appState == STATE_RR_PLACEHOLDER ||
        appState == STATE_FROGGER_PLAYING ||
        appState == STATE_FROGGER_PLACEHOLDER) {
      gfx->fillScreen(RGB565_BLACK);
      drawCenteredText("Connection lost", 180, 2, RGB565_RED);
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

  if (inRect(x, y, btnGamesNavLeftX, btnGamesHomeY, btnGamesNavW, btnGamesHomeH)) {
    beepClick();
    returnToHome(false);
    return;
  }

  if (inRect(x, y, btnGamesNavRightX, btnGamesHomeY, btnGamesNavW, btnGamesHomeH)) {
    beepClick();
    drawGamesMoreScreen();
    return;
  }
}

void handleGamesMoreTouch(int x, int y) {
  if (inRect(x, y, btnGamesX, btnGamesSnakeY, btnGamesW, btnGamesH)) {
    beepClick();
    drawSnakeMenuScreen();
    return;
  }

  if (inRect(x, y, btnGamesX, btnGamesBreakoutY, btnGamesW, btnGamesH)) {
    beepClick();
    drawBreakoutMenuScreen();
    return;
  }

  if (inRect(x, y, btnGamesX, btnGamesPongY, btnGamesW, btnGamesH)) {
    beepClick();
    drawPongMenuScreen();
    return;
  }

  if (inRect(x, y, btnGamesX, btnGamesRanchRushY, btnGamesW, btnGamesH)) {
    beepClick();
    drawRanchRushMenuScreen();
    return;
  }

  if (inRect(x, y, btnGamesNavLeftX, btnGamesHomeY, btnGamesNavW, btnGamesHomeH)) {
    beepClick();
    drawGamesScreen();
    return;
  }

  if (inRect(x, y, btnGamesNavRightX, btnGamesHomeY, btnGamesNavW, btnGamesHomeH)) {
    beepClick();
    drawGamesExtraScreen();
    return;
  }
}

void handleGamesExtraTouch(int x, int y) {
  if (inRect(x, y, btnGamesX, btnGamesRpsY, btnGamesW, btnGamesH)) {
    beepClick();
    drawFroggerMenuScreen();
    return;
  }

  if (inRect(x, y, btnGamesNavLeftX, btnGamesHomeY, btnGamesNavW, btnGamesHomeH)) {
    beepClick();
    drawGamesMoreScreen();
    return;
  }

  if (inRect(x, y, btnGamesNavRightX, btnGamesHomeY, btnGamesNavW, btnGamesHomeH)) {
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
    beepStart();
    activeNetworkGame = NETWORK_GAME_PT;
    startHostMode();
    return;
  }

  if (inRect(x, y, btnJoinX, btnJoinY, btnJoinW, btnJoinH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_PT;
    startJoinMode();
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

void handleBreakoutMenuTouch(int x, int y) {
  if (inRect(x, y, btnLocalX, btnLocalY, btnLocalW, btnLocalH)) {
    startBreakoutLocalGame();
    return;
  }

  if (inRect(x, y, btnHostX, btnHostY, btnHostW, btnHostH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_BREAKOUT;
    startHostMode();
    return;
  }

  if (inRect(x, y, btnJoinX, btnJoinY, btnJoinW, btnJoinH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_BREAKOUT;
    startJoinMode();
    return;
  }

  if (inRect(x, y, btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH)) {
    beepClick();
    resetBreakoutScore();
    drawBreakoutMenuScreen();
    return;
  }

  if (inRect(x, y, btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH)) {
    beepClick();
    drawGamesMoreScreen();
    return;
  }
}

void handleBreakoutPlaceholderTouch(int x, int y) {
  if (inRect(x, y, btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH)) {
    beepClick();
    drawBreakoutMenuScreen();
    return;
  }
}

void handleBreakoutPlayingTouch(int x, int y) {
  if (inRect(x, y, btnBreakoutMenuX, btnBreakoutMenuY, btnBreakoutMenuW, btnBreakoutMenuH)) {
    beepClick();
    if (localGame) {
      drawBreakoutMenuScreen();
    } else {
      returnToMenu(true);
    }
    return;
  }

  if (breakoutGameOver) {
    if (localGame) {
      newBreakoutGame();
    } else {
      sendNetMessage(buildNetworkMessage("NEW"));
      startNetworkGame();
    }
    return;
  }
}

void handlePongMenuTouch(int x, int y) {
  if (inRect(x, y, btnLocalX, btnLocalY, btnLocalW, btnLocalH)) {
    startPongLocalGame();
    return;
  }

  if (inRect(x, y, btnHostX, btnHostY, btnHostW, btnHostH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_PONG;
    startHostMode();
    return;
  }

  if (inRect(x, y, btnJoinX, btnJoinY, btnJoinW, btnJoinH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_PONG;
    startJoinMode();
    return;
  }

  if (inRect(x, y, btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH)) {
    beepClick();
    resetPongScore();
    drawPongMenuScreen();
    return;
  }

  if (inRect(x, y, btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH)) {
    beepClick();
    drawGamesMoreScreen();
    return;
  }
}

void handlePongPlaceholderTouch(int x, int y) {
  if (inRect(x, y, btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH)) {
    beepClick();
    drawPongMenuScreen();
    return;
  }
}

void handleSnakeMenuTouch(int x, int y) {
  if (inRect(x, y, btnLocalX, btnLocalY, btnLocalW, btnLocalH)) {
    startSnakeLocalGame();
    return;
  }

  if (inRect(x, y, btnHostX, btnHostY, btnHostW, btnHostH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_SNAKE;
    startHostMode();
    return;
  }

  if (inRect(x, y, btnJoinX, btnJoinY, btnJoinW, btnJoinH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_SNAKE;
    startJoinMode();
    return;
  }

  if (inRect(x, y, btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH)) {
    beepClick();
    resetSnakeScore();
    drawSnakeMenuScreen();
    return;
  }

  if (inRect(x, y, btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH)) {
    beepClick();
    drawGamesMoreScreen();
    return;
  }
}

void handleSnakePlaceholderTouch(int x, int y) {
  if (inRect(x, y, btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH)) {
    beepClick();

    if (localGame) {
      drawSnakeMenuScreen();
    } else {
      returnToMenu(true);
    }

    return;
  }
}

void handleRanchRushMenuTouch(int x, int y) {
  if (inRect(x, y, btnLocalX, btnLocalY, btnLocalW, btnLocalH)) {
    startRanchRushLocalGame();
    return;
  }

  if (inRect(x, y, btnHostX, btnHostY, btnHostW, btnHostH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_RANCH_RUSH;
    startHostMode();
    return;
  }

  if (inRect(x, y, btnJoinX, btnJoinY, btnJoinW, btnJoinH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_RANCH_RUSH;
    startJoinMode();
    return;
  }

  if (inRect(x, y, btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH)) {
    beepClick();
    resetRanchRushScore();
    drawRanchRushMenuScreen();
    return;
  }

  if (inRect(x, y, btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH)) {
    beepClick();
    drawGamesMoreScreen();
    return;
  }
}

void handleRanchRushPlaceholderTouch(int x, int y) {
  if (inRect(x, y, btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH)) {
    beepClick();

    if (localGame) {
      drawRanchRushMenuScreen();
    } else {
      returnToMenu(true);
    }

    return;
  }
}

void handleRanchRushPlayingTouch(int x, int y) {
  if (inRect(x, y, btnRrMenuX, btnRrMenuY, btnRrMenuW, btnRrMenuH)) {
    beepClick();
    if (localGame) {
      drawRanchRushMenuScreen();
    } else {
      returnToMenu(true);
    }
    return;
  }

  if ((localGame && rrGameOver) || (!localGame && rrNetGameOver)) {
    beepStart();
    if (localGame) {
      newRanchRushGame();
    } else {
      sendNetMessage(buildNetworkMessage("NEW"));
      startNetworkGame();
    }
    return;
  }

  if (y >= RR_BTN_AREA_TOP) {
    if (x < 110) {
      applyRanchRushPlayerAction(0);
    } else if (x < 210) {
      applyRanchRushPlayerAction(1);
    } else {
      applyRanchRushPlayerAction(2);
    }

    return;
  }

  if (y >= RR_FIELD_TOP && y < RR_FIELD_BOT) {
    int fieldMid = (RR_FIELD_TOP + RR_FIELD_BOT) / 2;

    if (y < fieldMid) {
      applyRanchRushPlayerAction(0);
    } else {
      applyRanchRushPlayerAction(1);
    }

    return;
  }
}

void handleFroggerMenuTouch(int x, int y) {
  if (inRect(x, y, btnLocalX, btnLocalY, btnLocalW, btnLocalH)) {
    startFroggerLocalGame();
    return;
  }

  if (inRect(x, y, btnHostX, btnHostY, btnHostW, btnHostH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_FROGGER;
    startHostMode();
    return;
  }

  if (inRect(x, y, btnJoinX, btnJoinY, btnJoinW, btnJoinH)) {
    beepStart();
    activeNetworkGame = NETWORK_GAME_FROGGER;
    startJoinMode();
    return;
  }

  if (inRect(x, y, btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH)) {
    beepClick();
    resetFroggerScore();
    drawFroggerMenuScreen();
    return;
  }

  if (inRect(x, y, btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH)) {
    beepClick();
    drawGamesExtraScreen();
    return;
  }
}

void handleFroggerPlaceholderTouch(int x, int y) {
  if (inRect(x, y, btnEmptyBackX, btnEmptyBackY, btnEmptyBackW, btnEmptyBackH)) {
    beepClick();

    if (localGame) {
      drawFroggerMenuScreen();
    } else {
      returnToMenu(true);
    }

    return;
  }
}

void handleFroggerPlayingTouch(int x, int y) {
  if (inRect(x, y, btnFrogMenuX, btnFrogMenuY, btnFrogMenuW, btnFrogMenuH)) {
    beepClick();
    if (localGame) {
      drawFroggerMenuScreen();
    } else {
      returnToMenu(true);
    }
    return;
  }

  if ((localGame && frogGameOver) || (!localGame && frogNetGameOver)) {
    if (localGame) {
      startFroggerLocalGame();
    } else {
      sendNetMessage(buildNetworkMessage("NEW"));
      startNetworkGame();
    }

    return;
  }

  if (localGame && frogDying) return;

  if (y >= FROG_BTN_TOP) {
    int buttonW = 68;
    int gap = (screenW - 4 * buttonW) / 5;

    if (x < gap + buttonW) {
      applyFroggerPlayerAction(0);
    } else if (x < 2 * gap + 2 * buttonW) {
      applyFroggerPlayerAction(1);
    } else if (x < 3 * gap + 3 * buttonW) {
      applyFroggerPlayerAction(2);
    } else {
      applyFroggerPlayerAction(3);
    }

    return;
  }

  if (y >= FROG_FIELD_TOP && y < FROG_BTN_TOP) {
    int fieldMidY = (FROG_FIELD_TOP + FROG_BTN_TOP) / 2;
    int fieldMidX = screenW / 2;
    int dy = abs(y - fieldMidY);
    int dx = abs(x - fieldMidX);

    if (dy >= dx) {
      applyFroggerPlayerAction(y < fieldMidY ? 1 : 2);
    } else {
      applyFroggerPlayerAction(x < fieldMidX ? 0 : 3);
    }
  }
}

void handleSnakePlayingTouch(int x, int y) {
  if (inRect(x, y, btnSnakeMenuX, btnSnakeMenuY, btnSnakeMenuW, btnSnakeMenuH)) {
    beepClick();

    if (localGame) {
      drawSnakeMenuScreen();
    } else {
      returnToMenu(true);
    }

    return;
  }

  if ((localGame && snakeGameOver) || (!localGame && snakeNetGameOver)) {
    if (localGame) {
      beepStart();
      newSnakeGame();
    } else {
      beepStart();
      sendNetMessage(buildNetworkMessage("NEW"));
      startNetworkGame();
    }

    return;
  }

  if (inRect(x, y, btnSnakeUpX, btnSnakeUpY, btnSnakeDirW, btnSnakeDirH)) {
    beepClick();
    applySnakeDirectionInput(SNAKE_DIR_UP);
    return;
  }

  if (inRect(x, y, btnSnakeLeftX, btnSnakeLeftY, btnSnakeDirW, btnSnakeDirH)) {
    beepClick();
    applySnakeDirectionInput(SNAKE_DIR_LEFT);
    return;
  }

  if (inRect(x, y, btnSnakeDownX, btnSnakeDownY, btnSnakeDirW, btnSnakeDirH)) {
    beepClick();
    applySnakeDirectionInput(SNAKE_DIR_DOWN);
    return;
  }

  if (inRect(x, y, btnSnakeRightX, btnSnakeRightY, btnSnakeDirW, btnSnakeDirH)) {
    beepClick();
    applySnakeDirectionInput(SNAKE_DIR_RIGHT);
    return;
  }

  if (inRect(x, y, SNAKE_BOARD_X, SNAKE_BOARD_Y,
             SNAKE_GRID_COLS * SNAKE_CELL, SNAKE_GRID_ROWS * SNAKE_CELL)) {
    int headCol;
    int headRow;

    if (localGame) {
      headCol = snakeX[0];
      headRow = snakeY[0];
    } else {
      int playerIndex = (myPlayer == '2') ? 1 : 0;

      if (snakeNetLength[playerIndex] <= 0) return;

      headCol = snakeNetX[playerIndex][0];
      headRow = snakeNetY[playerIndex][0];
    }

    int headCenterX = SNAKE_BOARD_X + headCol * SNAKE_CELL + SNAKE_CELL / 2;
    int headCenterY = SNAKE_BOARD_Y + headRow * SNAKE_CELL + SNAKE_CELL / 2;
    int dx = x - headCenterX;
    int dy = y - headCenterY;

    if (abs(dx) > abs(dy)) {
      applySnakeDirectionInput(dx > 0 ? SNAKE_DIR_RIGHT : SNAKE_DIR_LEFT);
    } else {
      applySnakeDirectionInput(dy > 0 ? SNAKE_DIR_DOWN : SNAKE_DIR_UP);
    }

    return;
  }
}

void handlePongPlayingTouch(int x, int y) {
  if (inRect(x, y, btnPongMenuX, btnPongMenuY, btnPongMenuW, btnPongMenuH)) {
    beepClick();
    if (localGame) {
      drawPongMenuScreen();
    } else {
      returnToMenu(true);
    }
    return;
  }

  if (pongGameOver) {
    if (localGame) {
      newPongMatch();
    } else {
      sendNetMessage(buildNetworkMessage("NEW"));
      startNetworkGame();
    }
    return;
  }
}

void handlePocketTanksPlayingTouch(int x, int y) {
  // Tanks Wars controls are button-only for now: angle, power, fire, menu.
  if (inRect(x, y, btnPtAngleDownX, btnPtAngleDownY, btnPtControlW, btnPtControlH)) {
    if (!localGame && !myTurn) return;
    beepClick();
    adjustPocketTanksAngle(-5);
    return;
  }

  if (inRect(x, y, btnPtAngleUpX, btnPtAngleUpY, btnPtControlW, btnPtControlH)) {
    if (!localGame && !myTurn) return;
    beepClick();
    adjustPocketTanksAngle(5);
    return;
  }

  if (inRect(x, y, btnPtPowerDownX, btnPtPowerDownY, btnPtControlW, btnPtControlH)) {
    if (!localGame && !myTurn) return;
    beepClick();
    adjustPocketTanksPower(-5);
    return;
  }

  if (inRect(x, y, btnPtPowerUpX, btnPtPowerUpY, btnPtControlW, btnPtControlH)) {
    if (!localGame && !myTurn) return;
    beepClick();
    adjustPocketTanksPower(5);
    return;
  }

  if (inRect(x, y, btnPtFireX, btnPtFireY, btnPtFireW, btnPtFireH)) {
    if (!localGame && !myTurn) return;
    sendPocketTanksFireMessage();
    firePocketTanksShot();
    return;
  }

  if (inRect(x, y, btnPtMenuX, btnPtMenuY, btnPtMenuW, btnPtMenuH)) {
    beepClick();
    if (localGame) {
      drawPocketTanksMenuScreen();
    } else {
      returnToMenu(true);
    }
    return;
  }
}

void handlePocketTanksResultTouch(int x, int y) {
  if (inRect(x, y, btnPlayAgainX, btnPlayAgainY, btnPlayAgainW, btnPlayAgainH)) {
    if (localGame) {
      startPocketTanksLocalGame();
    } else {
      beepStart();
      preparePocketTanksNetworkSeed();
      sendNetMessage(buildNetworkMessage("NEW"));
      startNetworkGame();
    }

    return;
  }

  if (inRect(x, y, btnResultMenuX, btnResultMenuY, btnResultMenuW, btnResultMenuH)) {
    beepClick();
    if (localGame) {
      drawPocketTanksMenuScreen();
    } else {
      returnToMenu(true);
    }
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
  if (inRect(x, y, btnSettingsMusicX, btnSettingsMusicY, btnSettingsMusicW, btnSettingsMusicH)) {
    beepClick();
    drawMusicSettingsScreen();
    return;
  }

  if (inRect(x, y, btnSettingsWifiX, btnSettingsWifiY, btnSettingsWifiW, btnSettingsWifiH)) {
    beepClick();
    activeIpField = 0;
    activeIpFieldNeedsClear = true;
    updateIpTextFromParts();
    drawWifiSettingsScreen();
    return;
  }

  if (inRect(x, y, btnSettingsHomeX, btnSettingsHomeY, btnSettingsHomeW, btnSettingsHomeH)) {
    beepClick();
    drawHomeScreen();
    return;
  }
}

void handleMusicSettingsTouch(int x, int y) {
  if (inRect(x, y, btnMusicToggleX, btnMusicToggleY, btnMusicToggleW, btnMusicToggleH)) {
    musicEnabled = !musicEnabled;
    saveConsoleSettings();

    if (!musicEnabled) {
      stopMenuMusic();
    } else {
      menuMusicNextTime = 0;
    }

    beepClick();
    drawMusicSettingsScreen();
    return;
  }

  if (inRect(x, y, btnSfxToggleX, btnSfxToggleY, btnSfxToggleW, btnSfxToggleH)) {
    sfxEnabled = !sfxEnabled;
    saveConsoleSettings();
    beepClick();
    drawMusicSettingsScreen();
    return;
  }

  if (inRect(x, y, btnSettingsHomeX, btnSettingsHomeY, btnSettingsHomeW, btnSettingsHomeH)) {
    beepClick();
    drawSettingsScreen();
    return;
  }
}

void handleWifiSettingsTouch(int x, int y) {
  if (inRect(x, y, btnWifiPrevX, btnWifiSsidY, btnWifiPrevW, btnWifiSsidH)) {
    beepClick();
    selectedHostSSIDIndex--;

    if (selectedHostSSIDIndex < 0) {
      selectedHostSSIDIndex = EPIC_SSID_COUNT - 1;
    }

    hostSSIDListOffset = (selectedHostSSIDIndex / MAX_HOST_SSID_VISIBLE) * MAX_HOST_SSID_VISIBLE;
    drawSettingsWifiSelector();
    return;
  }

  if (inRect(x, y, btnWifiNextX, btnWifiSsidY, btnWifiNextW, btnWifiSsidH)) {
    beepClick();
    selectedHostSSIDIndex++;

    if (selectedHostSSIDIndex >= EPIC_SSID_COUNT) {
      selectedHostSSIDIndex = 0;
    }

    hostSSIDListOffset = (selectedHostSSIDIndex / MAX_HOST_SSID_VISIBLE) * MAX_HOST_SSID_VISIBLE;
    drawSettingsWifiSelector();
    return;
  }

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
    drawWifiSettingsScreen();
    return;
  }

  if (inRect(x, y, btnSettingsHomeX, btnSettingsHomeY, btnSettingsHomeW, btnSettingsHomeH)) {
    beepClick();
    saveNetworkSettings();
    drawSettingsScreen();
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
  } else if (appState == STATE_GAMES_MORE) {
    handleGamesMoreTouch(x, y);
  } else if (appState == STATE_GAMES_EXTRA) {
    handleGamesExtraTouch(x, y);
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
  } else if (appState == STATE_BREAKOUT) {
    handleBreakoutMenuTouch(x, y);
  } else if (appState == STATE_BREAKOUT_PLAYING) {
    handleBreakoutPlayingTouch(x, y);
  } else if (appState == STATE_BREAKOUT_PLACEHOLDER) {
    handleBreakoutPlaceholderTouch(x, y);
  } else if (appState == STATE_PONG) {
    handlePongMenuTouch(x, y);
  } else if (appState == STATE_PONG_PLAYING) {
    handlePongPlayingTouch(x, y);
  } else if (appState == STATE_PONG_PLACEHOLDER) {
    handlePongPlaceholderTouch(x, y);
  } else if (appState == STATE_SNAKE) {
    handleSnakeMenuTouch(x, y);
  } else if (appState == STATE_SNAKE_PLAYING) {
    handleSnakePlayingTouch(x, y);
  } else if (appState == STATE_SNAKE_PLACEHOLDER) {
    handleSnakePlaceholderTouch(x, y);
  } else if (appState == STATE_RANCH_RUSH) {
    handleRanchRushMenuTouch(x, y);
  } else if (appState == STATE_RR_PLAYING) {
    handleRanchRushPlayingTouch(x, y);
  } else if (appState == STATE_RR_PLACEHOLDER) {
    handleRanchRushPlaceholderTouch(x, y);
  } else if (appState == STATE_FROGGER) {
    handleFroggerMenuTouch(x, y);
  } else if (appState == STATE_FROGGER_PLAYING) {
    handleFroggerPlayingTouch(x, y);
  } else if (appState == STATE_FROGGER_PLACEHOLDER) {
    handleFroggerPlaceholderTouch(x, y);
  } else if (appState == STATE_EMPTY_GAME) {
    handleEmptyGameTouch(x, y);
  } else if (appState == STATE_MENU) {
    handleMenuTouch(x, y);
  } else if (appState == STATE_SETTINGS) {
    handleSettingsTouch(x, y);
  } else if (appState == STATE_SETTINGS_MUSIC) {
    handleMusicSettingsTouch(x, y);
  } else if (appState == STATE_SETTINGS_WIFI) {
    handleWifiSettingsTouch(x, y);
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
  loadBreakoutScore();
  loadPongScore();
  loadSnakeScore();
  loadRanchRushScore();
  loadFroggerScore();
  loadNetworkSettings();
  loadConsoleSettings();
  clearBoard();
  WiFi.mode(WIFI_OFF);

  drawHomeScreen();
}

void loop() {
  checkHostClient();
  checkJoinConnection();
  pollNetwork();
  updateFroggerEspNowNetwork();

  int tx, ty;
  bool touched = readTouchScreen(tx, ty);

  breakoutTouchDown = touched;
  if (touched) {
    breakoutTouchX = tx;
    breakoutTouchY = ty;
  }

  pongTouchDown = touched;
  if (touched) {
    pongTouchX = tx;
    pongTouchY = ty;
  }

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

  updateMenuMusic();

  updateBreakoutGame();
  updatePongGame();
  updateSnakeGame();
  updateRanchRushGame();
  updateFroggerGame();

  delay(10);
}
