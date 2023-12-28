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

#endif // QMK_FIRMWARE_KEYMAP_H

// Modifiers
#define CTL_TAB CTL_T(KC_TAB)
#define CTL_ENT CTL_T(KC_ENT)

#define HYPER_L ALL_T(KC_LBRC)
#define HYPER_R ALL_T(KC_RBRC)

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

// Dashed
#define KC_NDSH LALT(KC_MINS)
#define KC_MDSH S(LALT(KC_MINS))
