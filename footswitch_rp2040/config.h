/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
//#define VENDOR_ID      0xFF14
//#define PRODUCT_ID     0x0020
//#define DEVICE_VER     0x0001
//#define MANUFACTURER   NeoTrinity
//#define PRODUCT        FootSwitch3


#define MATRIX_ROWS 1
#define MATRIX_COLS 3


#define MATRIX_ROW_PINS {  }
#define MATRIX_COL_PINS { GP7, GP8, GP9 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

//#define LOCKING_SUPPORT_ENABLE
//#define LOCKING_RESYNC_ENABLE

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U // Specify a optional status led which blinks when entering the bootloader
