// qmk flash -kb bm40hsrgb -km signynt_2_loud

/* Copyright 2021 Vincenzo Mitchell Barroso
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
/* USB Device descriptor parameter */
#define VENDOR_ID       0x4B50 // "KP"
#define PRODUCT_ID      0x3430 // "40"
#define DEVICE_VER      0x0001
#define MANUFACTURER    KPRepublic
#define PRODUCT         BM40 Hotswap RGB

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { B3, B2, E6, B5 }
#define MATRIX_COL_PINS { B6, C6, B4, D7, D4, D6, C7, F6, F5, F4, F1, F0 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW


#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_ANIMATIONS

#define PERMISSIVE_HOLD
#define RGB_MATRIX_STARTUP_VAL 0//RGB_MATRIX_MAXIMUM_BRIGHTNESS
//#define RGBLIGHT_LIMIT_VAL 10

//bootmagic
#define BOOTMAGIC_KEY_SALT KC_V
#define BOOTMAGIC_KEY_EEPROM_CLEAR KC_Q

#define RGB_DI_PIN E2
#define DRIVER_LED_TOTAL 53
#ifdef RGB_DI_PIN
#    define RGB_MATRIX_KEYPRESSES // reacts to keypresses
//#    define RGBLIGHT_LIMIT_VAL 180 // Limit to vendor-recommended value
#endif
#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180 // Limit to vendor-recommended value
# define RGBLIGHT_LAYERS_RETAIN_VAL
#endif
#define TAPPING_TERM 200

//--------------------------------------------------------------------------------------------------------
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS


#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
//disable broken animations
//#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define DISABLE_RGB_MATRIX_BREATHING
#define DISABLE_RGB_MATRIX_BAND_SAT
#define DISABLE_RGB_MATRIX_BAND_VAL
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
//#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
//#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
//#define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define DISABLE_RGB_MATRIX_CYCLE_ALL
#define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
//#define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
//#define DISABLE_RGB_MATRIX_DUAL_BEACON
#define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
//#define DISABLE_RGB_MATRIX_RAINBOW_BEACON
//#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//#define DISABLE_RGB_MATRIX_RAINDROPS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS // DO NOT ENABLE
//#define DISABLE_RGB_MATRIX_TYPING_HEATMAP
//#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
//#define DISABLE_RGB_MATRIX_SPLASH
//#define DISABLE_RGB_MATRIX_MULTISPLASH
//#define DISABLE_RGB_MATRIX_SOLID_SPLASH
//#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH

#undef RGB_MATRIX_STARTUP_MODE

#define RGBLIGHT_HUE_STEP 20

