#include "s21_test.h"

START_TEST(decToInt_1) {
  s21_decimal src = {{21452123, 0, 0, 2147483648}};
  int converted = 0;
  int checkResult = -21452123;
  int result = s21_from_decimal_to_int(src, &converted);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(converted, checkResult);
}
END_TEST;

START_TEST(decToInt_2) {
  s21_decimal src = {{4294967286, 4, 0, 65536}};  //  2147483647.0
  int converted = 0;
  int checkResult = 2147483647;
  int result = s21_from_decimal_to_int(src, &converted);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(converted, checkResult);
}
END_TEST;

START_TEST(decToInt_3) {
  s21_decimal src = {{4294967286, 4, 0, 2147549184}};  //  2147483647.0
  int converted = 0;
  int checkResult = -2147483647;
  int result = s21_from_decimal_to_int(src, &converted);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(converted, checkResult);
}
END_TEST;

START_TEST(decToInt_4) {
  s21_decimal src = {{0, 0, 0, 2147549184}};
  int converted = 0;
  int checkResult = 0;
  int result = s21_from_decimal_to_int(src, &converted);

  ck_assert_int_eq(result, false);
  ck_assert_int_eq(converted, checkResult);
}
END_TEST;

START_TEST(decToInt_5) {
  s21_decimal src = {{2147483648, 0, 0, 0}};
  int converted = 0;
  int checkResult = false;
  int result = s21_from_decimal_to_int(src, &converted);

  ck_assert_int_eq(result, true);
  ck_assert_int_eq(converted, checkResult);
}
END_TEST;

START_TEST(decToInt_6) {
  s21_decimal src = {{4294967286, 2147549184, 0, 2147549184}};  //  2147483647.0
  int converted = 0;
  int checkResult = 0;
  int result = s21_from_decimal_to_int(src, &converted);

  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(converted, checkResult);
}
END_TEST;

START_TEST(decToFloat_1) {
  s21_decimal src = {{2147483648, 0, 0, 0}};
  float converted = 0;
  float checkResult = 2147483648;
  int result = s21_from_decimal_to_float(src, &converted);

  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(converted, checkResult);
}
END_TEST;

START_TEST(decToFloat_2) {
  s21_decimal src = {{4294967286, 4, 0, 2147549184}};  //  2147483647.0
  float converted = 0;
  float checkResult = -2147483647.0;
  int result = s21_from_decimal_to_float(src, &converted);

  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(converted, checkResult);
}
END_TEST;

//  65839236468958810921567371243
//  0: 11010100101111001111000010100000
//  1: 10111000101110101100001010001101
//  2: 11111111111111111111111111111111
//  3: 1 0000000 00011100 0000000000000000

START_TEST(decToFloat_3) {
  s21_decimal src = {{0b11111111111111111111111111111111,
                      0b10111000101110101100001010001101,
                      0b11010100101111001111000010100000,
                      0b10000000000111000000000000000000}};  //  -1  10^28
  float converted = 0;
  float checkResult = -6.5839236468958810921567371243;
  int result = s21_from_decimal_to_float(src, &converted);

  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(converted, checkResult);
}
END_TEST;

START_TEST(decToFloat_4) {
  s21_decimal src = {{0b11111111111111111111111111111111,
                      0b10111000101110101100001010001101,
                      0b11010100101111001111000010100000,
                      0b00000000000011110000000000000000}};  //  +1  10^15
  float converted = 0;
  float checkResult = 65839236468958.810921567371243;
  int result = s21_from_decimal_to_float(src, &converted);

  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(converted, checkResult);
}
END_TEST;

START_TEST(decToFloat_5) {
  s21_decimal src = {{0b11111111111111111111111111111111,
                      0b10111000101110101100001010001101,
                      0b11010100101111001111000010100000, 0}};  //  +1  10^0
  float converted = 0;
  float checkResult = 65839236468958810921567371243.0;
  int result = s21_from_decimal_to_float(src, &converted);

  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(converted, checkResult);
}
END_TEST;

START_TEST(decToFloat_6) {
  s21_decimal src = {{0, 0, 0, 0}};
  float converted = 0;
  float checkResult = 0;
  int result = s21_from_decimal_to_float(src, &converted);

  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(converted, checkResult);
}
END_TEST;

START_TEST(decToInt_error1) {
  s21_decimal src = {{4294967286, 4, 0, 30 << 19}};
  int converted = 0;
  int checkResult = 0;
  int result = s21_from_decimal_to_int(src, &converted);

  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(converted, checkResult);
}
END_TEST;

START_TEST(decToFloat_error1) {
  s21_decimal src = {{4294967286, 4, 0, 30 << 19}};  //  +1  10^0
  float converted = 0;
  float checkResult = 0.0;
  int result = s21_from_decimal_to_float(src, &converted);

  ck_assert_int_eq(result, 1);
  ck_assert_float_eq(converted, checkResult);
}
END_TEST;

Suite *decimalConvertTests(void) {
  Suite *s = suite_create("\033[45mDecimal Convertions test\033[0m");
  TCase *tc = tcase_create("Decimal Convertions");

  //  dec to int
  tcase_add_test(tc, decToInt_1);
  tcase_add_test(tc, decToInt_2);
  tcase_add_test(tc, decToInt_3);
  tcase_add_test(tc, decToInt_4);
  tcase_add_test(tc, decToInt_5);
  tcase_add_test(tc, decToInt_6);
  tcase_add_test(tc, decToInt_error1);

  //  dec to float
  tcase_add_test(tc, decToFloat_1);
  tcase_add_test(tc, decToFloat_2);
  tcase_add_test(tc, decToFloat_3);
  tcase_add_test(tc, decToFloat_4);
  tcase_add_test(tc, decToFloat_5);
  tcase_add_test(tc, decToFloat_6);
  tcase_add_test(tc, decToFloat_error1);

  suite_add_tcase(s, tc);
  return s;
}