#include QMK_KEYBOARD_H

/* Mod-tap aliases */
#define LA(kc) MT(MOD_LALT, kc)
#define LC(kc) MT(MOD_LCTL, kc)
#define LG(kc) MT(MOD_LGUI, kc)
#define LS(kc) MT(MOD_LSFT, kc)
#define RA(kc) MT(MOD_RALT, kc)
#define RC(kc) MT(MOD_RCTL, kc)
#define RG(kc) MT(MOD_RGUI, kc)
#define RS(kc) MT(MOD_RSFT, kc)

enum layer_names
{
    _BASE,  /* alpha (qwerty) */
    _SYM,  /* symbols */
    _FNUM, /* fn and numerical */
    _NAV,  /* navigation */
    _UTIL,  /* maintenance */
};

/* Layer-tap aliases */
#define TAB_FN LT(_FNUM, KC_TAB)
#define SPC_SY LT(_SYM, KC_SPC)
#define BSP_NAV LT(_NAV, KC_BSPC)

/* Tap for $, hold for € */
#define USD_EUR LT(0, KC_NO)

enum combos
{
    CAO_COMBO = SAFE_RANGE,
    AO_COMBO,
};

/* Portuguese digraph combos */
const uint16_t PROGMEM cao_combo[] = {LA(KC_S), LS(KC_D), COMBO_END};
const uint16_t PROGMEM ao_combo[]  = {LS(KC_D), LC(KC_F), COMBO_END};

combo_t key_combos[] =
{
    COMBO(cao_combo, CAO_COMBO),
    COMBO(ao_combo, AO_COMBO),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [_BASE] = LAYOUT_ferris_hlc
    (
               KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,      KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,
           LG(KC_A),   LA(KC_S),   LS(KC_D),   LC(KC_F),       KC_G,      KC_H,    RC(KC_J), RS(KC_K), RA(KC_L), RG(KC_SCLN),
               KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,      KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                                                 TAB_FN,     SPC_SY,      BSP_NAV, LS(KC_ENT),

            KC_MUTE,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO
    ),
    [_SYM] = LAYOUT_ferris_hlc
    (
            KC_QUOT,    KC_LABK,    KC_RABK,    KC_DQUO,     KC_DOT,      KC_AMPR, KC_COLN,  KC_LCBR,  KC_RCBR,  KC_PERC,
            KC_EXLM,    KC_MINS,    KC_PLUS,     KC_EQL,    KC_HASH,      KC_PIPE, KC_UNDS,  KC_LPRN,  KC_RPRN,  KC_QUES,
            KC_CIRC,    KC_SLSH,    KC_ASTR,    KC_BSLS,     KC_GRV,      KC_TILD, USD_EUR,  KC_LBRC,  KC_RBRC,  KC_AT,
                                                XXXXXXX,    XXXXXXX,      KC_BSPC, XXXXXXX,

              KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO
    ),
    [_FNUM] = LAYOUT_ferris_hlc
    (
          MO(_UTIL),      KC_F9,     KC_F10,     KC_F11,     KC_F12,      KC_PLUS, KC_7,     KC_8,     KC_9,     KC_ASTR,
        LG(KC_PSCR),  LA(KC_F5),  LS(KC_F6),  LC(KC_F7),      KC_F8,      KC_0,    RC(KC_4), RS(KC_5), LA(KC_6), RG(KC_DOT),
            XXXXXXX,      KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_MINS, KC_1,     KC_2,     KC_3,     KC_SLSH,
                                                XXXXXXX,    XXXXXXX,      KC_BSPC, KC_EQL,

              KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO
    ),
    [_NAV] = LAYOUT_ferris_hlc
    (
             KC_ESC, C(KC_LEFT), C(KC_RGHT), C(KC_BSPC),  C(KC_DEL),      KC_HOME, KC_PGDN,  KC_PGUP,  KC_END,   KC_DEL,
            KC_CAPS,    MS_BTN3,    MS_BTN2,    MS_BTN1, C(KC_PGUP),      KC_LEFT, KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,
         LGUI(KC_L),    KC_MPRV,    KC_MPLY,    KC_MNXT, C(KC_PGDN),      XXXXXXX, KC_LCTL,  KC_LSFT,  KC_LALT,  KC_LGUI,
                                                 KC_ESC,    XXXXXXX,      XXXXXXX, XXXXXXX,

            C(KC_0),      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO
    ),
    [_UTIL] = LAYOUT_ferris_hlc
    (
            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,      RM_TOGG, RM_HUEU,  RM_SATU,  RM_VALU,  QK_BOOT,
            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  QK_RBT,
            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX, RM_HUED,  RM_SATD,  RM_VALD,  EE_CLR,
                                                XXXXXXX,    XXXXXXX,      XXXXXXX, XXXXXXX,

              KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO
    ),

};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] =
{
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SYM]  = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [_FNUM] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [_NAV]  = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)) },
    [_UTIL] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
};

bool
process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (!record->event.pressed)
    {
        return true;
    }

    switch (keycode)
    {
    case CAO_COMBO:
        tap_code16(ALGR(KC_COMM));
    case AO_COMBO:
        tap_code16(KC_TILD);
        SEND_STRING("ao");
        return false;

    case USD_EUR:
        if (record->tap.count)
        {
            tap_code16(S(KC_4)); /* $ on tap */
        }
        else
        {
            tap_code16(ALGR(KC_5)); /* € on hold */
        }
        return false;
    }
    return true;
}

static void
set_underglow(uint8_t r, uint8_t g, uint8_t b)
{
    /* left side */
    rgb_matrix_set_color(0,  r, g, b);
    rgb_matrix_set_color(1,  r, g, b);
    rgb_matrix_set_color(2,  r, g, b);
    rgb_matrix_set_color(3,  r, g, b);
    rgb_matrix_set_color(4,  r, g, b);
    rgb_matrix_set_color(5,  r, g, b);
    /* right side */
    rgb_matrix_set_color(23, r, g, b);
    rgb_matrix_set_color(24, r, g, b);
    rgb_matrix_set_color(25, r, g, b);
    rgb_matrix_set_color(26, r, g, b);
    rgb_matrix_set_color(27, r, g, b);
    rgb_matrix_set_color(28, r, g, b);
}

bool
rgb_matrix_indicators_user(void)
{
    if (!rgb_matrix_is_enabled())
    {
        return false;
    }

    rgb_matrix_set_color_all(0, 0, 0);  /* reset all */

    if (host_keyboard_led_state().caps_lock)
    {
        set_underglow(48, 0, 0);
        return false;
    }

    switch (get_highest_layer(layer_state | default_layer_state))
    {
    case _SYM:
        set_underglow(22, 10, 0);
        break;

    case _FNUM:
        set_underglow(28, 8, 0);
        break;

    case _NAV:
        set_underglow(26, 4, 0);
        break;

    case _UTIL:
        set_underglow(48, 18, 0);
        break;

    case _BASE:
    default:
        set_underglow(16, 6, 0);
        break;
    }
    return false;
}
