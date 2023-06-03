#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  decimalZeroing(result);
  int res = OK;
  if (!decimalIsRight(value)) {
    res = ERROR;
  } else {
    *result = value;
    if (getSignBitForDecimal(value)) {  //  число отрицательное
      unsetSignBit(&result->bits[3]);
    } else {
      setSignBit(&result->bits[3]);
    }
  }
  return res;
}