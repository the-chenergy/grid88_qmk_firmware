/**
 * defines the layers for grid88, a custom handwired keyboard.
 * 
 * qianlang chen
 * m 05/11/20
 */

#include "grid88.h"

/*******************************************************************************
 * key layer definitions
 ******************************************************************************/

/** the key layers used by this keyboard (base, numpad, function). */
enum key_layers { K_B, K_N, K_F };

/** the raw chars to be sent in the numpad layer. */
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

/** defines key functions for each layer. */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* the base layer. */
  [K_B] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,
    KC_BSLS,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,
    KC_NLCK,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
    OSL(K_F), KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,
    KC_LGUI,  KC_LCTL,  KC_HOME,  KC_PGUP,  KC_END,   KC_SPC,
                                  KC_PGDN,            KC_LALT,  KC_LSFT,
    
    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
    KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,
    KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_PSCR,
              KC_SPC,   KC_LEFT,  KC_UP,    KC_RGHT,  KC_RCTL,  KC_RALT,
    KC_RSFT,  KC_BSPC,            KC_DOWN
  ),
  
  /* the numpad layer.
   * (some raw chars are sent to avoid getting caught by ab's ui.) */
  [K_N] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    X(POU),   X(DOL),   X(LPA),   KC_P7,    KC_P8,    KC_P9,    X(RPA),
    _______,  _______,  X(PER),   KC_P4,    KC_P5,    KC_P6,    X(CAR),
    _______,  _______,  KC_PMNS,  KC_P1,    KC_P2,    KC_P3,    KC_PSLS,
    _______,  _______,  KC_PPLS,  X(COM),   KC_PDOT,  KC_P0,    KC_PAST,
    _______,  _______,  _______,  _______,  _______,  _______,
                                  _______,            KC_BSPC,  KC_PENT,
    
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
              _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,            _______
  ),
  
  /* the function layer. */
  [K_F] = LAYOUT(
    KC_DEL,   KC_F12,   KC_F11,   KC_F10,   KC_F9,    KC_F8,    KC_F7,
    KC_BSPC,  KC_EQL,   KC_MINS,  KC_0,     KC_9,     KC_8,     KC_7,
    KC_RBRC,  KC_LBRC,  KC_P,     KC_O,     KC_I,     KC_U,     KC_Y,
    KC_ENT,   KC_QUOT,  KC_SCLN,  KC_L,     KC_K,     KC_J,     KC_H,
    _______,  _______,  KC_SLSH,  KC_DOT,   KC_COMM,  KC_M,     KC_N,
    RGB_VAD,  RGB_VAI,  KC_LEFT,  KC_UP,    KC_RGHT,  RGB_MOD,
                                  KC_DOWN,            RGB_HUI,  RGB_SAI,
    
    _______,  _______,  _______,  _______,  KC_SLCK,  KC_PAUS,  KC_INS,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  RESET,
              KC_MPLY,  KC_MPRV,  KC_VOLU,  KC_MNXT,  KC_APP,   _______,
    KC_MSEL,  KC_MUTE,            KC_VOLD
  ),
};

/*******************************************************************************
 * led layer definitions
 * 
 * qmk allows us to customize the leds so that some leds light up when certain
 * layers are activated, without disturbing the animations other leds are in
 * play.
 ******************************************************************************/

/** the led layers used by this keyboard (caps, numpad, function). */
enum led_layers { L_C, L_N, L_F };

/** define the led layers. */

static const rgblight_segment_t PROGMEM caps_led_layer[] =
  RGBLIGHT_LAYER_SEGMENTS({6, 1, HSV_CYAN});

static const rgblight_segment_t PROGMEM num_led_layer[] =
  RGBLIGHT_LAYER_SEGMENTS({5, 1, HSV_YELLOW});

static const rgblight_segment_t PROGMEM fn_led_layer[] =
  RGBLIGHT_LAYER_SEGMENTS({7, 1, HSV_MAGENTA});

static const rgblight_segment_t* const PROGMEM led_layers[] =
  RGBLIGHT_LAYERS_LIST(caps_led_layer, num_led_layer, fn_led_layer);

/** runs after the keyboard initializes. registers the led layers. */
void keyboard_post_init_user(void)
{
  rgblight_layers = led_layers;
}

/*******************************************************************************
 * event callbacks / special function definitions
 *
 * qmk provides callbacks for events such as key-presses and layer-changes.
 * this gives us convenient ways to define special function for certain keys.
 ******************************************************************************/

/**
 * processes the event of a key-press or release by the user.
 * 
 * @param  keycode  the keycode which the user just pressed or released.
 * @param  record   object with info associated to the key-press/release.
 * 
 * @return  whether the default behavior of the keycode should still be
 *          triggered after it has been processed.
 */
bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
  switch (keycode)
  {
    /* let reset only work with fn+lshift+rshift. */
    case RESET:
    {
      if (record->event.pressed)
        return get_mods() == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT));
      
      return true;
    }
    
    default:
      return true;
  }
}

/**
 * processes the event where a one-shot (aka sticky) layer is activated or
 * deactivated.
 * 
 * @param  layer  the id of the layer being activated, or 0 if a one-shot layer
 *                is being deactivated.
 */
void oneshot_layer_changed_user(uint8_t layer)
{
  /* only light up the function layer indicator when the one-shot layer is
   * on (by doing the light-up check here rather than in
   * `layer_state_set_user`. */
  if (layer == K_F)
    rgblight_set_layer_state(L_F, true);
}

/**
 * processes the event that a key layer is activated or deactivated.
 * 
 * @param  state  object with info of each key layer.
 */
layer_state_t layer_state_set_user(layer_state_t state)
{
  if (!layer_state_cmp(state, K_F))
    rgblight_set_layer_state(L_F, false);
  
  return state;
}

/**
 * processes the event where a built-in indicator changes its state. built-in
 * indicators include the leds for capslock, numlock, and scroll lock.
 * 
 * @param  object with info of the built-in indicators.
 * 
 * @return  whether it should continue and process the event in the keyboard
 *          level.
 */
bool led_update_user(led_t led_state)
{
  rgblight_set_layer_state(L_C, led_state.caps_lock);
  rgblight_set_layer_state(L_N, led_state.num_lock);

  /* activate the numpad layer according to the state of numlock. */
  if (led_state.num_lock)
    layer_on(K_N);
  else
    layer_off(K_N);
  
  return true;
}
