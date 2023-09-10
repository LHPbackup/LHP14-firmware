// Copyright 2023 Neo Trinity
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define RGBLED_NUM 20 // Number of LEDs. Tape LED >>> RGBLED_NUM 5   onboard LED >>> RGBLED_NUM 1


#define JOYSTICK_BUTTON_COUNT 1
#define JOYSTICK_AXIS_COUNT 2
#define JOYSTICK_AXIS_RESOLUTION 8

#define OLED_TIMEOUT 0

#define OLED_FONT_H "keyboards/lhp14lite_rp2040d/glcdfont_lhp14lite.c"

#define LAYER_STATE_32BIT


#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET 
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U 
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U 

#define OLED_DISPLAY_128X32
#define I2C1_SCL_PIN GP3
#define I2C1_SDA_PIN GP2
#define I2C_DRIVER I2CD1
#define OLED_BRIGHTNESS 128

