#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  decimalZeroing(result);
  int res = OK;
  if (!decimalIsRight(value)) {
    res = ERROR;
  } else {
    s21_big_decimal A = fromDecimalToBigDecimal(value);
    s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0}};
    s21_big_decimal bigResult = {0};
    s21_big_decimal remainder = {0};
    decimalZeroing(result);
    int exp = getExpFromDecimalIntBit(value.bits[3]);
    for (; exp > 0; exp--) {
      bigDecimalDivCore(A, ten, &bigResult, &remainder);
      A = bigResult;
    }
    fromBigDecimalToDecimal(A, result);
  }
  return res;
}