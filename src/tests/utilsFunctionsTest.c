#include "s21_test.h"

START_TEST(isDecimalOverflowTest1) {
  s21_big_decimal src = {{0xffffffff, 0xffffffff, 0xfffff000, 0, 0, 0, 0}};
  bool result = isBigDecimalOverflowed(src);

  ck_assert_int_eq(result, false);
}
END_TEST;

START_TEST(isDecimalOverflowTest2) {
  s21_big_decimal src = {
      {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0, 0, 0}};
  bool result = isBigDecimalOverflowed(src);
  bool expected = true;

  ck_assert_int_eq(result, expected);
}
END_TEST;

START_TEST(isDecimalOverflowTest3) {
  s21_big_decimal src = {{0xffffffff, 0xffffffff, 0xffffffff, 0, 0, 0, 0}};
  bool result = isBigDecimalOverflowed(src);
  bool expected = false;

  ck_assert_int_eq(result, expected);
}
END_TEST;

START_TEST(isDecimalOverflowTest4) {
  s21_big_decimal src = {{0, 0, 0, 0, 0, 0, 0}};
  bool result = isBigDecimalOverflowed(src);
  bool expected = false;

  ck_assert_int_eq(result, expected);
}
END_TEST;

START_TEST(bigDecimalSuCoreTest1) {
  s21_big_decimal A = {{78, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal B = {{34, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal res = {0};

  bigDecimalSubCore(A, B, &res);
  ck_assert_int_eq(res.bits[0], 44);
}
END_TEST;

START_TEST(bigDecimalSuCoreTest2) {
  s21_big_decimal A = {{0x369D2EC, 0x1C4, 0, 0, 0, 0, 0}};
  s21_big_decimal B = {{34, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal res = {0};

  bigDecimalSubCore(A, B, &res);  // 1941382484716 - 34 = 1941382484682

  ck_assert_int_eq(res.bits[0], 57266890);
  ck_assert_int_eq(res.bits[1], 452);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
  ck_assert_int_eq(res.bits[4], 0);
  ck_assert_int_eq(res.bits[5], 0);
  ck_assert_int_eq(res.bits[6], 0);
}
END_TEST;

START_TEST(bigDecimalSuCoreTest3) {
  s21_big_decimal A = {{0x115D2FC, 0x5AA9, 0, 0, 0, 0, 0}};  // 99681914180348
  s21_big_decimal B = {{0x34, 0x8854223, 0, 0, 0, 0, 0}};  // 613969642297229364
  s21_big_decimal res = {0};

  bigDecimalSubCore(
      A, B, &res);  // 99681914180348 - 613969642297229364 = -613869960383049016

  ck_assert_int_eq(res.bits[0], 4276759864);
  ck_assert_int_eq(res.bits[1], 142927737);
  ck_assert_int_eq(res.bits[6], 2147483648);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
  ck_assert_int_eq(res.bits[4], 0);
  ck_assert_int_eq(res.bits[5], 0);
}
END_TEST;

START_TEST(bigDecimalSuCoreTest4) {
  s21_big_decimal A = {
      {0x53de5, 0x45060f, 0, 0, 0, 0, 0}};              // 19428434887654885
  s21_big_decimal B = {{0x20, 0x8853, 0, 0, 0, 0, 0}};  // 149890063663136
  s21_big_decimal res = {0};

  bigDecimalSubCore(
      A, B, &res);  // 19428434887654885 - 149890063663136 = 19278544823991749

  ck_assert_int_eq(res.bits[0], 343493);
  ck_assert_int_eq(res.bits[1], 4488636);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
  ck_assert_int_eq(res.bits[4], 0);
  ck_assert_int_eq(res.bits[5], 0);
  ck_assert_int_eq(res.bits[6], 0);
}
END_TEST;

START_TEST(bigDecimalShiftTest1) {
  s21_big_decimal A = {{0b10100001111111110011110111111111,
                        0b10100001111111110011110111111111, 0, 0, 0, 0, 0}};

  bigDecimalShiftLeft(&A, 3);
}
END_TEST;

START_TEST(bigDecimalDivTest1) {
  s21_big_decimal A = {{385, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal B = {{5, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal res = {{0, 0, 0, 0, 0, 0, 0}};

  bigDecimalDiv(A, B, &res);

  ck_assert_int_eq(res.bits[0], 77);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
  ck_assert_int_eq(res.bits[4], 0);
  ck_assert_int_eq(res.bits[5], 0);
  ck_assert_int_eq(res.bits[6], 0);
}
END_TEST;

START_TEST(bigDecimalDivTest2) {
  s21_big_decimal A = {{6547, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal B = {{73, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal res = {{0, 0, 0, 0, 0, 0, 0}};

  bigDecimalDiv(A, B, &res);  // 89.6849315068493150684931506849

  ck_assert_int_eq(res.bits[0], 3129295521);
  ck_assert_int_eq(res.bits[1], 2017973599);
  ck_assert_int_eq(res.bits[2], 1373658533);
  ck_assert_int_eq(res.bits[3], 11);
  ck_assert_int_eq(res.bits[4], 0);
  ck_assert_int_eq(res.bits[5], 0);
  ck_assert_int_eq(res.bits[6], 1835008);
}
END_TEST;

START_TEST(bigDecimalDivTest3) {
  s21_big_decimal A = {{5634625, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal B = {{10, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal res = {{0, 0, 0, 0, 0, 0, 0}};

  bigDecimalDiv(A, B, &res);  // 5634625 / 10 = 563462.5

  ck_assert_int_eq(res.bits[0], 5634625);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
  ck_assert_int_eq(res.bits[4], 0);
  ck_assert_int_eq(res.bits[5], 0);
  ck_assert_int_eq(res.bits[6], 65536);
}
END_TEST;

START_TEST(bigDecimalDivTest4) {
  s21_big_decimal A = {{543235747, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal B = {{94736, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal res = {{0, 0, 0, 0, 0, 0, 0}};

  bigDecimalDiv(A, B, &res);  // 5734.2060779429150481337611889883

  ck_assert_int_eq(res.bits[0], 2434968795);
  ck_assert_int_eq(res.bits[1], 2775114846);
  ck_assert_int_eq(res.bits[2], 3257988584);
  ck_assert_int_eq(res.bits[3], 723);
  ck_assert_int_eq(res.bits[4], 0);
  ck_assert_int_eq(res.bits[5], 0);
  ck_assert_int_eq(res.bits[6], 1835008);
}
END_TEST;

START_TEST(biDecimalMulByTenTest1) {
  s21_big_decimal A = {{13, 0, 0, 0, 0, 0, 0}};

  bigDecimalMulByTen(&A);

  ck_assert_int_eq(A.bits[0], 130);
  ck_assert_int_eq(A.bits[1], 0);
  ck_assert_int_eq(A.bits[2], 0);
  ck_assert_int_eq(A.bits[3], 0);
  ck_assert_int_eq(A.bits[4], 0);
  ck_assert_int_eq(A.bits[5], 0);
  ck_assert_int_eq(A.bits[6], 0);
}
END_TEST;

START_TEST(biDecimalMulByTenTest2) {
  s21_big_decimal A = {{3241563, 0, 0, 0, 0, 0, 0}};

  bigDecimalMulByTen(&A);

  ck_assert_int_eq(A.bits[0], 32415630);
  ck_assert_int_eq(A.bits[1], 0);
  ck_assert_int_eq(A.bits[2], 0);
  ck_assert_int_eq(A.bits[3], 0);
  ck_assert_int_eq(A.bits[4], 0);
  ck_assert_int_eq(A.bits[5], 0);
  ck_assert_int_eq(A.bits[6], 0);
}
END_TEST;

START_TEST(biDecimalMulByTenTest3) {
  s21_big_decimal A = {{1, 0, 0, 0, 0, 0, 0}};

  bigDecimalMulByTen(&A);

  ck_assert_int_eq(A.bits[0], 10);
  ck_assert_int_eq(A.bits[1], 0);
  ck_assert_int_eq(A.bits[2], 0);
  ck_assert_int_eq(A.bits[3], 0);
  ck_assert_int_eq(A.bits[4], 0);
  ck_assert_int_eq(A.bits[5], 0);
  ck_assert_int_eq(A.bits[6], 0);
}
END_TEST;

START_TEST(biDecimalMulByTenTest4) {
  s21_big_decimal A = {{4325, 64224, 0, 0, 0, 0, 0}};  // 275839979622629
  bigDecimalMulByTen(&A);                              // 2758399796226290

  ck_assert_int_eq(A.bits[0], 43250);
  ck_assert_int_eq(A.bits[1], 642240);
  ck_assert_int_eq(A.bits[2], 0);
  ck_assert_int_eq(A.bits[3], 0);
  ck_assert_int_eq(A.bits[4], 0);
  ck_assert_int_eq(A.bits[5], 0);
  ck_assert_int_eq(A.bits[6], 0);
}
END_TEST;

START_TEST(fromBigDecimalToDecimalTest1) {
  s21_big_decimal bigA = {{4325, 64224, 0, 0, 0, 0, 0}};
  s21_decimal a = {0};

  int status = fromBigDecimalToDecimal(bigA, &a);

  ck_assert_int_eq(a.bits[0], 4325);
  ck_assert_int_eq(a.bits[1], 64224);
  ck_assert_int_eq(a.bits[2], 0);
  ck_assert_int_eq(a.bits[3], 0);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(fromBigDecimalToDecimalTest2) {
  s21_big_decimal bigA = {{4325, 64224, 4366, 54353424, 53241232, 0, 0}};
  // 18117052447053132300855.847104969631167483482341

  setBigDecimalScale(&bigA, 24);

  s21_decimal a = {0};
  //  18117052447053132300855.847105

  int status = fromBigDecimalToDecimal(bigA, &a);

  ck_assert_int_eq(a.bits[0], 867739841);
  ck_assert_int_eq(a.bits[1], 457162833);
  ck_assert_int_eq(a.bits[2], 982127381);
  ck_assert_int_eq(a.bits[3], 393216);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(fromBigDecimalToDecimalTest3) {
  s21_big_decimal bigA = {{4325, 64224, 4366, 54353424, 53241232, 0, 0}};

  s21_decimal a = {0};

  int status = fromBigDecimalToDecimal(bigA, &a);

  ck_assert_int_eq(a.bits[0], 0);
  ck_assert_int_eq(a.bits[1], 0);
  ck_assert_int_eq(a.bits[2], 0);
  ck_assert_int_eq(a.bits[3], 0);
  ck_assert_int_eq(status, 1);
}
END_TEST;

START_TEST(fromBigDecimalToDecimalTest4) {
  s21_big_decimal bigA = {{0xffffffff, 0xffffffff, 0xffffffff, 0, 0, 0, 0}};

  s21_decimal a = {0};

  int status = fromBigDecimalToDecimal(bigA, &a);

  ck_assert_int_eq(a.bits[0], 4294967295);
  ck_assert_int_eq(a.bits[1], 4294967295);
  ck_assert_int_eq(a.bits[2], 4294967295);
  ck_assert_int_eq(a.bits[3], 0);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(fromBigDecimalToDecimalTest5) {
  s21_big_decimal bigA = {{0xffffffff, 0xffffffff, 0xffffffff, 0, 0, 0, 0}};

  s21_decimal a = {0};

  int status = fromBigDecimalToDecimal(bigA, &a);

  ck_assert_int_eq(a.bits[0], 4294967295);
  ck_assert_int_eq(a.bits[1], 4294967295);
  ck_assert_int_eq(a.bits[2], 4294967295);
  ck_assert_int_eq(a.bits[3], 0);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(fromBigDecimalToDecimalTest6) {
  s21_big_decimal bigA = {
      {0xffffffff, 0xffffffff, 0xffffffff, 0, 0, 0, 2147876864}};

  s21_decimal a = {0};

  int status = fromBigDecimalToDecimal(bigA, &a);

  ck_assert_int_eq(a.bits[0], 4294967295);
  ck_assert_int_eq(a.bits[1], 4294967295);
  ck_assert_int_eq(a.bits[2], 4294967295);
  ck_assert_int_eq(a.bits[3], 2147876864);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(fromBigDecimalToDecimalTest7) {
  s21_big_decimal bigA = {
      {0xffffffff, 0xffffffff, 0xffffffff, 0, 0, 0, 2149515264}};

  s21_decimal a = {0};

  // -0.0079228162514264337593543950335
  // -0.0079228162514264337593543950

  int status = fromBigDecimalToDecimal(bigA, &a);

  ck_assert_int_eq(a.bits[0], 2645699854);
  ck_assert_int_eq(a.bits[1], 1271310319);
  ck_assert_int_eq(a.bits[2], 4294967);
  ck_assert_int_eq(a.bits[3], 2149318656);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(fromBigDecimalToDecimalTest8) {
  s21_big_decimal bigA = {
      {0xffffffff, 0xffffffff, 0xffffffff, 323245, 0, 0, 2149515264}};

  s21_decimal a = {0};

  //  -2561.0186620085890069762707770310655 31
  //  -2561.0186620085890069762707770 25

  int status = fromBigDecimalToDecimal(bigA, &a);

  ck_assert_int_eq(a.bits[0], 2858455354);
  ck_assert_int_eq(a.bits[1], 2417276313);
  ck_assert_int_eq(a.bits[2], 1388330998);
  ck_assert_int_eq(a.bits[3], 2149122048);
  ck_assert_int_eq(status, 0);
}
END_TEST;

START_TEST(fromBigDecimalToDecimalTest9) {
  s21_big_decimal bigA = {{0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                           0xffffffff, 5346345, 2147614720}};

  s21_decimal a = {0};

  int status = fromBigDecimalToDecimal(bigA, &a);

  ck_assert_int_eq(a.bits[0], 0);
  ck_assert_int_eq(a.bits[1], 0);
  ck_assert_int_eq(a.bits[2], 0);
  ck_assert_int_eq(a.bits[3], 0);
  ck_assert_int_eq(status, 2);
}
END_TEST;

Suite *utilsFunctionsTest(void) {
  Suite *s = suite_create("\033[45mUtils test\033[0m");
  TCase *tc = tcase_create("Utils test");

  tcase_add_test(tc, isDecimalOverflowTest1);
  tcase_add_test(tc, isDecimalOverflowTest2);
  tcase_add_test(tc, isDecimalOverflowTest3);
  tcase_add_test(tc, isDecimalOverflowTest4);
  tcase_add_test(tc, bigDecimalSuCoreTest1);
  tcase_add_test(tc, bigDecimalSuCoreTest2);
  tcase_add_test(tc, bigDecimalSuCoreTest3);
  tcase_add_test(tc, bigDecimalSuCoreTest4);
  tcase_add_test(tc, bigDecimalShiftTest1);
  tcase_add_test(tc, bigDecimalDivTest1);
  tcase_add_test(tc, bigDecimalDivTest2);
  tcase_add_test(tc, bigDecimalDivTest3);
  tcase_add_test(tc, bigDecimalDivTest4);
  tcase_add_test(tc, biDecimalMulByTenTest1);
  tcase_add_test(tc, biDecimalMulByTenTest2);
  tcase_add_test(tc, biDecimalMulByTenTest3);
  tcase_add_test(tc, biDecimalMulByTenTest4);
  tcase_add_test(tc, fromBigDecimalToDecimalTest1);
  tcase_add_test(tc, fromBigDecimalToDecimalTest2);
  tcase_add_test(tc, fromBigDecimalToDecimalTest3);
  tcase_add_test(tc, fromBigDecimalToDecimalTest4);
  tcase_add_test(tc, fromBigDecimalToDecimalTest5);
  tcase_add_test(tc, fromBigDecimalToDecimalTest6);
  tcase_add_test(tc, fromBigDecimalToDecimalTest7);
  tcase_add_test(tc, fromBigDecimalToDecimalTest8);
  tcase_add_test(tc, fromBigDecimalToDecimalTest9);

  suite_add_tcase(s, tc);
  return s;
}
