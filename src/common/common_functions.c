#include "../s21_decimal.h"

int checkBit(int src, const int position) {
  return ((src & (1 << position)) != 0);
}

int setBit(const int value, const int position) {
  return (value | (1 << position));
}

void setSignBit(unsigned int *value) {
  *value = (*value | (1 << signBitIndex));
}

void unsetSignBit(unsigned int *value) {
  *value = (*value & (~(1 << signBitIndex)));
}

int unsetBit(const int value, const int position) {
  return (value & ~(1 << position));
}

int inverseBit(const int value, const int position) {
  return (value ^ (1 << position));
}

unsigned char getExpForDecimal(s21_decimal dec) {
  unsigned char result = 0;
  int cBit = 0;
  for (int bit = 16; bit < startExpIndex + 8; ++bit) {
    bool b = (1 << bit) & dec.bits[3];
    if (b)
      result |= (1 << cBit);
    else
      result &= ~(1 << cBit);
    cBit++;
  }
  return result;
}

int getExpFromIntBits(int src) {
  int exp = 0;
  for (int i = 23, k = 0; i <= 30; i++) {
    if (checkBit(src, i)) exp = setBit(exp, k);
    k++;
  }
  exp -= 127;
  return exp;
}

int getExpFromDecimalIntBit(int src) {
  src = src << 1;
  src = src >> 17;

  return src;
}

bool getSignBitForDecimal(s21_decimal dec) {
  return (1 << signBitIndex) & dec.bits[3];
}

int isDoubleInf(double src) {
  int result = 0;
  if (src == INFINITY || src == -INFINITY) result = 1;
  return result;
}

int isDoubleNan(double src) {
  int result = 0;
  if (isnan(src)) result = 1;
  return result;
}

int getFloatBits(float src) { return *((int *)&src); }

int checkSignBit(int value) { return checkBit(value, signBitIndex); }

void setDecimalBit(s21_decimal *dst, int bitIndex) {
  int byteIndex = bitIndex / 32;
  int bitInByteIndex = bitIndex % 32;
  dst->bits[byteIndex] =
      (unsigned int)setBit(dst->bits[byteIndex], bitInByteIndex);
}

int checkDecimalBit(s21_decimal *dst, int bitIndex) {
  int byteIndex = bitIndex / 32;
  int bitInByteIndex = bitIndex % 32;
  return checkBit(dst->bits[byteIndex], bitInByteIndex);
}

void setDecimalScale(s21_decimal *dst, int scale) {
  int isSignNeed = checkSignBit((int)dst->bits[3]);

  dst->bits[3] = (unsigned int)scale;
  dst->bits[3] <<= 16;

  if (isSignNeed) setSignBit(&dst->bits[3]);
}

int getIntLengthFromFloat(long double n) {
  int len = 0;
  long double leftSideNum = 0;
  modfl(n, &leftSideNum);
  n = leftSideNum;
  if (truncl(n) == 0.) {
    len = 1;
  } else {
    if (truncl(n) < 0.) {
      n = n * (-1);
    }
    while (truncl(n) > 0.) {
      modfl(n, &leftSideNum);
      n = leftSideNum;
      len++;
      n /= 10;
    }
  }
  return len;
}

void decimalZeroing(s21_decimal *src) {
  for (int i = 0; i < 4; i++) {
    src->bits[i] = 0;
  }
}

void setDecimalSignBit(s21_decimal *src, const int sign) {
  if (sign == 1) {
    setSignBit(&src->bits[3]);
  } else {
    unsetSignBit(&src->bits[3]);
  }
}

void toCommonFactor(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  int scale1 = getBigDecimalScale(*value_1);
  int scale2 = getBigDecimalScale(*value_2);

  if (scale1 > scale2) {
    int dif = scale1 - scale2;
    for (int i = 0; i < dif; i++) {
      bigDecimalMulByTen(value_2);
    }
    setBigDecimalScale(value_2, scale1);
  } else if (scale1 < scale2) {
    int dif = scale2 - scale1;
    for (int i = 0; i < dif; i++) {
      bigDecimalMulByTen(value_1);
    }
    setBigDecimalScale(value_1, scale2);
  }
}
