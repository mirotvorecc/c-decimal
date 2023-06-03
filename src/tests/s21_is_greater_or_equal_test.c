#include "s21_test.h"

START_TEST(isGreaterOrEqualTest1) {
  s21_decimal val1 = {{1, 0, 0, 0x80000000}};
  s21_decimal val2 = {{1, 0, 0, 0}};

  int result = s21_is_greater_or_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

START_TEST(isGreaterOrEqualTest2) {
  s21_decimal val1 = {{0x0000009A, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal val2 = {{0x00003C28, 0x00000000, 0x00000000, 0x80020000}};

  int result = s21_is_greater_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isGreaterOrEqualTest3) {
  s21_decimal val1 = {{1, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  int result = s21_is_greater_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isGreaterOrEqualTest4) {
  s21_decimal val1 = {{0x000000F3, 0x00000000, 0x00000000, 0x00020000}};
  s21_decimal val2 = {{0x000000F4, 0x00000000, 0x00000000, 0x00030000}};

  int result = s21_is_greater_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isGreaterOrEqualTest5) {
  s21_decimal val1 = {{1, 0, 0, 0x80000000}};
  s21_decimal val2 = {{1, 0, 0, 0}};

  int result = s21_is_greater_or_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

START_TEST(isGreaterOrEqualTest6) {
  s21_decimal val1 = {{21, 0, 0, 0x80000000}};
  s21_decimal val2 = {{22, 0, 0, 0x80000000}};

  int result = s21_is_greater_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isGreaterOrEqualTest7) {
  s21_decimal val1 = {{0x00000000, 0x00000000, 0x00000000, 0x00070000}};
  s21_decimal val2 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};

  int result = s21_is_greater_or_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

Suite *isGreaterOrEqualTest(void) {
  Suite *s = suite_create("\033[45misGreaterOrEqualTest\033[0m");
  TCase *tc = tcase_create("isGreaterOrEqualTest");

  tcase_add_test(tc, isGreaterOrEqualTest1);
  tcase_add_test(tc, isGreaterOrEqualTest2);
  tcase_add_test(tc, isGreaterOrEqualTest3);
  tcase_add_test(tc, isGreaterOrEqualTest4);
  tcase_add_test(tc, isGreaterOrEqualTest5);
  tcase_add_test(tc, isGreaterOrEqualTest6);
  tcase_add_test(tc, isGreaterOrEqualTest7);

  suite_add_tcase(s, tc);
  return s;
}
