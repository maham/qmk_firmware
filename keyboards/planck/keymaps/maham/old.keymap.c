#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_swedish_mac_iso.h"
#include "color.h"
#include "features/mouse_turbo_click.h"


#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

enum planck_keycodes {
  RGB_SLD = SAFE_RANGE,
  SE_LSPO,
  SE_RSPC,
  TURBO,
};


enum planck_layers {
  _GAMING,
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
#include "g/keymap_engine.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_GAMING] = LAYOUT_planck_grid(
    KC_ESC,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_ARNG,
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           SE_ODIA,        SE_ADIA,
    LSFT_SE_SECT,   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         SE_MINS,        RSFT_SE_QUOT,
    OSM(MOD_LCTL),  OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LGUI),  LOWER_BSPC,     KC_SPC,         KC_NO,          RAISE_ENT,      OSM(MOD_RGUI),  OSM(MOD_RALT),  OSM(MOD_RCTL),  OSM(MOD_RCTL)
  ),

  [_BASE] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_ARNG,
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           SE_ODIA,        SE_ADIA,
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         SE_MINS,        SE_QUOT,
    OSM(MOD_LSFT),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LOWER,          KC_SPC,         KC_NO,          RAISE,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSM(MOD_RSFT)
  ),

  [_LOWER] = LAYOUT_planck_grid(
    TURBO,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           SE_PLUS,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, SE_PIPE,        SE_LBRC,        SE_RBRC,        SE_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP,        KC_PGDOWN,      KC_TRANSPARENT, KC_TRANSPARENT, SE_TILD,        SE_LCBR,        SE_RCBR,        SE_CIRC,        SE_GRV,
    KC_TRANSPARENT, CMB_ON,         CMB_OFF,        OSL(_FUNCTION), KC_NO,          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_NONUS_BSLASH,    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           SE_PLUS,
    S(KC_NONUS_BSLASH), KC_EXLM,        SE_DQUO,        KC_HASH,        SE_EURO,        KC_PERC,        SE_AMPR,        SE_SLSH,        SE_LPRN,        SE_RPRN,        SE_EQL,         SE_QUES,
    A(KC_NONUS_BSLASH), SE_AT,          SE_TM,          SE_PND,         SE_DLR,         KC_TRANSPARENT, SE_SECT,        KC_NONUS_HASH,  SE_LBRC,        SE_RBRC,        KC_TRANSPARENT, SE_TILD,
    KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, AU_ON,          AU_OFF,         AU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,        RGB_VAI,        RGB_VAD,        KC_TRANSPARENT, RESET,
    KC_TRANSPARENT, KC_TRANSPARENT, MU_ON,          MU_OFF,         MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, RGB_MOD,        RGB_HUI,        RGB_HUD,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_FUNCTION] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F13,         KC_F14,         KC_F15,         KC_F16,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_F17,         KC_F18,         KC_F19,         KC_F20,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_F21,         KC_F22,         KC_F23,         KC_F24,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, CMB_TOG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, TO(_GAMING),    TO(_BASE),      KC_TRANSPARENT, KC_TRANSPARENT
  ),

};

// extern bool g_suspend_state
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();

//   debug_enable = true;
//   debug_matrix = true;
//   debug_keyboard = true;
}

// const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
//   [_GAMING]   = {{HSV_BLUE      }, {HSV_BLUE      }, {HSV_WHITE     }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      },
//                  {HSV_BLUE      }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      },
//                  {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      }, {HSV_BLUE      },
//                  {HSV_GREEN     }, {HSV_GREEN     }, {HSV_GREEN     }, {HSV_GREEN     }, {HSV_GREEN     }, {HSV_GREEN     }, /*             */ {HSV_GREEN     }, {HSV_GREEN     }, {HSV_GREEN     }, {HSV_GREEN     }, {HSV_GREEN     },},

//   [_BASE]     = {{HSV_OFF       }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     },
//                  {HSV_OFF       }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     },
//                  {HSV_OFF       }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     }, {HSV_WHITE     },
//                  {HSV_WHITE     }, {HSV_OFF       }, {HSV_OFF       }, {HSV_OFF       }, {HSV_PINK      }, {HSV_OFF       }, /*             */ {HSV_CHARTREUSE}, {HSV_OFF       }, {HSV_OFF       }, {HSV_OFF       }, {HSV_WHITE     },},

//   [_LOWER]    = {{HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      },
//                  {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      },
//                  {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      },
//                  {HSV_PINK      }, {HSV_GREEN     }, {HSV_RED       }, {HSV_ORANGE    }, {HSV_PINK      }, {HSV_PINK      }, /*             */ {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      }, {HSV_PINK      },},

//   [_RAISE]    = {{HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE},
//                  {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE},
//                  {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE},
//                  {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, /*             */ {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE}, {HSV_CHARTREUSE},},

//   [_ADJUST]   = {{200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133},
//                  {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133},
//                  {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133},
//                  {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, {200, 167, 255}, /*            */ {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}, {  0,   3, 133}},

// //   [_STENO]    = {{212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255},
// //                  {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255},
// //                  {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255},
// //                  {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, /*            */ {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, {212, 193, 255}, { 25, 250, 248}},

//   [_FUNCTION] = {{HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    },
//                  {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    },
//                  {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    },
//                  {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_CHARTREUSE}, {HSV_ORANGE    }, {HSV_ORANGE    }, {HSV_ORANGE    }, /*             */ {HSV_ORANGE    }, {HSV_BLUE      }, {HSV_WHITE     }, {HSV_ORANGE    }, {HSV_ORANGE    },},

// };

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (/* g_suspend_state || */ keyboard_config.disable_layer_led) { return; }
//   set_layer_color(biton32(layer_state));
  switch (biton32(layer_state)) {
    case _GAMING:
      set_layer_color(_GAMING);
      break;
    case _BASE:
      set_layer_color(_BASE);
      break;
    case _LOWER:
      set_layer_color(_LOWER);
      break;
    case _RAISE:
      set_layer_color(_RAISE);
      break;
    case _ADJUST:
      set_layer_color(_ADJUST);
      break;
    case _FUNCTION:
      set_layer_color(_FUNCTION);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

  if (!process_mouse_turbo_click(keycode, record, TURBO)) { return false; }

  switch (keycode) {
    case SE_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
      return false;
    case SE_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }

  return true;
}

#ifdef SWAP_HANDS_ENABLE
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    {{ 5,  4}, { 4,  4}, { 3,  4}, { 2,  4}, { 1,  4}, { 0,  4}},
    {{ 5,  5}, { 4,  5}, { 3,  5}, { 2,  5}, { 1,  5}, { 0,  5}},
    {{ 5,  6}, { 4,  6}, { 3,  6}, { 2,  6}, { 1,  6}, { 0,  6}},

    {{ 4,  3}, { 3,  3}, { 2,  7}, { 1,  3}, { 0,  4}, { 0,  0}},

    {{ 5,  0}, { 4,  0}, { 3,  0}, { 2,  0}, { 1,  0}, { 0,  0}},
    {{ 5,  1}, { 4,  1}, { 3,  1}, { 2,  1}, { 1,  1}, { 0,  1}},
    {{ 5,  2}, { 4,  2}, { 3,  2}, { 2,  2}, { 1,  2}, { 0,  2}},

    {{ 4,  7}, { 3,  7}, { 2,  3}, { 1,  7}, { 0,  7}, { 5,  7}},
};
#endif

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

// void matrix_scan_user(void) {
// #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//         if (muse_counter == 0) {
//             uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//             if (muse_note != last_muse_note) {
//                 stop_note(compute_freq_for_midi_note(last_muse_note));
//                 play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                 last_muse_note = muse_note;
//             }
//         }
//         muse_counter = (muse_counter + 1) % muse_tempo;
//     }
// #endif
// }

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void matrix_init_user() {
//   steno_set_mode(STENO_MODE_GEMINI);
}

//
// Leader key
//

// LEADER_EXTERNS();
void leader_start_user(void) {
}

// void matrix_scan_user(void) {
// #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//         if (muse_counter == 0) {
//             uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//             if (muse_note != last_muse_note) {
//                 stop_note(compute_freq_for_midi_note(last_muse_note));
//                 play_note(compute_freq_for_midi_note(muse_note), 0xF);
//                 last_muse_note = muse_note;
//             }
//         }
//         muse_counter = (muse_counter + 1) % muse_tempo;
//     }
// #endif

//     LEADER_DICTIONARY() {
//         leading = false;
//         leader_end();

//         SEQ_ONE_KEY(KC_T) {
//             SEND_STRING(SS_LGUI("t"));
//         }

//         SEQ_ONE_KEY(KC_R) {
//             SEND_STRING(SS_LSFT("8"));
//         }

//         SEQ_ONE_KEY(KC_U) {
//             SEND_STRING(SS_LSFT("9"));
//         }

//         SEQ_ONE_KEY(KC_E) {
//             SEND_STRING("`");
//         }

//         SEQ_ONE_KEY(KC_I) {
//             SEND_STRING(SS_LSFT("`"));
//         }

//         SEQ_ONE_KEY(KC_W) {
//             SEND_STRING(SS_LALT("8"));
//         }

//         SEQ_ONE_KEY(KC_O) {
//             SEND_STRING(SS_LALT("9"));
//         }

//         SEQ_ONE_KEY(KC_Q) {
//             SEND_STRING(SS_LSFT(SS_LALT("8")));
//         }

//         SEQ_ONE_KEY(KC_P) {
//             SEND_STRING(SS_LSFT(SS_LALT("9")));
//         }

//         SEQ_ONE_KEY(KC_F) {
//             SEND_STRING("for ");
//             SEND_STRING(SS_LSFT("8"));
//         }

//         SEQ_TWO_KEYS(KC_I, KC_F) {
//             SEND_STRING("if ");
//             SEND_STRING(SS_LSFT("8"));
//         }

//         SEQ_TWO_KEYS(KC_F, KC_N) {
//             SEND_STRING("function");
//             SEND_STRING(SS_LSFT("8"));
//         }

//         SEQ_TWO_KEYS(KC_F, KC_U) {
//             SEND_STRING("Future");
//         }

//         SEQ_TWO_KEYS(KC_F, KC_I) {
//             SEND_STRING("final ");
//         }

//         SEQ_TWO_KEYS(KC_R, KC_E) {
//             SEND_STRING("required ");
//         }

//         SEQ_TWO_KEYS(KC_E, KC_Q) {
//             SEND_STRING(" "SS_LSFT("00")" ");
//         }

//         SEQ_TWO_KEYS(KC_L, KC_E) {
//             SEND_STRING(" `"SS_LSFT("0")" ");
//         }

//         SEQ_TWO_KEYS(KC_G, KC_E) {
//             SEND_STRING(" "SS_LSFT("`0")" ");
//         }

//         SEQ_TWO_KEYS(KC_I, KC_S) {
//             SEND_STRING(" "SS_LSFT("0")" ");
//         }

//         SEQ_TWO_KEYS(KC_G, KC_S) {
//             SEND_STRING("git status");
//         }

//         SEQ_TWO_KEYS(KC_G, KC_S) {
//             SEND_STRING("git status");
//         }

//         SEQ_TWO_KEYS(KC_G, KC_C) {
//             SEND_STRING("git commit ");
//         }

//         SEQ_THREE_KEYS(KC_G, KC_C, KC_A) {
//             SEND_STRING("git commit -a");
//         }

//         SEQ_THREE_KEYS(KC_G, KC_S, KC_T) {
//             SEND_STRING("git stash");
//         }

//         SEQ_THREE_KEYS(KC_G, KC_S, KC_P) {
//             SEND_STRING("git stash pop");
//         }
//     }
// }
void leader_end_user(void) {

        if (leader_sequence_one_key(KC_T)) {
            SEND_STRING(SS_LGUI("t"));
        } else if (leader_sequence_one_key(KC_R)) {
            SEND_STRING(SS_LSFT("8"));
        } else if (leader_sequence_one_key(KC_U)) {
            SEND_STRING(SS_LSFT("9"));
        } else if (leader_sequence_one_key(KC_E)) {
            SEND_STRING("`");
        } else if (leader_sequence_one_key(KC_I)) {
            SEND_STRING(SS_LSFT("`"));
        } else if (leader_sequence_one_key(KC_W)) {
            SEND_STRING(SS_LALT("8"));
        } else if (leader_sequence_one_key(KC_O)) {
            SEND_STRING(SS_LALT("9"));
        } else if (leader_sequence_one_key(KC_Q)) {
            SEND_STRING(SS_LSFT(SS_LALT("8")));
        } else if (leader_sequence_one_key(KC_P)) {
            SEND_STRING(SS_LSFT(SS_LALT("9")));
        } else if (leader_sequence_one_key(KC_F)) {
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
        } else if (leader_sequence_two_keys(KC_E, KC_Q)) {
            SEND_STRING(" "SS_LSFT("00")" ");
        } else if (leader_sequence_two_keys(KC_L, KC_E)) {
            SEND_STRING(" `"SS_LSFT("0")" ");
        } else if (leader_sequence_two_keys(KC_G, KC_E)) {
            SEND_STRING(" "SS_LSFT("`0")" ");
        } else if (leader_sequence_two_keys(KC_I, KC_S)) {
            SEND_STRING(" "SS_LSFT("0")" ");
        } else if (leader_sequence_two_keys(KC_G, KC_S)) {
            SEND_STRING("git status");
        } else if (leader_sequence_two_keys(KC_G, KC_S)) {
            SEND_STRING("git status");
        } else if (leader_sequence_two_keys(KC_G, KC_C)) {
            SEND_STRING("git commit ");
        } else if (leader_sequence_three_keys(KC_G, KC_C, KC_A)) {
            SEND_STRING("git commit -a");
        } else if (leader_sequence_three_keys(KC_G, KC_S, KC_T)) {
            SEND_STRING("git stash");
        } else if (leader_sequence_three_keys(KC_G, KC_S, KC_P)) {
            SEND_STRING("git stash pop");
        }
    }
}
