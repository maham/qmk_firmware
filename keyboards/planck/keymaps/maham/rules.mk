# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE		= no
COMMAND_ENABLE		= no
RGBLIGHT_ENABLE		= no
RGB_MATRIX_ENABLE	= yes
WEBUSB_ENABLE		= yes
ORYX_ENABLE			= yes

SWAP_HANDS_ENABLE	= yes
CAPS_WORD_ENABLE	= yes

# Combos
VPATH				+= keyboards/gboards/
COMBO_ENABLE		= yes
# SRC					+= g/engine.c

# Mouse turbo click
# SRC += features/mouse_turbo_click.c
# MOUSEKEY_ENABLE = yes
# DEFERRED_EXEC_ENABLE = yes
