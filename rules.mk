# defines rules for grid88, a custom handwired keyboard.
#
# qianlang chen
# u 05/10/20

# controller configs
MCU = atmega32u4
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT
OPT_DEFS += -DBOOTLOADER_SIZE=4096

# build options
AUDIO_ENABLE      = no
BACKLIGHT_ENABLE  = no
BLUETOOTH_ENABLE  = no
BOOTMAGIC_ENABLE  = yes
COMMAND_ENABLE    = no
CONSOLE_ENABLE    = no
EXTRAKEY_ENABLE   = yes
FAUXCLICKY_ENABLE = no
HD44780_ENABLE    = no
MIDI_ENABLE       = no
MOUSEKEY_ENABLE   = yes
NKRO_ENABLE       = yes
RGBLIGHT_ENABLE   = yes
SLEEP_LED_ENABLE  = no
UNICODE_ENABLE    = yes
UNICODEMAP_ENABLE = yes
