/* Copyright 2020 ZSA Technology Inc
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

#include "keymap_swedish_mac_iso.h"
#include "features/mouse_turbo_click.h"
#include "color.h"

#define IS_MOD_ACTIVE(mod) (get_mods() & MOD_BIT(mod) || get_oneshot_mods() & MOD_BIT(mod))

enum planck_keycodes {
  RGB_SLD = SAFE_RANGE,
};

enum planck_layers {
  // _GAMING,
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION,
};

#define LOWER_BSPC LT(_LOWER, KC_BSPC)
#define RAISE_ENT LT(_RAISE, KC_ENT)
#define LSFT_SE_SECT MT(MOD_LSFT, SE_SECT)
#define RSFT_SE_QUOT MT(MOD_RSFT, SE_QUOT)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCTION MO(_FUNCTION)

#define LALT_ESC MT(MOD_LALT, KC_ESC)
#define LCTL_TAB MT(MOD_LCTL, KC_TAB)
#define RALT_ARNG MT(MOD_RALT, SE_ARNG)
#define RCTL_ADIA MT(MOD_RCTL, SE_ADIA)

#define RGUI_J MT(MOD_RGUI, KC_J)

#include "g/keymap_combo.h"
// #include "g/keymap_engine.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//   [_GAMING] = LAYOUT_planck_grid(
//     KC_ESC,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_ARNG,
//     KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           SE_ODIA,        SE_ADIA,
//     LSFT_SE_SECT,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         SE_MINS,        RSFT_SE_QUOT,
//     OSM(MOD_LCTL),  OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LGUI),  LOWER_BSPC,     KC_SPC,         KC_NO,          RAISE_ENT,      OSM(MOD_RGUI),  OSM(MOD_RALT),  OSM(MOD_RCTL),  OSM(MOD_RCTL)
//   ),

  [_BASE] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_ARNG,
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           SE_ODIA,        SE_ADIA,
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         SE_MINS,        SE_QUOT,
    OSM(MOD_LSFT),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LOWER,          KC_SPC,         KC_NO,          RAISE,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSM(MOD_RSFT)
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           SE_PLUS,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, SE_PIPE,        SE_LBRC,        SE_RBRC,        SE_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP,        KC_PGDN,        KC_TRANSPARENT, KC_TRANSPARENT, SE_TILD,        SE_LCBR,        SE_RCBR,        SE_CIRC,        SE_GRV,
    KC_TRANSPARENT, CM_ON,          CM_OFF,         OSL(_FUNCTION), KC_NO,          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_NONUS_BACKSLASH,    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           SE_PLUS,
    S(KC_NONUS_BACKSLASH), KC_EXLM,        SE_DQUO,        KC_HASH,        SE_EURO,        KC_PERC,        SE_AMPR,        SE_SLSH,        SE_LPRN,        SE_RPRN,        SE_EQL,         SE_QUES,
    A(KC_NONUS_BACKSLASH), SE_AT,          SE_TM,          SE_PND,         SE_DLR,         KC_TRANSPARENT, SE_SECT,        KC_NONUS_HASH,  SE_LBRC,        SE_RBRC,        KC_TRANSPARENT, SE_TILD,
    KC_TRANSPARENT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, AU_ON,          AU_OFF,         AU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,        RGB_VAI,        RGB_VAD,        KC_TRANSPARENT, RESET,
    KC_TRANSPARENT, KC_TRANSPARENT, MU_ON,          MU_OFF,         MU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, RGB_MOD,        RGB_HUI,        RGB_HUD,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_FUNCTION] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F13,         KC_F14,         KC_F15,         KC_F16,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F17,         KC_F18,         KC_F19,         KC_F20,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_F21,         KC_F22,         KC_F23,         KC_F24,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, CM_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT
  ),


};
// clang-format on

//
// Led Matrix Stuff
//

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][4] = {
  [_BASE]     = {{HSV_OFF       }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     },
                 {HSV_OFF       }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     },
                 {HSV_OFF       }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     },
                 {HSV_WHITE     }, {HSV_OFF       }, {HSV_OFF       }, {HSV_OFF       }, {HSV_PINK      }, {HSV_OFF       }, /*             */ {HSV_CHARTREUSE}, {HSV_OFF       }, {HSV_OFF       }, {HSV_OFF       }, {HSV_WHITE     },},

  [_LOWER]    = {{HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      },
                 {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      },
                 {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      },
                 {HSV_PINK      }, {HSV_GREEN     }, {HSV_RED       }, {HSV_ORANGE    }, {HSV_PINK      }, {HSV_PINK      }, /*             */ {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      },},

  [_RAISE]    = {{HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE},
                 {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE},
                 {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE},
                 {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, /*             */ {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE},},

  [_ADJUST]   = {{200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133},
                 {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133},
                 {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133},
                 {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, /*            */ {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}},

    // [0] = {{42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {32, 255, 234}, {32, 255, 234}, {32, 255, 234}, {32, 255, 234}},

    // [1] = {{89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}},

    // [2] = {{216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {249, 228, 255}, {249, 228, 255}, {249, 228, 255}, {216, 255, 255}, {216, 255, 255}, {105, 255, 255}, {105, 255, 255}, {105, 255, 255}, {216, 255, 255}, {14, 255, 255}, {216, 255, 255}, {216, 255, 255}, {249, 228, 255}, {249, 228, 255}, {249, 228, 255}, {216, 255, 255}, {216, 255, 255}, {105, 255, 255}, {105, 255, 255}, {105, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}},

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };

    if (!hsv.h && !hsv.s && !hsv.v) {
      rgb_matrix_set_color(i, 0, 0, 0);
    } else {
      RGB   rgb = hsv_to_rgb(hsv);
      float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
      rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) {
    return false;
  }

  set_layer_color(get_highest_layer(layer_state));

  if (IS_MOD_ACTIVE(KC_LSFT)) {
    rgb_matrix_set_color(36, RGB_BLUE);
  }

  if (IS_MOD_ACTIVE(KC_RSFT)) {
    rgb_matrix_set_color(46, RGB_BLUE);
  }

  if (IS_MOD_ACTIVE(KC_LGUI)) {
    rgb_matrix_set_color( 4, RGB_RED);
    rgb_matrix_set_color(16, RGB_RED);
  }

  if (IS_MOD_ACTIVE(KC_RGUI)) {
    rgb_matrix_set_color( 7, RGB_RED);
    rgb_matrix_set_color(19, RGB_RED);
  }

  if (IS_MOD_ACTIVE(KC_LALT)) {
    rgb_matrix_set_color( 3, RGB_GREEN);
    rgb_matrix_set_color(15, RGB_GREEN);
  }

  if (IS_MOD_ACTIVE(KC_RALT)) {
    rgb_matrix_set_color( 8, RGB_GREEN);
    rgb_matrix_set_color(20, RGB_GREEN);
  }

  if (IS_MOD_ACTIVE(KC_LCTL)) {
    rgb_matrix_set_color( 2, RGB_PURPLE);
    rgb_matrix_set_color(14, RGB_PURPLE);
  }

  if (IS_MOD_ACTIVE(KC_RCTL)) {
    rgb_matrix_set_color( 9, RGB_PURPLE);
    rgb_matrix_set_color(21, RGB_PURPLE);
  }

  if (is_caps_word_on())  {
    rgb_matrix_set_color(36, RGB_ORANGE);
    rgb_matrix_set_color(46, RGB_ORANGE);
  }

  return false;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
#    ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
#    else
        tap_code(KC_PGDN);
#    endif
    } else {
#    ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
#    else
        tap_code(KC_PGUP);
#    endif
    }
    return true;
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//
// Leader Key
//

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_F)) { // Flutter
        SEND_STRING("for ");
        SEND_STRING(SS_LSFT("8"));
    } else if (leader_sequence_two_keys(KC_I, KC_F)) {
        SEND_STRING("if ");
        SEND_STRING(SS_LSFT("8"));
    } else if (leader_sequence_two_keys(KC_F, KC_N)) {
        SEND_STRING("function");
        SEND_STRING(SS_LSFT("8"));
    } else if (leader_sequence_two_keys(KC_F, KC_U)) {
        SEND_STRING("Future");
    } else if (leader_sequence_two_keys(KC_F, KC_I)) {
        SEND_STRING("final ");
    } else if (leader_sequence_two_keys(KC_R, KC_E)) {
        SEND_STRING("required ");
    } else if (leader_sequence_three_keys(KC_R, KC_E, KC_T)) {
        SEND_STRING("return ");
    } else if (leader_sequence_two_keys(KC_G, KC_S)) { // Git
        SEND_STRING("git status");
    } else if (leader_sequence_two_keys(KC_G, KC_C)) {
        SEND_STRING("git commit ");
    } else if (leader_sequence_two_keys(KC_G, KC_P)) {
        SEND_STRING("git pull");
    } else if (leader_sequence_three_keys(KC_G, KC_C, KC_A)) {
        SEND_STRING("git commit /a");
    } else if (leader_sequence_three_keys(KC_G, KC_S, KC_T)) {
        SEND_STRING("git stash");
    } else if (leader_sequence_three_keys(KC_G, KC_S, KC_P)) {
        SEND_STRING("git stash pop");
    } else if (leader_sequence_five_keys(KC_G, KC_C, KC_A, KC_A, KC_N)) {
        SEND_STRING("git commit /a //amend //no/edit");
    } else if (leader_sequence_five_keys(KC_G, KC_P, KC_P, KC_F, KC_O)) {
        SEND_STRING("git push //force origin ");
    } else if (leader_sequence_three_keys(KC_Q, KC_M, KC_C)) { // Qmk
        SEND_STRING("qmk compile");
    } else if (leader_sequence_three_keys(KC_Q, KC_M, KC_F)) {
        SEND_STRING("qmk flash");
    } else if (leader_sequence_four_keys(KC_Q, KC_M, KC_C, KC_C)) {
        SEND_STRING("qmk clean" SS_LSFT(",") " qmk compile");
    } else if (leader_sequence_three_keys(KC_F, KC_L, KC_U)) { // Flutter CLI
        SEND_STRING("flutter ");
    } else if (leader_sequence_three_keys(KC_F, KC_L, KC_V)) {
        SEND_STRING("flutter -v ");
    } else if (leader_sequence_three_keys(KC_F, KC_L, KC_D)) {
        SEND_STRING("flutter doctor ");
    } else if (leader_sequence_four_keys(KC_F, KC_L, KC_D, KC_V)) {
        SEND_STRING("flutter doctor /v");
    }
}

//
// Caps Word
//

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case SE_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
