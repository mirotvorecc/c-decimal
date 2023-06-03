CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
MAIN_FILES=main_functions/*.c
BIG_DECIMAL_FILES=big_decimal_functions/*.c
COMMON_FILES=common/*.c
TEST_FILES=tests/*.c
CHECK_LINK=$(shell pkg-config --libs --cflags check)
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

all: run

s21_decimal.a: 
	$(CC) $(CFLAGS) -c $(BIG_DECIMAL_FILES) $(MAIN_FILES) $(COMMON_FILES)
	ar rc s21_decimal.a *.o
	ranlib s21_decimal.a

test: s21_decimal.a
	$(CC) $(CFLAGS) $(TEST_FILES) s21_decimal.a $(CHECK_LINK) -o s21_decimal_test.o

run: test
	./s21_decimal_test.o

clean:
	@rm -f *.o
	@rm -f *.a
	@rm -f *.gcno
	@rm -f *.gcba
	@rm -f *.info
	@rm -f *.gcda
	@rm -f ./icovOutput
	@rm -f *.html
	@rm -f *.css
	@rm -f *.png
	@rm -f tests/*.o
	@rm -f tests/*.a
	@rm -f tests/*.gcno
	@rm -f tests/*.gcba
	@rm -f tests/*.info
	@rm -f tests/*.gcda
	@rm -f tests/*.html
	@rm -f tests/*.css
	@rm -f tests/*.png
	@rm -f main_functions/*.o
	@rm -f main_functions/*.a
	@rm -f main_functions/*.gcno
	@rm -f main_functions/*.gcba
	@rm -f main_functions/*.info
	@rm -f main_functions/*.gcda
	@rm -f main_functions/*.html
	@rm -f main_functions/*.css
	@rm -f main_functions/*.png
	@rm -rf ./Applications
	@rm -rf report
	@rm -f big_decimal_functions/*.o
	@rm -f big_decimal_functions/*.a
	@rm -f big_decimal_functions/*.gcno
	@rm -f big_decimal_functions/*.gcba
	@rm -f big_decimal_functions/*.info
	@rm -f big_decimal_functions/*.gcda
	@rm -f big_decimal_functions/*.html
	@rm -f big_decimal_functions/*.css
	@rm -f big_decimal_functions/*.png
	@rm -f common/*.o
	@rm -f common/*.a
	@rm -f common/*.gcno
	@rm -f common/*.gcba
	@rm -f common/*.info
	@rm -f common/*.gcda
	@rm -f common/*.html
	@rm -f common/*.css
	@rm -f common/*.png
	@rm -f ./valgrind.txt
	@echo
	@echo / ALL FILES WERE DELETED /
	@echo

r: clean all

style:
	@clear
	@clang-format -i -style=google $(MAIN_FILES) $(COMMON_FILES) $(TEST_FILES) $(BIG_DECIMAL_FILES)
	@clang-format -n -style=google $(MAIN_FILES) $(COMMON_FILES) $(TEST_FILES) $(BIG_DECIMAL_FILES)
	@sleep 0.1
	@echo / GOOGLE STYLE TEST WAS PASSED /
	@sleep 1.5
	@clear

docker:
	docker build . -t s21_decimal --platform linux/amd64
	docker run s21_decimal

#docker:
#	docker build . -t s21_decimal
#	docker run -it -v $(PWD):/usr/src s21_decimal

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem main_functions/*.c common/*.c tests/*.c big_decimal_functions/*.c

#gcov_report
gcov_report: s21_decimalGR grBuild grRun icov htmlGen open

s21_decimalGR:
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $(BIG_DECIMAL_FILES) $(MAIN_FILES) $(COMMON_FILES)
	ar rc s21_decimal.a *.o
	ranlib s21_decimal.a

grBuild:
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(TEST_FILES) $(CHECK_LINK) s21_decimal.a -o icovOutput

grRun:
	./icovOutput

icov:
	lcov -t "test" -o icovOutput.info -c -d ./

htmlGen:
	genhtml  -o report icovOutput.info

open:
	open ./report/index.html

# valgrind

# silent mode for valgrind (only errors)
valgrind: test
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-reachable=yes --track-fds=yes ./s21_decimal_test.o > valgrind.txt 2>&1


