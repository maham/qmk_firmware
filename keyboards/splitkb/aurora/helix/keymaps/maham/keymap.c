#include QMK_KEYBOARD_H

#include "keymap_swedish_mac_iso.h"
#include "features/mouse_turbo_click.h"
#include "color.h"

#define IS_MOD_ACTIVE(mod) (get_mods() & MOD_BIT(mod) || get_oneshot_mods() & MOD_BIT(mod))

enum maham_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTION,
};

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    SE_SECT,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           SE_PLUS,
    _______,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_ARNG,
    _______,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           SE_ODIA,        SE_ADIA,
    _______,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_LBRC,        KC_RBRC,        KC_N,           KC_M,           KC_COMM,        KC_DOT,         SE_MINS,        SE_QUOT,
    OSM(MOD_LSFT),  _______,        _______,        _______,        MO(_LOWER),     KC_SPC,         SH_MON,         _______,        KC_SPC,         MO(_RAISE),     _______,        _______,        _______,        OSM(MOD_RSFT)
  ),

  [_LOWER] = LAYOUT(
    _______,        KC_F11,         KC_F12,         KC_F13,         KC_F14,         KC_F15,                                         KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         _______,
    _______,        _______,        _______,        _______,        _______,        _______,                                        SE_AMPR,        SE_SLSH,        SE_LPRN,        SE_RPRN,        SE_EQL,         SE_QUES,
    _______,        _______,        KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,                                       _______,        SE_PIPE,        SE_LBRC,        SE_RBRC,        SE_AEQL,        SE_PLMN,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        SE_BSLS,        SE_LCBR,        SE_RCBR,        SE_NEQL,        SE_IQUE,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______
  ),

  [_RAISE] = LAYOUT(
    _______,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F16,         KC_F17,         KC_F18,         SE_SLSH,        SE_ASTR,        SE_MINS,
    SE_DEG,         SE_EXLM,        SE_DQUO,        SE_HASH,        SE_EURO,        SE_PERC,                                        _______,        _______,        KC_7,           KC_8,           KC_9,           SE_PLUS,
    SE_PILC,        SE_COPY,        SE_TM,          SE_PND,         SE_DLR,         SE_INFN,                                        _______,        _______,        KC_4,           KC_5,           KC_6,           SE_PLUS,
    SE_BULT,        SE_IEXL,        SE_YEN,         SE_CENT,        SE_PERM,        SE_BSLS,        _______,        _______,        _______,        _______,        KC_1,           KC_2,           KC_3,           KC_ENT,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        KC_0,           KC_COMM,        _______,        KC_ENT
  ),

  [_ADJUST] = LAYOUT(
    _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______
  ),

  [_FUNCTION] = LAYOUT(
    _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,
    _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______
  ),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}


//
// Led matrix stuff
//

#ifdef RGB_MATRIX_ENABLE

// const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][1] = {
//     [_QWERTY] = {
//         { 0,  1,  2,  3,  4,  5,  6,  7},
//         { 8,  9, 10, 11, 12, 13, 14, 15},
//         {16, 17, 18, 19, 20, 21, 22, 23},
//         {24, 25, 26, 27, 28, 29, 30, 31},
//         {32, 33, 34, 35, 36, 37, 38, 39}
//     },
// }

bool rbg_matrix_indicators_user(uint8_t ledMin, uint8_t ledMax) {
  rgb_matrix_set_color_all(RGB_GREEN);

  for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    rgb_matrix_set_color(i, 0xFF, i, i);
  }

  return false;
}

#endif

//
// Leader Key
//

#ifdef LEADER_ENABLE

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

#endif

//
// Caps Word
//

#ifdef CAPS_WORD_ENABLE

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

#endif
