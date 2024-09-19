#include QMK_KEYBOARD_H

#define LG(kc) MT(MOD_LGUI, kc)
#define LA(kc) MT(MOD_LALT, kc)
#define LS(kc) MT(MOD_LSFT, kc)
#define LC(kc) MT(MOD_LCTL, kc)
#define RC(kc) MT(MOD_RCTL, kc)
#define RS(kc) MT(MOD_RSFT, kc)
#define RA(kc) MT(MOD_RALT, kc)
#define RG(kc) MT(MOD_RGUI, kc)

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
   E_COMBO,
   O_COMBO,
};

const uint16_t PROGMEM cao_combo[] = { LA(KC_S), LS(KC_D), COMBO_END };
const uint16_t PROGMEM ao_combo[] = { LS(KC_D), LC(KC_F), COMBO_END };
const uint16_t PROGMEM e_combo[] = { RC(KC_J), RS(KC_K), COMBO_END };
const uint16_t PROGMEM o_combo[] = { RS(KC_K), RA(KC_L), COMBO_END };

combo_t key_combos[] =
{
   COMBO(cao_combo, CAO_COMBO),
   COMBO(ao_combo, AO_COMBO),
   COMBO(e_combo, E_COMBO),
   COMBO(o_combo, O_COMBO),
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
   [ABC] = LAYOUT_split_3x5_3(
          KC_Q,     KC_W,     KC_E,     KC_R, KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,        KC_P,
      LG(KC_A), LA(KC_S), LS(KC_D), LC(KC_F), KC_G,      KC_H, RC(KC_J), RS(KC_K), RA(KC_L), RG(KC_SCLN),
          KC_Z,     KC_X,     KC_C,     KC_V, KC_B,      KC_N,     KC_M,  KC_COMM,   KC_DOT,     KC_SLSH,
LT(NAV, KC_ESC), LT(SYM, KC_SPC), LT(FNUM, KC_TAB),   KC_BSPC, LT(MSE, KC_ENT), KC_RSFT
   ),

   [SYM] = LAYOUT_split_3x5_3(
      KC_QUOT, S(KC_COMM), S(KC_DOT), S(KC_QUOT),  KC_DOT,      S(KC_7), S(KC_SCLN), S(KC_LBRC), S(KC_RBRC),    S(KC_5),
      S(KC_1),    KC_MINS, S(KC_EQL),     KC_EQL, S(KC_3),   S(KC_BSLS), S(KC_MINS),    S(KC_9),    S(KC_0), S(KC_SLSH),
      S(KC_6),    KC_SLSH,   S(KC_8),    KC_BSLS,  KC_GRV,    S(KC_GRV),    S(KC_4),    KC_LBRC,    KC_RBRC,    S(KC_2),
                                XXXXXXX, XXXXXXX, XXXXXXX,      KC_BSPC, KC_SCLN, KC_COMM
   ),

   [FNUM] = LAYOUT_split_3x5_3(
           KC_INS,     KC_F9,    KC_F10,    KC_F11, KC_F12,   S(KC_EQL),     KC_7,     KC_8,     KC_9,    S(KC_8),
      LG(KC_PSCR), LA(KC_F5), LS(KC_F6), LC(KC_F7),  KC_F8,        KC_0, RC(KC_4), RS(KC_5), LA(KC_6), RG(KC_DOT),
          KC_PAUS,     KC_F1,     KC_F2,     KC_F3,  KC_F4,     KC_MINS,     KC_1,     KC_2,     KC_3,    KC_SLSH,
                                 XXXXXXX, XXXXXXX, XXXXXXX,     KC_BSPC, KC_ENT, KC_EQL
   ),

   [NAV] = LAYOUT_split_3x5_3(
      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX,   KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,
      KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        XXXXXXX, XXXXXXX, XXXXXXX,    KC_DEL,  KC_ENT, KC_CAPS
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
         break;
      case AO_COMBO:
         if (record->event.pressed)
         {
            tap_code16(S(KC_GRV));
            SEND_STRING("ao");
         }
         break;
      case E_COMBO:
         if (record->event.pressed)
         {
            tap_code16(S(KC_6));
            tap_code16(KC_E);
         }
         break;
      case O_COMBO:
         if (record->event.pressed)
         {
            tap_code16(ALGR(KC_O));
         }
         break;
   }
   return true;
}
