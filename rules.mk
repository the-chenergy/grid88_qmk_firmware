# defines rules for grid88, a custom handwired keyboard.
#
# qianlang chen
# m 12/07/20

# controller configs
MCU   = atmega32u4
F_CPU = 16000000
ARCH  = AVR8
F_USB = $(F_CPU)

OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

BOOTLOADER = halfkay

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
MOUSEKEY_ENABLE   = no
NKRO_ENABLE       = yes
RGBLIGHT_ENABLE   = yes
SLEEP_LED_ENABLE  = no
UNICODE_ENABLE    = no
UNICODEMAP_ENABLE = no
