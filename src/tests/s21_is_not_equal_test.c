#include "s21_test.h"

START_TEST(isNotEqualTest1) {
  s21_decimal value_1 = {{0, 0, 0, 327680}};
  s21_decimal value_2 = {{0, 0, 0, 393216}};

  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

START_TEST(isNotEqualTest2) {
  s21_decimal value_1 = {{0, 0, 0, 2147483648}};
  s21_decimal value_2 = {{0, 0, 0, 0}};

  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

START_TEST(isNotEqualTest3) {
  s21_decimal value_1 = {{300, 0, 0, 65536}};
  s21_decimal value_2 = {{30, 0, 0, 0}};

  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

START_TEST(isNotEqualTest4) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};

  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

START_TEST(isNotEqualTest5) {
  s21_decimal value_1 = {{0, 0, 0, 1}};
  s21_decimal value_2 = {{0, 0, 0, 1}};

  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

START_TEST(isNotEqualTest6) {
  s21_decimal value_1 = {{0, 2147483648, 0, 2147483648}};
  s21_decimal value_2 = {{0, 2147487, 0, 2147483648}};

  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}

START_TEST(isNotEqualTest7) {
  s21_decimal value_1 = {{0, 7, 0, 2147483648}};
  s21_decimal value_2 = {{4, 7, 0, 2147483648}};

  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}

START_TEST(isNotEqualTest8) {
  s21_decimal value_1 = {{0, 7, 0, 2147483648}};
  s21_decimal value_2 = {{0, 7, 0, 2147483648}};

  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

START_TEST(isNotEqualTest9) {
  s21_decimal value_1 = {{300, 0, 0, 0}};
  s21_decimal value_2 = {{301, 0, 0, 0}};

  int result = s21_is_not_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

Suite *isNotEqualTest(void) {
  Suite *s = suite_create("\033[45misNotEqualTest\033[0m");
  TCase *tc = tcase_create("isNotEqualTest");

  tcase_add_test(tc, isNotEqualTest1);
  tcase_add_test(tc, isNotEqualTest2);
  tcase_add_test(tc, isNotEqualTest3);
  tcase_add_test(tc, isNotEqualTest4);
  tcase_add_test(tc, isNotEqualTest5);
  tcase_add_test(tc, isNotEqualTest6);
  tcase_add_test(tc, isNotEqualTest7);
  tcase_add_test(tc, isNotEqualTest8);
  tcase_add_test(tc, isNotEqualTest9);

  suite_add_tcase(s, tc);
  return s;
}