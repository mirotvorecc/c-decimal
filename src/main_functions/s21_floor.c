#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int res = OK;
  decimalZeroing(result);
  if (!decimalIsRight(value)) {
    res = ERROR;
  } else {
    bool nonZeroExp = (bool)getExpForDecimal(value);
    int sign = checkSignBit(value.bits[3]);
    s21_truncate(value, result);
    if (sign && nonZeroExp && !s21_is_equal(value, *result)) {
      s21_sub(*result, ((s21_decimal){{1, 0, 0, 0}}), result);
    }
  }
  return res;
}