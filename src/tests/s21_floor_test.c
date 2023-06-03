#include "s21_test.h"

START_TEST(floorTest1) {
  s21_decimal src = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal floored = {0};

  s21_floor(src, &floored);
  s21_decimal checkResult = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};

  bool result = s21_is_equal(floored, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(floorTest2) {
  s21_decimal src = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  s21_decimal floored = {0};

  s21_floor(src, &floored);
  s21_decimal checkResult = {{0x00000008, 0x00000000, 0x00000000, 0x80000000}};

  bool result = s21_is_equal(floored, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(floorTest3) {
  s21_decimal src = {{0xAC471B48, 0x0000A7C5, 0x00000000, 0x80000000}};
  s21_decimal floored = {0};

  s21_floor(src, &floored);
  s21_decimal checkResult = {{0x00000008, 0x00000000, 0x00000000, 0x80000000}};

  bool result = s21_is_equal(floored, checkResult);

  ck_assert_int_eq(result, false);
}
END_TEST;

START_TEST(floorTest4) {
  s21_decimal src = {{1, 0, 0, 0xFF0000}};
  s21_decimal floored = {0};

  s21_floor(src, &floored);
  s21_decimal checkResult = {{1, 0, 0, 0xFF0000}};

  bool result = s21_is_equal(floored, checkResult);

  ck_assert_int_eq(result, false);
}
END_TEST;

START_TEST(floorTest5) {
  s21_decimal src = {{1, 0, 0, 0xFF0000}};
  s21_decimal floored = {0};

  s21_floor(src, &floored);
  s21_decimal checkResult = {{0x00000008, 0x00000000, 0x00000000, 0x80000000}};

  bool result = s21_is_equal(floored, checkResult);

  ck_assert_int_eq(result, false);
}
END_TEST;

START_TEST(floorTest6) {
  s21_decimal src = {{1, 0, 0, 0}};
  s21_decimal floored = {0};

  s21_floor(src, &floored);
  s21_decimal checkResult = {{1, 0, 0, 0}};

  bool result = s21_is_equal(floored, checkResult);

  ck_assert_int_eq(result, true);
}
END_TEST;

START_TEST(floorTest7) {
  s21_decimal src = {{0, 0, 0, 0}};
  s21_decimal floored = {0};

  s21_floor(src, &floored);
  s21_decimal checkResult = {{1, 0, 0, 0}};

  bool result = s21_is_equal(floored, checkResult);

  ck_assert_int_eq(result, false);
}
END_TEST;

Suite *floorTest(void) {
  Suite *s = suite_create("\033[45mfloorTest\033[0m");
  TCase *tc = tcase_create("floorTest");

  tcase_add_test(tc, floorTest1);
  tcase_add_test(tc, floorTest2);
  tcase_add_test(tc, floorTest3);
  tcase_add_test(tc, floorTest4);
  tcase_add_test(tc, floorTest5);
  tcase_add_test(tc, floorTest6);
  tcase_add_test(tc, floorTest7);

  suite_add_tcase(s, tc);
  return s;
}