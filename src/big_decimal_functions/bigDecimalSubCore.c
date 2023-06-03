#include "s21_big_decimal.h"

void bigDecimalSubCore(s21_big_decimal A, s21_big_decimal B,
                       s21_big_decimal *result) {
  int whoIsReverse = bigDecimalCompare(A, B) == 1 ? 1 : 2;

  for (int i = 0; i <= 191; i++) {
    inverseBigDecimalBit(whoIsReverse == 1 ? &A : &B, i);
  }

  bigDecimalAddCore(A, B, result);

  for (int i = 0; i <= 191; i++) {
    inverseBigDecimalBit(result, i);
  }

  if (whoIsReverse != 1) setBigDecimalSignBit(result);
}