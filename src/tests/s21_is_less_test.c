#include "s21_test.h"

START_TEST(isLessTest1) {
  s21_decimal value_1 = {{0, 0, 0, 327680}};
  s21_decimal value_2 = {{0, 0, 0, 393216}};

  int result = s21_is_less(value_1, value_2);
  ck_assert_int_eq(result, 0);
}

START_TEST(isLessTest0) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(isLessTest2) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(isLessTest3) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(isLessTest4) {
  s21_decimal val1 = {{123, 0, 0, 0}};
  s21_decimal val2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(isLessTest5) {
  s21_decimal val1 = {{0, 140, 0, 0}};
  s21_decimal val2 = {{0, 320, 0, 0}};
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(isLessTest6) {
  s21_decimal val1 = {{0, 0, 140, 0}};
  s21_decimal val2 = {{0, 0, 320, 0}};
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(isLessTest7) {
  s21_decimal val1 = {{123, 12, 1, 0}};
  s21_decimal val2 = {{23200, 233020, 1, 0}};
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(isLessTest8) {
  s21_decimal val1 = {{123, 666666, 4, 0}};
  s21_decimal val2 = {{23200, 233020, 1, 0}};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(isLessTest9) {
  s21_decimal val1 = {{123, 666666, 1, 0}};
  s21_decimal val2 = {{23200, 666666, 1, 0}};
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(isLessTest10) {
  s21_decimal val1 = {{23200, 666666, 1, 0}};
  s21_decimal val2 = {{123, 666666, 1, 0}};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(isLessTest11) {
  s21_decimal val1 = {{1, 0, 0, 0}};
  s21_decimal val2 = {{123, 666666, 489389, 2149318656}};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(isLessTest12) {
  s21_decimal val1 = {{23200, 666666, 1, 2149318656}};
  s21_decimal val2 = {{1, 0, 0, 0}};
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(isLessTest13) {
  s21_decimal val1 = {{0x00000000, 0x00000000, 0x00000000, 0x800A0000}};
  s21_decimal val2 = {{0x00000000, 0x00000000, 0x00000000, 0x00030000}};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(isLessTest14) {
  s21_decimal val1 = {{0x0000000C, 0x00000000, 0x00000000, 0x80010000}};
  s21_decimal val2 = {{0x00000070, 0x00000000, 0x00000000, 0x80020000}};
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

Suite *isLessTest(void) {
  Suite *s = suite_create("\033[45misLessTest\033[0m");
  TCase *tc = tcase_create("isLessTest");

  tcase_add_test(tc, isLessTest0);
  tcase_add_test(tc, isLessTest1);
  tcase_add_test(tc, isLessTest2);
  tcase_add_test(tc, isLessTest3);
  tcase_add_test(tc, isLessTest4);
  tcase_add_test(tc, isLessTest5);
  tcase_add_test(tc, isLessTest6);
  tcase_add_test(tc, isLessTest7);
  tcase_add_test(tc, isLessTest8);
  tcase_add_test(tc, isLessTest9);
  tcase_add_test(tc, isLessTest10);
  tcase_add_test(tc, isLessTest11);
  tcase_add_test(tc, isLessTest12);
  tcase_add_test(tc, isLessTest13);
  tcase_add_test(tc, isLessTest14);

  suite_add_tcase(s, tc);
  return s;
}