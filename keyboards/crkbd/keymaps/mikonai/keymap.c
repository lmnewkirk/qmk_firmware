// mikonai's keymap for crkbd
/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
//#include <stdio.h>
#include "split_util.h"
// a bunch of BS to try to get rgb stuff to work which wasn't otherwise
//extern rgblight_config_t rgblight_config;
//#include "rgblight.h"
//#include "rgb_matrix.h"
//#include "~/qmk_firmware/quantum/rgb_matrix/rgb_matrix.h"



//tap dance declarations
enum {
    TD_MEDIA, TD_SCREEN,
};


// my function for layer lights
//void lightUp(int leds[], HSV myColor, int ledsLen) {
//    RGB rgb = hsv_to_rgb(myColor);
//    int i = 0;
//    while (i < ledsLen) {
//   rgb_matrix_set_color(leds[i], rgb.r, rgb.g, rgb.b);
//   i++;
//    }; 
//}



//tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MEDIA] = ACTION_TAP_DANCE_DOUBLE( KC_MPLY , KC_MNXT ),
    [TD_SCREEN] = ACTION_TAP_DANCE_DOUBLE( (G(S(KC_S))) , S(C(KC_4)) ),
};

#define KC_TD(TD_VARIABLE) TD(TD_VARIABLE)

//define layers
enum layers {BASEL, MEDR, NUM, NAVR, SYM}; 

uint8_t mod_state;


// layer lights

//void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//void rgb_matrix_indicators_user(void) {
//uint32_t layer_state_set_user(uint32_t state) {
//rgb_matrix_set_color_all(0, 0, 0);
//switch (biton32(state)) {
//  case NAVR:;
//
//    // I don't like how I have to set these variables all the time. this seems bad. but also it doesn't work and I have no idea why
////    int desktopLeds[] = {10, 11, 12, 15, 16, 17, 18, 19, 20};
////    int desktopLen = sizeof desktopLeds / sizeof desktopLeds[0];
////    HSV desktopColor = {255, 255, 40};
////    lightUp(desktopLeds, desktopColor, desktopLen);
//    rgb_matrix_set_color_all(0, 0, 0);
//    rgb_matrix_set_color(23, 255, 255, 40);
//    rgblight_setrgb_at(255, 255, 255, 10);
//    break;
//
//}
//return state;
//}
//}



// AtelierForest scheme:
// red: f22c40    rgb 242 44 64
// green: 5ab738  rgb 90 183 56
// gold: d5911a   rgb 219 145 26
// blue: 407ee7   rgb 64 126 231
// purple: 6666ea rgb 102 102 234
// teal: 00ad9c   rgb 0 173 156
// gray: a8a19f   rgb 168 161 159

//
////Per key lights from bermeo
//#ifdef RGB_MATRIX_ENABLE
//bool rgb_matrix_indicators_user(void) {
//    switch (get_highest_layer(layer_state)) {
//        case MEDR:
//            mod_state  = get_mods();
//            for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
//                if (mod_state & MOD_MASK_SHIFT) {
//                    rgb_matrix_set_color(52, 255, 255, 255);
//                    rgb_matrix_set_color(i, 255, 150, 0);
//                } else if (mod_state & MOD_MASK_GUI || mod_state & MOD_MASK_CTRL) {
//                    rgb_matrix_set_color(15, 255, 0, 0);
//                    switch (i) {
//                        case 0 ... 5:                            // underglow left side
//                        case 9:                                  // cmd + T white (new tab)
//                        case 11:                                 // cmd + F white (find)
//                        case 18:                                 // cmd + W white (close tab)
//                        case 19:                                 // cmd + S white (save)
//                        case 21:                                 // cmd + Z white (undo)
//                        case 22:                                 // cmd + A white (select all)
//                        case 27 ... 32:                          // underglow right side
//                        case 43:                                 // cmd + K white (comment for desktop remote)
//                        case 48:                                 // cmd + / white (comment line)
//                            rgb_matrix_set_color(i, 219, 145, 26); // white
//                            break;
//                        case 6:                                  // space bar off
//                        case 24 ... 26:                          // left column off
//                        case 33:                                 // backspace off
//                        case 41:                                 // shift off
//                        case 51 ... 53:                          // right column off
//                            rgb_matrix_set_color(i, 0, 0, 0);    //off
//                            break;
//                    }
//                    if (mod_state & MOD_MASK_GUI) {
//                        rgb_matrix_set_color(12, 255, 255, 255); // white V key
//                        rgb_matrix_set_color(15, 255, 255, 255); // white C key
//                        rgb_matrix_set_color(20, 255, 255, 255); // white X key
//                    } else {
//                    }
//                } else if (mod_state & MOD_MASK_ALT) {
//                } else {
//                    rgb_matrix_set_color(14, 0, 0, 0);          // command key off
//                }
//            }
//            rgb_matrix_set_color(13, 23, 181, 255);             // cyan layer
//            rgb_matrix_set_color(40, 255, 33, 0);               // orange layer
//            break;
//
//        case NUM:
//            for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
//                switch (i) {
//                    case 7:                                     // B key off
//                    case 8:                                     // G key off
//                    case 11:                                    // F key off
//                    case 12:                                    // V key off
//                    case 16:                                    // D key off
//                    case 19 ... 21:                             // S, X, Z keys off
//                    case 25:                                    // tab key off
//                    case 26:                                    // shift key off
//                    case 52 ... 53:                             // right column off
//                        rgb_matrix_set_color(i, 0, 0, 0);       // off
//                        break;
//                    case 15:                                    // Ç key
//                    case 22:                                    // Ã key
//                    case 24:                                    // Launch (F4)
//                    case 40:                                    // Active layer
//                        rgb_matrix_set_color(i, 255, 255, 255); // white
//                        break;
//                    case 13:                                    // active layer
//                        rgb_matrix_set_color(i, 0, 255, 0);     // green
//                        break;
//                    case 42:                                    // , shifted key
//                    case 47 ... 49:                             // . / ; shifted keys
//                        rgb_matrix_set_color(i, 255, 214, 0);   // yellow
//                        break;
//                    default:
//                        rgb_matrix_set_color(i, 255, 33, 0);    // orange
//                }
//            }
//            break;
//
//        case NAVR:
//            for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
//                switch (i) {
//                    case 7:                                     // Delete key
//                    case 51:                                    // ESC key
//                        rgb_matrix_set_color(i, 255, 0, 0);     // red
//                        break;
//                    case 12:                                    // V key off
//                    case 15:                                    // C key off
//                    case 20:                                    // X key off
//                    case 21:                                    // Z key off
//
//                    case 26:                                    // shift key off
//                    case 52 ... 53:                             // right column off
//                        rgb_matrix_set_color(i, 0, 0, 0);       // off
//                        break;
//                    case 11:                                    // Right arrow key
//                    case 13:                                    // Active layer
//                    case 16:                                    // Up arrow key
//                    case 19:                                    // Down arrow key
//                    case 22:                                    // Left arrow key
//                    case 24:                                    // Print
//                        rgb_matrix_set_color(i, 255, 255, 255); // white
//                        break;
//                    case 8:                                     // Enter key
//                    case 40:                                    // Activate Numpad
//                        rgb_matrix_set_color(i, 0, 255, 0);     // green
//                        break;
//                    case 42:                                    // , shifted key
//                    case 47 ... 49:                             // . / ; shifted keys
//                    case 25:                                    // opens emoji dialog (on macOS)
//                        rgb_matrix_set_color(i, 255, 214, 0);   // yellow
//                        break;
//                    default:
//                        rgb_matrix_set_color(i, 23, 181, 255);  // cyan
//                }
//            }
//
//            break;
//
//        case SYM:
//            for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
//                switch (i) {
//                    case 12:                                    // RGB speed-
//                    case 15:                                    // RGB brigthness-
//                    case 20:                                    // RGB saturation-
//                    case 21:                                    // RGB hue-
//                    case 49:                                    // Numpad -
//                    case 51:                                    // Numpad /
//                        rgb_matrix_set_color(i, 255, 0, 0);     // red
//                        break;
//                    case 8 ... 10:                              // G T R off
//                    case 17:                                    // E off
//                    case 18:                                    // W off
//                    case 23:                                    // Q off
//                    case 25:                                    // Tab off
//                    case 26:                                    // LShift off
//                    case 33:                                    // Backspace off
//                    case 35:                                    // H off
//                    case 36:                                    // Y off
//                    case 53:                                    // RShift off
//                        rgb_matrix_set_color(i, 0, 0, 0);       // off
//                        break;
//                    case 6:                                     // Space bar off
//                    case 13:                                    // Return to default layer
//                    case 16:                                    // RGB brigthness+
//                    case 24:                                    // RGB toggle
//                    case 37 ... 47:                             // Numpad numbers
//                    case 52:                                    // Enter key
//                        rgb_matrix_set_color(i, 255, 255, 255); // white
//                        break;
//                    case 11:                                    // RGB speed+
//                    case 19:                                    // RGB saturation+
//                    case 22:                                    // RGB hue+
//                    case 48:                                    // Numpad +
//                        rgb_matrix_set_color(i, 0, 255, 0);     // green
//                        break;
//                    case 34:                                    // . numpad key
//                        rgb_matrix_set_color(i, 255, 214, 0);   // yellow
//                        break;
//                }
//                rgb_matrix_set_color(13, 23, 181, 255);         // Activate cyan layer
//                rgb_matrix_set_color(40, 255, 33, 0);           // Activate orange layer
//                rgb_matrix_set_color(50, 0, 33, 255);           // Numpad *
//                rgb_matrix_set_color(14, 0, 255, 0);            // Green layer active
//            }
//    }
//    return false;
//};
//#endif
//
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}
#endif


/* TODO:
 * configure layer lights or something idk (thumb cluster changes per layer? Configure those complex "light up the relevant keys" settings?)
 * Add an alternate base layer for windows that switches the cmd_space thing to alt_spc or whatever for keypirinha (don't think I need to adjust any other layers)
 * Add IPA layer(s)? emulate typeit with multi-tap and/or combos?
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // base layer (linux). Need to make tap-dances for the alt tab and mod space functions because qmk is weird.
  [BASEL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LALT,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_TD(TD_MEDIA),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT, KC_RSFT,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RCTL_T(KC_ESC),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  RCTL_T(KC_BSLS),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            LGUI_T(G(KC_SPC)),   LT(MEDR,KC_TAB),  LT(NAVR,KC_ENT),     KC_SPC,   LT(NUM,KC_BSPC), LT(SYM,KC_RALT)
                                      //`--------------------------'  `--------------------------'

  ),

  // LT(NUM,KC_BSPC)
  // adjust right side with something?
  [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_PLUS,  KC_7,    KC_8,    KC_9,    KC_EQL,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_PIPE, KC_4, KC_5,   KC_6,      KC_TILDE,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_UNDS, KC_1, KC_2,    KC_3,      KC_BSPC,                      XXXXXXX, KC_COLN, KC_SCLN, _______, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_SPC, KC_0,  KC_MINS,     KC_SPC,   _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_PLUS,   KC_AMPR, KC_ASTR,  KC_EQL, KC_NO,                      _______, _______, KC_F7, KC_F8, KC_F9, KC_F10,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_EQL, KC_DLR, KC_PERC, KC_CIRC, KC_TILDE,                      _______,  _______, KC_F4, KC_F5, KC_F6,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_UNDS, KC_EXLM, KC_AT, KC_HASH, KC_PIPE,                      _______, _______, KC_F1, KC_F2, KC_F3, KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_UNDS,   KC_MINS,  KC_ENT,     KC_SPC, KC_BSPC, _______
                                      //`--------------------------'  `--------------------------'
  ),

[NAVR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, G(KC_7), G(KC_8), G(KC_9), KC_NO,                G(KC_LEFT), G(KC_DOWN), G(KC_UP), G(KC_RIGHT), KC_HOME, KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, G(KC_4), G(KC_5), G(KC_6), KC_NO,                      KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGDN, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_BTN1, G(KC_1), G(KC_2), G(KC_3), KC_BTN2,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_D, KC_WH_U,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, G(KC_0),  _______,     KC_SPC, KC_BSPC, KC_RALT 
                                          //`--------------------------'  `--------------------------'
    ),

  [MEDR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOTLOADER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_MUTE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_ENT,     KC_SPC, KC_BSPC, KC_RALT 
                                          //`--------------------------'  `--------------------------'

  ) };


// getting shift+backspace = del
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    uint16_t  temp_keycode = keycode;

    // Filter out the actual keycode from MT and LT keys.
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        temp_keycode &= 0xFF;
    }
 switch (temp_keycode) {

    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }

    }
    return true;
};
// end chords


// AtelierForest scheme:
// red: f22c40    rgb 242 44 64
// green: 5ab738  rgb 90 183 56
// gold: d5911a   rgb 219 145 26
// blue: 407ee7   rgb 64 126 231
// purple: 6666ea rgb 102 102 234
// teal: 00ad9c   rgb 0 173 156
// gray: a8a19f   rgb 168 161 159

// Layer lights but the code sucks and I don't understand it well enough to fix it

//uint32_t layer_state_set_user(uint32_t state) {
//    switch (biton32(state)) {
//    case NAVR:
//        if(isLeftHand) {
//
//          // rgblight_setrgb_at(R, G, B, LED);
//          // mousekeys -> red, left side 
//          rgblight_setrgb_at(242, 44, 64, 7); 
//          rgblight_setrgb_at(242, 44, 64, 21); // sets LED number 7 (nav) to purple on left hand
//          //rgb_matrix_set_color(7, 242, 44, 64);
//          // desktop keys -> purple (create a list to pull the i from?)
//          for(int i=10; i < 13; i ++) {
//          rgblight_setrgb_at(102, 102, 234, i); 
//            }
//          for(int i=15; i < 21; i ++) {
//          rgblight_setrgb_at(102, 102, 234, i); 
//            }
//
//          // mod arrow keys attempt 2 (top row, purple, using led map)
//          rgblight_setrgb_at(102, 102, 234, 36); 
//          rgblight_setrgb_at(102, 102, 234, 37); 
//          rgblight_setrgb_at(102, 102, 234, 44); 
//          rgblight_setrgb_at(102, 102, 234, 45); 
//
//        } else {
//
//          // mod arrow keys (top row, purple)
//          rgblight_setrgb_at(102, 102, 234, 10); 
//          rgblight_setrgb_at(102, 102, 234, 11); 
//          rgblight_setrgb_at(102, 102, 234, 18); 
//          rgblight_setrgb_at(102, 102, 234, 19); 
//          // arrow keys, pgup, pgdn,home,end (blue)
//          rgblight_setrgb_at(64, 126, 231, 9); 
//          rgblight_setrgb_at(64, 126, 231, 10); 
//          rgblight_setrgb_at(64, 126, 231, 17); 
//          rgblight_setrgb_at(64, 126, 231, 20);      
//          for(int i=23; i < 26; i ++) {
//            rgblight_setrgb_at(64, 126, 231, i); 
//            }
//          // mousekeys (bottom row, red)
//
//          rgblight_setrgb_at(242, 44, 64, 8); 
//          rgblight_setrgb_at(242, 44, 64, 13); 
//          rgblight_setrgb_at(242, 44, 64, 16); 
//          rgblight_setrgb_at(242, 44, 64, 20); 
//          rgblight_setrgb_at(242, 44, 64, 21); 
//          rgblight_setrgb_at(242, 44, 64, 26); 
//          }
//        break;
//    case NUM:
//
//        if(!isLeftHand) {
//          rgblight_setrgb_at(148, 0, 211, 13); // same thing here, sets LED 13 (raise) to purple and HJKL to cyan
//          rgblight_setrgb_at(0, 255, 150, 8);
//          rgblight_setrgb_at(0, 255, 150, 11);
//          rgblight_setrgb_at(0, 255, 150, 16);
//          rgblight_setrgb_at(0, 255, 150, 19);
//        }
//
//        break;
//    case SYM:
//      if(isLeftHand){
//        rgblight_setrgb_at(148,0,211, 26); // control purple, ZXCV cyan.
//        rgblight_setrgb_at(0,255,150,21);
//        rgblight_setrgb_at(0,255,150,20);
//        rgblight_setrgb_at(0,255,150,15);
//        rgblight_setrgb_at(0,255,150,12);
//      }
//      break;
////    default:
////        rgblight_enable();
////        if(isLeftHand) {                        // this sets the underside LEDs (1-6) to cyan on both sides and does nothing with the rest.
////          for(int i=0; i < 6; i ++) {           // this also means that if I manually change LED color to red, the bottom 6 LEDS will ALWAYS be cyan.
////            rgblight_setrgb_at(0, 0, 255, i); // it's the only way I found to make it switch back to underglow LEDs after I've used another layer.
////          }
////        } else {
////          for(int j=0; j < 6; j ++) {
////            rgblight_setrgb_at(0, 0, 255, j);
////          }
////        }
////        break;
//    }
//  return state;
//}


//int RGB_current_mode;
//
//void persistent_default_layer_set(uint16_t default_layer) {
//  eeconfig_update_default_layer(default_layer);
//  default_layer_set(default_layer);
//}
//
//// Setting ADJUST layer RGB back to default
//void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
//  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
//    layer_on(layer3);
//  } else {
//    layer_off(layer3);
//  }
//}
//
//void matrix_init_user(void) {
//    #ifdef RGBLIGHT_ENABLE
//      RGB_current_mode = rgblight_config.mode;
//    #endif
//    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
//    #ifdef SSD1306OLED
//        iota_gfx_init(!has_usb());   // turns on the display
//    #endif
//}


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
