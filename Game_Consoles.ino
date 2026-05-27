// ============================================================================
// CHANGELOG
// ============================================================================
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

// ============================================================================
// HARDWARE CONFIG
// ============================================================================
static const int PIN_LCD_CS   = 21;
static const int PIN_LCD_DC   = 18;
static const int PIN_LCD_RST  = 17;

static const int PIN_LCD_MOSI = 38;
static const int PIN_LCD_MISO = 47;
static const int PIN_LCD_SCLK = 48;

static const int PIN_SD_CS    = 8;
static const int SD_SPI_FREQ  = 49000000;

static const int PIN_TP_INT   = 6;
static const int PIN_TP_RST   = 7;

static const int PIN_SDA      = 11;
static const int PIN_SCL      = 12;

static const int PIN_BUZZER   = 4;

static const uint8_t FT6336_ADDR = 0x38;

// Keep these in sync with the newest CHANGELOG entry.
// Build ID format: GC-V<major><minor>-<YYYYMMDDHH>.
const char *APP_VERSION_TEXT = "Version 3.8";
const char *APP_BUILD_ID_TEXT = "Build ID GC-V38-2026052714";



// ============================================================================
// NETWORK CONFIG
// ============================================================================
const char *AP_SSID = "TicTacToe_ESP32";
const char *AP_PASS = "Alchemist2026";
const char *JOIN_WIFI_PASS = "Alchemist2026";

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
enum AppState {
  STATE_HOME,
  STATE_GAMES,
  STATE_ROCK_PAPER_SCISSORS,
  STATE_RPS_CHOICE_P1,
  STATE_RPS_CHOICE_P2,
  STATE_RPS_RESULT,
  STATE_RPS_PLACEHOLDER,
  STATE_BATTLESHIP,
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

char board[3][3];
char currentPlayer = 'X';
bool gameOver = false;
char winner = ' ';

bool localGame = false;
bool isHost = false;
bool networkConnected = false;
char myPlayer = ' ';
bool myTurn = false;

static const int MAX_HOST_SSID_VISIBLE = 8;
int selectedHostSSIDIndex = 0;
int hostSSIDListOffset = 0;

static const int MAX_JOIN_NETWORKS = 24;
static const int MAX_JOIN_NETWORKS_VISIBLE = 8;
String joinNetworks[MAX_JOIN_NETWORKS];
int joinNetworkCount = 0;
int selectedJoinNetwork = -1;
int joinNetworkListOffset = 0;

uint8_t ipParts[4] = {192, 168, 10, 1};
char ipFieldText[4][4] = {"192", "168", "10", "1"};
int activeIpField = 0;
bool activeIpFieldNeedsClear = true;

int scoreX = 0;
int scoreO = 0;
int scoreDraw = 0;

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

bool touchWasDown = false;
unsigned long lastTouchTime = 0;
const unsigned long touchDebounceMs = 80;

// ============================================================================
// LAYOUT
// ============================================================================
const int screenW = 320;
const int screenH = 480;

const int topBarH = 90;

const int boardX = 20;
const int boardY = 110;
const int boardSize = 280;
const int cellSize = boardSize / 3;

const int btnLocalX = 60;
const int btnLocalY = 185;
const int btnLocalW = 200;
const int btnLocalH = 45;

const int btnHostX = 60;
const int btnHostY = 245;
const int btnHostW = 200;
const int btnHostH = 45;

const int btnJoinX = 60;
const int btnJoinY = 305;
const int btnJoinW = 200;
const int btnJoinH = 45;

const int btnResetScoreX = 60;
const int btnResetScoreY = 365;
const int btnResetScoreW = 200;
const int btnResetScoreH = 45;

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

const int btnTttHomeX = 60;
const int btnTttHomeY = 420;
const int btnTttHomeW = 200;
const int btnTttHomeH = 45;

const int btnGamesX = 35;
const int btnGamesTttY = 135;
const int btnGamesRpsY = 205;
const int btnGamesBattleshipY = 275;
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
const int btnRpsMenuX = 90;
const int btnRpsMenuY = 420;
const int btnRpsMenuW = 140;
const int btnRpsMenuH = 40;

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
static const int VIDEO_W = 320;
static const int VIDEO_H = 480;
static const int RAW_BLOCK_LINES = 32;
static const int RAW_FRAME_SIZE = VIDEO_W * VIDEO_H * 2;
static const int INTRO_FIRST_FRAME = 0;
static const int INTRO_TOTAL_FRAMES = 75;
static const int INTRO_TARGET_FPS = 65;
static const int INTRO_ROTATION = 0;
static const unsigned long INTRO_FIRST_FRAME_HOLD_MS = 1000;

static uint16_t rawDrawBuffer[VIDEO_W * RAW_BLOCK_LINES];
static uint16_t rawScaleSourceBuffer[homeButtonRawW * homeButtonRawH];
static uint16_t rawScaleLineBuffer[screenW];

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

// ============================================================================
// NETWORK SETTINGS
// ============================================================================
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
void beepMove()  { tone(PIN_BUZZER, 1000, 40); }
void beepStart() { tone(PIN_BUZZER, 1400, 70); }
void beepWin()   { tone(PIN_BUZZER, 2200, 180); }
void beepDraw()  { tone(PIN_BUZZER, 1200, 150); }
void beepClick() { tone(PIN_BUZZER, 1600, 60); }

// ============================================================================
// TOUCH
// ============================================================================
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

void drawButton(int x, int y, int w, int h, uint16_t fillColor, uint16_t borderColor, uint16_t textColor, const char *label, int textSize) {
  gfx->fillRoundRect(x, y, w, h, 10, fillColor);
  gfx->drawRoundRect(x, y, w, h, 10, borderColor);

  int16_t x1, y1;
  uint16_t tw, th;

  gfx->setTextSize(textSize);
  gfx->getTextBounds((char *)label, 0, 0, &x1, &y1, &tw, &th);

  int tx = x + (w - tw) / 2;
  int ty = y + (h - th) / 2 + 2;

  gfx->setCursor(tx, ty);
  gfx->setTextColor(textColor);
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
  const char *baseName = getRpsWinImageBaseName(winningChoice, losingChoice);
  const char *folder = (rpsWinner == 1) ? rpsPlayer1WinsPath : rpsPlayer2WinsPath;

  return drawRpsRawResultImage(folder, baseName);
}

// ============================================================================
// GAME DRAWING
// ============================================================================
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

// ============================================================================
// SCREENS
// ============================================================================
void drawMenuScreen() {
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("TIC TAC TOE", 35, 3, RGB565_WHITE);
  drawCenteredText("LOCAL / NETWORK", 75, 2, RGB565_CYAN);

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "X:%d   O:%d   E:%d", scoreX, scoreO, scoreDraw);
  drawCenteredText(scoreLine, 145, 2, RGB565_YELLOW);

  drawButton(btnLocalX, btnLocalY, btnLocalW, btnLocalH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "LOCAL", 2);

  drawButton(btnHostX, btnHostY, btnHostW, btnHostH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "HOST - X", 2);

  drawButton(btnJoinX, btnJoinY, btnJoinW, btnJoinH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "JOIN - O", 2);

  drawButton(btnResetScoreX, btnResetScoreY, btnResetScoreW, btnResetScoreH,
             RGB565_RED, RGB565_WHITE, RGB565_WHITE, "RESET SCOR", 2);

  drawButton(btnTttHomeX, btnTttHomeY, btnTttHomeW, btnTttHomeH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "BACK", 2);
}

void drawGamesScreen() {
  appState = STATE_GAMES;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("GAMES", 35, 3, RGB565_CYAN);

  drawButton(btnGamesX, btnGamesTttY, btnGamesW, btnGamesH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "TIC TAC TOE", 2);

  drawButton(btnGamesX, btnGamesRpsY, btnGamesW, btnGamesH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "ROCK-PAPER-SCISSORS", 2);

  drawButton(btnGamesX, btnGamesBattleshipY, btnGamesW, btnGamesH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "BATTLESHIP", 2);

  drawButton(btnGamesX, btnGamesHomeY, btnGamesW, btnGamesHomeH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "HOME", 2);
}

void drawRpsMenuScreen() {
  appState = STATE_ROCK_PAPER_SCISSORS;
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("ROCK PAPER", 28, 2, RGB565_WHITE);
  drawCenteredText("SCISSORS LIZARD SPOCK", 58, 2, RGB565_CYAN);

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "P1:%d   P2:%d   E:%d", rpsScoreP1, rpsScoreP2, rpsScoreDraw);
  drawCenteredText(scoreLine, 125, 2, RGB565_YELLOW);

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

void drawRpsResultScreen() {
  appState = STATE_RPS_RESULT;

  bool resultImageDrawn = (rpsWinner == 0) ? drawRpsDrawImage() : drawRpsWinningImage();

  if (!resultImageDrawn) {
    gfx->fillScreen(RGB565_BLACK);

    if (rpsWinner == 0) {
      drawCenteredText("Missing draw image", 150, 2, RGB565_RED);
    } else {
      drawCenteredText("Missing win image", 150, 2, RGB565_RED);
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

void drawWaitingHostScreen() {
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("HOST ACTIV", 28, 3, RGB565_GREEN);
  drawCenteredText("Tu esti X", 72, 2, RGB565_WHITE);

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
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("JOIN", 70, 3, RGB565_BLUE);
  drawCenteredText("Tu esti O", 120, 2, RGB565_WHITE);

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
    backgroundDrawn = drawRaw565ImageFromSD("/home_screen/background.raw", 0, 0, screenW, screenH);
  }

  if (!backgroundDrawn) {
    gfx->fillScreen(RGB565_BLACK);
    drawCenteredText("HOME", 80, 3, RGB565_WHITE);
    drawCenteredText("Missing /home_screen files", 125, 1, RGB565_YELLOW);
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

// ============================================================================
// NETWORK
// ============================================================================
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
  if (selectedJoinNetwork < 0 || selectedJoinNetwork >= joinNetworkCount) return;

  saveNetworkSettings();

  localGame = false;
  isHost = false;
  myPlayer = 'O';
  myTurn = false;
  networkConnected = false;

  appState = STATE_CONNECTING_JOIN;
  drawConnectingJoinScreen();

  WiFi.mode(WIFI_STA);
  WiFi.begin(joinNetworks[selectedJoinNetwork].c_str(), JOIN_WIFI_PASS);
}

void beginHostNetwork() {
  saveNetworkSettings();
  stopNetwork();

  localGame = false;
  isHost = true;
  myPlayer = 'X';
  myTurn = true;

  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(HOST_IP, HOST_IP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(epicSSIDList[selectedHostSSIDIndex], AP_PASS);

  gameServer.begin();

  appState = STATE_WAITING_HOST;
  drawWaitingHostScreen();
}

void startLocalGame() {
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
  localGame = false;
  resetGameLogic();

  appState = STATE_PLAYING;
  beepStart();
  drawGameScreenFull();
}

void checkHostClient() {
  if (!isHost || networkConnected) return;

  WiFiClient newClient = gameServer.available();

  if (newClient) {
    netClient = newClient;
    netClient.setTimeout(10);
    networkConnected = true;

    sendNetMessage("START");
    startNetworkGame();
  }
}

void checkJoinConnection() {
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
void startRpsLocalGame() {
  beepStart();
  resetRpsRound();
  drawRpsChoiceScreen(1);
}

void finishRpsLocalGame() {
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

void finishGame(char result) {
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
  if (notifyPeer && !localGame) {
    sendNetMessage("LEAVE");
  }

  localGame = false;
  stopNetwork();

  appState = STATE_MENU;
  drawMenuScreen();
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
void handleNetMessage(String msg) {
  msg.trim();

  if (msg == "START") {
    startNetworkGame();
    return;
  }

  if (msg == "NEW") {
    startNetworkGame();
    return;
  }

  if (msg == "LEAVE") {
    returnToMenu(false);
    return;
  }

  if (msg.startsWith("MOVE:")) {
    int comma = msg.indexOf(',');

    if (comma > 5) {
      int col = msg.substring(5, comma).toInt();
      int row = msg.substring(comma + 1).toInt();

      applyMove(col, row);
    }
  }
}

void pollNetwork() {
  if (!networkConnected) return;

  if (!netClient || !netClient.connected()) {
    networkConnected = false;

    if (appState == STATE_PLAYING || appState == STATE_RESULT) {
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
void handleMenuTouch(int x, int y) {
  if (inRect(x, y, btnLocalX, btnLocalY, btnLocalW, btnLocalH)) {
    startLocalGame();
    return;
  }

  if (inRect(x, y, btnHostX, btnHostY, btnHostW, btnHostH)) {
    beepStart();
    startHostMode();
    return;
  }

  if (inRect(x, y, btnJoinX, btnJoinY, btnJoinW, btnJoinH)) {
    beepStart();
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

  if (inRect(x, y, btnGamesX, btnGamesBattleshipY, btnGamesW, btnGamesH)) {
    beepClick();
    drawEmptyGameScreen("BATTLESHIP", STATE_BATTLESHIP);
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

void handleRpsMenuTouch(int x, int y) {
  if (inRect(x, y, btnLocalX, btnLocalY, btnLocalW, btnLocalH)) {
    startRpsLocalGame();
    return;
  }

  if (inRect(x, y, btnHostX, btnHostY, btnHostW, btnHostH)) {
    beepClick();
    drawRpsPlaceholderScreen("RPS HOST");
    return;
  }

  if (inRect(x, y, btnJoinX, btnJoinY, btnJoinW, btnJoinH)) {
    beepClick();
    drawRpsPlaceholderScreen("RPS JOIN");
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
  if (inRect(x, y, btnRpsMenuX, btnRpsMenuY, btnRpsMenuW, btnRpsMenuH)) {
    beepClick();
    drawRpsMenuScreen();
    return;
  }

  int choice = rpsChoiceFromTouch(x, y);
  if (choice < 0) return;

  beepMove();

  if (appState == STATE_RPS_CHOICE_P1) {
    rpsP1Choice = choice;
    drawRpsChoiceScreen(2);
    return;
  }

  rpsP2Choice = choice;
  finishRpsLocalGame();
}

void handleRpsResultTouch(int x, int y) {
  if (inRect(x, y, btnPlayAgainX, btnPlayAgainY, btnPlayAgainW, btnPlayAgainH)) {
    startRpsLocalGame();
    return;
  }

  if (inRect(x, y, btnResultMenuX, btnResultMenuY, btnResultMenuW, btnResultMenuH)) {
    beepClick();
    drawRpsMenuScreen();
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
      sendNetMessage("NEW");
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
  if (appState == STATE_HOME) {
    handleHomeTouch(x, y);
  } else if (appState == STATE_GAMES) {
    handleGamesTouch(x, y);
  } else if (appState == STATE_ROCK_PAPER_SCISSORS) {
    handleRpsMenuTouch(x, y);
  } else if (appState == STATE_RPS_CHOICE_P1 || appState == STATE_RPS_CHOICE_P2) {
    handleRpsChoiceTouch(x, y);
  } else if (appState == STATE_RPS_RESULT) {
    handleRpsResultTouch(x, y);
  } else if (appState == STATE_RPS_PLACEHOLDER) {
    handleRpsPlaceholderTouch(x, y);
  } else if (appState == STATE_BATTLESHIP) {
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
void setup() {
  Serial.begin(115200);
  delay(1000);

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
