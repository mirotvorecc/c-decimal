#include "s21_test.h"

START_TEST(truncateTest1) {
  // exp = 2 == 00000000000000100000000000000000; 123,4
  s21_decimal src = {{1234, 0, 0, 131072}};
  s21_decimal truncated = {0};

  s21_truncate(src, &truncated);
  s21_decimal checkResult = {{12, 0, 0, 0}};

  bool result = s21_is_equal(truncated, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(truncateTest2) {
  // exp = 6 == 00000000000000100000000000000000; 123,4
  s21_decimal src = {{2112345678, 0, 0, 524288}};
  s21_decimal truncated = {0};

  s21_truncate(src, &truncated);
  s21_decimal checkResult = {{21, 0, 0, 0}};

  bool result = s21_is_equal(truncated, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(truncateTest3) {
  s21_decimal src = {{4294967295, 4294967295, 4294967295, 1835008}};
  s21_decimal truncated = {0};

  s21_truncate(src, &truncated);
  s21_decimal checkResult = {{7, 0, 0, 0}};

  bool result = s21_is_equal(truncated, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(truncateTest4) {
  s21_decimal src = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal truncated = {0};

  s21_truncate(src, &truncated);
  s21_decimal checkResult = {{4294967295, 4294967295, 4294967295, 0}};

  bool result = s21_is_equal(truncated, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(truncateTest5) {
  s21_decimal src = {{1, 0, 0, 0xFF0000}};
  s21_decimal truncated = {0};

  s21_truncate(src, &truncated);
  s21_decimal checkResult = {{1, 0, 0, 0xFF0000}};

  bool result = s21_is_equal(truncated, checkResult);

  ck_assert_int_eq(result, false);
}
END_TEST;

START_TEST(truncateTest6) {
  s21_decimal src = {{0, 0, 0, 0}};
  s21_decimal truncated = {0};

  s21_truncate(src, &truncated);
  s21_decimal checkResult = {{1, 0, 0, 0xFF0000}};

  bool result = s21_is_equal(truncated, checkResult);

  ck_assert_int_eq(result, false);
}
END_TEST;

START_TEST(truncateTest7) {
  s21_decimal src = {{0, 0, 0, 0}};
  s21_decimal truncated = {0};

  s21_truncate(src, &truncated);
  s21_decimal checkResult = {{0, 0, 0, 0}};

  bool result = s21_is_equal(truncated, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

Suite *truncateTest(void) {
  Suite *s = suite_create("\033[45mtruncateTest\033[0m");
  TCase *tc = tcase_create("truncateTest");

  tcase_add_test(tc, truncateTest1);
  tcase_add_test(tc, truncateTest2);
  tcase_add_test(tc, truncateTest3);
  tcase_add_test(tc, truncateTest4);
  tcase_add_test(tc, truncateTest5);
  tcase_add_test(tc, truncateTest6);
  tcase_add_test(tc, truncateTest7);

  suite_add_tcase(s, tc);
  return s;
}