#include "s21_test.h"

START_TEST(isEqualTest1) {
  s21_decimal value_1 = {{0, 0, 0, 327680}};
  s21_decimal value_2 = {{0, 0, 0, 393216}};

  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isEqualTest2) {
  s21_decimal value_1 = {{0, 0, 0, 2147483648}};
  s21_decimal value_2 = {{0, 0, 0, 0}};

  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isEqualTest3) {
  s21_decimal value_1 = {{300, 0, 0, 65536}};
  s21_decimal value_2 = {{30, 0, 0, 0}};

  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isEqualTest4) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};

  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isEqualTest5) {
  s21_decimal value_1 = {{0, 0, 0, 1}};
  s21_decimal value_2 = {{0, 0, 0, 1}};

  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isEqualTest6) {
  s21_decimal value_1 = {{0, 2147483648, 0, 2147483648}};
  s21_decimal value_2 = {{0, 2147487, 0, 2147483648}};

  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}

START_TEST(isEqualTest7) {
  s21_decimal value_1 = {{0, 7, 0, 2147483648}};
  s21_decimal value_2 = {{4, 7, 0, 2147483648}};

  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}

START_TEST(isEqualTest8) {
  s21_decimal value_1 = {{0, 7, 0, 2147483648}};
  s21_decimal value_2 = {{0, 7, 0, 2147483648}};

  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 1);
}

END_TEST;

START_TEST(isEqualTest9) {
  s21_decimal value_1 = {{300, 0, 0, 0}};
  s21_decimal value_2 = {{301, 0, 0, 0}};

  int result = s21_is_equal(value_1, value_2);
  ck_assert_int_eq(result, 0);
}

END_TEST;

Suite *isEqualTest(void) {
  Suite *s = suite_create("\033[45misEqualTest\033[0m");
  TCase *tc = tcase_create("isEqualTest");

  tcase_add_test(tc, isEqualTest1);
  tcase_add_test(tc, isEqualTest2);
  tcase_add_test(tc, isEqualTest3);
  tcase_add_test(tc, isEqualTest4);
  tcase_add_test(tc, isEqualTest5);
  tcase_add_test(tc, isEqualTest6);
  tcase_add_test(tc, isEqualTest7);
  tcase_add_test(tc, isEqualTest8);
  tcase_add_test(tc, isEqualTest9);

  suite_add_tcase(s, tc);
  return s;
}