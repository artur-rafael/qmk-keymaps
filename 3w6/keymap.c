#include QMK_KEYBOARD_H

#define LG(kc) MT(MOD_LGUI, kc)
#define LA(kc) MT(MOD_LALT, kc)
#define LS(kc) MT(MOD_LSFT, kc)
#define LC(kc) MT(MOD_LCTL, kc)
#define RC(kc) MT(MOD_RCTL, kc)
#define RS(kc) MT(MOD_RSFT, kc)
#define RA(kc) MT(MOD_RALT, kc)
#define RG(kc) MT(MOD_RGUI, kc)

#define USD_EUR LT(0, KC_NO)

enum layer_names
{
   ABC, /* alpha (qwerty) */
   SYM, /* symbols */
   FNUM, /* fn and numerical */
   NAV, /* navigation */
   MSE, /* mouse */
};

enum custom_keycodes
{
   CAO_COMBO = SAFE_RANGE,
   AO_COMBO,
};

const uint16_t PROGMEM cao_combo[] = { LA(KC_S), LS(KC_D), COMBO_END };
const uint16_t PROGMEM ao_combo[] = { LS(KC_D), LC(KC_F), COMBO_END };
const uint16_t PROGMEM esc_combo[] = { RC(KC_J), RS(KC_K), COMBO_END };

combo_t key_combos[] =
{
   COMBO(cao_combo, CAO_COMBO),
   COMBO(ao_combo, AO_COMBO),
   COMBO(esc_combo, KC_ESC),
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
   [ABC] = LAYOUT_split_3x5_3(
          KC_Q,     KC_W,     KC_E,     KC_R, KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,        KC_P,
      LG(KC_A), LA(KC_S), LS(KC_D), LC(KC_F), KC_G,      KC_H, RC(KC_J), RS(KC_K), RA(KC_L), RG(KC_SCLN),
          KC_Z,     KC_X,     KC_C,     KC_V, KC_B,      KC_N,     KC_M,  KC_COMM,   KC_DOT,     KC_SLSH,
         KC_ESC, LT(SYM, KC_SPC), LT(FNUM, KC_TAB), LT(MSE, KC_ENT), LT(NAV, KC_BSPC), KC_RSFT
   ),

   [SYM] = LAYOUT_split_3x5_3(
      KC_QUOT, S(KC_COMM), S(KC_DOT), S(KC_QUOT),  KC_DOT,      S(KC_7), S(KC_SCLN), S(KC_LBRC), S(KC_RBRC),    S(KC_5),
      S(KC_1),    KC_MINS, S(KC_EQL),     KC_EQL, S(KC_3),   S(KC_BSLS), S(KC_MINS),    S(KC_9),    S(KC_0), S(KC_SLSH),
      S(KC_6),    KC_SLSH,   S(KC_8),    KC_BSLS,  KC_GRV,    S(KC_GRV),    USD_EUR,    KC_LBRC,    KC_RBRC,    S(KC_2),
                                XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,    KC_BSPC, XXXXXXX
   ),

   [FNUM] = LAYOUT_split_3x5_3(
           KC_INS,     KC_F9,    KC_F10,    KC_F11, KC_F12,   S(KC_EQL),     KC_7,     KC_8,     KC_9,    S(KC_8),
      LG(KC_PSCR), LA(KC_F5), LS(KC_F6), LC(KC_F7),  KC_F8,        KC_0, RC(KC_4), RS(KC_5), LA(KC_6), RG(KC_DOT),
          KC_PAUS,     KC_F1,     KC_F2,     KC_F3,  KC_F4,     KC_MINS,     KC_1,     KC_2,     KC_3,    KC_SLSH,
                                 XXXXXXX, XXXXXXX, XXXXXXX,      KC_EQL, KC_BSPC, XXXXXXX
   ),

   [NAV] = LAYOUT_split_3x5_3(
       KC_ESC, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,   KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_DEL,
      KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
      KC_CAPS, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
   ),

   [MSE] = LAYOUT_split_3x5_3(
      XXXXXXX, XXXXXXX,   MS_UP, XXXXXXX, XXXXXXX,   MS_ACL0, MS_WHLL, MS_WHLU, MS_WHLR, XXXXXXX,
      XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX,   MS_ACL1, MS_BTN1, MS_BTN3, MS_BTN2, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   MS_ACL2, XXXXXXX, MS_WHLD, XXXXXXX, XXXXXXX,
                        KC_LALT, KC_LSFT, KC_LCTL,   XXXXXXX, XXXXXXX, XXXXXXX
   ),
};
/* clang-format on */

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
   switch(keycode)
   {
   case CAO_COMBO:
      if (record->event.pressed)
      {
         tap_code16(ALGR(KC_COMM));
         tap_code16(S(KC_GRV));
         SEND_STRING("ao");
      }
      return false;
   case AO_COMBO:
      if (record->event.pressed)
      {
         tap_code16(S(KC_GRV));
         SEND_STRING("ao");
      }
      return false;
   case USD_EUR:
      if (record->tap.count && record->event.pressed)
      {
         tap_code16(S(KC_4)); /* $ on tap */
      }
      else if (record->event.pressed)
      {
         tap_code16(ALGR(KC_5)); /* € on hold */
      }
      return false;
   }
   return true;
}
