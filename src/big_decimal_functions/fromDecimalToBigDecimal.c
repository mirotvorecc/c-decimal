#include "s21_big_decimal.h"

s21_big_decimal fromDecimalToBigDecimal(s21_decimal src) {
  s21_big_decimal result = {0};
  for (int i = 0; i < 3; i++) {
    result.bits[i] = src.bits[i];
  }
  result.bits[6] = src.bits[3];

  return result;
}