#include "../s21_decimal.h"

int s21_add(s21_decimal A, s21_decimal B, s21_decimal *result) {
  decimalZeroing(result);

  int status = OK;
  int isANegative = checkDecimalBit(&A, decimalSignBitIndex);
  int isBNegative = checkDecimalBit(&B, decimalSignBitIndex);

  s21_big_decimal bigA = fromDecimalToBigDecimal(A);
  s21_big_decimal bigB = fromDecimalToBigDecimal(B);
  s21_big_decimal bigResult = {0};

  toCommonFactor(&bigA, &bigB);

  if (isANegative == isBNegative) {
    if (isANegative) setBigDecimalSignBit(&bigResult);
    bigDecimalAddCore(bigA, bigB, &bigResult);

  } else {
    bigDecimalSubCore(bigA, bigB, &bigResult);

    if (bigDecimalCompare(bigA, bigB) == 1) {
      if (checkBigDecimalSignBit(bigA)) setBigDecimalSignBit(&bigResult);
    } else {
      if (checkBigDecimalSignBit(bigB)) setBigDecimalSignBit(&bigResult);
    }
  }

  setBigDecimalScale(&bigResult, getBigDecimalScale(bigA));

  status = fromBigDecimalToDecimal(bigResult, result);

  return status;
}
