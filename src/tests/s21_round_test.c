#include "s21_test.h"

START_TEST(roundTest1) {
  s21_decimal src = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  s21_decimal rounded = {0};

  s21_round(src, &rounded);
  s21_decimal checkResult = {{0x00000008, 0x00000000, 0x00000000, 0x80000000}};

  bool result = s21_is_equal(rounded, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(roundTest2) {
  s21_decimal src = {{0, 0, 0, 0}};
  s21_decimal rounded = {0};

  s21_round(src, &rounded);
  s21_decimal checkResult = {{0, 0, 0, 0}};

  bool result = s21_is_equal(rounded, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(roundTest3) {
  s21_decimal src = {{1, 0, 0, 0xFF0000}};
  s21_decimal rounded = {0};

  s21_round(src, &rounded);
  s21_decimal checkResult = {{1, 0, 0, 0xFF0000}};

  bool result = s21_is_equal(rounded, checkResult);

  ck_assert_int_eq(result, false);
}
END_TEST;

START_TEST(roundTest4) {
  s21_decimal src = {{1, 0, 0, 0x80000000}};
  s21_decimal rounded = {0};

  s21_round(src, &rounded);
  s21_decimal checkResult = {{1, 0, 0, 0x80000000}};

  bool result = s21_is_equal(rounded, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(roundTest5) {
  s21_decimal src = {{1, 0, 0, 0x30000}};
  s21_decimal rounded = {0};

  s21_round(src, &rounded);
  s21_decimal checkResult = {{1, 0, 0, 0x30000}};

  bool result = s21_is_equal(rounded, checkResult);

  ck_assert_int_eq(result, false);
}
END_TEST;

START_TEST(roundTest6) {
  s21_decimal src = {{0, 0, 0, 0}};
  s21_decimal rounded = {0};

  s21_round(src, &rounded);
  s21_decimal checkResult = {{0, 0, 0, 0}};

  bool result = s21_is_equal(rounded, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(roundTest7) {
  s21_decimal src = {{1, 0, 0, 0}};
  s21_decimal rounded = {0};

  s21_round(src, &rounded);
  s21_decimal checkResult = {{1, 0, 0, 0}};

  bool result = s21_is_equal(rounded, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

Suite *roundTest(void) {
  Suite *s = suite_create("\033[45mroundTest\033[0m");
  TCase *tc = tcase_create("roundTest");

  tcase_add_test(tc, roundTest1);
  tcase_add_test(tc, roundTest2);
  tcase_add_test(tc, roundTest3);
  tcase_add_test(tc, roundTest4);
  tcase_add_test(tc, roundTest5);
  tcase_add_test(tc, roundTest6);
  tcase_add_test(tc, roundTest7);

  suite_add_tcase(s, tc);
  return s;
}