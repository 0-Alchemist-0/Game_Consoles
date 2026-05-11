#include <stdint.h>
#pragma once

#include <Arduino.h>
#include <Wire.h>

#define TP_I2C_FREQ 400000
#define FT6336U_ADDR 0x38
#define FT6336U_ID_REG 0xa8

#define FT6336U_TOUCH_NUM_REG 0x02
#define FT6336U_TOUCH_XH_REG 0x03
#define FT6336U_TOUCH_XL_REG 0x04
#define FT6336U_TOUCH_YH_REG 0x05
#define FT6336U_TOUCH_YL_REG 0x06

#define FT6336U_TOUCH_MAX_NUM   2


typedef struct{
    uint16_t x;
    uint16_t y;
}touch_coords_t;

typedef struct{
  touch_coords_t coords[FT6336U_TOUCH_MAX_NUM];
  uint16_t touch_num;
}touch_data_t;


void ft6336u_init(int tp_rst, int tp_int);
bool get_touch_data(touch_data_t *touch_data);

void ft6636_touch_int_cb(void);

