/**
 * defines pin configurations for grid88, a custom handwired keyboard.
 *
 * qianlang chen
 * u 05/10/20
 */

#ifndef CONFIG_H
# define CONFIG_H

# include "config_common.h"

/* keyboard descriptions */
# define VENDOR_ID    0xFEED
# define PRODUCT_ID   0x0001
# define DEVICE_VER   0x0001
# define MANUFACTURER qianlang chen
# define PRODUCT      grid88
# define DESCRIPTION  a custom handwired split keyboard.

/* matrix configs */
# define MATRIX_ROWS     7
# define MATRIX_COLS     14
# define MATRIX_ROW_PINS { B0, B1, B2, B3, B7, D0, D1 }
# define MATRIX_COL_PINS { D2, D3, C6, C7, D7, B4, B5,                         \
                           B6, F7, F6, F5, F4, F1, F0 }
# define UNUSED_PINS

# define DIODE_DIRECTION COL2ROW

/* led strip configs */
# define RGB_DI_PIN D6

# ifdef RGB_DI_PIN
#   define RGBLIGHT_HUE_STEP   16
#   define RGBLIGHT_SAT_STEP   32
#   define RGBLIGHT_VAL_STEP   21
#   define RGBLIGHT_LIMIT_VAL  84
#   define RGBLIGHT_ANIMATIONS
# endif

# define RGBLIGHT_LAYERS

# include "grid88_led.h"

/* additional keyboard features */
# define DEBOUNCE 24

# define PREVENT_STUCK_MODIFIERS

# define LOCKING_SUPPORT_ENABLE
# define LOCKING_RESYNC_ENABLE

#endif /* CONFIG_H */
