#include "s21_big_decimal.h"

int fromBigDecimalToDecimal(s21_big_decimal src, s21_decimal *result) {
  int status = fixOverflow(&src);

  if (status == OK) {
    bool isDecimalNull = true;
    for (int i = 0; i < 96; i++) {
      if (checkBigDecimalBit(&src, i)) {
        isDecimalNull = false;
        setDecimalBit(result, i);
      }
    }

    setDecimalScale(result, getBigDecimalScale(src));

    if (checkBigDecimalSignBit(src) && !isDecimalNull)
      setDecimalSignBit(result, 1);

  } else {
    status = checkBigDecimalSignBit(src) ? INF_NEG : INF;
    decimalZeroing(result);
  }

  return status;
}

int fixOverflow(s21_big_decimal *src) {
  int status = OK;
  int scale = getBigDecimalScale(*src);
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal remainder = {0};

  while (isBigDecimalOverflowed(*src) || scale > 28) {
    if (scale) {
      scale--;
    } else {
      status = INF;
      break;
    }

    bigDecimalDivCore(*src, ten, src, &remainder);
  }

  setBigDecimalScale(src, scale);

  status = bigDecimalBankRoundByRemainder(src, remainder);

  return status;
}
