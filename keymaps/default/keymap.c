/**
 * defines the key layers for grid88, a custom handwired keyboard.
 * 
 * qianlang chen
 * u 05/10/20
 */

#include "grid88.h"

/** the layers used by this keyboard. */
static enum layers { BASE, NUM, FN };

/** defines the chars sent for 'numpad keys.' */
const uint32_t PROGMEM unicode_map[] = {
  [N_0]  = (uint32_t)'0',
  [N_1]  = (uint32_t)'1',
  [N_2]  = (uint32_t)'2',
  [N_3]  = (uint32_t)'3',
  [N_4]  = (uint32_t)'4',
  [N_5]  = (uint32_t)'5',
  [N_6]  = (uint32_t)'6',
  [N_7]  = (uint32_t)'7',
  [N_8]  = (uint32_t)'8',
  [N_9]  = (uint32_t)'9',
  [COMM] = (uint32_t)',',
  [DOT]  = (uint32_t)'.',
  [PLUS] = (uint32_t)'+',
  [MINS] = (uint32_t)'-',
  [ASTR] = (uint32_t)'*',
  [SLSH] = (uint32_t)'/',
  [PERC] = (uint32_t)'%',
  [CART] = (uint32_t)'^',
  [POUD] = (uint32_t)'#',
  [DOLL] = (uint32_t)'$',
  [LPAR] = (uint32_t)'(',
  [RPAR] = (uint32_t)')',
};

/** defines key functions in each layer. */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  /** the base layer. */
  [BASE] = KEY_MAP(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
    KC_BSLS, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
    TO(NUM), KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    OSL(FN), KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
    KC_LGUI, KC_LCTL, KC_HOME, KC_PGUP, KC_END,  KC_SPC,
                               KC_PGDN,          KC_LALT, KC_LSFT,
    
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQU,  KC_BSPC,
    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_PSCN,
             KC_SPC,  KC_LEFT, KC_UP,   KC_RGHT, KC_RCTL, KC_RALT,
    KC_RSFT, KC_BSPC,          KC_DOWN
  ),
  
  /** the numpad layer. (raw chars are sent here to avoid caught by asui.) */
  [NUM] = KEY_MAP(
    _______, _______, _______, _______, _______, _______, _______,
    X(POUD), X(DOLL), X(LPAR), X(N_7),  X(N_8),  X(N_9),  X(RPAR),
    _______, _______, X(PERC), X(N_4),  X(N_5),  X(N_6),  X(CART),
    _______, _______, X(MINS), X(N_1),  X(N_2),  X(N_3),  X(SLSH),
    _______, _______, X(PLUS), X(COMM), X(DOT),  X(N_0),  X(ASTR),
    _______, _______, _______, _______, _______, _______,
                               _______,          KC_BSPC, KC_ENT,
    
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,
    _______, _______,          _______
  ),
  
  /** the function layer. */
  [FN] = KEY_MAP(
    KC_DEL,  KC_F12,  KC_F11,  KC_F10,  KC_F9,   KC_F8,   KC_F7,
    KC_BSPC, KC_EQU,  KC_MINS, KC_0,    KC_9,    KC_8,    KC_7,
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

/** processes keycodes and defines some custom functions to some keys. */
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
    case RESET: /* reset key only works with fn+lshift+rshift */
      if (record->event.pressed)
        return get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT));
      
      return true;
    
    default:
      return true;
  }
}

#include "ledmap.c"
