#include "s21_test.h"

START_TEST(addTest1) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {0};
  s21_decimal ans = {0};

  dec1.bits[0] = 123456;
  dec2.bits[0] = 532167;

  s21_decimal true_ans = {0};
  true_ans.bits[0] = 655623;

  int status = s21_add(dec1, dec2, &ans);

  int true_status = 0;

  ck_assert_int_eq(ans.bits[0], true_ans.bits[0]);
  ck_assert_int_eq(status, true_status);
}
END_TEST;

START_TEST(addTest2) {
  s21_decimal dec1 = {{34535, 0, 0, 2147483648}};
  s21_decimal dec2 = {{267977, 0, 0, 0}};
  s21_decimal ans = {0};

  // -34535 + 267977 = 233442

  s21_decimal true_ans = {{233442, 0, 0, 0}};
  int status = s21_add(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], true_ans.bits[0]);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(addTest3) {
  s21_decimal dec1 = {{
      776726685,
      46,
      0,
  }};
  s21_decimal dec2 = {{781775, 542387564, 0, 2147483648}};
  s21_decimal ans = {0};

  // 198345222301 + (-2329536849137888719) = -2329536650792666418

  int status = s21_add(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 3519022386);
  ck_assert_int_eq(ans.bits[1], 542387517);
  ck_assert_int_eq(ans.bits[2], 0);
  ck_assert_int_eq(ans.bits[3], 2147483648);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(addTest4) {
  s21_decimal dec1 = {{86727862, 465437, 1, 2147483648}};
  s21_decimal dec2 = {{355626, 356436333, 52, 2147483648}};
  s21_decimal ans = {0};

  // -18448743110489627830 + (-960761574226238205226) =
  //   -979210317336727833056
  int status = s21_add(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 87083488);
  ck_assert_int_eq(ans.bits[1], 356901770);
  ck_assert_int_eq(ans.bits[2], 53);
  ck_assert_int_eq(ans.bits[3], 2147483648);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(addTest5) {
  s21_decimal dec1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
  s21_decimal dec2 = {{3556453626, 3564363353, 557372952, 0}};
  s21_decimal ans = {0};

  int status = s21_add(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 0);
  ck_assert_int_eq(ans.bits[1], 0);
  ck_assert_int_eq(ans.bits[2], 0);
  ck_assert_int_eq(ans.bits[3], 0);
  ck_assert_int_eq(status, 1);
}
END_TEST;

START_TEST(addTest6) {
  s21_decimal dec1 = {{0xffffffff, 0xffffffff, 0xffffffff, 2147483648}};
  s21_decimal dec2 = {{3556453626, 3564363353, 557372952, 2147483648}};
  s21_decimal ans = {0};

  int status = s21_add(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 0);
  ck_assert_int_eq(ans.bits[1], 0);
  ck_assert_int_eq(ans.bits[2], 0);
  ck_assert_int_eq(ans.bits[3], 0);
  ck_assert_int_eq(status, 2);
}
END_TEST;

START_TEST(addTest7) {
  s21_decimal dec1 = {{435, 243, 43256645, 851968}};
  s21_decimal dec2 = {{454353, 43543535, 2567365545, 1310720}};
  s21_decimal ans = {0};

  //  79794425980230.8951039541683 +        473595351.52461861215095156433
  //  79794425980230.89510395416830000000 + 473595351.52461861215095156433
  // big_ans: 79794899575582.41972256631925156433
  // ans:     79794899575582.41972256631925
  // c#       79794899575582.41972256631925

  int status = s21_add(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 3263556725);
  ck_assert_int_eq(ans.bits[1], 1570006293);
  ck_assert_int_eq(ans.bits[2], 432569017);
  ck_assert_int_eq(ans.bits[3], 917504);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(addTest8) {
  s21_decimal dec1 = {{543, 3, 765555, 2147483648}};
  s21_decimal dec2 = {{5, 7, 45436, 1310720}};
  s21_decimal ans = {0};

  int status = s21_add(dec1, dec2, &ans);

  ck_assert_int_eq(ans.bits[0], 4287128833);
  ck_assert_int_eq(ans.bits[1], 2999);
  ck_assert_int_eq(ans.bits[2], 765555000);
  ck_assert_int_eq(ans.bits[3], 2147680256);
  ck_assert_int_eq(status, 0);
}
END_TEST;

Suite *addTest(void) {
  Suite *s = suite_create("\033[45maddTest\033[0m");
  TCase *tc = tcase_create("addTest");

  tcase_add_test(tc, addTest1);
  tcase_add_test(tc, addTest2);
  tcase_add_test(tc, addTest3);
  tcase_add_test(tc, addTest4);
  tcase_add_test(tc, addTest5);
  tcase_add_test(tc, addTest6);
  tcase_add_test(tc, addTest7);
  tcase_add_test(tc, addTest8);

  suite_add_tcase(s, tc);
  return s;
}