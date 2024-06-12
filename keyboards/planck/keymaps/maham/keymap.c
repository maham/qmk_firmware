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

#include "keymap_swedish_pro_mac_iso.h"
#include "features/mouse_turbo_click.h"
#include "color.h"

#define IS_MOD_ACTIVE(mod) (get_mods() & MOD_BIT(mod) || get_oneshot_mods() & MOD_BIT(mod))

enum planck_keycodes {
  RGB_SLD = SAFE_RANGE,
};

enum planck_layers {
  _BASE,
  _GAMING,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER_BSPC    LT(_LOWER, KC_BSPC)
#define RAISE_ENT     LT(_RAISE, KC_ENT)
#define LSFT_SE_SECT  MT(MOD_LSFT, SE_SECT)
#define RSFT_SE_QUOT  MT(MOD_RSFT, SE_QUOT)

#define LOWER         MO(_LOWER)
#define RAISE         MO(_RAISE)
#define ADJUST        MO(_ADJUST)
#define GAMING        MO(_GAMING)

#define LALT_ESC      MT(MOD_LALT, KC_ESC)
#define LCTL_TAB      MT(MOD_LCTL, KC_TAB)
#define RALT_ARNG     MT(MOD_RALT, SE_ARNG)
#define RCTL_ADIA     MT(MOD_RCTL, SE_ADIA)

#define UNDO          LCTL(KC_Z)
#define REDO          LCTL(KC_Y)
#define CUT           LGUI(KC_X)
#define COPY          LGUI(KC_C)
#define PASTE         LGUI(KC_V)

#define MUTE          KC_KB_MUTE
#define VOLU          KC_KB_VOLUME_UP
#define VOLD          KC_KB_VOLUME_DOWN

#include "g/keymap_combo.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_NO,          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_ARNG,
    KC_NO,          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           SE_ODIA,        SE_ADIA,
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         SE_MINS,        SE_QUOT,
    OSM(MOD_LSFT),  KC_NO,          KC_NO,          ADJUST,         LOWER,          KC_SPC,         KC_NO,          RAISE,          ADJUST,         KC_NO,          KC_NO,          OSM(MOD_RSFT)
  ),

  [_GAMING] = LAYOUT_planck_grid(
    KC_ESC,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_ARNG,
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           SE_ODIA,        SE_ADIA,
    KC_LSFT,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         SE_MINS,        RSFT_SE_QUOT,
    KC_LCTL,        KC_LALT,        KC_LGUI,        ADJUST,         LOWER_BSPC,     KC_SPC,         KC_NO,          RAISE_ENT,      ADJUST,         KC_RGUI,        KC_RALT,        KC_RCTL
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_NO,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           SE_PLUS,
    KC_NO,          KC_NO,          KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       SE_AMPR,        SE_SLSH,        SE_LPRN,        SE_RPRN,        SE_EQL,         SE_QUES,
    KC_NO,          KC_NO,          KC_NO,          KC_PGUP,        KC_PGDN,        KC_NO,          SE_SECT,        SE_PIPE,        SE_LBRC,        SE_RBRC,        SE_AEQL,        SE_PLMN,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_NO,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           SE_PLUS,
    KC_NO,          KC_EXLM,        SE_DQUO,        KC_HASH,        SE_EURO,        KC_PERC,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_NO,
    SE_PILC,        SE_COPY,        SE_AT,          SE_PND,         SE_DLR,         SE_INFN,        KC_NO,          KC_PGDN,        KC_PGUP,        KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_NO,
    KC_NO,          KC_F11,         KC_F12,         KC_F13,         KC_F14,         KC_F15,         KC_F16,         KC_F17,         KC_F18,         KC_F19,         KC_F20,         KC_NO,
    KC_NO,          UNDO,           CUT,            COPY,           PASTE,          REDO,           KC_NO,          MUTE,           VOLD,           VOLU,           KC_NO,          KC_NO,
    KC_TRANSPARENT, CM_ON,          CM_OFF,         KC_NO,          TG(_GAMING),    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT
  ),
};
// clang-format on

//
// Led Matrix Stuff
//

#define HSV_WWHITE 50, 192, 255

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][4] = {
  [_BASE]     = {{HSV_OFF        }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     },
                 {HSV_OFF        }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     },
                 {HSV_OFF        }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     },
                 {HSV_WWHITE     }, {HSV_OFF        }, {HSV_OFF        }, {HSV_ORANGE     }, {HSV_CORAL      }, {HSV_OFF        }, /*              */ {HSV_SPRINGGREEN}, {HSV_ORANGE     }, {HSV_OFF        }, {HSV_OFF        }, {HSV_WWHITE     },},

  [_GAMING]   = {{HSV_BLUE       }, {HSV_BLUE       }, {HSV_WWHITE     }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       },
                 {HSV_BLUE       }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_WWHITE     }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       },
                 {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       }, {HSV_BLUE       },
                 {HSV_GREEN      }, {HSV_GREEN      }, {HSV_GREEN      }, {HSV_ORANGE     }, {HSV_CORAL      }, {HSV_OFF        }, /*              */ {HSV_SPRINGGREEN}, {HSV_ORANGE     }, {HSV_GREEN      }, {HSV_GREEN      }, {HSV_GREEN      },},

  [_LOWER]    = {{HSV_OFF        }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      },
                 {HSV_OFF        }, {HSV_OFF        }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      },
                 {HSV_OFF        }, {HSV_OFF        }, {HSV_OFF        }, {HSV_CORAL      }, {HSV_OFF        }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      }, {HSV_CORAL      },
                 {HSV_CORAL      }, {HSV_OFF        }, {HSV_OFF        }, {HSV_ORANGE     }, {HSV_OFF        }, {HSV_CORAL      }, /*              */ {HSV_OFF        }, {HSV_ORANGE     }, {HSV_OFF        }, {HSV_OFF        }, {HSV_CORAL      },},

  [_RAISE]    = {{HSV_OFF        }, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN},
                 {HSV_OFF        }, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_OFF        }, {HSV_OFF        },
                 {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_OFF        }, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_OFF        }, {HSV_OFF        }, {HSV_OFF        },
                 {HSV_SPRINGGREEN}, {HSV_OFF        }, {HSV_OFF        }, {HSV_ORANGE     }, {HSV_OFF        }, {HSV_SPRINGGREEN}, /*              */ {HSV_OFF        }, {HSV_ORANGE     }, {HSV_OFF        }, {HSV_OFF        }, {HSV_SPRINGGREEN},},

  [_ADJUST]   = {{HSV_OFF        }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_OFF        },
                 {HSV_OFF        }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_OFF        },
                 {HSV_OFF        }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_OFF        }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_ORANGE     }, {HSV_OFF        }, {HSV_OFF        },
                 {HSV_ORANGE     }, {HSV_GREEN      }, {HSV_RED        }, {HSV_OFF        }, {HSV_BLUE       }, {HSV_ORANGE     }, /*              */ {HSV_OFF        }, {HSV_OFF        }, {HSV_OFF        }, {HSV_OFF        }, {HSV_ORANGE     },},
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

