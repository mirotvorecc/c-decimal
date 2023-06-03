#include "s21_test.h"

START_TEST(negateTest1) {
  s21_decimal src = {{45671, 12, 56783, 2148728832}};
  s21_decimal negated = {0};

  s21_negate(src, &negated);
  s21_decimal checkResult = {{45671, 12, 56783, 1245184}};

  bool result = s21_is_equal(negated, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(negateTest2) {
  s21_decimal src = {{45671, 12, 56783, 1245184}};
  s21_decimal negated = {0};

  s21_negate(src, &negated);
  s21_decimal checkResult = {{45671, 12, 56783, 2148728832}};

  bool result = s21_is_equal(negated, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(negateTest3) {
  s21_decimal src = {{0, 0, 0, 1245184}};
  s21_decimal negated = {0};

  s21_negate(src, &negated);
  s21_decimal checkResult = {{0, 0, 0, 2148728832}};  //  -0 / (10^n)

  bool result = s21_is_equal(negated, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(negateTest4) {
  s21_decimal src = {{0, 0, 0, 1245184}};
  s21_decimal negated = {0};

  s21_negate(src, &negated);
  s21_decimal checkResult = {{0, 0, 0, 1245184}};  //  +0 / (10^n)

  bool result = s21_is_equal(negated, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(negateTest5) {
  s21_decimal src = {0};  //  +0
  s21_decimal negated = {0};

  s21_negate(src, &negated);
  s21_decimal checkResult = {{0, 0, 0, 2147483648}};  // -0 / (10 ^ 0)

  bool result = s21_is_equal(negated, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(negateTest6) {
  s21_decimal src = {0};  //  +0
  s21_decimal negated = {0};

  s21_negate(src, &negated);
  s21_decimal checkResult = {{0, 0, 0, 2147483648}};  // -0 / (10 ^ 0)

  bool result = s21_is_equal(negated, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(negateTest7) {
  s21_decimal src = {{1, 0, 0, 0xFF0000}};
  s21_decimal negated = {0};

  s21_negate(src, &negated);
  s21_decimal checkResult = {{1, 0, 0, 0x80FF0000}};

  bool result = s21_is_equal(negated, checkResult);

  ck_assert_int_eq(result, false);
}
END_TEST;

Suite *negateTest(void) {
  Suite *s = suite_create("\033[45mnegateTest\033[0m");
  TCase *tc = tcase_create("negateTest");

  tcase_add_test(tc, negateTest1);
  tcase_add_test(tc, negateTest2);
  tcase_add_test(tc, negateTest3);
  tcase_add_test(tc, negateTest4);
  tcase_add_test(tc, negateTest5);
  tcase_add_test(tc, negateTest6);
  tcase_add_test(tc, negateTest7);

  suite_add_tcase(s, tc);
  return s;
}