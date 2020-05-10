/**
 * defines the key layers for grid88, a custom handwired keyboard.
 * 
 * qianlang chen
 * u 05/10/20
 */

#include QMK_KEYBOARD_H

/** the layers used by this keyboard. */
enum layers { _B, _N, _F };

/** some raw chars to be sent in the numpad layer. */
enum custom_charcodes { POU, DOL, LPA, RPA, PER, CAR, COM };

const uint32_t PROGMEM unicode_map[] = {
  [POU] = (uint32_t)'#',
  [DOL] = (uint32_t)'$',
  [LPA] = (uint32_t)'(',
  [RPA] = (uint32_t)')',
  [PER] = (uint32_t)'%',
  [CAR] = (uint32_t)'^',
  [COM] = (uint32_t)',',
};

/** defines key functions in each layer. */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* the base layer. */
  [_B] = KEY_MAP(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    KC_BSLS, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
    TO(_N),  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    OSL(_F), KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
    KC_LGUI, KC_LCTL, KC_HOME, KC_PGUP, KC_END,  KC_SPC,
                               KC_PGDN,          KC_LALT, KC_LSFT,
    
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_PSCR,
             KC_SPC,  KC_LEFT, KC_UP,   KC_RGHT, KC_RCTL, KC_RALT,
    KC_RSFT, KC_BSPC,          KC_DOWN
  ),
  
  /* the numpad layer.
   * (some raw chars are sent to avoid getting caught by ab's ui.) */
  [_N] = KEY_MAP(
    _______, _______, _______, _______, _______, _______, _______,
    X(POU),  X(DOL),  X(LPA),  KC_P7,   KC_P8,   KC_P9,   X(RPA),
    _______, _______, X(PER),  KC_P4,   KC_P5,   KC_P6,   X(CAR),
    _______, _______, KC_PMNS, KC_P1,   KC_P2,   KC_P3,   KC_PSLS,
    _______, _______, KC_PPLS, X(COM),  KC_PDOT, KC_P0,   KC_PAST,
    _______, _______, _______, _______, _______, _______,
                               _______,          KC_BSPC, KC_PENT,
    
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,
    _______, _______,          _______
  ),
  
  /* the function layer. */
  [_F] = KEY_MAP(
    KC_DEL,  KC_F12,  KC_F11,  KC_F10,  KC_F9,   KC_F8,   KC_F7,
    KC_BSPC, KC_EQL,  KC_MINS, KC_0,    KC_9,    KC_8,    KC_7,
    KC_RBRC, KC_LBRC, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,
    KC_ENT,  KC_QUOT, KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,
    _______, RGB_MOD, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,
    RGB_VAD, RGB_VAI, KC_LEFT, KC_UP,   KC_RGHT, RGB_HUI,
                               KC_DOWN,          RGB_SAD, RGB_SAI,
    
    _______, _______, _______, _______, KC_SLCK, KC_PAUS, KC_INS,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, RESET,
             KC_MPLY, KC_MPRV, KC_VOLU, KC_MNXT, KC_APP,  _______,
    KC_MSEL, KC_MUTE,          KC_VOLD
  ),
};

/** an extremely stupid way for qmk to check if numlock is on. */
bool is_numlock_on;
void led_set_keymap(uint8_t usb_led)
{
  is_numlock_on = usb_led & (1 << USB_LED_NUM_LOCK);
}

/** processes keycodes and defines some custom functions to some keys. */
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
    case TO(_N):
    {
      if ((layer_state & (1 << _N)) == is_numlock_on)
	tap_code(KC_NLCK); /* activate numlock as appropriate */
      return true;
    }
    
    case RESET: /* reset key only works with fn+lshift+rshift */
    {
      if (record->event.pressed)
        return get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT));
      
      return true;
    }
    
    default:
      return true;
  }
}

#include "ledmap.c"
