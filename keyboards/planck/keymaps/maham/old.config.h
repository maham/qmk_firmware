#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define RETRO_TAPPING

#undef IGNORE_MOD_TAP_INTERRUPT

#define USB_SUSPEND_WAKEUP_DELAY 0
#define HOLD_ON_OTHER_KEY_PRESS
#define RGB_MATRIX_STARTUP_SPD 60

#define COMBO_TERM 25
#define COMBO_VARIABLE_LEN
// #define COMBO_SHOULD_TRIGGER

#define LEADER_TIMEOUT 250
#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT

#define ONESHOT_TAP_TOGGLE 5
#define ONESHOT_TIMEOUT 3000
