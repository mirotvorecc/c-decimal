#ifndef SRC_BIG_DECIMAL_FUNCTIONS_S21_BIG_DECIMAL_H
#define SRC_BIG_DECIMAL_FUNCTIONS_S21_BIG_DECIMAL_H

typedef struct {
  unsigned int bits[7];
} s21_big_decimal;

#define bigdecimalSignBitIndex 223

#include "../s21_decimal.h"

s21_big_decimal fromDecimalToBigDecimal(s21_decimal src);
int checkBigDecimalBit(s21_big_decimal *src, const int position);
void setBigDecimalBit(s21_big_decimal *dst, int bitIndex);
int fromBigDecimalToDecimal(s21_big_decimal src, s21_decimal *result);
void bigDecimalAddCore(s21_big_decimal A, s21_big_decimal B,
                       s21_big_decimal *result);
bool isBigDecimalOverflowed(s21_big_decimal src);
bool checkUnderflow(s21_big_decimal src);
int fixOverflow(s21_big_decimal *src);
int bigDecimalTruncateByTen(s21_big_decimal *src);
int getBigDecimalScale(s21_big_decimal src);
void setBigDecimalScale(s21_big_decimal *src, int scale);
void bigDecimalSubCore(s21_big_decimal A, s21_big_decimal B,
                       s21_big_decimal *result);
int bigDecimalCompare(s21_big_decimal A, s21_big_decimal B);
void inverseBigDecimalBit(s21_big_decimal *src, const int position);
void setBigDecimalSignBit(s21_big_decimal *src);
void unsetBigDecimalSignBit(s21_big_decimal *src);
void bigDecimalDivCore(s21_big_decimal A, s21_big_decimal B,
                       s21_big_decimal *result, s21_big_decimal *remainder);
void unsetBigDecimalBit(s21_big_decimal *src, const int position);
void bigDecimalShiftLeft(s21_big_decimal *src, int shift);
void bigDecimalShiftRight(s21_big_decimal *src, int shift);
int getBigDecimalSignBit(s21_big_decimal src);
void bigDecimalDiv(s21_big_decimal A, s21_big_decimal B,
                   s21_big_decimal *result);
void bigDecimalMul(s21_big_decimal A, s21_big_decimal B,
                   s21_big_decimal *result);
void bigDecimalMulByTen(s21_big_decimal *src);
void bigDecimalZeroing(s21_big_decimal *src);
int bigDecimalBankRoundByRemainder(s21_big_decimal *src,
                                   s21_big_decimal remainder);
int checkBigDecimalSignBit(s21_big_decimal src);

#endif  // SRC_BIG_DECIMAL_FUNCTIONS_S21_BIG_DECIMAL_H
