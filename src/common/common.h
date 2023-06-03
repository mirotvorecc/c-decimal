#ifndef SRC_COMMON_COMMON_H_
#define SRC_COMMON_COMMON_H_

#include "../s21_decimal.h"

int checkBit(const int src, const int position);
int setBit(const int value, const int position);
int unsetBit(const int value, const int position);
int inverseBit(const int value, const int position);
unsigned char getExpForDecimal(s21_decimal dec);
bool getSignBitForDecimal(s21_decimal dec);
void setSignBitForDecimal(s21_decimal *dec, bool isNegative);
int isDoubleNan(double src);
int isDoubleInf(double src);
int getFloatBits(float src);
int checkSignBit(int value);
void setSignBit(unsigned int *value);
void unsetSignBit(unsigned int *value);
int getExpFromIntBits(int src);
int getExpFromDecimalIntBit(int src);
void setDecimalBit(s21_decimal *dst, int bitIndex);
void setDecimalScale(s21_decimal *dst, int scale);
int floatChecks(float src);
int getIntLengthFromFloat(long double n);
int scaleInit(long double *src);
void signPreparing(s21_decimal *dst, long double *src);
void toCommonFactor(s21_big_decimal *value_1, s21_big_decimal *value_2);
int addMain(s21_decimal A, s21_decimal B, s21_decimal *result);
int checkDecimalBit(s21_decimal *dst, int bitIndex);
void decimalZeroing(s21_decimal *src);
void setDecimalSignBit(s21_decimal *src, const int sign);
bool decimalIsRight(s21_decimal src);

#endif  // SRC_COMMON_COMMON_H_