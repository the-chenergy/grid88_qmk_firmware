/**
 * defines the led layers for grid88, a custom handwired keyboard.
 * 
 * qianlang chen
 * u 05/10/20
 */

/** the ids of the leds used as indicators for activating different layers. */
static const int caps_led_indicator = 6;
static const int num_led_indicator  = 5;
static const int fn_led_indicator   = 7;

/** define led layers. */
static const rgblight_segment_t PROGMEM caps_led_layer[] =
  RGBLIGHT_LAYER_SEGMENTS({caps_led_indicator, 1, HSV_CYAN});

static const rgblight_segment_t PROGMEM num_led_layer[] =
  RGBLIGHT_LAYER_SEGMENTS({num_led_indicator, 1, HSV_YELLOW});

static const rgblight_segment_t PROGMEM fn_led_layer[] =
  RGBLIGHT_LAYER_SEGMENTS({fn_led_indicator, 1, HSV_MAGENTA});

static const rgblight_segment_t* const PROGMEM led_layers[] =
  RGBLIGHT_LAYERS_LIST(caps_led_layer, num_led_layer, fn_led_layer);

void keyboard_post_init_user(void)
{
  rgblight_layers = led_layers;
}

/** register led layers. */
layer_state_t layer_state_set_user(layer_state_t state)
{
  rgblight_set_layer_state(NUM, layer_state_cmp(state, NUM));
  rgblight_set_layer_state(FN, layer_state_cmp(state, FN));
  
  return state;
}

bool led_update_user(led_t led_state)
{
  rgblight_set_layer_state(0, led_state.caps_lock);
  return true;
}
