#include "s21_test.h"

START_TEST(fromIntToDecimalTest1) {
  int n = 47352465;
  s21_decimal d = {0};
  s21_from_int_to_decimal(n, &d);

  ck_assert_int_eq(d.bits[0], n);
}
END_TEST;

START_TEST(fromIntToDecimalTest2) {
  int n = 0;
  s21_decimal d = {0};
  s21_from_int_to_decimal(n, &d);

  ck_assert_int_eq(d.bits[0], n);
}
END_TEST;

START_TEST(fromIntToDecimalTest3) {
  int n = -351453;
  s21_decimal d = {0};
  s21_from_int_to_decimal(n, &d);

  ck_assert_int_eq(checkBit(d.bits[3], signBitIndex), 1);
  ck_assert_int_eq(d.bits[0], 351453);
}
END_TEST;

Suite *fromIntToDecimalTest(void) {
  Suite *s = suite_create("\033[45mfromIntToDecimalTest\033[0m");
  TCase *tc = tcase_create("fromIntToDecimalTest");

  tcase_add_test(tc, fromIntToDecimalTest1);
  tcase_add_test(tc, fromIntToDecimalTest2);
  tcase_add_test(tc, fromIntToDecimalTest3);

  suite_add_tcase(s, tc);
  return s;
}
