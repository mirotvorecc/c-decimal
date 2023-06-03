#include "s21_big_decimal.h"

void bigDecimalAddCore(s21_big_decimal A, s21_big_decimal B,
                       s21_big_decimal *result) {
  int mem = 0;
  int a = 0;
  int b = 0;

  for (int i = 0; i < 192; i++) {
    a = checkBigDecimalBit(&A, i);
    b = checkBigDecimalBit(&B, i);

    if (!a && !b && !mem) {
      unsetBigDecimalBit(result, i);
      mem = 0;
    } else if (a && b && mem) {
      setBigDecimalBit(result, i);
      mem = 1;
    } else if ((a ^ b ^ mem) == 0) {
      unsetBigDecimalBit(result, i);
      mem = 1;
    } else if ((a ^ b ^ mem) == 1) {
      setBigDecimalBit(result, i);
      mem = 0;
    }
  }
}
