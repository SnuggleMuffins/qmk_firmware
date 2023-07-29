#include QMK_KEYBOARD_H

enum planck_layers {
    _BASE,
    _SYMBOL,
    _GAME,
    _FKEYS,
    _ADJUST,
    _NAV,
};

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    BACKLIT,
    CTRL_ESC,
    NAV_SCLN,
    KVM_SWT,
    COPYADDR,
    SYMBOL,
    GAME,
    MD_CODE,
    MEH_ENT,
    LOCK,
};

#define FKEYS MO(_FKEYS)
// #define NAV MO(_NAV)

#define WORD_L LCTL(KC_LEFT)
#define WORD_R LCTL(KC_RGHT)

#define LINE_L LCTL(KC_LBRC)
#define LINE_R LCTL(KC_RBRC)

#define DEL_WRD LCTL(KC_BSPC)

#define TAB_L LCTL(LSFT(KC_TAB))
#define TAB_R LCTL(KC_TAB)

#define CUT   LCTL(KC_X)
#define COPY  LCTL(KC_C)
#define PASTE LCTL(KC_V)

#define EMOJI LCTL(LGUI(KC_SPC))

#define CAP_LST LGUI(LSFT(KC_7))        // Capture last screen region
#define CAP_IMG LGUI(LSFT(KC_6))        // Capture portion of screen
#define CAP_MOV LGUI(LSFT(KC_5))        // Capture video of screen

#define XBX_IMG LGUI(LALT(KC_PSCR))     // Capture portion of screen
#define XBX_MOV LGUI(LALT(KC_G))        // Capture last 30 seconds
