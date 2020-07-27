
#include QMK_KEYBOARD_H
#include "matrix.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    LCMD(KC_U), SCMD(KC_U), SCMD(KC_E), \
    KC_LEFT, KC_F, KC_RIGHT  \
  )
};

void matrix_scan_user(void) {
  // jump to bootloaer when all keys are pressed
  if (matrix_get_row(0) == 0b111 && matrix_get_row(1) == 0b111) {
    clear_keyboard();
    bootloader_jump();
  }
};
