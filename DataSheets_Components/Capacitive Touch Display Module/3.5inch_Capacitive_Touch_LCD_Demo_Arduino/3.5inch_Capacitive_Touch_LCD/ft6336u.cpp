#include <Arduino_GFX_Library.h>
#include <Wire.h>

// ---------------- PINI ----------------
static const int PIN_LCD_CS   = 10;
static const int PIN_LCD_DC   = 9;
static const int PIN_LCD_RST  = 8;
static const int PIN_LCD_BL   = 6;

static const int PIN_TP_INT   = 3;
static const int PIN_TP_RST   = 4;
static const int PIN_SD_CS    = 5;   // optional
static const int PIN_BUZZER   = 2;

static const uint8_t FT6336_ADDR = 0x38;

// ---------------- DISPLAY ----------------
Arduino_DataBus *bus = new Arduino_HWSPI(PIN_LCD_DC, PIN_LCD_CS);
Arduino_GFX *gfx = new Arduino_ST7796(bus, PIN_LCD_RST, 1, true, 320, 480);

// ---------------- ECRAN / UI ----------------
int screenW = 320;
int screenH = 480;

int boardX = 20;
int boardY = 110;
int boardSize = 280;
int cellSize = boardSize / 3;

int startBtnX = 60;
int startBtnY = 300;
int startBtnW = 200;
int startBtnH = 55;

int resetBtnX = 30;
int resetBtnY = 410;
int resetBtnW = 120;
int resetBtnH = 45;

int menuBtnX = 170;
int menuBtnY = 410;
int menuBtnW = 120;
int menuBtnH = 45;

// ---------------- STARE ----------------
enum GameState {
  STATE_MENU,
  STATE_GAME
};

GameState gameState = STATE_MENU;

char board[3][3];
char currentPlayer = 'X';
bool gameOver = false;
char winner = ' ';

int scoreX = 0;
int scoreO = 0;
int scoreDraw = 0;

unsigned long lastTouchTime = 0;
const unsigned long touchDebounceMs = 180;

// ---------------- SUNETE ----------------
void beep(int freq, int duration) {
  ledcAttach(PIN_BUZZER, freq, 8);
  ledcWrite(PIN_BUZZER, 128);
}