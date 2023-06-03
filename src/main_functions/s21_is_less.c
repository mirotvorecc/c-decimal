#include "../s21_decimal.h"

int s21_is_less(s21_decimal val1, s21_decimal val2) {
  int res = 0;
  int zero_counter = 0;

  s21_big_decimal big_val1 = fromDecimalToBigDecimal(val1);
  s21_big_decimal big_val2 = fromDecimalToBigDecimal(val2);

  int sign_big_val1 = getBigDecimalSignBit(big_val1);
  int sign_big_val2 = getBigDecimalSignBit(big_val2);

  for (int i = 0; i < 3; i++) {
    if ((big_val1.bits[i] == big_val2.bits[i]) && (big_val1.bits[i] == 0))
      zero_counter++;
  }

  if (zero_counter == 3) {
    res = 0;
  } else {
    if (sign_big_val1 != sign_big_val2) {
      if (sign_big_val1 > sign_big_val2) res = 1;
      if (sign_big_val1 < sign_big_val2) res = 0;

    } else {
      if ((getBigDecimalScale(big_val1) != getBigDecimalScale(big_val2)))
        toCommonFactor(&big_val1, &big_val2);
      if (sign_big_val1 == 1) {
        if (bigDecimalCompare(big_val1, big_val2) == 1) res = 1;
      } else {
        if (bigDecimalCompare(big_val1, big_val2) == 2) res = 1;
      }
    }
  }

  return res;
}
