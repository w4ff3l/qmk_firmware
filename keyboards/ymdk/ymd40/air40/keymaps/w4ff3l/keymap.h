/*
 * Copyright 2023
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

#ifndef QMK_FIRMWARE_KEYMAP_H
#define QMK_FIRMWARE_KEYMAP_H

// Modifiers
#define CTL_TAB CTL_T(KC_TAB)
#define CTL_ENT CTL_T(KC_ENT)

#define HYPER_L ALL_T(KC_LBRC)
#define HYPER_R ALL_T(KC_RBRC)

// Homerow mods
// Layer 1
#define RALT__G RALT_T(KC_G)
#define RALT__M RALT_T(KC_M)

#define LCTL__T LCTL_T(KC_T)
#define RCTL__N RCTL_T(KC_N)

#define LSFT__S RSFT_T(KC_S)
#define RSFT__E RSFT_T(KC_E)

#define LALT__R LALT_T(KC_R)
#define RALT__I RALT_T(KC_I)

#define LGUI__A LGUI_T(KC_A)
#define RGUI__O LGUI_T(KC_O)

// Layer 2
#define RALT__5 RALT_T(KC_5)
#define RALT__6 RALT_T(KC_6)

#define LCTL__4 LCTL_T(KC_4)
#define RCTL__7 RCTL_T(KC_7)

#define LSFT__3 RSFT_T(KC_3)
#define RSFT__8 RSFT_T(KC_8)

#define LALT__2 LALT_T(KC_2)
#define RALT__9 RALT_T(KC_9)

#define LGUI__1 LGUI_T(KC_1)
#define RGUI__0 LGUI_T(KC_0)

// Layer 3
// _______, KC_EXLM, KC_AT,   KC_HASH, KC_DOLLAR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_QUOT, KC_DQUO, _______,
#define RALT_PE RALT_T(KC_PERC)
#define RALT_CI RALT_T(KC_CIRC)

#define LCTL_DO LCTL_T(KC_DOLLAR)
#define RCTL_AM RCTL_T(KC_AMPR)

#define LSFT_HA RSFT_T(KC_HASH)
#define RSFT_AS RSFT_T(KC_ASTR)

#define LALT_AT LALT_T(KC_AT)
#define RALT_QU RALT_T(KC_QUOT)

#define LGUI_EX LGUI_T(KC_EXLM)
#define RGUI_DQ LGUI_T(KC_DQUO)

// Dashed
#define KC_NDSH LALT(KC_MINS)
#define KC_MDSH S(LALT(KC_MINS))

// Options
#define USB_SUSPEND_WAKEUP_DELAY 0
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 240
#define RETRO_TAPPING

#endif // QMK_FIRMWARE_KEYMAP_H

