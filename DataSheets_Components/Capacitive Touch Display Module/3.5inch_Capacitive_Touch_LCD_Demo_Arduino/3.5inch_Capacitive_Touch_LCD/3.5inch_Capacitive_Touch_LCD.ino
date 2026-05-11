#include <Arduino_GFX_Library.h>
#include <Wire.h>

// ---------------- PINI ----------------
static const int PIN_LCD_CS   = 10;
static const int PIN_LCD_DC   = 9;
static const int PIN_LCD_RST  = 8;
static const int PIN_LCD_BL   = 6;

static const int PIN_TP_INT   = 3;
static const int PIN_TP_RST   = 4;
static const int PIN_SD_CS    = 5;   // optional, nefolosit aici

// FT6336U touch controller
static const uint8_t FT6336_ADDR = 0x38;

// ---------------- DISPLAY ----------------
// Arduino_GFX documentează declarația simplă cu Arduino_HWSPI(DC, CS). :contentReference[oaicite:1]{index=1}
Arduino_DataBus *bus = new Arduino_HWSPI(
  PIN_LCD_DC,
  PIN_LCD_CS
);

Arduino_GFX *gfx = new Arduino_ST7796(
  bus,
  PIN_LCD_RST,
  1,
  true,
  320,
  480
);

// ---------------- JOC ----------------
char board[3][3];
char currentPlayer = 'X';
bool gameOver = false;
char winner = ' ';

int screenW = 320;
int screenH = 480;

int boardX = 20;
int boardY = 70;
int boardSize = 280;
int cellSize = boardSize / 3;

int resetBtnX = 90;
int resetBtnY = 380;
int resetBtnW = 140;
int resetBtnH = 50;

unsigned long lastTouchTime = 0;
const unsigned long touchDebounceMs = 180;

// ---------------- TOUCH FT6336U ----------------
uint8_t tpReadReg(uint8_t reg) {
  Wire.beginTransmission(FT6336_ADDR);
  Wire.write(reg);
  if (Wire.endTransmission(false) != 0) return 0;
  Wire.requestFrom((int)FT6336_ADDR, 1);
  if (Wire.available()) return Wire.read();
  return 0;
}

bool readTouchRaw(uint16_t &x, uint16_t &y) {
  uint8_t points = tpReadReg(0x02) & 0x0F;
  if (points == 0) return false;

  uint8_t xh = tpReadReg(0x03);
  uint8_t xl = tpReadReg(0x04);
  uint8_t yh = tpReadReg(0x05);
  uint8_t yl = tpReadReg(0x06);

  x = ((xh & 0x0F) << 8) | xl;
  y = ((yh & 0x0F) << 8) | yl;

  return true;
}

bool readTouchScreen(int &sx, int &sy) {
  uint16_t rx, ry;
  if (!readTouchRaw(rx, ry)) return false;

  sx = map(ry, 0, 480, 0, screenW);
  sy = map(rx, 0, 320, 0, screenH);

  if (sx < 0) sx = 0;
  if (sx >= screenW) sx = screenW - 1;
  if (sy < 0) sy = 0;
  if (sy >= screenH) sy = screenH - 1;

  return true;
}

// ---------------- UTILITARE JOC ----------------
void resetGame() {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      board[r][c] = ' ';
    }
  }
  currentPlayer = 'X';
  gameOver = false;
  winner = ' ';
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

// ---------------- DESENARE ----------------
void drawCenteredText(const char *txt, int y, int size, uint16_t color) {
  int16_t x1, y1;
  uint16_t w, h;
  gfx->setTextSize(size);
  gfx->getTextBounds((char*)txt, 0, y, &x1, &y1, &w, &h);
  int x = (screenW - w) / 2;
  gfx->setCursor(x, y);
  gfx->setTextColor(color);
  gfx->print(txt);
}

void drawStatus() {
  gfx->fillRect(0, 0, screenW, 55, RGB565_BLACK);

  if (!gameOver) {
    char msg[32];
    snprintf(msg, sizeof(msg), "Randul: %c", currentPlayer);
    drawCenteredText(msg, 18, 2, RGB565_WHITE);
  } else {
    if (winner == 'D') {
      drawCenteredText("Egal!", 18, 2, RGB565_YELLOW);
    } else {
      char msg[32];
      snprintf(msg, sizeof(msg), "Castiga: %c", winner);
      drawCenteredText(msg, 18, 2, RGB565_GREEN);
    }
  }
}

void drawGrid() {
  gfx->fillRect(boardX - 2, boardY - 2, boardSize + 4, boardSize + 4, RGB565_WHITE);
  gfx->fillRect(boardX, boardY, boardSize, boardSize, RGB565_BLACK);

  gfx->fillRect(boardX + cellSize - 2, boardY, 4, boardSize, RGB565_WHITE);
  gfx->fillRect(boardX + 2 * cellSize - 2, boardY, 4, boardSize, RGB565_WHITE);

  gfx->fillRect(boardX, boardY + cellSize - 2, boardSize, 4, RGB565_WHITE);
  gfx->fillRect(boardX, boardY + 2 * cellSize - 2, boardSize, 4, RGB565_WHITE);
}

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

void drawMarks() {
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      if (board[r][c] == 'X') drawX(c, r);
      if (board[r][c] == 'O') drawO(c, r);
    }
  }
}

void drawResetButton() {
  gfx->fillRoundRect(resetBtnX, resetBtnY, resetBtnW, resetBtnH, 10, RGB565_BLUE);
  gfx->drawRoundRect(resetBtnX, resetBtnY, resetBtnW, resetBtnH, 10, RGB565_WHITE);

  gfx->setTextSize(2);
  gfx->setTextColor(RGB565_WHITE);
  gfx->setCursor(resetBtnX + 28, resetBtnY + 16);
  gfx->print("RESTART");
}

void drawUI() {
  gfx->fillScreen(RGB565_BLACK);
  drawStatus();
  drawGrid();
  drawMarks();
  drawResetButton();
}

bool inResetButton(int x, int y) {
  return (x >= resetBtnX && x < resetBtnX + resetBtnW &&
          y >= resetBtnY && y < resetBtnY + resetBtnH);
}

bool inBoard(int x, int y) {
  return (x >= boardX && x < boardX + boardSize &&
          y >= boardY && y < boardY + boardSize);
}

void handleBoardTouch(int x, int y) {
  if (!inBoard(x, y) || gameOver) return;

  int col = (x - boardX) / cellSize;
  int row = (y - boardY) / cellSize;

  if (row < 0 || row > 2 || col < 0 || col > 2) return;
  if (board[row][col] != ' ') return;

  board[row][col] = currentPlayer;

  winner = checkWinner();
  if (winner != ' ') {
    gameOver = true;
  } else {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  }

  drawUI();
}

void setup() {
  Serial.begin(115200);
  delay(200);

  pinMode(PIN_LCD_BL, OUTPUT);
  digitalWrite(PIN_LCD_BL, HIGH);

  pinMode(PIN_TP_INT, INPUT_PULLUP);
  pinMode(PIN_TP_RST, OUTPUT);

  digitalWrite(PIN_TP_RST, LOW);
  delay(20);
  digitalWrite(PIN_TP_RST, HIGH);
  delay(200);

  Wire.begin();
  Wire.setClock(400000);

  if (!gfx->begin()) {
    Serial.println("gfx->begin() failed!");
    while (1) delay(100);
  }

  gfx->fillScreen(RGB565_BLACK);

  resetGame();
  drawUI();
}

void loop() {
  int tx, ty;
  bool touched = readTouchScreen(tx, ty);

  if (touched) {
    unsigned long now = millis();
    if (now - lastTouchTime > touchDebounceMs) {
      lastTouchTime = now;

      Serial.print("Touch: ");
      Serial.print(tx);
      Serial.print(", ");
      Serial.println(ty);

      if (inResetButton(tx, ty)) {
        resetGame();
        drawUI();
      } else {
        handleBoardTouch(tx, ty);
      }
    }
  }

  delay(10);
}