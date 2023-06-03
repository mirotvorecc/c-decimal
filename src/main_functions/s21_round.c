#include "../big_decimal_functions/s21_big_decimal.h"
#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {  //  good
  decimalZeroing(result);
  int res = OK;
  if (!decimalIsRight(value)) {
    res = ERROR;

  } else {
    bool nonZeroExp = (bool)getExpForDecimal(value);
    int sign = checkSignBit(value.bits[3]);
    s21_decimal half = {{5, 0, 0, 65536}};  //  0.5
    if (nonZeroExp) {
      if (sign) {  //  отрицательное
        s21_sub(value, half, &value);
      } else {
        s21_add(value, half, &value);
      }
    }
    s21_truncate(value, result);
  }
  return res;
}