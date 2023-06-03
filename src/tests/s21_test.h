#ifndef SRC_TESTS_S21_TEST
#define SRC_TESTS_S21_TEST

#include <check.h>
#include <errno.h>
#include <stdio.h>

#include "../common/common.h"
#include "../s21_decimal.h"

// comparison tests
Suite *isEqualTest(void);
Suite *isNotEqualTest(void);
Suite *isLessTest(void);
Suite *isLessOrEqualTest(void);
Suite *isGreaterTest(void);
Suite *isGreaterOrEqualTest(void);
// convert tests
Suite *fromIntToDecimalTest(void);
Suite *fromFloatToDecimalTest(void);
Suite *decimalConvertTests(void);
// other functions tests
Suite *truncateTest(void);
Suite *negateTest(void);
Suite *floorTest(void);
Suite *roundTest(void);
Suite *utilsFunctionsTest(void);
Suite *otherFunctions(void);
// arithmetic tests
Suite *mulTest(void);
Suite *subTest(void);
Suite *divTest(void);
Suite *addTest(void);

#endif  // SRC_TESTS_S21_TEST
