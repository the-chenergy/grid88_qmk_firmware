/**
 * defines the layers for grid88, a custom handwired keyboard.
 *
 * v0.3:
 *   - added basic support of the asianboii's ui layout.
 *   - fixed numpad problem of outputting unicode junk for punctuation.
 *
 * qianlang chen
 * t 12/08/20
 *
 * ------------------------
 *
 * initial version
 *
 * m 05/11/20
 */

#include "grid88.h"

/*******************************************************************************
 * key layer definitions
 ******************************************************************************/

/** the key layers used by this keyboard. */
enum key_layers { K_B, K_A, K_As, K_Am, K_Af, K_N, K_F };

/**
 * the keycodes used in custom functions to communicate directly between a
 * keyboard layer and the key event-processing function.
 */
enum custom_keycodes { C_XXXX = SAFE_RANGE, C_KAON, C_KAOF, C_SKAS, C_RMOD };

/* clang-format off */

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

  /* the asianboii's ui layout layer. */
  [K_A] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,      KC_F6,
    S(KC_3),  S(KC_4),  S(KC_7),  S(KC_8),  KC_EQL,   S(KC_LBRC), S(KC_RBRC),
    KC_CAPS,  LT(K_Am, KC_TAB),
                        KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,       KC_Y,
    KC_NLCK,  KC_MINS,  KC_A,     KC_O,     KC_E,     KC_I,       KC_U,
    OSL(K_F), LM(K_Am, MOD_LCTL),
                        KC_SCLN,  KC_Q,     KC_J,     KC_K,       KC_X,
    LM(K_Am, MOD_LGUI),
              LT(K_Af, KC_ENT),
                        KC_HOME,  KC_PGUP,  KC_END,   LT(K_As, KC_SPC),
                                  KC_PGDN,            LM(K_Am, MOD_LALT),
                                                             LM(K_Am, MOD_LCTL),
    
    KC_F7,      KC_F8,     KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_DEL,
    S(KC_COMM), S(KC_DOT), S(KC_9),  S(KC_0),  KC_LBRC,  KC_RBRC,    KC_BSPC,
    KC_F,       KC_G,      KC_C,     KC_R,     KC_L,     KC_SLSH,    KC_BSLS,
    KC_D,       KC_H,      KC_T,     KC_N,     KC_S,     S(KC_MINS), KC_ENT,
    KC_B,       KC_M,      KC_W,     KC_V,     KC_Z,     LM(K_Am, MOD_RCTL),
                                                                     KC_PSCR,
                LT(K_As, KC_SPC),
                           KC_LEFT,  KC_UP,    KC_RGHT,
                                                         LT(K_Af, KC_ENT),
                                                             LM(K_Am, MOD_LSFT),
    KC_CAPS,    KC_BSPC,             KC_DOWN
  ),

  /* the asianboii's ui layout shifted layer. */
  [K_As] = LAYOUT(
    S(KC_ESC),  S(KC_F1),  S(KC_F2),   S(KC_F3),   S(KC_F4),  S(KC_F5),S(KC_F6),
    S(KC_GRV),  KC_1,      KC_2,       KC_3,       KC_4,      KC_5,     KC_6,
    S(KC_CAPS), S(KC_TAB), S(KC_QUOT), S(KC_SLSH), S(KC_1),   S(KC_P),  S(KC_Y),
    S(KC_NLCK), S(KC_EQL), S(KC_A),    S(KC_O),    S(KC_E),   S(KC_I),  S(KC_U),
    OSL(K_F),   _______,   S(KC_SCLN), S(KC_Q),    S(KC_J),   S(KC_K),  S(KC_X),
    _______,    _______,   S(KC_HOME), S(KC_PGUP), S(KC_END), _______,
                                       S(KC_PGDN),            _______,  _______,
    
    S(KC_F7),   S(KC_F8),  S(KC_F9), S(KC_F10),S(KC_F11),S( KC_F12), S(KC_DEL),
    KC_7,       KC_8,      KC_9,     KC_0,     S(KC_6),  KC_GRV,     S(KC_BSPC),
    S(KC_F),    S(KC_G),   S(KC_C),  S(KC_R),  S(KC_L),  S(KC_5),    S(KC_2),
    S(KC_D),    S(KC_H),   S(KC_T),  S(KC_N),  S(KC_S),  S(KC_BSLS), S(KC_ENT),
    S(KC_B),    S(KC_M),   S(KC_W),  S(KC_V),  S(KC_Z),  _______,    S(KC_PSCR),
                _______,    S(KC_LEFT),S(KC_UP),S(KC_RGHT),_______,   _______,
    _______,    S(KC_BSPC),           S(KC_DOWN)
  ),

  /* the asianboii's ui layout modifier-activated layer. */
  [K_Am] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,
    KC_BSLS,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,
    KC_NLCK,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
    OSL(K_F), _______,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,
    _______,  _______,  KC_HOME,  KC_PGUP,  KC_END,   KC_LSFT,
                                  KC_PGDN,            _______,  _______,
    
    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
    KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,
    KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_PSCR,
              KC_LSFT,   KC_LEFT,  KC_UP,    KC_RGHT,  _______,  _______,
    _______,  KC_BSPC,            KC_DOWN
  ),

  /* the asianboii's ui layout function layer. */
  [K_Af] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  C(KC_LEFT),KC_UP,   C(KC_RGHT),_______,
    _______,  _______,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,
    _______,  _______,  _______,  _______,  KC_PGDN,  KC_PGUP,  _______,
    _______,  _______,  _______,  _______,  _______,  KC_LSFT,
                                  _______,            _______,  _______,
    
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
              KC_LSFT,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,            _______
  ),

  /* the numpad layer.
   * (some raw chars are sent to avoid getting caught by ab's ui.) */
  [K_N] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    S(KC_3),  S(KC_4),  S(KC_9),  KC_P7,    KC_P8,    KC_P9,    S(KC_0),
    _______,  _______,  S(KC_5),  KC_P4,    KC_P5,    KC_P6,    S(KC_6),
    _______,  _______,  KC_PMNS,  KC_P1,    KC_P2,    KC_P3,    KC_PSLS,
    _______,  _______,  KC_PPLS,  KC_PCMM,  KC_PDOT,  KC_P0,    KC_PAST,
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
    _______,  KC_LSFT,  KC_SLSH,  KC_DOT,   KC_COMM,  KC_M,     KC_N,
    RGB_VAD,  RGB_VAI,  KC_LEFT,  KC_UP,    KC_RGHT,  RGB_MOD,
                                  KC_DOWN,            RGB_HUI,  RGB_SAI,
    
    C_KAON,   C_KAOF,   C_SKAS,   C_RMOD,   KC_SLCK,  KC_PAUS,  KC_INS,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  KC_RSFT,  RESET,
              KC_MPLY,  KC_MPRV,  KC_VOLU,  KC_MNXT,  KC_APP,   _______,
    KC_MSEL,  KC_MUTE,            KC_VOLD
  ),
};

/* clang-format on */

/*******************************************************************************
 * led layer definitions
 *
 * qmk allows us to customize the leds so that some leds light up when certain
 * layers are activated, without disturbing the animations other leds are in
 * play.
 ******************************************************************************/

/** the led layers used by this keyboard. */
enum led_layers { L_C, L_N, L_F, L_0, L_1 };

/** the "on" and "off" blinkers. */
static const int on_off_layers[] = {L_0, L_1};

/* define the led layers. */

/** L_C: capslock indicator (static). */
static const rgblight_segment_t PROGMEM caps_led_layer[] =
    RGBLIGHT_LAYER_SEGMENTS({5, 1, HSV_CYAN});

/** L_N: numlock indicator (static). */
static const rgblight_segment_t PROGMEM num_led_layer[] =
    RGBLIGHT_LAYER_SEGMENTS({4, 1, HSV_YELLOW});

/** L_F: function layer one-shot indicator (static). */
static const rgblight_segment_t PROGMEM fn_led_layer[] =
    RGBLIGHT_LAYER_SEGMENTS({6, 1, HSV_MAGENTA});

/** L_1: "yes/on/enabled" indicator (blink). */
static const rgblight_segment_t PROGMEM off_led_layer[] =
    RGBLIGHT_LAYER_SEGMENTS({4, 2, HSV_RED});

/** L_0: "no/off/disabled" indicator (blink). */
static const rgblight_segment_t PROGMEM on_led_layer[] =
    RGBLIGHT_LAYER_SEGMENTS({4, 2, HSV_GREEN});

static const rgblight_segment_t* const PROGMEM led_layers[] =
    RGBLIGHT_LAYERS_LIST(caps_led_layer, num_led_layer, fn_led_layer,
                         off_led_layer, on_led_layer);

/** runs after the keyboard initializes. registers the led layers. */
void keyboard_post_init_user(void) { rgblight_layers = led_layers; }

/** the default duration of an indication-blink in ms. */
static const int BLINK_DURATION = 1042;

/*******************************************************************************
 * event callbacks / special function definitions
 *
 * qmk provides callbacks for events such as key-presses and layer-changes.
 * this gives us convenient ways to define special functions for certain keys.
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
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    /* let the second press of the fn-key disable the oneshot layer. */
    case OSL(K_F): {
      if (record->event.pressed && layer_state_is(K_F)) {
        layer_off(K_F);
        return false;
      }

      return true;
    }

    /********************************
     * define custom key-functions.
     *******************************/

    /* turn the asui on. */
    case C_KAON: {
      layer_on(K_A);
      layer_off(K_F);

      rgblight_blink_layer(on_off_layers[1], BLINK_DURATION);

      return false;
    }

    /* turn the asui off. */
    case C_KAOF: {
      layer_off(K_A);
      layer_off(K_As);
      layer_off(K_Am);
      layer_off(K_Af);
      layer_off(K_F);

      rgblight_blink_layer(on_off_layers[0], BLINK_DURATION);

      return false;
    }

    /* show by blinking accordingly whether the asui is currently on. */
    case C_SKAS: {
      rgblight_blink_layer(on_off_layers[layer_state_is(K_A)], BLINK_DURATION);
      layer_off(K_F);

      return false;
    }

    /* release all modifiers. */
    case C_RMOD: {
      clear_mods();
      layer_off(K_F);

      return false;
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
void oneshot_layer_changed_user(uint8_t layer) {
  /* only light up the function layer indicator when the one-shot layer is
   * on (by doing the light-up check here rather than in
   * `layer_state_set_user`). */
  if (layer == K_F) rgblight_set_layer_state(L_F, true);
}

/**
 * processes the event that a key layer is activated or deactivated.
 *
 * @param  state  object with info of each key layer.
 */
layer_state_t layer_state_set_user(layer_state_t state) {
  if (!layer_state_cmp(state, K_F)) rgblight_set_layer_state(L_F, false);

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
bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(L_C, led_state.caps_lock);
  rgblight_set_layer_state(L_N, led_state.num_lock);

  /* activate the numpad layer according to the state of numlock. */
  if (led_state.num_lock)
    layer_on(K_N);
  else
    layer_off(K_N);

  return true;
}
