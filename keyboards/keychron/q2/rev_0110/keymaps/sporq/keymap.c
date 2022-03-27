/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#include "keymap_german.h"
#include "sendstring_german.h"


enum layers{
    _NEO_ONE,
    WIN_BASE,
    _N3,
    _FN1,
    _FN2,
    _FN3
};

enum custom_keycodes {
    WIN_REG = SAFE_RANGE,
};

void eeconfig_init_user(void) {
    set_unicode_input_mode(UC_WIN);
}

#define KC_WAVE S(KC_GRV)
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define DE_UE DE_UDIA
#define DE_OE DE_ODIA
#define DE_AE DE_ADIA

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NEO_ONE] = LAYOUT_ansi_67(
        DE_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS, S(DE_ACUT),KC_BSPC,          KC_ESC,  
        KC_TAB,  DE_X,    DE_V,    DE_L,    DE_C,    DE_W,    DE_K,    DE_H,    DE_G,    DE_F,    DE_Q,    DE_SS,    DE_ACUT,  MO(_N3),          KC_PGUP,   
        MO(_N3), DE_U,    DE_I,    DE_A,    DE_E,    DE_O,    DE_S,    DE_N,    DE_R,    DE_T,    DE_D,    DE_Y,               KC_ENT,           KC_PGDN,
        KC_LSFT,          DE_UDIA, DE_ODIA, DE_ADIA, DE_P,    DE_Z,    DE_B,    DE_M,    DE_COMM, DE_DOT,  DE_J,               KC_RSFT,   KC_UP,   
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_LALT, MO(_FN1), MO(_FN3),   KC_LEFT, KC_DOWN, KC_RGHT),

    [_N3] = LAYOUT_ansi_67(
        KC_TRNS, UC(L'¹'),DE_SUP2, DE_SUP3, UC(L'›'),UC(L'‹'),UC(L'¢'),UC(L'¥'),DE_COMM, UC(L'‘'),UC(L'’'),UC(L'—'), KC_TRNS, KC_TRNS,           KC_TRNS,
        KC_TRNS, UC(L'…'),DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, UC(L'ſ'), KC_TRNS, KC_TRNS,           KC_TRNS,
        KC_TRNS, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT,             KC_TRNS,           KC_TRNS,
        KC_TRNS,          DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, UC(L'`'),DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN,           KC_TRNS,    KC_TRNS,               
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS),

    [WIN_BASE] = LAYOUT_ansi_67(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,          KC_ESC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FN2), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN1] = LAYOUT_ansi_67(
        KC_GRV,  KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU, KC_TRNS,          KC_TRNS,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_FN2] = LAYOUT_ansi_67(
        KC_GRV,  KC_BRID, KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU, KC_TRNS,          KC_TRNS,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_FN3] = LAYOUT_ansi_67(
        KC_WAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_TRNS,          KC_TRNS,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

// from here: [https://github.com/kingdase/hasu-usb-usb-neo/blob/master/qmk/keymap.c]

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT))

#if 0
#include <print.h>
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
  bool isShift;

  isShift=get_mods() & MODS_SHIFT_MASK;

  uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);

    switch (keycode) {
    case KC_1:
      if (record->event.pressed)
      {
        if (isShift)
        {
          register_code(KC_3);
        } else
        {
          register_code(KC_1);
        }
      }
      if (! record->event.pressed)
      {
        if (isShift)
        {
          unregister_code(KC_3);
        } else
        {
          unregister_code(KC_1);
        }
      }
      return false;

    case KC_2:
      if (record->event.pressed)
      {
        if (isShift)
        {
          register_code(KC_4);
        } else
        {
          register_code(KC_2);
        }
      }
      if (! record->event.pressed)
      {
        if (isShift)
        {
          unregister_code(KC_4);
        } else
        {
          unregister_code(KC_2);
        }
      }
      return false;
    }
    return true;
}


#else

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool isShift;

  isShift=get_mods() & MODS_SHIFT_MASK;

//    uint8_t prev_mods; // to keep mod state

    inline bool my_unicode(uint16_t keycode, uint16_t new_keycode, keyrecord_t *record) {
    if (record->event.pressed)
    {
      if (isShift){
        process_unicode(new_keycode, record);
      } else {
        return true;
      }
    } else {
      unregister_code(keycode);
    }
    return false;
  };

  switch (keycode) {
    case KC_1:
      return my_unicode(keycode,UC(L'°')|QK_UNICODE,record);
    case KC_2: // § is a shifted '3'
      return my_unicode(keycode,UC(L'§')|QK_UNICODE,record);
    case KC_3:
      return my_unicode(keycode,UC(L'ℓ')|QK_UNICODE,record);
    case KC_4:
      return my_unicode(keycode,UC(L'»')|QK_UNICODE,record);
    case KC_5:
      return my_unicode(keycode,UC(L'«')|QK_UNICODE,record);
    case KC_6: // $ is a shifted 4
      return my_unicode(keycode,UC(L'$')|QK_UNICODE,record);
    case KC_7: // € is AltGr + e
      return my_unicode(keycode,UC(L'€')|QK_UNICODE,record);
    case KC_8:
      return my_unicode(keycode,UC(L'„')|QK_UNICODE,record);
    case KC_9:
      return my_unicode(keycode,UC(L'“')|QK_UNICODE,record);
    case KC_0:
      return my_unicode(keycode,UC(L'”')|QK_UNICODE,record);
    case DE_MINS: // confusing coz it's from the NEO Layer !
      return my_unicode(keycode,UC(L'—')|QK_UNICODE,record);
    case DE_COMM: // - is DE_MINS / KC_SLSH
      return my_unicode(keycode,UC(L'-')|QK_UNICODE,record);
    case DE_DOT:
      return my_unicode(keycode,UC(L'•')|QK_UNICODE,record);
    case DE_SS: // quick-hack
      return my_unicode(keycode,UC(L'ß')|QK_UNICODE,record);
    default:
      return true;
  }
}
#endif
