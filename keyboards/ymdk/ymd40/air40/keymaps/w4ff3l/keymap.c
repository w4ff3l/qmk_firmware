/* Copyright 2022 Dennis Kruyt (dennis@kruyt.org)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

void custom_mod_t(bool pressed, uint16_t key_hold, char key_tap);

enum custom_keycodes {
    LHYPER_C_T = SAFE_RANGE,
    RHYPER_C_T,
    LALT_C_T,
    RALT_C_T,
};

enum layer_names {
    _BASE,
    _RAISE,
    _LOWER,
    _RGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // COLEMAK
    [_BASE] = LAYOUT_ortho_4x12_1x2uC(
        KC_TAB,         KC_Q,       KC_W,     KC_F,    KC_P,       KC_G,   KC_J, KC_L,       KC_U,    KC_Y,     KC_SEMICOLON, KC_QUOT,
        LCTL_T(KC_ESC), KC_A,       KC_R,     KC_S,    KC_T,       KC_D,   KC_H, KC_N,       KC_E,    KC_I,     KC_O,         RCTL_T(KC_ENT),
        SC_LSPO,        KC_Z,       KC_X,     KC_C,    KC_V,       KC_B,   KC_K, KC_M,       KC_COMM, KC_DOT,   KC_SLSH,      SC_RSPC,
        KC_LBRC,        LHYPER_C_T, LALT_C_T, KC_LGUI, MO(_RAISE),    KC_SPC,    MO(_LOWER), KC_RGUI, RALT_C_T, RHYPER_C_T,   KC_RBRC
        ),
    // QWERTY
//    [_BASE] = LAYOUT_ortho_4x12_1x2uC(
//        KC_TAB,         KC_Q,       KC_W,     KC_E,    KC_R,       KC_T,   KC_Y, KC_U,       KC_I,    KC_O,     KC_P,       KC_QUOT,
//        LCTL_T(KC_ESC), KC_A,       KC_S,     KC_D,    KC_F,       KC_G,   KC_H, KC_J,       KC_K,    KC_L,     KC_SCLN,    RCTL_T(KC_ENT),
//        SC_LSPO,        KC_Z,       KC_X,     KC_C,    KC_V,       KC_B,   KC_N, KC_M,       KC_COMM, KC_DOT,   KC_SLSH,    SC_RSPC,
//        KC_LBRC,        LHYPER_C_T, LALT_C_T, KC_LGUI, MO(_RAISE),    KC_SPC,    MO(_LOWER), KC_RGUI, RALT_C_T, RHYPER_C_T, KC_RBRC
//        ),
    [_RAISE] = LAYOUT_ortho_4x12_1x2uC(
        KC_GRV,         KC_F1,       KC_F2,     KC_F3,   KC_F4,        KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_F10,     KC_QUOT,
        LCTL_T(KC_ESC), KC_1,        KC_2,      KC_3,    KC_4,         KC_5,    KC_6,    KC_7,     KC_8,    KC_9,     KC_0,       RCTL_T(KC_ENT),
        SC_LSPO,        KC_MINUS,    KC_EQUAL,  KC_GRV,  KC_BACKSLASH, _______, _______, _______,  _______, _______,  _______,    SC_RSPC,
        KC_LBRC,        LHYPER_C_T,  LALT_C_T,  KC_LGUI, _______,          KC_BSPC,      MO(_RGB), KC_RGUI, RALT_C_T, RHYPER_C_T, KC_RBRC
        ),
    [_LOWER] = LAYOUT_ortho_4x12_1x2uC(
        KC_GRV,         KC_F11,      KC_F12,    KC_F13,  KC_F14,    KC_F15,  KC_F16,  KC_F17,   KC_F18,  KC_F19,   KC_F20,     KC_QUOT,
        LCTL_T(KC_ESC), KC_EXLM,     KC_AT,     KC_HASH, KC_DOLLAR, KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_QUOT,  KC_DQUO,    RCTL_T(KC_ENT),
        SC_LSPO,        KC_UNDS,     KC_PLUS,   KC_TILD, _______,   _______, _______, _______,  _______, _______,  _______,    SC_RSPC,
        KC_LBRC,        LHYPER_C_T,  LALT_C_T,  KC_LGUI, _______,       KC_DELETE,    MO(_RGB), KC_RGUI, RALT_C_T, RHYPER_C_T, KC_RBRC
        ),
    [_RGB] = LAYOUT_ortho_4x12_1x2uC(
        _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
        )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LHYPER_C_T:
            custom_mod_t(record->event.pressed, KC_HYPR, '{');
            return false;
        case RHYPER_C_T:
            custom_mod_t(record->event.pressed, KC_HYPR, '}');
            return false;
        case LALT_C_T:
            custom_mod_t(record->event.pressed, KC_LALT, '<');
            return false;
        case RALT_C_T:
            custom_mod_t(record->event.pressed, KC_RALT, '>');
            return false;
        default:
            break;
    }
    return true;
}

void custom_mod_t(bool pressed, uint16_t key_hold, char key_tap) {
    char key_tap_arr[2] = {key_tap, '\0'};
    static uint16_t timer;
    if(pressed) {
        timer = timer_read();
        register_code(key_hold); // Change the key to be held here
    } else {
        unregister_code(key_hold); // Change the key that was held here, too!
        if (timer_elapsed(timer) < TAPPING_TERM) {
            send_string_with_delay(key_tap_arr, 0);
        }
    }
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_set_color_all(255, 0, 0);
}
