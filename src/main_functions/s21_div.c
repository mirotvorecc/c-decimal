#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  decimalZeroing(result);

  int status = OK;

  s21_big_decimal A = fromDecimalToBigDecimal(value_1);
  s21_big_decimal B = fromDecimalToBigDecimal(value_2);
  s21_big_decimal bigResult = fromDecimalToBigDecimal(*result);
  s21_big_decimal zero = {0};

  if (!bigDecimalCompare(B, zero)) return DIV_BY_ZERO;

  bigDecimalDiv(A, B, &bigResult);

  status = fromBigDecimalToDecimal(bigResult, result);

  return status;
}