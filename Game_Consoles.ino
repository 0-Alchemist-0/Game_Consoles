// ============================================================================
// CHANGELOG
// ============================================================================
// 2026-05-11 18:40 +02:00 - Added a 4 second hold on frame_000.raw before the
// rest of the RAW intro animation plays.
// 2026-05-11 18:05 +02:00 - Set RAW intro playback back to normal portrait
// rotation because frame_000.raw was displayed upside down.
// 2026-05-11 17:51 +02:00 - Replaced the intro player with RAW565 portrait
// playback, starting from frame_000.raw, using alternate portrait rotation.
// 2026-05-11 15:35 +02:00 - Enabled inverted display colors through a dedicated
// display setting.
// 2026-05-11 15:27 +02:00 - Added microSD support and a 24-bit BMP boot intro
// player while keeping local and WiFi gameplay modes.
// 2026-05-11 14:58 +02:00 - Removed the duplicate sketch compile conflict by
// keeping Game_Consoles.ino as the active Arduino sketch file.
// 2026-05-11 14:49 +02:00 - Rebuilt the sketch with a clean structure while
// keeping local play, WiFi host/join play, persistent score, touch input, and UI.
// 2026-05-11 14:18 +02:00 - Added local play mode with a main menu option,
// allowing X and O to play on the same device without WiFi.

#include <Arduino_GFX_Library.h>
#include <Wire.h>
#include <WiFi.h>
#include <Preferences.h>
#include <SPI.h>
#include <SD.h>
#include <FS.h>

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



// ============================================================================
// NETWORK CONFIG
// ============================================================================
const char *AP_SSID = "TicTacToe_ESP32";
const char *AP_PASS = "12345678";

const uint16_t NET_PORT = 3333;
IPAddress HOST_IP(192, 168, 4, 1);

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
  STATE_MENU,
  STATE_WAITING_HOST,
  STATE_CONNECTING_JOIN,
  STATE_PLAYING,
  STATE_RESULT
};

AppState appState = STATE_MENU;

char board[3][3];
char currentPlayer = 'X';
bool gameOver = false;
char winner = ' ';

bool localGame = false;
bool isHost = false;
bool networkConnected = false;
char myPlayer = ' ';
bool myTurn = false;

int scoreX = 0;
int scoreO = 0;
int scoreDraw = 0;

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
static const unsigned long INTRO_FIRST_FRAME_HOLD_MS = 4000;

static uint16_t rawDrawBuffer[VIDEO_W * RAW_BLOCK_LINES];

bool drawRaw565FromSD(const char *filename, int16_t x, int16_t y) {
  File rawFile = SD.open(filename, FILE_READ);

  if (!rawFile) {
    Serial.print("Cannot open RAW: ");
    Serial.println(filename);
    return false;
  }

  if (rawFile.size() != RAW_FRAME_SIZE) {
    Serial.print("Invalid RAW size: ");
    Serial.print(filename);
    Serial.print(" size=");
    Serial.println(rawFile.size());
    rawFile.close();
    return false;
  }

  for (int blockY = 0; blockY < VIDEO_H; blockY += RAW_BLOCK_LINES) {
    int linesThisBlock = RAW_BLOCK_LINES;

    if (blockY + linesThisBlock > VIDEO_H) {
      linesThisBlock = VIDEO_H - blockY;
    }

    int bytesToRead = VIDEO_W * linesThisBlock * 2;

    digitalWrite(PIN_LCD_CS, HIGH);

    int bytesRead = rawFile.read((uint8_t *)rawDrawBuffer, bytesToRead);

    if (bytesRead != bytesToRead) {
      rawFile.close();
      return false;
    }

    digitalWrite(PIN_SD_CS, HIGH);
    gfx->draw16bitRGBBitmap(x, y + blockY, rawDrawBuffer, VIDEO_W, linesThisBlock);
  }

  rawFile.close();
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
}

void drawWaitingHostScreen() {
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("HOST ACTIV", 60, 3, RGB565_GREEN);
  drawCenteredText("Tu esti X", 110, 2, RGB565_WHITE);

  drawCenteredText("Conecteaza al doilea", 180, 2, RGB565_YELLOW);
  drawCenteredText("setup cu JOIN", 210, 2, RGB565_YELLOW);

  drawCenteredText("SSID:", 280, 2, RGB565_WHITE);
  drawCenteredText(AP_SSID, 310, 2, RGB565_CYAN);

  drawButton(btnMenuX, btnMenuY, btnMenuW, btnMenuH,
             RGB565_BLUE, RGB565_WHITE, RGB565_WHITE, "MENIU", 2);
}

void drawConnectingJoinScreen() {
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("JOIN", 70, 3, RGB565_BLUE);
  drawCenteredText("Tu esti O", 120, 2, RGB565_WHITE);

  drawCenteredText("Caut host...", 200, 2, RGB565_YELLOW);
  drawCenteredText(AP_SSID, 235, 2, RGB565_CYAN);

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
  isHost = true;
  myPlayer = 'X';
  myTurn = true;

  WiFi.mode(WIFI_AP);
  WiFi.softAP(AP_SSID, AP_PASS);

  gameServer.begin();

  appState = STATE_WAITING_HOST;
  drawWaitingHostScreen();
}

void startJoinMode() {
  stopNetwork();

  localGame = false;
  isHost = false;
  myPlayer = 'O';
  myTurn = false;

  appState = STATE_CONNECTING_JOIN;
  drawConnectingJoinScreen();

  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID, AP_PASS);
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
  if (appState == STATE_MENU) {
    handleMenuTouch(x, y);
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
  clearBoard();
  WiFi.mode(WIFI_OFF);

  drawMenuScreen();
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
