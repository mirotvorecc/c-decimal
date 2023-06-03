#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int status = 0;

  s21_big_decimal A = {0};
  s21_big_decimal B = {0};
  s21_big_decimal C = {0};

  A = fromDecimalToBigDecimal(value_1);
  B = fromDecimalToBigDecimal(value_2);
  C = fromDecimalToBigDecimal(*result);

  bigDecimalMul(A, B, &C);

  status = fromBigDecimalToDecimal(C, result);

  return status;
}