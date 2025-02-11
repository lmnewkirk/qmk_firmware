// qmk flash -kb bm40hsrgb -km mikonai

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

#include QMK_KEYBOARD_H

// non-KC_ keycodes
#define KC_RST QK_BOOT
#define KC_TOG RGB_TOG
#define KC_MOD RGB_MOD
#define KC_HUI RGB_HUI
#define KC_SAI RGB_SAI
#define KC_VAI RGB_VAI

//define layers
enum layers {BASE, MEDR, NAVR, NSSL, NSL, FUNL, MIDI};

enum custom_keycodes {
  CMD_TAB = SAFE_RANGE,
};

//cmd tab

bool is_cmd_tab_active = false;
uint16_t cmd_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CMD_TAB:
      if (record->event.pressed) {
        if (!is_cmd_tab_active) {
          is_cmd_tab_active = true;
          register_code(KC_LCTL);
        }
        cmd_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

// commented out to see if it works without it
void matrix_scan_user(void) {
  if (is_cmd_tab_active) {
    if (timer_elapsed(cmd_tab_timer) > 500) {
      unregister_code(KC_LCTL);
      is_cmd_tab_active = false;
    }
  }
}

//layer led colors; commented out for troubleshooting
bool rgb_matrix_indicators_user(void) {

//void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  //HSV hsv = {0, 255, 40};

//  for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) {
  //  if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
        //rgb_matrix_set_color(i, 0, 0, 0);
   // }
//    if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
//        rgb_matrix_set_color(i, RGB_AZURE);
//    }
 // }

  //capslock; 
  if (host_keyboard_led_state().caps_lock) {
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) {
      if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
            rgb_matrix_set_color(i, RGB_WHITE);
      }
    }
   // hsv = {255, 255, 40};
  }

  //nav layer
  if (IS_LAYER_ON(NAVR)) {
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) {
      if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
     rgb_matrix_set_color(i, RGB_TEAL); } }
   // hsv = {255, 128, 128};
  }// else {
   //   hsv = {30, 255, 255};
 // }

   //RGB rgb = hsv_to_rgb(hsv);

    //for (uint8_t i = led_min; i <= led_max; i++) {
//      if (HAS_FLAGS(g_led_config.flags[i], 0x01)) { // 0x01 == LED_FLAG_MODIFIER
  //          rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    //    }
   // }
// media layer
  if (IS_LAYER_ON(MEDR)) {
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) {
      if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
        rgb_matrix_set_color(i, 0, 0, 20); } }
  }
  //funl layer
  if (IS_LAYER_ON(FUNL)) {
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) {
      if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, 255, 0, 20);
      }
    }
  }
//
//  //nsl layer
  if (IS_LAYER_ON(NSL)) {
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) {
      if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, 51, 0, 20);
      }
    }
  }

  //nssl layer
  if (IS_LAYER_ON(NSSL)) {
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) {
      if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, 0, 255, 20);
      }
    }
  }
//
//  //game layer
//  if (IS_LAYER_ON(GAME)) {
//    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) {
//      if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
//            rgb_matrix_set_color(i, 0, 204, 20);
//      }
//    }
//  }
//
//  //secgame layer
//  if (IS_LAYER_ON(SECGAME)) {
//    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) {
//      if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
//            rgb_matrix_set_color(i, 255, 0, 20);
//      }
//    }
//  }
//
  return false;
};




//tap dance declarations
enum {
    TD_MEDIA, TD_SCREEN,
};

//tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_MEDIA] = ACTION_TAP_DANCE_DOUBLE( KC_MPLY , KC_MNXT ),
    [TD_SCREEN] = ACTION_TAP_DANCE_DOUBLE( (G(S(KC_S))) , S(C(KC_4)) ),
};

#define KC_TD(TD_VARIABLE) TD(TD_VARIABLE)






//--------------------------------------------------------------------------------------------------------

//base
// switch space and enter
// right alt -> algr for compose
// change right ctrl to backslash

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_planck_mit(
    KC_LALT,              KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              KC_ALGR,
    KC_LSFT,              KC_A,              KC_S,              KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              KC_L,              KC_QUOT,           KC_LSFT,
    KC_LCTL,              KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,           RCTL_T(KC_BSLS),
    G(KC_SPC),            KC_PSCR,  KC_ESC,            LT(MEDR, KC_TAB),  LT(NAVR, KC_ENT),      LT(NSSL, KC_SPC),                 LT(NSL, KC_BSPC),  LT(FUNL, KC_DEL),  KC_LGUI,           KC_TD(TD_MEDIA),     CMD_TAB
  ),

//layers
  [NAVR] = LAYOUT_planck_mit(
    KC_LALT,              KC_RST,            G(KC_7),             G(KC_8),              G(KC_9),            G(KC_A),             G(KC_LEFT),        G(KC_DOWN),     G(KC_UP),           G(KC_RIGHT),           G(C(KC_M)),     KC_LALT,
    KC_LSFT,              G(S(C(KC_F1))),    G(KC_4),    G(KC_5),     G(KC_6),   MS_BTN1,             KC_LEFT,           KC_DOWN,           KC_UP,           KC_RGHT,             G(C(KC_A)),           KC_LSFT,
    KC_LCTL,              KC_NO,             G(KC_1),           G(KC_2),              G(KC_3),   KC_NO,             KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            KC_LCTL,
    TG(MIDI),             KC_NO,             KC_NO,             KC_NO,              KC_NO,                     KC_ENT,                      KC_BSPC,           KC_DEL,            KC_LGUI,             C(G(KC_LEFT)),     C(G(KC_RIGHT))
  ),
  [MEDR] = LAYOUT_planck_mit(
    KC_LALT,              KC_RST,            KC_NO,             KC_NO,              KC_NO,            KC_NO,             KC_TOG,            KC_MOD,            KC_HUI,            KC_SAI,            KC_VAI,            KC_LALT,
    KC_LSFT,              KC_NO,             KC_NO,             KC_NO,              KC_NO,            KC_NO,             KC_NO,             KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           KC_LSFT,
    KC_LCTL,              KC_NO,             KC_NO,             KC_NO,              KC_NO,            KC_NO,             KC_NO,             KC_F13,            KC_F14,            KC_F15,            RGB_VAI,           KC_LCTL,
    KC_NO,                KC_NO,             KC_NO,             KC_NO,              KC_NO,                     KC_MSTP,                     KC_MPLY,           KC_MUTE,           KC_NO,             KC_NO,             KC_NO
  ),
  [FUNL] = LAYOUT_planck_mit(
    KC_LALT,              KC_F12,            KC_F7,             KC_F8,              KC_F9,            KC_PSCR,           KC_F15,            KC_NO,             KC_NO,             KC_NO,             KC_RST,            KC_LALT,
    KC_LSFT,              KC_F11,            KC_F4,             KC_F5,              KC_F6,            KC_NO,           KC_F14,            KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_LSFT,
    KC_LCTL,              KC_F10,            KC_F1,             KC_F2,              KC_F3,            KC_PAUS,           KC_F13,            KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_LCTL,
    KC_NO,                KC_NO,             KC_TAB,            KC_APP,             KC_SPC,                    KC_UNDS,                     KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO
  ),
  // compose key under ctl, rctl -> backslash
  [NSL] = LAYOUT_planck_mit(
    KC_LALT,              KC_LPRN,           KC_7,              KC_8,               KC_9,             KC_RPRN,           KC_LBRC,           KC_AMPR,           KC_ASTR,           KC_LCBR,           KC_RBRC,           KC_BSPC,
    KC_LSFT,              KC_COLN,           KC_4,              KC_5,               KC_6,             KC_EQL,            KC_LCBR,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_RCBR,           KC_LSFT,
    KC_LCTL,              KC_GRV,            KC_1,              KC_2,               KC_3,             KC_PLUS,           KC_TILD,           KC_EXLM,           KC_COMM,           KC_DOT,            KC_SLSH,           KC_BSLS, A(S(C(KC_N))),        S(C(KC_5)),        KC_NO,             KC_UNDS,            KC_0,                      KC_MINS,                     KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_BSLS),
  [NSSL] = LAYOUT_planck_mit(
    KC_LALT,              KC_LCBR,           KC_AMPR,           KC_ASTR,            KC_LPRN,          KC_RCBR,           KC_NO,             KC_NO,              KC_NO,            KC_NO,             KC_NO,            KC_BSPC,
    KC_LSFT,              KC_SCLN,           KC_DLR,            KC_PERC,            KC_CIRC,          KC_PLUS,           KC_NO,             KC_MS_L,            KC_MS_D,          KC_MS_U,           KC_MS_R,           KC_LSFT,
    KC_LCTL,              KC_TILD,           KC_EXLM,           KC_AT,              KC_HASH,          KC_PIPE,           KC_NO,             KC_WH_L,            KC_WH_D,          KC_WH_U,           KC_WH_R,           KC_LCTL,
    KC_NO,                KC_NO,             KC_UNDS,           KC_GT,              KC_RPRN,                   KC_NO,                       KC_BTN1,            KC_BTN3,          KC_BTN2,           KC_NO,             KC_NO
  )
  // swap enter and space
//  [GAME] = LAYOUT_planck_mit(
//    KC_ESC,               KC_Q,              KC_W,              KC_E,               KC_R,             KC_T,              KC_Y,              KC_U,               KC_I,             KC_O,              KC_P,              TG(GAME),
//    KC_LALT,              KC_A,              KC_S,              KC_D,               KC_F,             KC_G,              KC_H,              KC_J,               KC_K,             KC_L,              KC_QUOT,           KC_LSFT,
//    KC_LSFT,              KC_Z,        KC_X,            KC_C,               KC_V,             KC_B,              KC_N,              KC_M,               KC_COMM,          KC_DOT,            KC_SLSH,           KC_LCTL,
//    KC_LCTL,              A(KC_TAB),         MO(SECGAME),       KC_TAB,             LT(SECGAME, KC_ENT),             KC_SPC,                KC_BSPC,            KC_DEL,           KC_MPRV,           KC_MPLY,           KC_MNXT
//  ),
//  [SECGAME] = LAYOUT_planck_mit(
//    KC_1,                 KC_2,              KC_3,              KC_4,               KC_5,             KC_6,              KC_7,              KC_8,               KC_9,             KC_0,              KC_MINS,           KC_EQL,
//    KC_F1,                KC_F2,             KC_F3,             KC_F4,              KC_F5,            KC_F6,             KC_F7,             KC_F8,              KC_F9,            KC_F10,            KC_F11,            KC_F12,
//    KC_LEFT,              KC_DOWN,           KC_UP,             KC_RGHT,            KC_NO,            KC_NO,             KC_NO,             KC_P1,              KC_P2,            KC_P3,             KC_P4,             KC_P5,
//    KC_LEFT,              KC_DOWN,           KC_UP,             KC_RGHT,            KC_NO,                     KC_NO,                       KC_P6,              KC_P7,            KC_P8,             KC_P9,             KC_P0
//  ),
//  [MIDI] = LAYOUT_planck_mit(
//      MI_C_4, MI_Cs_4, MI_D_4, MI_Ds_4, MI_E_4, MI_F_4, MI_Fs_4, MI_G_4, MI_Gs_4, MI_A_4, MI_As_4, MI_B_4,
//      MI_C_3, MI_Cs_3, MI_D_3, MI_Ds_3, MI_E_3, MI_F_3, MI_Fs_3, MI_G_3, MI_Gs_3, MI_A_3, MI_As_3, MI_B_3,
//      MI_C_2, MI_Cs_2, MI_D_2, MI_Ds_2, MI_E_2, MI_F_2, MI_Fs_2, MI_G_2, MI_Gs_2, MI_A_2, MI_As_2, MI_B_2,
//      MI_C_1, MI_Cs_1, MI_OCTD, MI_OCTU, MI_ALLOFF, MI_VEL_7, MI_VELD, MI_VELU, MI_Gs_1, MI_TOG,  TG(MIDI)
//  )
  
};
