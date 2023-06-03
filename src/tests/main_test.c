#include "s21_test.h"

int main() {
  int number_failed = 0;

  Suite *test[] = {//  COMPARISON
                   isEqualTest(), isNotEqualTest(), isLessTest(),
                   isGreaterTest(), isLessOrEqualTest(), isGreaterOrEqualTest(),
                   // OTHER FUNCTIONS TESTS
                   utilsFunctionsTest(), truncateTest(), negateTest(),
                   roundTest(), floorTest(),
                   // CONVERT TESTS
                   decimalConvertTests(), fromIntToDecimalTest(),
                   fromFloatToDecimalTest(),
                   // ARITHMETIC
                   mulTest(), addTest(), divTest(), subTest(), NULL};

  for (int i = 0; test[i] != NULL; i++) {
    printf("\n\n");
    SRunner *sr = srunner_create(test[i]);

    srunner_run_all(sr, CK_NORMAL);

    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  return (number_failed == 0) ? 0 : 1;
}
