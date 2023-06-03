#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (!decimalIsRight(src)) return ERROR;

  *dst = 0;
  int res = 0;

  s21_truncate(src, &src);
  if ((src.bits[1] || src.bits[2]) ||
      (src.bits[0]) > 2147483648) {  //  -2147483648 +2147483647
    res = 1;
  } else {
    *dst = (int)src.bits[0];
    if (getSignBitForDecimal(src)) {  //  если отрицательное
      *dst *= -1;
    } else if (src.bits[0] > 2147483647) {
      res = 1;
      *dst = 0;
    }
  }
  return res;
}