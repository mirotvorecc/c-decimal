#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (floatChecks(src)) return ERROR;

  long double tmpSrc = (long double)src;

  decimalZeroing(dst);

  signPreparing(dst, &tmpSrc);

  int scale = scaleInit(&tmpSrc);

  dst->bits[0] = (unsigned int)tmpSrc;

  s21_big_decimal tmp = fromDecimalToBigDecimal(*dst);

  decimalZeroing(dst);

  while (scale < 0) {
    bigDecimalMulByTen(&tmp);
    scale++;
  }

  setBigDecimalScale(&tmp, scale);

  fromBigDecimalToDecimal(tmp, dst);

  return OK;
}

int floatChecks(float src) {
  int status = OK;
  if (isDoubleInf(src) || isDoubleNan(src)) status = ERROR;
  if (src < 1e-28 && src > 0) status = ERROR;
  if (src > -1e-28 && src < 0) status = ERROR;
  int floatBits = getFloatBits(src);
  int exp = getExpFromIntBits(floatBits);
  if (exp > 95) status = ERROR;
  return status;
}

int scaleInit(long double *tmpSrc) {
  int scale = 0;

  for (; !((int)*tmpSrc) && (*tmpSrc < 1 && *tmpSrc > 0);
       *tmpSrc *= 10., scale++)
    ;

  int intLength = getIntLengthFromFloat(*tmpSrc);

  if (intLength > 7) {
    while (intLength > 7) {
      *tmpSrc /= 10.;
      intLength--;
      scale--;
    }
  } else {
    while (intLength < 7) {
      *tmpSrc *= 10.;
      intLength++;
      scale++;
    }
  }

  long double leftSideNum = 0;
  long double rightSideNum = modfl(*tmpSrc, &leftSideNum);

  if (rightSideNum >= 0.5) *tmpSrc += 1;

  return scale;
}

void signPreparing(s21_decimal *dst, long double *src) {
  int floatBits = getFloatBits(*src);
  if (checkSignBit(floatBits)) {
    setDecimalSignBit(dst, 1);
    *src *= -1;
  }
}