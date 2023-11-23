SRC += muse.c
# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
STENO_ENABLE = no
KEYBOARD_SHARED_EP = yes
MOUSEKEY_ENABLE = no

LEADER_ENABLE = yes
SWAP_HANDS_ENABLE = no
COMBO_ENABLE = yes

VPATH += keyboards/gboards/
# SRC += g/engine.c

# Mouse turbo click
SRC += features/mouse_turbo_click.c
MOUSEKEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes

