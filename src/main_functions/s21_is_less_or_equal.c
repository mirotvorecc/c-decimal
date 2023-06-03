#include "../s21_decimal.h"

int s21_is_less_or_equal(s21_decimal val1, s21_decimal val2) {
  int res = 0;
  if ((s21_is_less(val1, val2)) || (s21_is_equal(val1, val2))) res = 1;

  return res;
}