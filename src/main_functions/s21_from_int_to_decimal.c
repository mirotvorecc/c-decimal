#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  memset(&(dst->bits), 0, sizeof(s21_decimal));
  if (src < 0) {
    dst->bits[3] = 1 << signBitIndex;
    src = -src;
  }

  dst->bits[0] = src;
  return OK;
}