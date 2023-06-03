#include "s21_test.h"

START_TEST(subTest1) {
  s21_decimal dec1 = {{14, 0, 0, 0}};
  s21_decimal dec2 = {{8, 0, 0, 0}};
  s21_decimal ans = {0};

  int status = s21_sub(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 6);
  ck_assert_int_eq(ans.bits[1], 0);
  ck_assert_int_eq(ans.bits[2], 0);
  ck_assert_int_eq(ans.bits[3], 0);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(subTest2) {
  s21_decimal dec1 = {{7843786, 0, 0, 0}};
  s21_decimal dec2 = {{4532, 0, 0, 0}};
  s21_decimal ans = {0};

  int status = s21_sub(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 7839254);
  ck_assert_int_eq(ans.bits[1], 0);
  ck_assert_int_eq(ans.bits[2], 0);
  ck_assert_int_eq(ans.bits[3], 0);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(subTest3) {
  s21_decimal dec1 = {{14324, 0, 0, 0}};
  s21_decimal dec2 = {{32455775, 0, 0, 0}};
  s21_decimal ans = {0};

  int status = s21_sub(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 32441451);
  ck_assert_int_eq(ans.bits[1], 0);
  ck_assert_int_eq(ans.bits[2], 0);
  ck_assert_int_eq(ans.bits[3], 2147483648);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(subTest4) {
  s21_decimal dec1 = {{14324, 0, 0, 0}};
  s21_decimal dec2 = {{32455775, 0, 0, 0}};
  s21_decimal ans = {0};

  int status = s21_sub(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 32441451);
  ck_assert_int_eq(ans.bits[1], 0);
  ck_assert_int_eq(ans.bits[2], 0);
  ck_assert_int_eq(ans.bits[3], 2147483648);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(subTest5) {
  s21_decimal dec1 = {{346256456, 542664727, 452847392, 0}};
  s21_decimal dec2 = {{32455775, 4583772, 74656458, 0}};
  s21_decimal ans = {0};

  int status = s21_sub(dec1, dec2, &ans);

  // 8353559947001553470299010120
  // -
  // 1377168574195333195283512415
  // =
  // 6976391372806220275015497705

  ck_assert_int_eq(ans.bits[0], 313800681);
  ck_assert_int_eq(ans.bits[1], 538080955);
  ck_assert_int_eq(ans.bits[2], 378190934);
  ck_assert_int_eq(ans.bits[3], 0);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(subTest6) {
  s21_decimal dec1 = {{234, 46, 2, 2147483648}};
  s21_decimal dec2 = {{53465463, 7, 48378945, 2147483648}};
  s21_decimal ans = {0};

  int status = s21_sub(dec1, dec2, &ans);

  // -36893488344987599082
  // -
  // -892434016971070373723361655
  // =
  //  892433980077582028735762573

  ck_assert_int_eq(ans.bits[0], 53465229);
  ck_assert_int_eq(ans.bits[1], 4294967257);
  ck_assert_int_eq(ans.bits[2], 48378942);
  ck_assert_int_eq(ans.bits[3], 0);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(subTest7) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {0};

  int status = s21_sub(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 0);
  ck_assert_int_eq(ans.bits[1], 0);
  ck_assert_int_eq(ans.bits[2], 0);
  ck_assert_int_eq(ans.bits[3], 0);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(subTest8) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{45254245, 2345245, 2, 0}};
  s21_decimal ans = {0};

  int status = s21_sub(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 45254245);
  ck_assert_int_eq(ans.bits[1], 2345245);
  ck_assert_int_eq(ans.bits[2], 2);
  ck_assert_int_eq(ans.bits[3], 2147483648);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(subTest9) {
  s21_decimal dec1 = {{5463, 5356727, 766553, 2147483648}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {0};

  int status = s21_sub(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 5463);
  ck_assert_int_eq(ans.bits[1], 5356727);
  ck_assert_int_eq(ans.bits[2], 766553);
  ck_assert_int_eq(ans.bits[3], 2147483648);
  ck_assert_int_eq(status, 0);
}
END_TEST;

Suite *subTest(void) {
  Suite *s = suite_create("\033[45msubTest\033[0m");
  TCase *tc = tcase_create("addTest");

  tcase_add_test(tc, subTest1);
  tcase_add_test(tc, subTest2);
  tcase_add_test(tc, subTest3);
  tcase_add_test(tc, subTest4);
  tcase_add_test(tc, subTest5);
  tcase_add_test(tc, subTest6);
  tcase_add_test(tc, subTest7);
  tcase_add_test(tc, subTest8);
  tcase_add_test(tc, subTest9);

  suite_add_tcase(s, tc);
  return s;
}