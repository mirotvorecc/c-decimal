#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (!decimalIsRight(src)) return ERROR;

  *dst = 0;
  int status = 0;

  if (src.bits[0] == 0 && src.bits[1] == 0 && src.bits[2] == 0) {
    *dst = 0;
  } else {
    double dstDouble = 0;
    int exp = getExpFromDecimalIntBit(src.bits[3]);
    for (int i = 0; i < 96; i++) {
      dstDouble += checkDecimalBit(&src, i) * pow(2, i);
    }
    dstDouble /= pow(10, exp);
    if (getSignBitForDecimal(src)) dstDouble *= -1;
    *dst = (float)dstDouble;
  }

  return status;
}

bool decimalIsRight(s21_decimal src) {
  bool ret = 1;
  unsigned int checkBit = 0b01111111000000001111111111111111;
  if (((src.bits[3] & checkBit) != 0) || (getExpForDecimal(src) > 28)) {
    ret = 0;
  }
  return ret;
}
