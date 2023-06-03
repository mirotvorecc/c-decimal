#include "s21_test.h"

START_TEST(fromFloatToDecimalTest1) {
  float n = 33.6755;
  s21_decimal input = {0};
  s21_decimal res = {{3367550, 0, 0, 327680}};
  s21_from_float_to_decimal(n, &input);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(input.bits[i], res.bits[i]);
  }
}
END_TEST;

START_TEST(fromFloatToDecimalTest2) {
  float inp = 321213143.8323;
  //           321213200

  s21_decimal dec = {0};
  int flag = s21_from_float_to_decimal(inp, &dec);

  s21_decimal res = {{321213200, 0, 0, 0}};

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(dec.bits[i], res.bits[i]);
  }

  ck_assert_int_eq(flag, 0);
}
END_TEST;

START_TEST(fromFloatToDecimalTest3) {
  s21_decimal val = {0};
  float a = -1e-30;
  int error = s21_from_float_to_decimal(a, &val);

  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
  ck_assert_int_eq(error, 1);
}
END_TEST;

START_TEST(fromFloatToDecimalTest4) {
  float inp = 73.329959999;
  s21_decimal out = {{3211, 123145, 231, 312441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x006FE484, 0, 0, 0x00050000}};

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(out.bits[i], res.bits[i]);
  }

  ck_assert_int_eq(error, 0);
}
END_TEST;

START_TEST(fromFloatToDecimalTest5) {
  float inp = 0.003;
  //          0.003000000

  s21_decimal dec = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &dec);
  s21_decimal res = {{3000000, 0, 0, 589824}};

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(dec.bits[i], res.bits[i]);
  }

  ck_assert_int_eq(error, 0);
}
END_TEST;

START_TEST(fromFloatToDecimalTest6) {
  float inp = (float)7015000000000000000000000000.365656;

  s21_decimal dec = {0};
  int error = s21_from_float_to_decimal(inp, &dec);
  s21_decimal res = {{3338665984, 4291920790, 380283911, 0}};

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(dec.bits[i], res.bits[i]);
  }

  ck_assert_int_eq(error, 0);
}
END_TEST;

START_TEST(fromFloatToDecimalTest7) {
  float inp = 0.00000000000000075;
  //          0.0000000000000007500000
  s21_decimal dec = {0};

  int error = s21_from_float_to_decimal(inp, &dec);

  s21_decimal expected_ans = {{7500000, 0, 0, 1441792}};

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(dec.bits[i], expected_ans.bits[i]);
  }

  ck_assert_int_eq(error, 0);
}
END_TEST;

START_TEST(fromFloatToDecimalTest8) {
  float inp = -0.00723666;
  //          -0.007236660
  s21_decimal dec = {0};

  int error = s21_from_float_to_decimal(inp, &dec);

  s21_decimal expected_ans = {{7236660, 0, 0, 2148073472}};

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(dec.bits[i], expected_ans.bits[i]);
  }

  ck_assert_int_eq(error, 0);
}
END_TEST;

START_TEST(fromFloatToDecimalTest9) {
  float inp = 0;

  s21_decimal dec = {0};

  int error = s21_from_float_to_decimal(inp, &dec);

  s21_decimal expected_ans = {{0, 0, 0, 393216}};

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(dec.bits[i], expected_ans.bits[i]);
  }

  ck_assert_int_eq(error, 0);
}
END_TEST;

Suite *fromFloatToDecimalTest(void) {
  Suite *s = suite_create("\033[45mfromFloatToDecimalTest\033[0m");
  TCase *tc = tcase_create("fromFloatToDecimalTest");

  tcase_add_test(tc, fromFloatToDecimalTest1);
  tcase_add_test(tc, fromFloatToDecimalTest2);
  tcase_add_test(tc, fromFloatToDecimalTest3);
  tcase_add_test(tc, fromFloatToDecimalTest4);
  tcase_add_test(tc, fromFloatToDecimalTest5);
  tcase_add_test(tc, fromFloatToDecimalTest6);
  tcase_add_test(tc, fromFloatToDecimalTest7);
  tcase_add_test(tc, fromFloatToDecimalTest8);
  tcase_add_test(tc, fromFloatToDecimalTest9);

  suite_add_tcase(s, tc);
  return s;
}