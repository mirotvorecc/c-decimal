#include "s21_big_decimal.h"

void bigDecimalDiv(s21_big_decimal A, s21_big_decimal B,
                   s21_big_decimal *result) {
  s21_big_decimal tmp = {0};
  s21_big_decimal zero = {0};
  s21_big_decimal remainder = {0};

  int scale = getBigDecimalScale(A) - getBigDecimalScale(B);

  bigDecimalDivCore(A, B, result, &remainder);

  while (((bigDecimalCompare(remainder, zero) != 0) && (scale < 28)) ||
         (scale < 0)) {
    bigDecimalMulByTen(&remainder);
    bigDecimalMulByTen(result);
    bigDecimalDivCore(remainder, B, &tmp, &remainder);
    bigDecimalAddCore(*result, tmp, result);
    scale++;
  }

  setBigDecimalScale(result, scale);
}

void bigDecimalDivCore(s21_big_decimal A, s21_big_decimal B,
                       s21_big_decimal *result, s21_big_decimal *remainder) {
  bigDecimalZeroing(result);
  bigDecimalZeroing(remainder);

  for (int i = 191; i >= 0; i--) {
    bigDecimalShiftLeft(remainder, 1);

    remainder->bits[0] |= checkBigDecimalBit(&A, i);

    if (bigDecimalCompare(*remainder, B) != 2) {
      bigDecimalSubCore(*remainder, B, remainder);
      setBigDecimalBit(result, i);
    }
  }

  if (getBigDecimalSignBit(A) ^ getBigDecimalSignBit(B))
    setBigDecimalSignBit(result);
}
