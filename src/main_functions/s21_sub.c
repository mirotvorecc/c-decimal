#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  decimalZeroing(result);

  int status = OK;

  s21_big_decimal A = fromDecimalToBigDecimal(value_1);
  s21_big_decimal B = fromDecimalToBigDecimal(value_2);
  s21_big_decimal bigResult = {0};

  toCommonFactor(&A, &B);

  if (checkBigDecimalSignBit(A) == checkBigDecimalSignBit(B)) {
    bigDecimalSubCore(A, B, &bigResult);

    if (checkBigDecimalSignBit(A)) {
      if (checkBigDecimalSignBit(bigResult))
        unsetBigDecimalSignBit(&bigResult);
      else
        setBigDecimalSignBit(&bigResult);
    }
  } else {
    bigDecimalAddCore(A, B, &bigResult);

    if (checkBigDecimalSignBit(A)) setBigDecimalSignBit(&bigResult);
  }

  setBigDecimalScale(&bigResult, getBigDecimalScale(A));

  status = fromBigDecimalToDecimal(bigResult, result);

  return status;
}