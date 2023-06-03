#include "s21_test.h"

// 0 - OK
// 1 - INFINITY
// 2 - (-INFINITY)

START_TEST(mulTest1) {
  //
  // пушим в scale биг децимала 0 и ожидаем бесконечность

  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{4294967295, 4294967295, 4294967295, 228}};
  s21_decimal dec3 = {0};
  s21_decimal dec4 = {0};

  int status = s21_mul(dec1, dec2, &dec3);

  int expected_status = 0;
  ck_assert_int_eq(status, expected_status);
  ck_assert_int_eq(s21_is_equal(dec3, dec4), 1);
}

END_TEST;

START_TEST(mulTest2) {
  //
  // пушим в scale биг децимала -29 и ожидаем минус бесконечность

  s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, 2147483648}};
  s21_decimal dec2 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal dec3 = {0};

  int status = s21_mul(dec1, dec2, &dec3);

  int expected_status = 2;
  ck_assert_int_eq(status, expected_status);
}

END_TEST;

START_TEST(mulTest3) {
  //
  // умножаем 1 на 2 и ожидаем статус 0 и ответ 2

  s21_decimal dec1 = {{1, 0, 0, 0}};
  s21_decimal dec2 = {{2, 0, 0, 0}};
  s21_decimal dec3 = {0};

  int status = s21_mul(dec1, dec2, &dec3);

  int expected_status = 0;
  ck_assert_int_eq(status, expected_status);
  ck_assert_int_eq(s21_is_equal(dec2, dec3), 1);
}

END_TEST;

START_TEST(mulTest4) {
  //
  // умножаем 2042234234 на 202334324 и ожидаем статус 0 и ответ
  // 413214083186047816413214083186047816

  s21_decimal dec1 = {{2042234234, 0, 0, 0}};
  s21_decimal dec2 = {{202334324, 0, 0, 0}};
  s21_decimal dec3 = {0};
  s21_decimal dec4 = {{0xF47E3B48, 0x5BC0804, 0, 0}};

  int status = s21_mul(dec1, dec2, &dec3);

  int expected_status = 0;
  ck_assert_int_eq(status, expected_status);
  ck_assert_int_eq(s21_is_equal(dec3, dec4), 1);
}

END_TEST;

START_TEST(mulTest5) {
  //
  // умножаем 0 на 0 и ожидаем статус 0 и ответ 0

  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal dec3 = {0};
  s21_decimal dec4 = {{0, 0, 0, 0}};

  int status = s21_mul(dec1, dec2, &dec3);

  int expected_status = 0;
  ck_assert_int_eq(status, expected_status);
  ck_assert_int_eq(s21_is_equal(dec3, dec4), 1);
}

END_TEST;

START_TEST(mulTest6) {
  //
  // умножаем 0 на 0 и ожидаем статус 0 и ответ 0

  s21_decimal dec1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal dec2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal dec3 = {0};
  s21_decimal dec4 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};

  int status = s21_mul(dec1, dec2, &dec3);

  int expected_status = 0;
  ck_assert_int_eq(status, expected_status);
  ck_assert_int_eq(s21_is_equal(dec3, dec4), 1);
}

END_TEST;

START_TEST(mulTest7) {
  //
  // умножаем 0.000 на 0.00000 и ожидаем статус 0 и ответ 0.00000000

  s21_decimal dec1 = {{0x00000000, 0x00000000, 0x00000000, 0x00030000}};
  s21_decimal dec2 = {{0x00000000, 0x00000000, 0x00000000, 0x80050000}};
  s21_decimal dec3 = {0};
  s21_decimal dec4 = {{0x00000000, 0x00000000, 0x00000000, 0x80080000}};

  int status = s21_mul(dec1, dec2, &dec3);

  int expected_status = 0;
  ck_assert_int_eq(status, expected_status);
  ck_assert_int_eq(s21_is_equal(dec3, dec4), 1);
}

END_TEST;

START_TEST(mulTest8) {
  //
  // умножаем 1,5 на 2 и ожидаем статус 0 и ответ 3.0

  s21_decimal dec1 = {{0x0000000F, 0x00000000, 0x00000000, 0x00010000}};
  s21_decimal dec2 = {{0x00000002, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal dec3 = {0};
  s21_decimal dec4 = {{0x0000001E, 0x00000000, 0x00000000, 0x00010000}};

  int status = s21_mul(dec1, dec2, &dec3);

  int expected_status = 0;
  ck_assert_int_eq(status, expected_status);
  ck_assert_int_eq(s21_is_equal(dec3, dec4), 1);
}

END_TEST;

START_TEST(mulTest9) {
  //
  // умножаем 0.000000000000001 на 10000000000 и ожидаем статус 0 и ответ
  // 0.000010000000000

  s21_decimal dec1 = {{0x00000001, 0x00000000, 0x00000000, 0x000F0000}};
  s21_decimal dec2 = {{0x540BE400, 0x00000002, 0x00000000, 0x00000000}};
  s21_decimal dec3 = {0};
  s21_decimal dec4 = {{0x540BE400, 0x00000002, 0x00000000, 0x000F0000}};

  int status = s21_mul(dec1, dec2, &dec3);

  int expected_status = 0;
  ck_assert_int_eq(status, expected_status);
  ck_assert_int_eq(s21_is_equal(dec3, dec4), 1);
}

END_TEST;

START_TEST(mulTest10) {
  //
  // умножаем -79228.162514264337593543950335 на 79228.162514264337593543950335
  // и ожидаем статус 0 и ответ -6277101735.3866807638357894230

  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00180000}};
  s21_decimal dec3 = {0};
  s21_decimal dec4 = {{0x096EE456, 0x359A3B3E, 0xCAD2F7F5, 0x80130000}};

  int status = s21_mul(dec1, dec2, &dec3);

  int expected_status = 0;
  ck_assert_int_eq(status, expected_status);
  ck_assert_int_eq(s21_is_equal(dec3, dec4), 1);
}

END_TEST;

START_TEST(mulTest11) {
  //
  // умножаем -79228.162514264337593543950335 на 79228.162514264337593543950335
  // и ожидаем статус 0 и ответ -6277101735.3866807638357894230

  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal dec2 = {{0x00000001, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal dec3 = {0};
  s21_decimal dec4 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};

  int status = s21_mul(dec1, dec2, &dec3);

  int expected_status = 0;
  ck_assert_int_eq(status, expected_status);
  ck_assert_int_eq(s21_is_equal(dec3, dec4), 1);
}

END_TEST;

Suite *mulTest(void) {
  Suite *s = suite_create("\033[45mmulTest\033[0m");
  TCase *tc = tcase_create("mulTest");

  tcase_add_test(tc, mulTest1);
  tcase_add_test(tc, mulTest2);
  tcase_add_test(tc, mulTest3);
  tcase_add_test(tc, mulTest4);
  tcase_add_test(tc, mulTest5);
  tcase_add_test(tc, mulTest6);
  tcase_add_test(tc, mulTest7);
  tcase_add_test(tc, mulTest8);
  tcase_add_test(tc, mulTest9);
  tcase_add_test(tc, mulTest10);
  tcase_add_test(tc, mulTest11);

  suite_add_tcase(s, tc);
  return s;
}
