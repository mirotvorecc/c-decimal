#include "s21_test.h"

START_TEST(isLessOrEqualTest1) {
  s21_decimal val1 = {{1, 0, 0, 0x80000000}};
  s21_decimal val2 = {{1, 0, 0, 0}};

  int result = s21_is_less_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isLessOrEqualTest2) {
  s21_decimal val1 = {{0x00000000, 0x00000000, 0x00000000, 0x800A0000}};
  s21_decimal val2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};

  int result = s21_is_less_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isLessOrEqualTest3) {
  s21_decimal val1 = {{10, 0, 0, 0}};
  s21_decimal val2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};

  int result = s21_is_less_or_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

START_TEST(isLessOrEqualTest4) {
  s21_decimal val1 = {{27, 0, 0, 0x80000000}};
  s21_decimal val2 = {{27, 0, 0, 0}};

  int result = s21_is_less_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isLessOrEqualTest5) {
  s21_decimal val1 = {{145, 0x00000000, 0x00000000, 0}};
  s21_decimal val2 = {{144, 0x00000000, 0x00000000, 0}};

  int result = s21_is_less_or_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

START_TEST(isLessOrEqualTest6) {
  s21_decimal val1 = {{10, 0, 0, 0}};
  s21_decimal val2 = {{9, 0, 0, 0}};

  int result = s21_is_less_or_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

START_TEST(isLessOrEqualTest7) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{1, 0, 0, 0}};

  int result = s21_is_less_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

Suite *isLessOrEqualTest(void) {
  Suite *s = suite_create("\033[45misLessOrEqualTest\033[0m");
  TCase *tc = tcase_create("isLessOrEqualTest");

  tcase_add_test(tc, isLessOrEqualTest1);
  tcase_add_test(tc, isLessOrEqualTest2);
  tcase_add_test(tc, isLessOrEqualTest3);
  tcase_add_test(tc, isLessOrEqualTest4);
  tcase_add_test(tc, isLessOrEqualTest5);
  tcase_add_test(tc, isLessOrEqualTest6);
  tcase_add_test(tc, isLessOrEqualTest7);

  suite_add_tcase(s, tc);
  return s;
}