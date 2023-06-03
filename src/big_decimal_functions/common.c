#include "s21_big_decimal.h"

int checkBigDecimalBit(s21_big_decimal *src, const int position) {
  int byteIndex = position / 32;

  int bitInByteIndex = position % 32;

  return checkBit(src->bits[byteIndex], bitInByteIndex);
}

void setBigDecimalBit(s21_big_decimal *dst, int bitIndex) {
  int byteIndex = bitIndex / 32;
  int bitInByteIndex = bitIndex % 32;
  dst->bits[byteIndex] =
      (unsigned int)setBit(dst->bits[byteIndex], bitInByteIndex);
}

void unsetBigDecimalBit(s21_big_decimal *src, const int position) {
  int byteIndex = position / 32;
  int bitInByteIndex = position % 32;
  src->bits[byteIndex] =
      (unsigned int)unsetBit(src->bits[byteIndex], bitInByteIndex);
}

void inverseBigDecimalBit(s21_big_decimal *src, const int position) {
  int byteIndex = position / 32;
  int bitInByteIndex = position % 32;
  src->bits[byteIndex] =
      (unsigned int)inverseBit(src->bits[byteIndex], bitInByteIndex);
}

int getBigDecimalScale(s21_big_decimal src) {
  int exp = 0;
  for (int i = 16, k = 0; i <= 23; i++, k++) {
    if (checkBit(src.bits[6], i)) exp = setBit(exp, k);
  }

  return exp;
}

void setBigDecimalScale(s21_big_decimal *src, int expectedScale) {
  for (int i = 16, k = 0; i <= 23; i++, k++) {
    if (checkBit(expectedScale, k))
      src->bits[6] = setBit(src->bits[6], i);
    else
      src->bits[6] = unsetBit(src->bits[6], i);
  }
}

int bigDecimalCompare(s21_big_decimal A, s21_big_decimal B) {
  // 0 - equal
  // 1 - A > B
  // 2 - A < B
  int result = 0;
  for (int i = 191; i >= 0; i--) {
    if (checkBigDecimalBit(&A, i) ^ checkBigDecimalBit(&B, i)) {
      result = checkBigDecimalBit(&A, i) ? 1 : 2;
      break;
    }
  }
  return result;
}

void setBigDecimalSignBit(s21_big_decimal *src) { setBigDecimalBit(src, 223); }

void unsetBigDecimalSignBit(s21_big_decimal *src) {
  unsetBigDecimalBit(src, 223);
}

int getBigDecimalSignBit(s21_big_decimal src) {
  return checkBit(src.bits[6], 31);
}

void bigDecimalShiftLeft(s21_big_decimal *src, int shift) {
  s21_big_decimal tmp = {0};

  for (int i = 0; i < shift; i++) {
    tmp = *src;
    for (int k = 1; k < 192; k++) {
      if (checkBigDecimalBit(&tmp, k - 1))
        setBigDecimalBit(src, k);
      else
        unsetBigDecimalBit(src, k);
    }

    unsetBigDecimalBit(src, 0);
  }
}

void bigDecimalShiftRight(s21_big_decimal *src, int shift) {
  s21_big_decimal tmp = {0};

  for (int i = 0; i < shift; i++) {
    tmp = *src;
    for (int k = 190; k != -1; k--) {
      if (checkBigDecimalBit(&tmp, k + 1)) {
        setBigDecimalBit(src, k);
      } else {
        unsetBigDecimalBit(src, k);
      }
    }

    unsetBigDecimalBit(src, 191);
  }
}

void bigDecimalMulByTen(s21_big_decimal *src) {
  s21_big_decimal tmp = *src;
  bigDecimalShiftLeft(src, 3);
  bigDecimalShiftLeft(&tmp, 1);
  bigDecimalAddCore(*src, tmp, src);
}

void bigDecimalZeroing(s21_big_decimal *src) {
  for (int i = 0; i < 7; i++) {
    src->bits[i] = 0;
  }
}

int bigDecimalBankRoundByRemainder(s21_big_decimal *src,
                                   s21_big_decimal remainder) {
  int status = 0;
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0}};

  if (remainder.bits[0] == 5) {
    if (checkBigDecimalBit(src, 0)) bigDecimalAddCore(*src, one, src);
  } else if (remainder.bits[0] > 5) {
    bigDecimalAddCore(*src, one, src);
  }

  if (isBigDecimalOverflowed(*src)) status = INF;

  return status;
}

int checkBigDecimalSignBit(s21_big_decimal src) {
  return checkBigDecimalBit(&src, bigdecimalSignBitIndex);
}

bool isBigDecimalOverflowed(s21_big_decimal src) {
  bool result = false;
  s21_big_decimal max = {{0xffffffff, 0xffffffff, 0xffffffff, 0, 0, 0, 0}};

  for (int i = 191; i >= 0; i--) {
    if (checkBigDecimalBit(&src, i) ^ checkBigDecimalBit(&max, i)) {
      result = checkBigDecimalBit(&src, i) ? true : false;
      break;
    }
  }

  return result;
}
