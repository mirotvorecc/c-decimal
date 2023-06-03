#include "s21_test.h"

START_TEST(divTest1) {
  s21_decimal dec1 = {{400, 0, 0, 0}};
  s21_decimal dec2 = {{4, 0, 0, 0}};
  s21_decimal ans = {0};

  int status = s21_div(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 100);
  ck_assert_int_eq(ans.bits[1], 0);
  ck_assert_int_eq(ans.bits[2], 0);
  ck_assert_int_eq(ans.bits[3], 0);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(divTest2) {
  s21_decimal dec1 = {{51, 0, 0, 0}};
  s21_decimal dec2 = {{2, 0, 0, 0}};
  s21_decimal ans = {0};

  int status = s21_div(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 255);
  ck_assert_int_eq(ans.bits[1], 0);
  ck_assert_int_eq(ans.bits[2], 0);
  ck_assert_int_eq(ans.bits[3], 0x000010000);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(divTest3) {
  s21_decimal dec1 = {{3241, 31245, 132456, 0}};
  s21_decimal dec2 = {{35, 0, 0, 0}};
  s21_decimal ans = {0};

  int status = s21_div(dec1, dec2, &ans);

  // 2443381933161468622015657
  // / 35
  // =
  // 69810912376041960629018.771428

  ck_assert_int_eq(ans.bits[0], 706166756);
  ck_assert_int_eq(ans.bits[1], 279147529);
  ck_assert_int_eq(ans.bits[2], 3784457143);
  ck_assert_int_eq(ans.bits[3], 393216);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(divTest4) {
  s21_decimal dec1 = {{9872338, 35345433, 0, 851968}};
  s21_decimal dec2 = {{3525, 34, 0, 1245184}};
  s21_decimal ans = {0};

  int status = s21_div(dec1, dec2, &ans);

  // 15180.7478807831506
  // /
  // 0.0000000146028891589 19
  // =   1039571533796.8558057025299907
  // c#: 1039571533796.8558057025299907

  ck_assert_int_eq(ans.bits[0], 1943659971);
  ck_assert_int_eq(ans.bits[1], 2999259544);
  ck_assert_int_eq(ans.bits[2], 563552857);
  ck_assert_int_eq(ans.bits[3], 1048576);
  ck_assert_int_eq(status, 0);
}
END_TEST;
START_TEST(divTest5) {
  s21_decimal dec1 = {{9872338, 35345433, 0, 851968}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {0};

  int status = s21_div(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 0);
  ck_assert_int_eq(ans.bits[1], 0);
  ck_assert_int_eq(ans.bits[2], 0);
  ck_assert_int_eq(ans.bits[3], 0);
  ck_assert_int_eq(status, 3);
}
END_TEST;

START_TEST(divTest6) {
  s21_decimal dec1 = {{5435, 643666, 23456, 851968}};
  s21_decimal dec2 = {{1, 0, 0, 0}};
  s21_decimal ans = {0};

  int status = s21_div(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 5435);
  ck_assert_int_eq(ans.bits[1], 643666);
  ck_assert_int_eq(ans.bits[2], 23456);
  ck_assert_int_eq(ans.bits[3], 851968);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(divTest7) {
  s21_decimal dec1 = {{5435, 643666, 23456, 851968}};
  s21_decimal dec2 = {{1, 0, 0, 2147483648}};
  s21_decimal ans = {0};

  int status = s21_div(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 5435);
  ck_assert_int_eq(ans.bits[1], 643666);
  ck_assert_int_eq(ans.bits[2], 23456);
  ck_assert_int_eq(ans.bits[3], 2148335616);
  ck_assert_int_eq(status, 0);
}
END_TEST;

Suite *divTest(void) {
  Suite *s = suite_create("\033[45mdivTest\033[0m");
  TCase *tc = tcase_create("divTest");

  tcase_add_test(tc, divTest1);
  tcase_add_test(tc, divTest2);
  tcase_add_test(tc, divTest3);
  tcase_add_test(tc, divTest4);
  tcase_add_test(tc, divTest5);
  tcase_add_test(tc, divTest6);
  tcase_add_test(tc, divTest7);

  suite_add_tcase(s, tc);
  return s;
}