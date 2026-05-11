#include <Arduino_GFX_Library.h>
#include <Wire.h>
#include <WiFi.h>
#include <Preferences.h>

// ============================================================================
// CONFIG HARDWARE
// ============================================================================
static const int PIN_LCD_CS   = 21;
static const int PIN_LCD_DC   = 18;
static const int PIN_LCD_RST  = 17;

static const int PIN_LCD_MOSI = 38;
static const int PIN_LCD_MISO = 47;
static const int PIN_LCD_SCLK = 48;

static const int PIN_TP_INT   = 6;
static const int PIN_TP_RST   = 7;

static const int PIN_SDA      = 11;
static const int PIN_SCL      = 12;

static const int PIN_BUZZER   = 5;

static const uint8_t FT6336_ADDR = 0x38;

// ============================================================================
// WIFI NETWORK CONFIG
// ============================================================================
const char *AP_SSID = "TicTacToe_ESP32";
const char *AP_PASS = "12345678";

const uint16_t NET_PORT = 3333;
IPAddress HOST_IP(192, 168, 4, 1);

WiFiServer gameServer(NET_PORT);
WiFiClient netClient;

bool isHost = false;
bool networkConnected = false;
char myPlayer = ' ';
bool myTurn = false;

// ============================================================================
// DISPLAY / MEMORY
// ============================================================================
Preferences prefs;

Arduino_DataBus *bus = new Arduino_HWSPI(
  PIN_LCD_DC,
  PIN_LCD_CS,
  PIN_LCD_SCLK,
  PIN_LCD_MOSI,
  PIN_LCD_MISO
);

Arduino_GFX *gfx = new Arduino_ILI9488_18bit(bus, PIN_LCD_RST, 0, false);

// ============================================================================
// GAME STATE
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

int scoreX = 0;
int scoreO = 0;
int scoreDraw = 0;

const int screenW = 320;
const int screenH = 480;

const int boardX = 20;
const int boardY = 110;
const int boardSize = 280;
const int cellSize = boardSize / 3;

const int topBarH = 90;

const int btnHostX = 60;
const int btnHostY = 215;
const int btnHostW = 200;
const int btnHostH = 50;

const int btnJoinX = 60;
const int btnJoinY = 280;
const int btnJoinW = 200;
const int btnJoinH = 50;

const int btnResetScoreX = 60;
const int btnResetScoreY = 345;
const int btnResetScoreW = 200;
const int btnResetScoreH = 50;

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

unsigned long lastTouchTime = 0;
const unsigned long touchDebounceMs = 80;
bool touchWasDown = false;

// ============================================================================
// SCORE PERSISTENT
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
  myTurn = (myPlayer == 'X');
}

void resetScore() {
  scoreX = 0;
  scoreO = 0;
  scoreDraw = 0;
  saveScore();
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
// DRAW GAME
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

  char line1[48];
  snprintf(line1, sizeof(line1), "Scor X:%d  O:%d  E:%d", scoreX, scoreO, scoreDraw);
  drawCenteredText(line1, 10, 2, RGB565_WHITE);

  char line2[48];

  if (gameOver) {
    snprintf(line2, sizeof(line2), "Joc terminat");
  } else if (myTurn) {
    snprintf(line2, sizeof(line2), "Randul tau: %c", myPlayer);
  } else {
    snprintf(line2, sizeof(line2), "Asteapta: %c", currentPlayer);
  }

  drawCenteredText(line2, 42, 2, myTurn ? RGB565_GREEN : RGB565_YELLOW);
}

void drawMenuScreen() {
  gfx->fillScreen(RGB565_BLACK);

  drawCenteredText("TIC TAC TOE", 35, 3, RGB565_WHITE);
  drawCenteredText("NETWORK MODE", 75, 2, RGB565_CYAN);

  char scoreLine[48];
  snprintf(scoreLine, sizeof(scoreLine), "X:%d   O:%d   E:%d", scoreX, scoreO, scoreDraw);
  drawCenteredText(scoreLine, 145, 2, RGB565_YELLOW);

  drawButton(btnHostX, btnHostY, btnHostW, btnHostH,
             RGB565_GREEN, RGB565_WHITE, RGB565_BLACK, "HOST - X", 2);

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

  char line[48];
  snprintf(line, sizeof(line), "X:%d   O:%d   E:%d", scoreX, scoreO, scoreDraw);
  drawCenteredText(line, 210, 2, RGB565_WHITE);

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

void startHostMode() {
  stopNetwork();

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

  isHost = false;
  myPlayer = 'O';
  myTurn = false;

  appState = STATE_CONNECTING_JOIN;
  drawConnectingJoinScreen();

  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID, AP_PASS);
}

void startNetworkGame() {
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

void applyMove(int col, int row, bool localMove) {
  if (gameOver) return;
  if (col < 0 || col > 2 || row < 0 || row > 2) return;
  if (board[row][col] != ' ') return;

  char playerToPlace = currentPlayer;

  board[row][col] = playerToPlace;
  drawSingleMark(col, row, playerToPlace);
  beepMove();

  char result = checkWinner();

  if (result != ' ') {
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
    return;
  }

  currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  myTurn = (currentPlayer == myPlayer);

  drawScoreBar();
}

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
    stopNetwork();
    appState = STATE_MENU;
    drawMenuScreen();
    return;
  }

  if (msg.startsWith("MOVE:")) {
    int comma = msg.indexOf(',');

    if (comma > 5) {
      int col = msg.substring(5, comma).toInt();
      int row = msg.substring(comma + 1).toInt();

      applyMove(col, row, false);
    }

    return;
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
      stopNetwork();
      appState = STATE_MENU;
      drawMenuScreen();
    }

    return;
  }

  while (netClient.available()) {
    String msg = netClient.readStringUntil('\n');
    handleNetMessage(msg);
  }
}

// ============================================================================
// GAME ACTIONS
// ============================================================================
void handleBoardTouch(int x, int y) {
  if (!networkConnected) return;
  if (!myTurn) return;
  if (!inBoard(x, y) || gameOver) return;

  int col = (x - boardX) / cellSize;
  int row = (y - boardY) / cellSize;

  if (row < 0 || row > 2 || col < 0 || col > 2) return;
  if (board[row][col] != ' ') return;

  String msg = "MOVE:" + String(col) + "," + String(row);
  sendNetMessage(msg);

  applyMove(col, row, true);
}

// ============================================================================
// TOUCH ROUTING
// ============================================================================
void handleMenuTouch(int x, int y) {
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
    stopNetwork();
    appState = STATE_MENU;
    drawMenuScreen();
  }
}

void handlePlayingTouch(int x, int y) {
  if (inRect(x, y, btnMenuX, btnMenuY, btnMenuW, btnMenuH)) {
    beepClick();
    sendNetMessage("LEAVE");
    stopNetwork();
    appState = STATE_MENU;
    drawMenuScreen();
    return;
  }

  handleBoardTouch(x, y);
}

void handleResultTouch(int x, int y) {
  if (inRect(x, y, btnPlayAgainX, btnPlayAgainY, btnPlayAgainW, btnPlayAgainH)) {
    beepStart();
    sendNetMessage("NEW");
    startNetworkGame();
    return;
  }

  if (inRect(x, y, btnResultMenuX, btnResultMenuY, btnResultMenuW, btnResultMenuH)) {
    beepClick();
    sendNetMessage("LEAVE");
    stopNetwork();
    appState = STATE_MENU;
    drawMenuScreen();
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
    Serial.println("Eroare: Initializarea GFX a esuat!");
    while (1) delay(100);
  }

  gfx->fillScreen(RGB565_BLACK);

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