#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#define OK 0
#define ERROR 1
#define INF 1
#define INF_NEG 2
#define DIV_BY_ZERO 3
#define NumberIsLargeOrEqualToInfinity 1
#define NumberIsSmallOrEqualToNegativeInfinity 2
#define startExpIndex 16
#define signBitIndex 31
#define decimalSignBitIndex 127

typedef struct {
  unsigned int bits[4];
} s21_decimal;

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "big_decimal_functions/s21_big_decimal.h"
#include "common/common.h"

//  Arithmetic Operators

int s21_add(s21_decimal A, s21_decimal B, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

//  Return value:

//  0 - OK
//  1 - the number is too large or equal to infinity
//  2 - the number is too small or equal to negative infinity
//  3 - division by 0

//  Comparison Operators

int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal val_1, s21_decimal val_2);
int s21_is_less_or_equal(s21_decimal val1, s21_decimal val2);
int s21_is_greater(s21_decimal val1, s21_decimal val2);
int s21_is_greater_or_equal(s21_decimal val1, s21_decimal val2);

//  Return value:

//  0 - FALSE
//  1 - TRUE

//  Convertors and parsers

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

//  Return value - code error:
//  0 - OK
//  1 - convertation error

//  Another functions

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

//  Return value - code error:

//  0 - OK
//  1 - calculation error

#endif // SRC_S21_DECIMAL_H_
