#include QMK_KEYBOARD_H

#define _BASE 0
#define _MOVE 1
#define _HOME 2
#define _GAME 3

/* krashanoff
 * Simple and effective layout for GH60 Rev. C.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_all( /* 0: qwerty */
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LEAD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL, XXXXXXX,
        KC_LCTL, KC_LGUI, KC_LAPO,                   KC_SPC,                                      KC_RAPC, TG(_GAME), LT(_HOME, KC_APP),  LT(_MOVE, KC_RCTL)
    ),

    [_MOVE] = LAYOUT_all( /* 1: fn and others */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_RSFT, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______,                                     _______, _______, _______, _______
    ),

    [_HOME] = LAYOUT_all( /* 2: arrows */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_INS,  KC_HOME, KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_DEL,  KC_END,  KC_PGDN, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______,                                     _______, _______, _______, _______
    ),

    [_GAME] = LAYOUT_all( /* 3: Locks arrow keys to I, J, K, L */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______,                                     _______, _______, _______, _______
    ),

};

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Cancel (whoops!)
        SEQ_ONE_KEY(KC_BSPC) {
            return;
        }

        // CAPSLOCK
        SEQ_ONE_KEY(KC_C) {
            tap_code(KC_CAPS);
        }

        // Can we get an F in chat?
        SEQ_ONE_KEY(KC_F) {
            SEND_STRING("Can we get an F in chat?");
        }

        // Put keyboard into bootloader
        SEQ_FIVE_KEYS(KC_R, KC_E, KC_S, KC_E, KC_T) {
            reset_keyboard();
        }
    }
}
