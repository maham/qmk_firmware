#include QMK_KEYBOARD_H

#include "keymap_swedish_pro_mac_iso.h"
// #include "keymap_swedish.h"
#include "color.h"
#include "transactions.h"

enum maham_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAMING,
};

#define LOWER         MO(_LOWER)
#define RAISE         MO(_RAISE)
#define ADJUST        MO(_ADJUST)

#define UNDO          LCTL(KC_Z)
#define REDO          LCTL(KC_Y)
#define CUT           LGUI(KC_X)
#define COPY          LGUI(KC_C)
#define PASTE         LGUI(KC_V)

#define MUTE          KC_KB_MUTE
#define VOLU          KC_KB_VOLUME_UP
#define VOLD          KC_KB_VOLUME_DOWN

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_NO,
    KC_NO,          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_ARNG,
    KC_NO,          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           SE_ODIA,        SE_ADIA,
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           CM_TOGG,        KC_NO,          KC_N,           KC_M,           KC_COMM,        KC_DOT,         SE_MINS,        SE_QUOT,
    OSM(MOD_LSFT),  KC_NO,          KC_NO,          ADJUST,         LOWER,          KC_SPC,         SH_MON,         KC_NO,          KC_SPC,         RAISE,          ADJUST,         KC_NO,          KC_NO,          OSM(MOD_RSFT)
  ),

  [_LOWER] = LAYOUT(
    KC_NO,          KC_F11,         KC_F12,         KC_F13,         KC_F14,         KC_F15,                                         KC_F16,         KC_F17,         KC_F18,         KC_F19,         KC_F20,         KC_NO,
    KC_NO,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           SE_PLUS,
    KC_NO,          KC_NO,          KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,                                       SE_AMPR,        SE_SLSH,        SE_LPRN,        SE_RPRN,        SE_EQL,         SE_QUES,
    KC_NO,          KC_NO,          KC_NO,          KC_PGUP,        KC_PGDN,        KC_NO,          KC_NO,          SE_TILD,        SE_SECT,        SE_PIPE,        SE_LBRC,        SE_RBRC,        KC_NO,          KC_NO,
    _______,        KC_NO,          KC_NO,          _______,        KC_NO,          _______,        KC_NO,          KC_NO,          _______,        KC_NO,          _______,        KC_NO,          KC_NO,          _______
  ),

  [_RAISE] = LAYOUT(
    KC_NO,          KC_F11,         KC_F12,         KC_F13,         KC_F14,         KC_F15,                                         KC_F16,         KC_F17,         KC_F18,         KC_F19,         KC_F20,         KC_NO,
    KC_NO,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_NO,
    KC_NO,          SE_EXLM,        SE_DQUO,        SE_HASH,        SE_EURO,        SE_PERC,                                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_NO,
    SE_TILD,        KC_NO,          SE_AT,          SE_PND,         SE_DLR,         KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_PGDN,        KC_PGUP,        KC_NO,          KC_NO,          KC_NO,
    _______,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          _______
  ),

  [_ADJUST] = LAYOUT(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          SE_DLR,         KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          UNDO,           CUT,            COPY,           PASTE,          REDO,           TG(_GAMING),    KC_NO,          KC_NO,          MUTE,           VOLD,           VOLU,           KC_NO,          KC_NO,
    _______,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          _______
  ),

  [_GAMING] = LAYOUT(
    KC_ESC,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_BSPC,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_ARNG,
    KC_NO,          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           SE_ODIA,        SE_ADIA,
    KC_LSFT,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           CM_TOGG,        SE_TILD,        KC_N,           KC_M,           KC_COMM,        KC_DOT,         SE_MINS,        SE_QUOT,
    KC_LCTL,        KC_LALT,        KC_LGUI,        ADJUST,         LOWER,          KC_SPC,         SH_MON,         KC_ENT,         KC_SPC,         RAISE,          ADJUST,         KC_RGUI,        KC_RALT,        KC_RCTL
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//
// Encoders
//

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // 0 is left-half encoder,
    // 1 is right-half encoder
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }

    return false;
}
#endif


//
// Disable controller LED
//

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

//
// RGB Matrix
//

#ifdef RGB_MATRIX_ENABLE

#define MHM_IS_MOD_ACTIVE(mod) (get_mods() & MOD_BIT(mod) || get_oneshot_mods() & MOD_BIT(mod))

static const uint8_t MAX_V = 0x80;

void mhm_rgb_matrix_set_color_all(uint8_t r, uint8_t g, uint8_t b) {
  for (uint8_t led = 6; led <= 37; led++) {
    rgb_matrix_set_color(led, r, g, b);
  }
  for (uint8_t led = 44; led <= 75; led++) {
    rgb_matrix_set_color(led, r, g, b);
  }
}

void mhm_rgb_underglow_set_color_all(uint8_t r, uint8_t g, uint8_t b) {
  for (uint8_t led = 0; led < 6; led++) {
    rgb_matrix_set_color(led, r, g, b);
  }
  for (uint8_t led = 38; led < 44; led++) {
    rgb_matrix_set_color(led, r, g, b);
  }
}

void mhm_set_color_hsv(uint8_t led, HSV hsv) {
  hsv.v = MAX_V;
  RGB rgb = hsv_to_rgb(hsv);
  rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
}

#define MHM_SET_COLOR_HSV(led, hsv) mhm_set_color_hsv(led, (HSV){hsv})

void mhm_set_color_hsv_range(uint8_t first_led, uint8_t last_led, HSV hsv) {
  if (first_led > last_led) {
    uint8_t tmp = first_led;
    first_led = last_led;
    last_led = tmp;
  }

  hsv.v = MAX_V;
  RGB rgb = hsv_to_rgb(hsv);

  for (uint8_t led = first_led; led <= last_led; led++) {
    rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
  }
}

#define MHM_SET_COLOR_HSV_RANGE(first_led, last_led, hsv) mhm_set_color_hsv_range(first_led, last_led, (HSV){hsv})

void mhm_set_color_hsv_all(HSV hsv) {
  hsv.v = MAX_V;
  RGB rgb = hsv_to_rgb(hsv);
  mhm_rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
}

#define MHM_SET_COLOR_HSV_ALL(hsv) mhm_set_color_hsv_all((HSV){hsv})

bool rgb_matrix_indicators_advanced_user(uint8_t ledMin, uint8_t ledMax) {
  mhm_rgb_underglow_set_color_all(0, 0, 0);

  if(is_swap_hands_on()) {
    MHM_SET_COLOR_HSV_ALL(HSV_CHARTREUSE);
  } else {
    mhm_set_color_hsv_all((HSV){30, 180, 255});
  }

  if (is_caps_word_on() && caps_word_remaining_time() > 0) {
    double progress = (double)caps_word_remaining_time() / CAPS_WORD_IDLE_TIMEOUT;
    MHM_SET_COLOR_HSV_RANGE(37, 37 - (uint8_t)(7 * progress), HSV_ORANGE);
    MHM_SET_COLOR_HSV_RANGE(75, 75 - (uint8_t)(7 * progress), HSV_ORANGE);
  }

  if (MHM_IS_MOD_ACTIVE(KC_LSFT)) {
    MHM_SET_COLOR_HSV(37, HSV_BLUE);
  }

  if (MHM_IS_MOD_ACTIVE(KC_RSFT)) {
    MHM_SET_COLOR_HSV(75, HSV_BLUE);
  }

  if (MHM_IS_MOD_ACTIVE(KC_LGUI)) {
    MHM_SET_COLOR_HSV(13, HSV_RED);
    MHM_SET_COLOR_HSV(19, HSV_RED);
  }

  if (MHM_IS_MOD_ACTIVE(KC_RGUI)) {
    MHM_SET_COLOR_HSV(51, HSV_RED);
    MHM_SET_COLOR_HSV(57, HSV_RED);
  }

  if (MHM_IS_MOD_ACTIVE(KC_LALT)) {
    MHM_SET_COLOR_HSV(14, HSV_GREEN);
    MHM_SET_COLOR_HSV(20, HSV_GREEN);
  }

  if (MHM_IS_MOD_ACTIVE(KC_RALT)) {
    MHM_SET_COLOR_HSV(52, HSV_GREEN);
    MHM_SET_COLOR_HSV(58, HSV_GREEN);
  }

  if (MHM_IS_MOD_ACTIVE(KC_LCTL)) {
    MHM_SET_COLOR_HSV(15, HSV_PURPLE);
    MHM_SET_COLOR_HSV(21, HSV_PURPLE);
  }

  if (MHM_IS_MOD_ACTIVE(KC_RCTL)) {
    MHM_SET_COLOR_HSV(53, HSV_PURPLE);
    MHM_SET_COLOR_HSV(59, HSV_PURPLE);
  }

  if (!is_combo_enabled()) {
    MHM_SET_COLOR_HSV(24, HSV_RED);
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
    } else if (leader_sequence_four_keys(KC_G, KC_S, KC_T, KC_P)) {
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

//
// Sync sides
//

// #define SPLIT_TRANSACTION_IDS_USER USER_SYNC_A

// typedef struct _master_to_slave_t {
//     int m2s_data;
// } master_to_slave_t;

// typedef struct _slave_to_master_t {
//     int s2m_data;
// } slave_to_master_t;

// void user_sync_a_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
//     const master_to_slave_t* m2s = (master_to_slave_t*)in_data;
//     slave_to_master_t *s2m = (slave_to_master_t*)out_data;
//     s2m->s2m_data = m2s->m2s_data + 5;
// }

// void keyboard_post_init_user(void) {
//     transaction_register_rpc(USER_SYNC_A, user_sync_a_slave_handler);
// }

//
// Housekeeping
//

// void housekeepint_task_user(void) {
//   if (is_keyboard_master()) {
//     static uint32_t last_sync = 0;
//     if (timer_elapsed32(last_sync) > 500) {
//       master_to_slave_t m2s = {6};
//       slave_to_master_t s2m = {0};

//       if (transaction_master_send(USER_SYNC_A, sizeof(m2s), &m2s, sizeof(s2m), &s2m)) {
//         last_sync = timer_read32();
//       } else {
//         dprintf("Sync failed\n");
//       }
//     }
//   }
// }
