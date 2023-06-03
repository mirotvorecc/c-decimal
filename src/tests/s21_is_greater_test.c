#include "s21_test.h"

START_TEST(isGreaterTest1) {
  s21_decimal val1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal val2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};

  int result = s21_is_greater(val1, val2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

START_TEST(isGreaterTest2) {
  s21_decimal val1 = {{0x00000000, 0x00000000, 0x00000000, 0x00030000}};
  s21_decimal val2 = {{0x00000000, 0x00000000, 0x00000000, 0x00010000}};

  int result = s21_is_greater(val1, val2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

START_TEST(isGreaterTest3) {
  s21_decimal val1 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal val2 = {{0x00000000, 0x00000000, 0x00000000, 0x00070000}};

  int result = s21_is_greater(val1, val2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isGreaterTest4) {
  s21_decimal val1 = {{0x00000025, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal val2 = {{0x00000024, 0x00000000, 0x00000000, 0x00000000}};

  int result = s21_is_greater(val1, val2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isGreaterTest5) {
  s21_decimal val1 = {{2, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal val2 = {{1, 0x00000000, 0x00000000, 0x00000000}};

  int result = s21_is_greater(val1, val2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isGreaterTest6) {
  s21_decimal val1 = {{0, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal val2 = {{1, 0x00000000, 0x00000000, 0x00000000}};

  int result = s21_is_greater(val1, val2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

START_TEST(isGreaterTest7) {
  s21_decimal val1 = {{789, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal val2 = {{788, 0x00000000, 0x00000000, 0x00000000}};

  int result = s21_is_greater(val1, val2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

Suite *isGreaterTest(void) {
  Suite *s = suite_create("\033[45misGreaterTest\033[0m");
  TCase *tc = tcase_create("isGreaterTest");

  tcase_add_test(tc, isGreaterTest1);
  tcase_add_test(tc, isGreaterTest2);
  tcase_add_test(tc, isGreaterTest3);
  tcase_add_test(tc, isGreaterTest4);
  tcase_add_test(tc, isGreaterTest5);
  tcase_add_test(tc, isGreaterTest6);
  tcase_add_test(tc, isGreaterTest7);

  suite_add_tcase(s, tc);
  return s;
}