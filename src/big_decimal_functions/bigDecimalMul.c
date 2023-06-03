#include "s21_big_decimal.h"

void bigDecimalMul(s21_big_decimal A, s21_big_decimal B,
                   s21_big_decimal *result) {
  int scale = getBigDecimalScale(A) + getBigDecimalScale(B);

  setBigDecimalScale(result, scale);

  for (int i = 191; i != -1; i--) {
    if (checkBigDecimalBit(&B, i)) {
      bigDecimalShiftLeft(&A, i);
      bigDecimalAddCore(*result, A, result);
      bigDecimalShiftRight(&A, i);
    }
  }

  if ((getBigDecimalSignBit(A)) != getBigDecimalSignBit(B))
    setBigDecimalSignBit(result);
}