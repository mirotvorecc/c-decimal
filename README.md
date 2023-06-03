# c-decimal

A custom implementation of the `decimal.h` library in C, supporting precise decimal arithmetic and extended operations.

This repository provides source code for a decimal value type and associated arithmetic, comparison, and conversion functions. The implementation is designed for high-precision calculations, such as those needed in financial applications, and includes support for both standard and "big decimal" operations.

## Prerequisites

- GCC
- [Make](https://www.gnu.org/software/make/) for building and testing
- [Docker](https://www.docker.com/get-started) (optional, if using the provided Dockerfile)

## Contents

- [`src/big_decimal_functions/`](src/big_decimal_functions/): Functions for high-precision ("big decimal") arithmetic and conversions
- `bigDecimalAddCore.c`, `bigDecimalDiv.c`, `bigDecimalMul.c`, `bigDecimalSubCore.c`: Core arithmetic for big decimals
- `fromBigDecimalToDecimal.c`, `fromDecimalToBigDecimal.c`: Conversion routines
- `common.c`, `s21_big_decimal.h`: Shared helpers and type definitions
- [`src/common/`](src/common/): Common utilities and helpers for decimal operations
- [`src/main_functions/`](src/main_functions/): Core decimal arithmetic, comparison, and conversion functions
- Includes: `s21_add.c`, `s21_div.c`, `s21_floor.c`, `s21_from_decimal_to_float.c`, `s21_is_equal.c`, `s21_mul.c`, `s21_negate.c`, `s21_round.c`, and others
- [`src/tests/`](src/tests/): Unit tests for all implemented functions
- [`src/s21_decimal.h`](src/s21_decimal.h): Public header file for the decimal type and API
- [`src/Makefile`](src/Makefile): Build and test automation
- [`src/Dockerfile`](src/Dockerfile): Docker container setup for isolated builds and testing

## Setup and Usage

1. **Clone this repository:**
    ```
    git clone https://github.com/mirotvorecc/c-decimal.git
    cd c-decimal/src
    ```

2. **Build the project:**
    ```
    make
    ```

3. **Run the tests:**
    ```
    make test
    ```

4. **(Optional) Build and run in Docker:**
    ```
    make docker
    ```

5. **Integrate into your project:**
    - Copy required source files and `s21_decimal.h` from `src/` into your project.
    - Include `s21_decimal.h` in your C source files.

## Features

- **Decimal type (`s21_decimal`)**: 96-bit signed real numbers for precise calculations, avoiding floating-point errors.
- **Big decimal support**: Extended operations for larger numbers via `big_decimal_functions`.
- **Arithmetic operations**: Addition, subtraction, multiplication, division, modulus.
- **Comparison operations**: Equal, not equal, greater, less, greater or equal, less or equal.
- **Conversion functions**: Between decimal, float, int, and big decimal types.
- **Rounding and sign functions**: Floor, round, truncate, negate.
- **Modular structure**: All functions are organized by category for clarity and maintainability.
- **Unit tests**: Automated test suite achieves over 80% line coverage across the codebase, with coverage metrics generated using `gcov`.
- **Docker support**: Optional containerized build and test environment.

## Notes

- The decimal type is implemented as a struct with bit fields to represent value, scale, and sign, closely following the design used in financial and accounting systems.
- Big decimal functions allow operations on numbers larger than the standard decimal range.
- Error codes are returned by most operations to indicate overflow, underflow, division by zero, or other calculation errors.
- The project is modular and can be easily extended or integrated into other C projects.
